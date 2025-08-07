#include "Food.h"
#include "Point.h"
#include <cstdlib>
#include <ctime>

// (0,0)'dan ba�lat
Food::Food() : position(0, 0) {}

// Belirli konumdan ba�lat
Food::Food(int x, int y) : position(x, y) {}

void Food::spawnRandom(int maxX, int maxY) {
    int x = rand() % maxX;
    int y = rand() % maxY;
    setPosition(x, y);
}

void Food::setPosition(int x, int y) {
    position = Point(x, y); 
}

void Food::setPosition(const Point& p) {
    position = p;
}

Point Food::getPosition() const {
    return position;
}
