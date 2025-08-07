#include "GameManager.h"
#include <iostream>
#include <conio.h>   // _kbhit(), _getch() i�in
#include <windows.h> // Sleep() i�in
#include <algorithm> // find() i�in

GameManager::GameManager(int w, int h)
    : width(w), height(h), gameOver(false), score(0) {
    reset(); // y�lan ve yemi s�f�rla
}
 
void GameManager::reset() {
    snake = Snake();  // yeni y�lan olu�tur
    food = Food();    // yeni yem olu�tur

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
        processInput(); // klavyeden y�n kontrol� al
        update();       // y�lan� ilerlet, �arp��malar� kontrol et
        render();       // ekran� �iz
        Sleep(100);     // 100 ms bekle (oyun h�z�n� belirler)
    }

    std::cout << "Game Over! Final Score: " << score << std::endl;
}

void GameManager::processInput() {
    if (_kbhit()) { // Klavyeden tu�a bas�ld�ysa
        char ch = _getch(); // Tu�u oku
        switch (ch) {
        case 'w':
        case 'W':
        case 72: // Yukar� ok
            snake.changeDirection(Direction::UP);
            break;
        case 's':
        case 'S':
        case 80: // A�a�� ok
            snake.changeDirection(Direction::DOWN);
            break;
        case 'a':
        case 'A':
        case 75: // Sol ok
            snake.changeDirection(Direction::LEFT);
            break;
        case 'd':
        case 'D':
        case 77: // Sa� ok
            snake.changeDirection(Direction::RIGHT);
            break;
        case 27: // ESC tu�u -> oyunu bitir
            gameOver = true;
            break;
        }
    }
}
void GameManager::update() {
    Point nextPos = snake.getNextHeadPosition();

    // Duvar �arpmas� kontrol�
    if (nextPos.x < 0 || nextPos.x >= width || nextPos.y < 0 || nextPos.y >= height) {
        gameOver = true;
        return;
    }

    // Kendi kendine �arpma
    if (snake.isCollision()) {
        gameOver = true;
        return;
    }

    // Yiyece�i yedi mi?
    if (nextPos == food.getPosition()) {
        snake.growUp(); // B�y�meyi i�aretle
        food.setPosition(rand() % width, rand() % height); // Yeni yiyecek konumu
    }

    // Y�lan� hareket ettir
    snake.move();
}
void GameManager::render() const{
    system("cls"); // Ekran� temizle (Windows i�in)

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Point p(x, y);

            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                std::cout << "#"; // Kenarl�k
            }
            else if (p == snake.getHead()) {
                std::cout << "@"; // Y�lan�n ba��
            }
            else if (std::find(snake.getBody().begin(), snake.getBody().end(), p) != snake.getBody().end()) {
                std::cout << "o"; // Y�lan�n g�vdesi
            }
            else if (p == food.getPosition()) {
                std::cout << "*"; // Yiyecek
            }
            else {
                std::cout << " "; // Bo�luk
            }
        }
        std::cout << "\n";
    }

    std::cout << "Use W A S D or Arrow Keys to move. Press ESC to quit.\n";
}


