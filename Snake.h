#pragma once
#include <deque> //baþ ve kuyruða ekleme, silme ve eriþim iþlemleri için deque kullanýlýr.
#include "Point.h"
#include "Direction.h"

class Snake {
private:
    std::deque<Point> body; //Yýlanýn her bir parçasýnýn konumunu tutar. 
	Direction currentDirection; //Yýlanýn hareket yönünü tutar.
    bool growing;

public:
    Snake(Point startPosition);

    void move();
    void changeDirection(Direction newDirection);
    void growUp();
    void grow();
	Point getNextHeadPosition() const; // Yýlanýn bir sonraki baþ pozisyonunu döndürür.
    bool isCollision() const;
    Point getHead() const;
	const std::deque<Point>& getBody() const; //bu fonksiyon, yýlanýn gövdesini dýþarýya eriþim için saðlar.
	Direction getDirection() const; // bu fonksiyon, yýlanýn hareket yönünü dýþarýya eriþim için saðlar.
};

