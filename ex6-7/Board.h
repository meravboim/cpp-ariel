#pragma once
#include <iostream>
#include "Coordinate.h"
#include "Cell.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;

class Board {
	int boardSize;
	Cell** my_board;
	
	friend 	ostream& operator<< (ostream& os, const Board& b);

    	public:
   	Board (uint s) : boardSize(s){	//construter
		if(boardSize<0)
			throw std::invalid_argument( "Size < 0\n" );
		my_board= new Cell* [boardSize];
		for (int i = 0; i < boardSize; i++){
    			my_board[i] = new Cell [boardSize];
			for (int j = 0; j < boardSize; j++){
    				my_board[i][j] = '.';
			}
		}
	}

	Board (Board const &b){	//copy construter
		boardSize=b.boardSize;
		my_board = new Cell* [boardSize];
		for (int i = 0; i < boardSize; i++){
    			my_board[i] = new Cell[boardSize];
			
		}
		for (int i = 0; i < boardSize; i++){
			for (int j = 0; j < boardSize; j++){
    				my_board[i][j]=b.my_board[i][j];
			}
		}
	}

	Cell& operator[] (Coordinate p)const;
	Board& operator=(Board b);		//the operation = with board 
	Board& operator=(char c);		//fill the matrix with char c
	uint size()const{return boardSize;};
			
};
