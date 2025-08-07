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

    void run();                 // Ana oyun döngüsü
    void processInput();        // Klavye giriþi iþleme
    void update();              // Oyun verilerini güncelle
    void render() const;        // Ekraný çiz
    void reset();               // Oyunu sýfýrla
    bool isGameOver() const;    // Oyun bitmiþ mi?
    void increaseScore();       // Skoru artýran fonksiyon
    int getScore() const;       // Skoru döndüren fonksiyon
};
