#include "GameManager.h"
#include <iostream>
#include <conio.h>   // _kbhit(), _getch() için
#include <windows.h> // Sleep() için
#include <algorithm> // find() için

GameManager::GameManager(int w, int h)
    : width(w), height(h), gameOver(false), score(0) {
    reset(); // yýlan ve yemi sýfýrla
}
 
void GameManager::reset() {
    snake = Snake();  // yeni yýlan oluþtur
    food = Food();    // yeni yem oluþtur

    int fx = rand() % width;
    int fy = rand() % height;
    food.setPosition(fx, fy);

    gameOver = false;
    score = 0;
}
bool GameManager::isGameOver() const {
    return gameOver;
}

void GameManager::run() {
    while (!gameOver) {
        processInput(); // klavyeden yön kontrolü al
        update();       // yýlaný ilerlet, çarpýþmalarý kontrol et
        render();       // ekraný çiz
        Sleep(100);     // 100 ms bekle (oyun hýzýný belirler)
    }

    std::cout << "Game Over! Final Score: " << score << std::endl;
}

void GameManager::processInput() {
    if (_kbhit()) { // Klavyeden tuþa basýldýysa
        char ch = _getch(); // Tuþu oku
        switch (ch) {
        case 'w':
        case 'W':
        case 72: // Yukarý ok
            snake.changeDirection(Direction::UP);
            break;
        case 's':
        case 'S':
        case 80: // Aþaðý ok
            snake.changeDirection(Direction::DOWN);
            break;
        case 'a':
        case 'A':
        case 75: // Sol ok
            snake.changeDirection(Direction::LEFT);
            break;
        case 'd':
        case 'D':
        case 77: // Sað ok
            snake.changeDirection(Direction::RIGHT);
            break;
        case 27: // ESC tuþu -> oyunu bitir
            gameOver = true;
            break;
        }
    }
}
void GameManager::update() {
    Point nextPos = snake.getNextHeadPosition();

    // Duvar çarpmasý kontrolü
    if (nextPos.x < 0 || nextPos.x >= width || nextPos.y < 0 || nextPos.y >= height) {
        gameOver = true;
        return;
    }

    // Kendi kendine çarpma
    if (snake.isCollision()) {
        gameOver = true;
        return;
    }

    // Yiyeceði yedi mi?
    if (nextPos == food.getPosition()) {
        snake.growUp(); // Büyümeyi iþaretle
        food.setPosition(rand() % width, rand() % height); // Yeni yiyecek konumu
    }

    // Yýlaný hareket ettir
    snake.move();
}
void GameManager::render() const{
    system("cls"); // Ekraný temizle (Windows için)

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Point p(x, y);

            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                std::cout << "#"; // Kenarlýk
            }
            else if (p == snake.getHead()) {
                std::cout << "@"; // Yýlanýn baþý
            }
            else if (std::find(snake.getBody().begin(), snake.getBody().end(), p) != snake.getBody().end()) {
                std::cout << "o"; // Yýlanýn gövdesi
            }
            else if (p == food.getPosition()) {
                std::cout << "*"; // Yiyecek
            }
            else {
                std::cout << " "; // Boþluk
            }
        }
        std::cout << "\n";
    }

    std::cout << "Use W A S D or Arrow Keys to move. Press ESC to quit.\n";
}


