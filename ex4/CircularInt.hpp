#pragma once
#include <iostream>
using namespace std;
/*
	--
	++		

*/
class CircularInt {

	int start;	//the start of the range
	int end;	//the end of the range
	int current;    //the current value

	friend 	istream& operator>> (istream& is, CircularInt& c); 		// get input for CircularInt
	friend 	ostream& operator<< (ostream& os, const CircularInt& c); 	//print the value
	friend	bool operator!= (CircularInt c1,CircularInt c2);		//the operation != not equals
	friend	bool operator!= (CircularInt c,int x);		//the operation != not equals
	friend	bool operator!= (int x,CircularInt c);		//the operation != not equals
	friend	bool operator== (CircularInt c1,CircularInt c2);		//the operation == equals 
	friend	bool operator== (CircularInt c,int x);		//the operation == equals 
	friend	bool operator== (int x,CircularInt c);		//the operation == equals 
	friend 	CircularInt operator+ (CircularInt& c, int x); 			//the operation + with int after the +
	friend	CircularInt operator- (CircularInt& c, int x);			//the operation - with int after the -
	friend 	CircularInt operator* (CircularInt& c, int x);			//the operation * with int after the *
	friend 	CircularInt operator/ (CircularInt& c, int x);			//the operation / with int after the /
	friend 	CircularInt operator+ (int x,CircularInt& c); 			//the operation + with int before the +
	friend	CircularInt operator* (int x,CircularInt& c);			//the operation - with int before the *
	friend	CircularInt operator- (int x,CircularInt& c);			//the operation - with int before the -
	friend 	CircularInt operator/ (int x,CircularInt& c); 			//the operation + with int before the /
	friend 	CircularInt operator+ (CircularInt& c1,CircularInt& c2); 	//the operation + 
	friend	CircularInt operator- (CircularInt& c1,CircularInt& c2);	//the operation - 
	friend 	CircularInt operator/ (CircularInt& c1,CircularInt& c2); 	//the operation / 
	friend	CircularInt operator* (CircularInt& c1,CircularInt& c2);	//the operation * 
	friend	bool operator< (const CircularInt& c1,const CircularInt& c2);	//the operation < 
	friend	bool operator> (const CircularInt& c1,const CircularInt& c2);	//the operation > 
	friend	bool operator<= (const CircularInt& c1,const CircularInt& c2);	//the operation <= 
	friend	bool operator>= (const CircularInt& c1,const CircularInt& c2);	//the operation >=
	friend	bool operator< (const CircularInt& c, int x);			//the operation < with int after <
	friend	bool operator> (const CircularInt& c, int x);			//the operation > with int after >
	friend	bool operator<= (const CircularInt& c, int x);		//the operation <= with int after <=
	friend	bool operator>= (const CircularInt& c, int x);		//the operation >= with int after >=
	friend	bool operator< (int x,const CircularInt& c);			//the operation < with int before <
	friend	bool operator> (int x,const CircularInt& c);			//the operation > with int before >
	friend	bool operator<= (int x,const CircularInt& c);			//the operation <= with int before <=
	friend	bool operator>= (int x,const CircularInt& c);			//the operation >= with int before >=
	friend	CircularInt operator^ (CircularInt& c1,CircularInt& c2);	//the operation ^
	friend	CircularInt operator^ (CircularInt& c, int x);			//the operation ^ with int after ^
	friend	CircularInt operator^ (int x,CircularInt& c);			//the operation ^ with int before ^
	friend	CircularInt operator% (CircularInt& c1,CircularInt& c2);	//the operation %
	friend	CircularInt operator% (CircularInt& c, int x);			//the operation % with int after %
	friend	CircularInt operator% (int x,CircularInt& c);			//the operation % with int before %

    	public:
   	CircularInt (int s, int e) : start(s), end(e), current(s){	//construter
		if(end<start){
			start=e;
			end=s;
			current=e;
		}
	}  
	
	CircularInt (const CircularInt &c){	//copy construter
		start=c.start;
		end=c.end;
		current=c.current;
	}

	int GetValue() {return current;} // return the current value
	
	friend void normalization(int num, CircularInt& c) {  // normalization function
		int area=c.end-c.start+1;
		if(num>c.end){
			while(num>c.end){
				num-=area;
			}
		}
		if(num<c.start){
			while(num<c.start){
				num+=area;
			}
		}
		c.current=num;
	}

	CircularInt operator-();  //minus -a
	CircularInt& operator= (int x); 			//the operation = with int

	CircularInt& operator=(CircularInt c);		//the operation =
	CircularInt& operator++(); // prefix ++a
	const CircularInt operator++(int); // postfix a++
	CircularInt& operator--(); // prefix --a
	const CircularInt operator--( int); // postfix a--
	CircularInt& operator+= ( int x);		 	//the operation += with int
	CircularInt& operator-= ( int x);			//the operation -= with int
 	CircularInt& operator*=  (int x);			//the operation *= with int
 	CircularInt& operator/= ( int x);			//the operation /= with int
 	CircularInt& operator+= (CircularInt& c); 		//the operation += 
	CircularInt& operator-= (CircularInt& c);		//the operation -=
	CircularInt& operator/= (CircularInt& c); 		//the operation /= 
	CircularInt& operator*= (CircularInt& c);		//the operation *=
	CircularInt& operator^= (CircularInt& c);		//the operation ^=
	CircularInt& operator^= ( int x);			//the operation ^= with int after ^=
	CircularInt& operator%= (CircularInt& c);		//the operation %=
	CircularInt& operator%= ( int x);			//the operation %= with int after %=

	  
};






