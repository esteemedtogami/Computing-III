/*********************************
Programmer: Sam Pickell
Date: 12/11/2016
Time Spent: 13 hours and 25 minutes 
Purpose: Create the game Snake
*********************************/
#include "Snake.h"

bool game_is_not_over = true, red_wins = false, blue_wins = false;
int p1_score = 0, p2_score = 0;
int red_head_X, red_head_Y, blue_head_X, blue_head_Y;
Direction p1_direction = UP, p2_direction = DOWN;
vector<Tile_ptr> red_bodies, blue_bodies;

void one_player_game(bool& user_wishes_to_continue)
{
	srand((time(0)));
	World world;
	int speed_check = 1;
	int health_check = 2;
	int sleep_time = 100;

	//First Pass
	vector<Tile_ptr> red_snakes;
	vector<Tile_ptr> green_apples;
	for (int i = 1; i < world.get_height(); i++)
	{
		for (int j = 1; j < world.get_width(); j++)
		{
			world[i][j]->draw();
			if (world[i][j]->who() == RED)
			{
				red_snakes.push_back(world[i][j]);
			}
			else if (world[i][j]->who() == APPLE)
			{
				green_apples.push_back(world[i][j]);
			}
		}
	}

	for (vector<Tile_ptr>::iterator p = red_snakes.begin(); p != red_snakes.end(); p++)
	{
		(*p)->move(world);
	}
	gotoxy(0, 0);
	cout << "Score: " << p1_score;


	// Subsequent passes
	while (game_is_not_over)
	{
		vector<Tile_ptr> red_snakes;
		vector<Tile_ptr> red_tail;
		vector<Tile_ptr> green_apples;
		for (int i = 2; i < world.get_height(); i++)
		{
			for (int j = 2; j < world.get_width(); j++)
			{
				
				if (world[i][j]->who() == RED)
				{
					world[i][j]->draw();
					red_snakes.push_back(world[i][j]);
				}
				if (world[i][j]->who() == APPLE)
				{
					world[i][j]->draw();
					green_apples.push_back(world[i][j]);
				}
			}
		}

		for (vector<Tile_ptr>::iterator p = red_snakes.begin(); p != red_snakes.end(); p++)
		{
			if (GetAsyncKeyState(VK_UP) && !(p1_direction == DOWN))
			{
				p1_direction = UP;
			}
			if (GetAsyncKeyState(VK_DOWN) && !(p1_direction == UP))
			{
				p1_direction = DOWN;
			}
			if (GetAsyncKeyState(VK_LEFT) && !(p1_direction == RIGHT))
			{
				p1_direction = LEFT;
			}
			if (GetAsyncKeyState(VK_RIGHT) && !(p1_direction == LEFT))
			{
				p1_direction = RIGHT;
			}


			(*p)->move(world);
		}

		for (vector<Tile_ptr>::iterator p = red_bodies.begin(); p != red_bodies.end(); p++)
		{
			(*p)->move(world);
		}

		//for every 4 eaten apples, speed increases
		if (((p1_score + p2_score) / 100) == speed_check)
		{
			sleep_time -= 10;
			speed_check++;
		}

		if (sleep_time < 0)
		{
			sleep_time = 0;
		}

		Sleep(sleep_time);
		
		gotoxy(0, 0);
		cout << "Score: " << p1_score;
	}

	blue_wins = false;

	game_over(world);

	replay_game(user_wishes_to_continue);
}

