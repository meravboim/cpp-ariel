#pragma once
#include <iostream>
#include <string>
#include "Coordinate.h"
using namespace std;

class IllegalCoordinateException {

	public:
  		 IllegalCoordinateException(const Coordinate& p) : point_(p) {}
  		~IllegalCoordinateException() {}

   		string theCoordinate() const {	
			string s="("+to_string(point_.x)+","+to_string(point_.y)+")";
			return(s);
		}
	private:
  		Coordinate point_;
};


