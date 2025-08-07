#pragma once
#include <deque> //ba� ve kuyru�a ekleme, silme ve eri�im i�lemleri i�in deque kullan�l�r.
#include "Point.h"
#include "Direction.h"

class Snake {
private:
    std::deque<Point> body; //Y�lan�n her bir par�as�n�n konumunu tutar. 
	Direction currentDirection; //Y�lan�n hareket y�n�n� tutar.
    bool growing;

public:
    Snake(Point startPosition);

    void move();
    void changeDirection(Direction newDirection);
    void growUp();
    void grow();
	Point getNextHeadPosition() const; // Y�lan�n bir sonraki ba� pozisyonunu d�nd�r�r.
    bool isCollision() const;
    Point getHead() const;
	const std::deque<Point>& getBody() const; //bu fonksiyon, y�lan�n g�vdesini d��ar�ya eri�im i�in sa�lar.
	Direction getDirection() const; // bu fonksiyon, y�lan�n hareket y�n�n� d��ar�ya eri�im i�in sa�lar.
};

