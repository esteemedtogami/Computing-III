#ifndef SNAKE_H
/*********************************
Programmer: Sam Pickell
Date: 12/11/2016
Time Spent: 13 hours and 25 minutes
Purpose: Create the game Snake
*********************************/
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#undef max

using namespace std;

const int DEFAULT_WORLD_HEIGHT = 35;
const int DEFAULT_WORLD_WIDTH = 75;

static void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

enum Direction { UP, DOWN, LEFT, RIGHT, NUMBER_OF_DIRECTIONS };
enum Tile_type { EMPTY, BOUNDRY, RED, RED_BODY, BLUE, BLUE_BODY, APPLE, NUMBER_OF_EMPTY_TILES };

struct Position
{
	int x;
	int y;
};

class Tile;
typedef Tile* Tile_ptr;

class World;

class Tile
{
public:
	Tile() : position{ 0,0 } {}
	Tile(int a, int b) : position{ a, b } {}
	Position get_position() { return position; };
	void set_position(Position pos) { position = pos; }
	virtual void draw() = 0; 
	friend void swap_position(Tile_ptr& first, Tile_ptr& second);
	virtual void move(World& w) = 0;
	virtual Tile_type who() = 0;

private:
	Position position;

};



class Snake : public Tile
{
public:
	Snake() : health{ 1 } {}
	Snake(int a, int b) : Tile(a, b), health{ 1 } {}
	Snake(int a, int b, int h) : Tile(a, b), health(h) {}
	int get_health() { return health; }
	void set_health(int i) { health += i; }
	virtual void move(World& w) {};
	virtual Tile_type who() = 0;

private:
	int health = 1;
};

class Empty : public Tile
{
public:
	Empty() {}
	Empty(int a, int b) : Tile(a, b) {}
	virtual void draw();
	virtual void move(World& w) {};
	virtual Tile_type who() { return EMPTY; }

};

class Boundry : public Tile
{
public:
	Boundry() {}
	Boundry(int a, int b) : Tile(a, b) {}
	virtual void draw();
	virtual void move(World& w) {};
	virtual Tile_type who() { return BOUNDRY; }

};

class Apple : public Tile
{
public:
	Apple() {}
	Apple(int a, int b) : Tile(a, b) {}
	virtual void draw();
	virtual void move(World& w) {};
	virtual Tile_type who() { return APPLE; }

};

class Red_Snake : public Snake
{
public:
	Red_Snake() {}
	Red_Snake(int a, int b) : Snake(a, b) {}
	virtual void draw();
	virtual void move(World& w);
	virtual Tile_type who() { return RED; }
};

class Red_Body : public Snake
{
public:
	Red_Body() {}
	Red_Body(int a, int b) : Snake(a, b) {}
	virtual void draw();
	virtual void move(World& w);
	virtual Tile_type who() { return RED_BODY; }

private:
	Position position;
};

class Blue_Snake : public Snake
{
public:
	Blue_Snake() {}
	Blue_Snake(int a, int b) : Snake(a, b) {}
	virtual void draw();
	virtual void move(World& w);
	virtual Tile_type who() { return BLUE; }
};

class Blue_Body : public Snake
{
public:
	Blue_Body() {}
	Blue_Body(int a, int b) : Snake(a, b) {}
	virtual void draw();
	virtual void move(World& w);
	virtual Tile_type who() { return BLUE_BODY; }

private:
	Position position;
};


class World
{
public:
	World();
	World(int mode);
	int get_height() const { return height; }
	int get_width() const { return width; }
	Tile_ptr* operator[](int index);

private:

private:
	int height;
	int width;
	Tile_ptr** grid;
};

void one_player_game(bool& user_wishes_to_continue);
void two_player_game(bool& user_wishes_to_continue);

void game_over(World& world);

void replay_game(bool& player_continue);

void clear_screen();

#endif
