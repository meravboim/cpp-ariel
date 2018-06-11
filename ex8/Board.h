#pragma once
#include <iostream>
#include <fstream>
#include "Coordinate.h"
#include "Cell.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"
#include <math.h>

using namespace std;
	static int file_num=0;
struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board {
	unsigned int size;
	Cell** my_board;
	friend 	ostream& operator<< (ostream& os, const Board& b);
	friend  istream& operator>> (istream& is,  Board& b);

    	public:
   	Board (unsigned int s) : size(s){	//construter
		my_board= new Cell* [size];
		for (int i = 0; i < size; i++){
    			my_board[i] = new Cell [size];
			for (int j = 0; j < size; j++){
    				my_board[i][j] = '.';
			}
		}
	}
	
	Board(){}

	Board (Board const &b){	//copy construter
		size=b.size;
		my_board = new Cell* [size];
		for (int i = 0; i < size; i++){
    			my_board[i] = new Cell[size];
			
		}
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
    				my_board[i][j]=b.my_board[i][j];
			}
		}
	}

	string draw(int const n);


	Cell& operator[] (Coordinate p);
	Board& operator=(Board b);		//the operation = with board 
	Board& operator=(char c);		//fill the matrix with char c

			
};
