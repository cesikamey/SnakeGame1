#pragma once
#include "Point.h"

class Food
{
public:
    Food(); // Baþlangýçta (0,0) konumuna yerleþtirir
    Food(int x, int y); // Belirli konuma yerleþtir

    void spawnRandom(int maxX, int maxY); // Rastgele konum belirler
    void setPosition(int x, int y);       // Elle konum belirle
    void setPosition(const Point& p);     // Nokta nesnesiyle konum belirle

    Point getPosition() const; // Mevcut konumu al

private:
    Point position;
};
