#pragma once

#include "Snake.h"
#include "Food.h"

class GameManager {
private:
    Snake snake;
    Food food;
    int width;
    int height;
    bool gameOver;
    int score;

public:
    GameManager(int w, int h);

    void run();                 // Ana oyun d�ng�s�
    void processInput();        // Klavye giri�i i�leme
    void update();              // Oyun verilerini g�ncelle
    void render() const;        // Ekran� �iz
    void reset();               // Oyunu s�f�rla
    bool isGameOver() const;    // Oyun bitmi� mi?
    void increaseScore();       // Skoru art�ran fonksiyon
    int getScore() const;       // Skoru d�nd�ren fonksiyon
};
