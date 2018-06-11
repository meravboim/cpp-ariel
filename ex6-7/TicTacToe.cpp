#include <iostream>
#include "TicTacToe.h"
using namespace std;



void TicTacToe::play(Player& X, Player& O){
	myBoard='.';
	the_winner=&O;
	Player* current=&X;
	X.myChar='X';
	O.myChar='O';
	bool end=false;
	Coordinate tmp{0,0};
	while(!end){
		if(current->myChar=='X'){
			try{
				tmp=current->play(myBoard);
				if(myBoard[tmp]!='.'){
					the_winner=&O;
					end=true;	
				}
			}
			catch(string s){
				the_winner=&O;
				end=true;
			}	
			if(!end){
				myBoard[current->play(myBoard)]= current->myChar;
				end=(checkForWinner(current,tmp));
				current=&O;
			}
		}
		else {
			try{
				tmp= current->play(myBoard);
				if(myBoard[tmp]!='.'){
					the_winner=&X;
					end=true;	
				}
			}
			catch(string s){
				the_winner=&X;
				end=true;
			}
			if(!end){
				myBoard[current->play(myBoard)]= current->myChar;
				end=(checkForWinner(current,tmp));
				current=&X;
			}
		}
	}
}




bool TicTacToe::checkForWinner(Player* current, Coordinate cord){
	return fullBoard()||winCol(current, cord.getY())|| winRow(current, cord.getX()) || slantUp(current) || slantDown(current);
}



bool TicTacToe::fullBoard(){
	for(uint i=0; i<myBoard.size(); i++){
		for(uint j=0; j<myBoard.size(); j++){
			if(myBoard[{i,j}]=='.') return false;
		}
	}
	return true;
}


bool TicTacToe::winCol(Player* current, uint x){
	for(uint i=0; i<myBoard.size(); i++){
		if(myBoard[{i,x}]!= current->myChar) return false;
	}
	the_winner= current;
	return true;
}

bool TicTacToe::winRow(Player* current, uint y){
	for(uint i=0; i<myBoard.size(); i++){
		if(myBoard[{y,i}]!= current->myChar) return false;
	}
	the_winner= current;
	return true;
}

bool TicTacToe::slantUp(Player* current){
	for(uint i=0; i<myBoard.size(); i++){
		if(myBoard[{i,myBoard.size()-1-i}]!=current->myChar) return false;
	}
	the_winner= current;
	return true;
}
bool TicTacToe::slantDown(Player* current){
	for(uint i=0; i<myBoard.size(); i++){
		if(myBoard[{i,i}]!=current->myChar) return false;
	}
	the_winner= current;
	return true;
}
































