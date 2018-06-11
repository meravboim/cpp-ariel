#pragma once
#include <iostream>
using namespace std;

class Coordinate {
	friend class Board;
	friend class IllegalCoordinateException;     
	int x;
	int y;

	public:
   	Coordinate (uint _x,uint _y) : x(_x), y(_y){	//construter
		if(x<0||y<0)
			throw std::invalid_argument( "x<0 OR y<0\n" );
	}

};
