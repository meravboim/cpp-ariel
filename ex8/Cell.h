#pragma once
#include <iostream>
#include "IllegalCharException.h"
using namespace std;

class Cell {  
	friend class Board;  

	public:
   	Cell (char c) : my_char(c){	//construter
		if(c!= 'X' && c!='O' && c!='.')
			throw IllegalCharException(c);
	}

	Cell (){	//empty construter;
		my_char='.';
	}
	
	Cell& operator=(char c){
		if(c!= 'X' && c!='O' && c!='.')
			throw IllegalCharException(c);
		my_char=c;
		return *this;
	}

	Cell& operator=(Cell c){
		my_char=c.my_char;
		return *this;
	}	

	friend ostream& operator<< (ostream& os, const Cell& c){

    		os << c.my_char;
		return os;
	}
	
	operator char() { return my_char; }
	

	char my_char;
};
