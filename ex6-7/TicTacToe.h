#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Coordinate.h"
using namespace std;

class TicTacToe{

	Board myBoard{0};
	Player* the_winner;

	public:
		TicTacToe (uint s){
			Board tmp{s};
			myBoard=tmp;
		}
	

		void play(Player& x, Player& o);
	 	Player& winner()const{return *the_winner;}
		const Board& board()const{return myBoard;}
		bool checkForWinner(Player* current, Coordinate cord);
		bool fullBoard();
		bool winCol(Player* current, uint x);
		bool winRow(Player* current, uint y);
		bool slantUp(Player* current);
		bool slantDown(Player* current);
	
};
