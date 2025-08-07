#include "Snake.h"
#include "Direction.h"

Snake::Snake(Point startPosition) {
    body.push_front(startPosition);
    currentDirection = Direction::RIGHT; //
}

Point Snake::getHead() const {
    return body.front();
}

void Snake::move() {
    Point newHead = getHead();

    switch (currentDirection) {
    case Direction::UP:
        newHead.y--;
        break;
    case Direction::DOWN:
        newHead.y++;
        break;
    case Direction::LEFT:
        newHead.x--;
        break;
    case Direction::RIGHT:
        newHead.x++;
        break;
    }

    body.push_front(newHead);

    if (!growing)
        body.pop_back();

    growing = false;
}

void Snake::changeDirection(Direction newDirection) {
    if ((currentDirection == Direction::UP && newDirection == Direction::DOWN) ||
        (currentDirection == Direction::DOWN && newDirection == Direction::UP) ||
        (currentDirection == Direction::LEFT && newDirection == Direction::RIGHT) ||
        (currentDirection == Direction::RIGHT && newDirection == Direction::LEFT)) {
        return;
    }

    currentDirection = newDirection;
}

void Snake::growUp() {
    growing = true;
}

bool Snake::isCollision() const {
    Point head = getHead();

    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i] == head)
            return true;
    }

    return false;
}
Point Snake::getNextHeadPosition() const {  
    Point currentHead = getHead();  
    switch (currentDirection) { // Corrected from "Direction" to "currentDirection"  
    case Direction::UP:    return Point(currentHead.x, currentHead.y - 1);  
    case Direction::DOWN:  return Point(currentHead.x, currentHead.y + 1);  
    case Direction::LEFT:  return Point(currentHead.x - 1, currentHead.y);  
    case Direction::RIGHT: return Point(currentHead.x + 1, currentHead.y);  
    }  
    return currentHead; // Fallback return  
}
const std::deque<Point>& Snake::getBody() const {
    return body; // Yýlanýn gövdesini dýþarýya eriþim için saðlar.
}
void Snake::grow() {
    Point newHead = getNextHeadPosition();
    body.push_front(newHead);  // Kuyruðu silmeden yeni baþ ekle ? büyüme
}