void two_player_game(bool& user_wishes_to_continue)
{
	srand((time(0)));
	World world(1);
	int speed_check = 1;
	int sleep_time = 100;

	//First Pass
	vector<Tile_ptr> red_snakes;
	vector<Tile_ptr> blue_snakes;
	vector<Tile_ptr> green_apples;
	for (int i = 1; i < world.get_height(); i++)
	{
		for (int j = 1; j < world.get_width(); j++)
		{
			world[i][j]->draw();
			if (world[i][j]->who() == RED)
			{
				red_snakes.push_back(world[i][j]);
			}
			else if (world[i][j]->who() == APPLE)
			{
				green_apples.push_back(world[i][j]);
			}
			else if (world[i][j]->who() == BLUE)
			{
				blue_snakes.push_back(world[i][j]);
			}
		}
	}

	for (vector<Tile_ptr>::iterator p = red_snakes.begin(); p != red_snakes.end(); p++)
	{
		(*p)->move(world);
	}
	for (vector<Tile_ptr>::iterator p = blue_snakes.begin(); p != blue_snakes.end(); p++)
	{
		(*p)->move(world);
	}
	gotoxy(0, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Score: " << p1_score;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
		FOREGROUND_BLUE | FOREGROUND_GREEN);

	gotoxy(55, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Score: " << p2_score;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
		FOREGROUND_BLUE | FOREGROUND_GREEN);


	// Subsequent passes
	while (game_is_not_over)
	{
		vector<Tile_ptr> red_snakes;
		vector<Tile_ptr> blue_snakes;
		vector<Tile_ptr> green_apples;
		for (int i = 2; i < world.get_height(); i++)
		{
			for (int j = 2; j < world.get_width(); j++)
			{

				if (world[i][j]->who() == RED)
				{
					world[i][j]->draw();
					red_snakes.push_back(world[i][j]);
				}
				if (world[i][j]->who() == APPLE)
				{
					world[i][j]->draw();
					green_apples.push_back(world[i][j]);
				}
				if (world[i][j]->who() == BLUE)
				{
					world[i][j]->draw();
					blue_snakes.push_back(world[i][j]);
				}
			}
		}

		for (vector<Tile_ptr>::iterator p = red_snakes.begin(); p != red_snakes.end(); p++)
		{
			if (GetAsyncKeyState(VK_UP) && !(p1_direction == DOWN))
			{
				p1_direction = UP;
			}
			if (GetAsyncKeyState(VK_DOWN) && !(p1_direction == UP))
			{
				p1_direction = DOWN;
			}
			if (GetAsyncKeyState(VK_LEFT) && !(p1_direction == RIGHT))
			{
				p1_direction = LEFT;
			}
			if (GetAsyncKeyState(VK_RIGHT) && !(p1_direction == LEFT))
			{
				p1_direction = RIGHT;
			}


			(*p)->move(world);
		}

		for (vector<Tile_ptr>::iterator p = blue_snakes.begin(); p != blue_snakes.end(); p++)
		{
			if (GetAsyncKeyState(0x57) && !(p2_direction == DOWN))
			{
				p2_direction = UP;
			}
			if (GetAsyncKeyState(0x53) && !(p2_direction == UP))
			{
				p2_direction = DOWN;
			}
			if (GetAsyncKeyState(0x41) && !(p2_direction == RIGHT))
			{
				p2_direction = LEFT;
			}
			if (GetAsyncKeyState(0x44) && !(p2_direction == LEFT))
			{
				p2_direction = RIGHT;
			}


			(*p)->move(world);
		}

		for (vector<Tile_ptr>::iterator p = red_bodies.begin(); p != red_bodies.end(); p++)
		{
			(*p)->move(world);
		}

		for (vector<Tile_ptr>::iterator p = blue_bodies.begin(); p != blue_bodies.end(); p++)
		{
			(*p)->move(world);
		}

		//for every 4 eaten apples, speed increases
		if (((p1_score + p2_score) / 100) == speed_check)
		{
			sleep_time -= 10;
			speed_check++;
		}

		if (sleep_time < 0)
		{
			sleep_time = 0;
		}

		Sleep(sleep_time);

		gotoxy(0, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Score: " << p1_score;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
			FOREGROUND_BLUE | FOREGROUND_GREEN);

		gotoxy(55, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Score: " << p2_score;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
			FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	game_over(world);

	replay_game(user_wishes_to_continue);
}

void Empty::draw()
{
	gotoxy(get_position().x, get_position().y);
	cout << " " << endl;
}

void Red_Snake::draw()
{

	gotoxy(get_position().x, get_position().y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "O" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
		FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void Red_Body::draw()
{

	gotoxy(get_position().x, get_position().y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "o" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
		FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void Blue_Snake::draw()
{

	gotoxy(get_position().x, get_position().y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "O" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
		FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void Blue_Body::draw()
{

	gotoxy(get_position().x, get_position().y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "o" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
		FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void Apple::draw()
{
	gotoxy(get_position().x, get_position().y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "*" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
		FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void Boundry::draw()
{
	gotoxy(get_position().x, get_position().y);
	cout << "*" << endl;
}

World::World()
{
	int apple = 1;
	int red_guy = 1;
	height = DEFAULT_WORLD_HEIGHT;
	width = DEFAULT_WORLD_WIDTH;

	grid = new Tile_ptr*[height];
	for (int i = 0; i < height; i++)
	{
		grid[i] = new Tile_ptr[width];
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (apple > 0 && i == (DEFAULT_WORLD_HEIGHT / 2) && j == (DEFAULT_WORLD_WIDTH / 2))
			{
				grid[i][j] = new Apple(j, i);
				apple--;
			}
			else if (red_guy > 0 && i == (DEFAULT_WORLD_HEIGHT - 4) && j == (DEFAULT_WORLD_WIDTH - 4))
			{
				grid[i][j] = new Red_Snake(j, i);
				red_guy--;
			}
			else
			{
				grid[i][j] = new Empty(j, i);
			}
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 1 || j == width - 1)
			{
				grid[i][j] = new Boundry(j, i);
			}
			else if (i == 1 || i == height - 1)
			{
				grid[i][j] = new Boundry(j, i);
			}
		}
	}
}

World::World(int mode)
{
	if (mode == 1)
	{
		int apple = 1;
		int red_guy = 1;
		int blue_guy = 1;
		height = DEFAULT_WORLD_HEIGHT;
		width = DEFAULT_WORLD_WIDTH;

		grid = new Tile_ptr*[height];
		for (int i = 0; i < height; i++)
		{
			grid[i] = new Tile_ptr[width];
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (blue_guy > 0 && i == (DEFAULT_WORLD_HEIGHT - (DEFAULT_WORLD_HEIGHT - 4)) && 
					j == (DEFAULT_WORLD_WIDTH - (DEFAULT_WORLD_WIDTH - 4)))
				{
					grid[i][j] = new Blue_Snake(j, i);
					blue_guy--;
				}
				else if (apple > 0 && i == (DEFAULT_WORLD_HEIGHT / 2) && j == (DEFAULT_WORLD_WIDTH / 2))
				{
					grid[i][j] = new Apple(j, i);
					apple--;
				}
				else if (red_guy > 0 && i == (DEFAULT_WORLD_HEIGHT - 4) && j == (DEFAULT_WORLD_WIDTH - 4))
				{
					grid[i][j] = new Red_Snake(j, i);
					red_guy--;
				}
				else
				{
					grid[i][j] = new Empty(j, i);
				}
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 1 || j == width - 1)
				{
					grid[i][j] = new Boundry(j, i);
				}
				else if (i == 1 || i == height - 1)
				{
					grid[i][j] = new Boundry(j, i);
				}
			}
		}
	}
	else
	{
		cout << "Incorrect mode selected!!!" << endl;
		exit(1);
	}
}

void swap_position(Tile_ptr& first, Tile_ptr& second)
{
	swap(first->position, second->position);
	swap(first, second);
}

Tile_ptr* World::operator[](int index)
{
	return grid[index];
}

void Red_Snake::move(World& w)
{
	int x1, y1, x2, y2;
	x1 = get_position().x;
	y1 = get_position().y;
	x2 = -1;
	y2 = -1;

	if (p1_direction == UP)
	{
		x2 = x1;
		y2 = y1 - 1;
	}
	else if (p1_direction == DOWN)
	{
		x2 = x1;
		y2 = y1 + 1;
	}
	else if (p1_direction == LEFT)
	{
		x2 = x1 - 1;
		y2 = y1;
	}
	else if (p1_direction == RIGHT)
	{
		x2 = x1 + 1;
		y2 = y1;
	}

	if (x2 != -1 && w[y2][x2]->who() == EMPTY)
	{
		swap_position(w[y1][x1], w[y2][x2]);
		w[y1][x1]->draw();
		w[y2][x2]->draw();
	}
	else if (x2 != -1 && w[y2][x2]->who() == BOUNDRY)
	{
		blue_wins = true;
		game_is_not_over = false;
	}
	else if (x2 != -1 && w[y2][x2]->who() == RED_BODY)
	{
		blue_wins = true;
		game_is_not_over = false;
	}
	else if (x2 != -1 && w[y2][x2]->who() == BLUE_BODY)
	{
		blue_wins = true;
		game_is_not_over = false;
	}
	else if (x2 != -1 && w[y2][x2]->who() == BLUE)
	{
		blue_wins = true;
		game_is_not_over = false;
	}
	else if (x2 != -1 && w[y2][x2]->who() == APPLE)
	{
		for (;;)
		{
			int x3 = rand() % DEFAULT_WORLD_WIDTH;
			int y3 = rand() % DEFAULT_WORLD_HEIGHT;
			if (x3 <= 5 || x3 >= DEFAULT_WORLD_WIDTH - 5 ||
				y3 <= 5 || x3 >= DEFAULT_WORLD_HEIGHT - 5)
			{

			}
			else
			{
				if (w[y3][x3]->who() == EMPTY)
				{
					swap_position(w[y2][x2], w[y3][x3]);
					w[y2][x2]->draw();
					w[y3][x3]->draw();
					break;
				}
			}
			
		}
		swap_position(w[y1][x1], w[y2][x2]);
		w[y1][x1] = new Red_Body(x1, y1);
		red_bodies.push_back(w[y1][x1]);
		
		
		p1_score += 50;
	}
	red_head_X = x1;
	red_head_Y = y1;
}

void Blue_Snake::move(World& w)
{
	int x1, y1, x2, y2;
	x1 = get_position().x;
	y1 = get_position().y;
	x2 = -1;
	y2 = -1;

	if (p2_direction == UP)
	{
		x2 = x1;
		y2 = y1 - 1;
	}
	else if (p2_direction == DOWN)
	{
		x2 = x1;
		y2 = y1 + 1;
	}
	else if (p2_direction == LEFT)
	{
		x2 = x1 - 1;
		y2 = y1;
	}
	else if (p2_direction == RIGHT)
	{
		x2 = x1 + 1;
		y2 = y1;
	}

	if (x2 != -1 && w[y2][x2]->who() == EMPTY)
	{
		swap_position(w[y1][x1], w[y2][x2]);
		w[y1][x1]->draw();
		w[y2][x2]->draw();
	}
	else if (x2 != -1 && w[y2][x2]->who() == BOUNDRY)
	{
		red_wins = true;
		game_is_not_over = false;
	}
	else if (x2 != -1 && w[y2][x2]->who() == RED_BODY)
	{
		red_wins = true;
		game_is_not_over = false;
	}
	else if (x2 != -1 && w[y2][x2]->who() == BLUE_BODY)
	{
		red_wins = true;
		game_is_not_over = false;
	}
	else if (x2 != -1 && w[y2][x2]->who() == RED)
	{
		red_wins = true;
		game_is_not_over = false;
	}
	else if (x2 != -1 && w[y2][x2]->who() == APPLE)
	{
		for (;;)
		{
			int x3 = rand() % DEFAULT_WORLD_WIDTH;
			int y3 = rand() % DEFAULT_WORLD_HEIGHT;
			if (x3 <= 5 || x3 >= DEFAULT_WORLD_WIDTH - 5 ||
				y3 <= 5 || x3 >= DEFAULT_WORLD_HEIGHT - 5)
			{

			}
			else
			{
				if (w[y3][x3]->who() == EMPTY)
				{
					swap_position(w[y2][x2], w[y3][x3]);
					w[y2][x2]->draw();
					w[y3][x3]->draw();
					break;
				}
			}

		}
		swap_position(w[y1][x1], w[y2][x2]);
		w[y1][x1] = new Blue_Body(x1, y1);
		blue_bodies.push_back(w[y1][x1]); //red_bodies.push_back(w[y1][x1]);


		p2_score += 50;
	}
	blue_head_X = x1;
	blue_head_Y = y1;
}

void Red_Body::move(World& w)
{
	int x1, y1, x2, y2;
	Position new_position;
	x1 = get_position().x;
	y1 = get_position().y;
	x2 = red_head_X;
	y2 = red_head_Y;

	new_position.x = x2;
	new_position.y = y2;

	swap_position(w[y1][x1], w[y2][x2]);
	w[y1][x1]->draw();
	w[y2][x2]->draw();

	this->set_position(new_position);

	red_head_X = x1;
	red_head_Y = y1;


}

void Blue_Body::move(World& w)
{
	int x1, y1, x2, y2;
	Position new_position;
	x1 = get_position().x;
	y1 = get_position().y;
	x2 = blue_head_X;
	y2 = blue_head_Y;

	new_position.x = x2;
	new_position.y = y2;

	swap_position(w[y1][x1], w[y2][x2]);
	w[y1][x1]->draw();
	w[y2][x2]->draw();

	this->set_position(new_position);

	blue_head_X = x1;
	blue_head_Y = y1;


}

void game_over(World& world)
{
	gotoxy(0, 1);
	for (int i = 1; i < DEFAULT_WORLD_HEIGHT; i++)
	{
		for (int j = 1; j < DEFAULT_WORLD_WIDTH; j++)
		{
			world[i][j] = new Empty(j, i);
			world[i][j]->draw();
			delete world[i][j];
		}
	}
	gotoxy(0, 1);
	cout << "Game Over." << endl;

	if (red_wins == true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Red wins!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
			FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	else if (blue_wins == true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Blue wins!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
			FOREGROUND_BLUE | FOREGROUND_GREEN);
	}

	game_is_not_over = false;
	
}

void replay_game(bool& player_continue)
{
	char answer;
	cin.clear();

	/*Clean globals up after last game
	******************************************************/
	game_is_not_over = true;
	red_wins = false;
	blue_wins = false;
	p1_score = 0, p2_score = 0;
	red_head_X, red_head_Y, blue_head_X, blue_head_Y;
	p1_direction = UP, p2_direction = DOWN;
	
	for (int i = red_bodies.size() - 1; i >= 0; i--)
	{
		red_bodies.pop_back();
	}

	for (int i = blue_bodies.size() - 1; i >= 0; i--)
	{
		blue_bodies.pop_back();
	}

	/******************************************************/

	for (;;)
	{
		cout << "Would you like to continue? Y/N: ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			player_continue = true;
			return;
		}
		else if (answer == 'n' || answer == 'N')
		{
			player_continue = false;
			return;
		}
		else
		{
			cout << "Invaild value typed in." << endl;
			cout << "Would you like to continue? Y/N: ";
			cin >> answer;
			cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void clear_screen()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
}