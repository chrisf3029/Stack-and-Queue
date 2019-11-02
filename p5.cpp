//Christopher Fong
//File: p5.cpp

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "stack.h"
#include "queue.h"

using namespace std;

//public variables
const int MAX_CARDS = 52;
Stack draw;					//draw pile
Stack discards;				//discard pile
Queue p1;					//player 1 hand
Queue p2;					//player 2 hand

//Methods
Stack shuffle();				//shuffles a new deck
void deal();					//deals to players and sets out first discard
void player1();					//player 1's turn
void player2();					//player 2's turn
void outcome(Queue &player);	//outcome of the player's turn
void flipDiscards();			//flips discard pile when draw pile runs out
bool gameOver();			//true when game is over

int main()
{
	string response;
	bool again;

	do
	{
		again = false;

		//new game setup
		draw = shuffle();
		deal();

		//alternate turns
		while (!gameOver())
		{
			player1();
			if (gameOver())
				break;
			player2();
		}

		//determine winner
		if (p1.empty())
			cout << "Player 1 wins!" << endl << endl;
		else
			cout << "Player 2 wins!" << endl << endl;

		//ask to play again
		cout << "Do you want to play again? (y or n): ";
		getline(cin, response);

		if (response == "Y" || response == "y")
		{
			again = true;
			//clear all players' hands
			p1.clear();
			p2.clear();
		}
	} while (again);

	return 0;
}

Stack shuffle()
{
	Stack temp;
	int usedMax[13];				//keeps track of cards placed in draw pile
	for (int i = 0; i < 13; i++)
		usedMax[i] = 0;

	srand(time(NULL));

	for (int i = 0; i < MAX_CARDS; i++)
	{
		int num = (int)rand() % 13 + 1;

		//makes sure each unique value is only used 4 times
		while (usedMax[num - 1] == 4)		
		{
			num = (int)rand() % 13 + 1;
		}
		usedMax[num - 1]++;
		temp.push(num);
	}
	return temp;
}

void deal()
{
	for (int i = 0; i < 7; i++)			//deal 7 cards to each player
	{
		p1.enqueue(draw.peek());
		draw.pop();
		p2.enqueue(draw.peek());
		draw.pop();
	}

	//after deal top card is first in discard
	discards.push(draw.peek());
	draw.pop();
}

void player1()
{
	string enter;

	cout << "Cards in hand." << endl;
	cout << "--------------" << endl << endl;

	cout << "Player 1" << endl;
	p1.print();
	cout << endl;

	cout << "Player 2" << endl;
	p2.print();
	cout << endl;

	cout << "Player 1, press RETURN to take turn." << endl;
	getline(cin, enter);

	cout << "Top of the stack is " << discards.peek() << endl << endl;

	outcome(p1);
}

void player2()
{
	string enter;

	cout << "Cards in hand." << endl;
	cout << "--------------" << endl << endl;

	cout << "Player 1" << endl;
	p1.print();
	cout << endl;

	cout << "Player 2" << endl;
	p2.print();
	cout << endl;

	cout << "Player 2, press RETURN to take turn." << endl;
	getline(cin, enter);

	cout << "Top of the stack is " << discards.peek() << endl << endl;

	outcome(p2);
}

void outcome(Queue &player)
{
	if (player.peek() < discards.peek())
	{
		cout << "Your card " << player.peek() << 
		" is less than " << discards.peek() << "." << endl;
		discards.push(player.peek());
		player.dequeue();
		cout << "You draw 2 cards." << endl << endl;

		if (draw.empty())
			flipDiscards();
		player.enqueue(draw.peek());
		draw.pop();

		if (draw.empty())
			flipDiscards();
		player.enqueue(draw.peek());
		draw.pop();
	}
	else if (player.peek() == discards.peek())
	{
		cout << "Your card " << player.peek() << 
		" is equal to " << discards.peek() << "." << endl;
		discards.push(player.peek());
		player.dequeue();
		cout << "You draw 1 card." << endl << endl;

		if (draw.empty())
			flipDiscards();
		player.enqueue(draw.peek());
		draw.pop();
	}
	else
	{
		cout << "Your card " << player.peek() << 
		" is larger than " << discards.peek() << "." << endl;
		discards.push(player.peek());
		player.dequeue();
		cout << "Good job!" << endl << endl;
	}
}

void flipDiscards()
{
	int temp = discards.peek();
	discards.pop();
	while (!discards.empty())
	{
		draw.push(discards.peek());
		discards.pop();
	}
	discards.push(temp);
}

bool gameOver()
{
	return p1.empty() || p2.empty();
}
