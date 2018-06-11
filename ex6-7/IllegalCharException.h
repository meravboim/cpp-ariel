#pragma once
#include <iostream>
#include <string>
using namespace std;

class IllegalCharException {

	public:
  		 IllegalCharException(const char& c) : char_(c) {}
  		~IllegalCharException() {}

   		char theChar() const {	
			return(char_);
		}
	private:
  		char char_;
};

