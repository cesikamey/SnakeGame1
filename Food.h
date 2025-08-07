#pragma once
#include "Point.h"

class Food
{
public:
    Food(); // Ba�lang��ta (0,0) konumuna yerle�tirir
    Food(int x, int y); // Belirli konuma yerle�tir

    void spawnRandom(int maxX, int maxY); // Rastgele konum belirler
    void setPosition(int x, int y);       // Elle konum belirle
    void setPosition(const Point& p);     // Nokta nesnesiyle konum belirle

    Point getPosition() const; // Mevcut konumu al

private:
    Point position;
};
