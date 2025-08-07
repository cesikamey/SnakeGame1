#pragma once //bu yapý , bu header dosyasýnýn sadece bir kez dahil edilmesini saðlar. ifndef, define ve endif ile ayný iþlevi görür.

enum class Direction { 
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
};
 


// This header file defines an enumeration for the possible directions in the Snake game.
// The `Direction` enum includes five values: Up, Down, Left, Right, and None.
// This enum can be used to control the movement of the snake in the game.
// The `None` value can be used to indicate that there is no movement or direction change.
// The `#pragma once` directive ensures that this header file is included only once in a single compilation,
// preventing multiple definitions and improving compilation efficiency.
// The `#ifndef`, `#define`, and `#endif` directives are used to prevent multiple inclusions of this header file,
// which is a common practice in C++ header files to avoid redefinition errors.
// The `Direction` enum can be used in the game logic to determine how the snake should move based on user input or game events.
// The `Direction` enum can be extended in the future if additional movement directions are needed,
// but currently, it provides a simple and clear way to represent the four cardinal directions and a neutral state.
// The `Direction` enum can be used in conjunction with other game components, such as the snake's body segments,
// the game board, and the food items, to create a cohesive and interactive gameplay experience.
// The `Direction` enum can also be used to implement collision detection,
// where the snake's movement direction is checked against the boundaries of the game board or against itself.
// This enum can be easily integrated into the game's input handling system,
