#include <iostream>
#include "Board.h"

using namespace std;

ostream& operator<< (ostream& os, const Board& b){

	for (int i = 0; i < b.boardSize; i++){
		for (int j = 0; j < b.boardSize; j++){
    			os << b.my_board[i][j];
		}
		os<<"\n";
	}
	return os;
}

Cell& Board::operator[] (Coordinate p)const{
	if(p.x>=boardSize || p.y>=boardSize)
		throw IllegalCoordinateException(p);
	return my_board[p.x][p.y];
}

Board& Board::operator=(char c){
	if(c!='.')
		throw IllegalCharException(c);
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
    			my_board[i][j]=c;
		}
	}
	return (*this);
}

Board& Board::operator=(Board b){
	boardSize=b.boardSize;
	my_board= new Cell* [boardSize];
	for (int i = 0; i < boardSize; i++){
    		my_board[i] = new Cell[boardSize];
	}
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardSize; j++){
    			my_board[i][j]=b.my_board[i][j];
		}
	}
	return (*this);
}

	







