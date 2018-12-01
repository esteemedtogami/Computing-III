/*********************************
Programmer: Sam Pickell
Date: 12/11/2016
Time Spent: 13 hours and 25 minutes
Purpose: Create the game Snake
*********************************/
#include "Snake.h"

int main()
{
	bool user_wishes_to_continue = true;

	do
	{
		srand(time(0));
		int number_of_players = -42;

		gotoxy(0,0);
		clear_screen();
		gotoxy(0, 0);
		cout << "Please enter the number of players: ";
		cin >> number_of_players;
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//User wears black hat
		if (number_of_players != 1 && number_of_players != 2)
		{
			for (;;)
			{
				cout << "Invaild value typed in." << endl;
				cout << "Please enter the number of players: ";
				cin >> number_of_players;
				cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (number_of_players == 1)
				{
					break;
				}
				else if (number_of_players == 2)
				{
					break;
				}
			}
		}
		cin.clear();
		if (number_of_players == 1)
		{
			//1 player game
			gotoxy(0,0);
			for (int i = 0; i < 80; i++)
			{
				cout << " ";
			}
			cout << endl;
			one_player_game(user_wishes_to_continue);
		}
		else if (number_of_players == 2)
		{
			gotoxy(0, 0);
			for (int i = 0; i < 80; i++)
			{
				cout << " ";
			}
			cout << endl;
			two_player_game(user_wishes_to_continue);
		}

	} while (user_wishes_to_continue);

	cout << "Thank you for playing snake!" << endl;

	return 0;
}