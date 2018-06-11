#include "Champion.h"


const Coordinate Champion::play(const Board& board) {
	if(board[{board.size()-1,board.size()-1}]=='.')
		return {board.size()-1,board.size()-1};
	else {
		if(board[{0,1}]!='.'){
			uint j=0;
			while(board[{j,board.size()-1}]!='.'){
				j++;
			}
			return {j,board.size()-1};
		}
		else{
			uint j=0;
			while(board[{board.size()-1,j}]!='.'){
				j++;
			}
			return {board.size()-1,j};

		}
	}
	return {0,0};  // did not find an empty square - play on the top-left
}

