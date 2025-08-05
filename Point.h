#pragma once
// oyundaki tüm konumlanabilir nesnelerin (yani yýlan, yem, duvar vs.) konumlarýný temsil etmek için de kullanýlacak.

struct Point {
	int x;
	int y;

	bool operator==(const Point& other) const {	 //Yýlanýn kendi vücuduna çarpýp çarpmadýðýný anlamak için Yem ile yýlanýn ayný pozisyonda olup olmadýðýný kontrol etmek için
	return x == other.x && y == other.y;		//Bu fonksiyon, iki Point nesnesinin x ve y koordinatlarýnýn eþit olup olmadýðýný kontrol eder.

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
