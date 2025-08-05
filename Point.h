#pragma once
// oyundaki t�m konumlanabilir nesnelerin (yani y�lan, yem, duvar vs.) konumlar�n� temsil etmek i�in de kullan�lacak.

struct Point {
	int x;
	int y;

	bool operator==(const Point& other) const {	 //Y�lan�n kendi v�cuduna �arp�p �arpmad���n� anlamak i�in Yem ile y�lan�n ayn� pozisyonda olup olmad���n� kontrol etmek i�in
	return x == other.x && y == other.y;		//Bu fonksiyon, iki Point nesnesinin x ve y koordinatlar�n�n e�it olup olmad���n� kontrol eder.

	}s	
};

// This struct defines a `Point` type that represents a position in a 2D space with `x` and `y` coordinates.
// The `Point` struct includes an equality operator (`==`) to compare two `Point` instances.
// The `operator==` checks if the `x` and `y` coordinates of two `Point` instances are equal.
// This struct can be used to represent positions of objects in a game, such as the snake's head, food items, or walls.
// The `Point` struct can be used in conjunction with the `Direction` enum to determine the movement of the snake.
// The `Point` struct can be extended in the future to include additional properties, such as color or size,
// but currently, it serves as a simple representation of a position in the game.
// The `Point` struct can be used in various game logic calculations, such as collision detection,
// distance calculations, and rendering positions on the game board.
