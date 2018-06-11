#include <iostream>
#include "CircularInt.hpp"
using namespace std;

ostream& operator<< (ostream& os, const CircularInt& c){
	return os<< c.current;
}


istream& operator>> (istream& is, CircularInt& c){
	int tmp;
	is>>tmp;
	normalization(tmp,c);
	return is;
}

bool operator!= (CircularInt c1,CircularInt c2){
	if(c1.start==c2.start && c1.end==c2.end && c1.current==c2.current)
		return false;
	return true;	
}

bool operator!= (CircularInt c,int x){
	if(c.current!=x)
		return true;
	return false;	
}

bool operator!= (int x, CircularInt c){
	if(c.current!=x)
		return true;
	return false;	
}

bool operator== (CircularInt c1,CircularInt c2){
	if(c1.start==c2.start && c1.end==c2.end && c1.current==c2.current)
		return true;
	return false;	
}

bool operator== (CircularInt c,int x){
	if(c.current==x)
		return true;
	return false;	
}

bool operator== (int x, CircularInt c){
	if(c.current==x)
		return true;
	return false;	
}

CircularInt& CircularInt::CircularInt ::operator= (int x){ 	
	normalization(x,*this);
	return *this;		
}


CircularInt& CircularInt::CircularInt::operator= (CircularInt c){
	start=c.start;
	current=c.current;
	end=c.end;
	return *this;
}

	
bool operator< (const CircularInt& c1,const CircularInt& c2){
	CircularInt tmp(c1);
	normalization(c2.current,tmp);
	if(c1.current<tmp.current)
		return true;
	return false;	
}
	 
bool operator> (const CircularInt& c1,const CircularInt& c2){
	CircularInt tmp(c1);
	normalization(c2.current,tmp);
	if(c1.current>tmp.current)
		return true;
	return false;
}

bool operator<= (const CircularInt& c1,const CircularInt& c2){
	CircularInt tmp(c1);
	normalization(c2.current,tmp);
	if(c1.current<=tmp.current)
		return true;
	return false;
}

bool operator>= (const CircularInt& c1,const CircularInt& c2){
	CircularInt tmp(c1);
	normalization(c2.current,tmp);
	if(c1.current>=tmp.current)
		return true;
	return false;
}
bool operator< (const CircularInt& c, int x){
	CircularInt tmp(c);
	normalization(x,tmp);
	if(c.current<tmp.current)
		return true;
	return false;	
}
			
bool operator> (const CircularInt& c, int x){
	CircularInt tmp(c);
	normalization(x,tmp);
	if(c.current>tmp.current)
		return true;
	return false;
}
			
bool operator<= (const CircularInt& c, int x){
	CircularInt tmp(c);
	normalization(x,tmp);
	if(c.current<=tmp.current)
		return true;
	return false;
}
		
bool operator>= (const CircularInt& c, int x){
	CircularInt tmp(c);
	normalization(x,tmp);
	if(c.current>=tmp.current)
		return true;
	return false;
}
			
bool operator< (int x,const CircularInt& c){
	CircularInt tmp(c);
	normalization(x,tmp);
	if(tmp.current<c.current)
		return true;
	return false;
}
				
bool operator> (int x,const CircularInt& c){
	CircularInt tmp(c);
	normalization(x,tmp);
	if(tmp.current>c.current)
		return true;
	return false;
}
		
bool operator<= (int x,const CircularInt& c){
	CircularInt tmp(c);
	normalization(x,tmp);
	if(tmp.current<=c.current)
		return true;
	return false;
}
		
bool operator>= (int x,const CircularInt& c){
	CircularInt tmp(c);
	normalization(x,tmp);
	if(tmp.current>=c.current)
		return true;
	return false;
}	

CircularInt operator+ (CircularInt& c1,CircularInt& c2){
	CircularInt tmp(c1);
	tmp+=c2.current;
	return tmp;
}


CircularInt operator+ (CircularInt& c, int x){
	CircularInt tmp(c);
	int num=c.current+x;
	normalization(num,tmp);
	return tmp;
}


CircularInt operator+ (int x,CircularInt& c){
	CircularInt tmp(c);
	int num=c.current+x;
	normalization(num,tmp);
	return tmp;
}

CircularInt& CircularInt:: operator+= (CircularInt& c){
	*this+=c.current;
	return *this;
}

CircularInt& CircularInt:: operator+= ( int x){	
	int num=current+x;
	normalization(num,*this);
	return *this;
}


CircularInt operator- (CircularInt& c1,CircularInt& c2){
	CircularInt tmp(c1);
	tmp-=c2.current;
	return tmp;
}


CircularInt operator- (CircularInt& c, int x){
	CircularInt tmp(c);
	int num=c.current-x;
	normalization(num,tmp);
	return tmp;
}

CircularInt operator- (int x,CircularInt& c){
	CircularInt tmp(c);
	int num=x-c.current;
	normalization(num,tmp);
	return tmp;
}

CircularInt& CircularInt:: operator-= (CircularInt& c){
	*this-=c.current;
	return *this;
}

CircularInt& CircularInt::operator-= ( int x){
	int num=current-x;
	normalization(num,*this);
	return *this;
}

CircularInt operator* (CircularInt& c1,CircularInt& c2){
	CircularInt tmp(c1);
	tmp*=c2.current;
	return tmp;
}

CircularInt operator* (CircularInt& c, int x){
	CircularInt tmp(c);
	int num=c.current*x;
	normalization(num,tmp);
	return tmp;
}


CircularInt operator* (int x,CircularInt& c){
	CircularInt tmp(c);
	int num=x*c.current;
	normalization(num,tmp);
	return tmp;
}

CircularInt& CircularInt:: operator*= (CircularInt& c){
	*this*=c.current;
	return *this;
}

CircularInt& CircularInt::operator*= ( int x){
	int num=current*x;
	normalization(num,*this);
	return *this;
}

CircularInt operator/ (CircularInt& c1,CircularInt& c2){
	CircularInt tmp(c1);
	tmp/=c2.current;
	return tmp;
}


CircularInt operator/ (CircularInt& c, int x){
	CircularInt j{c.start,c.end};
	CircularInt tmp(c);
	for(int i=c.start;i<=c.end;i++){
		if(j*x==c){
			tmp.current=i;
			return tmp;
		}
		j+=1;
	}
	throw std::invalid_argument( "There is no such a number\n" );
}

CircularInt operator/ (int x,CircularInt& c){
	CircularInt tmp(c);
	CircularInt temp_x(c);
	temp_x.current=x;
	x=x%(tmp.end-tmp.start+1);
	if(x<tmp.start)
		x+=(tmp.end-tmp.start+1);
	for(int i=c.start;i<=c.end;i++){
		if(i*c==temp_x){
			tmp.current=i;
			return tmp;
		}
	}
	throw std::invalid_argument( "There is no such a number\n" );


}

CircularInt& CircularInt:: operator/= (CircularInt& c){
	*this/=current;
	return *this;
}
	
CircularInt& CircularInt:: operator/= ( int x){
	CircularInt j{start,end};
	for(int i=start;i<=end;i++){
		if(j*x==*this){
			current=i;
			return *this;
		}
		j+=1;
	}
	throw std::invalid_argument( "There is no such a number\n" );

}

CircularInt operator^ (CircularInt& c, int x){
	CircularInt tmp(c);
	int num= tmp.current^x;
	normalization(num,tmp);
	return tmp;
}

CircularInt operator^ (int x,CircularInt& c){
	CircularInt tmp(c);
	int num= tmp.current^x;
	normalization(num,tmp);
	return tmp;
}

CircularInt operator^ (CircularInt& c1,CircularInt& c2){
	CircularInt tmp(c1);
	int num= tmp.current^c2.current;
	normalization(num,tmp);
	return tmp;
}	


CircularInt& CircularInt:: operator^= (CircularInt& c){
	*this=*this^c.current;
	return *this;
}

CircularInt& CircularInt:: operator^= ( int x){
	*this=*this^x;
	return *this;
}
	
CircularInt operator% (CircularInt& c, int x){
	CircularInt tmp(c);
	int num= tmp.current%x;
	normalization(num,tmp);
	return tmp;
}


CircularInt operator% (int x,CircularInt& c){
	CircularInt tmp(c);
	int num= x%tmp.current;
	normalization(num,tmp);
	return tmp;
}

CircularInt operator% (CircularInt& c1,CircularInt& c2){
	CircularInt tmp(c1);
	int num= tmp.current%c2.current;
	normalization(num,tmp);
	return tmp;
}

CircularInt& CircularInt:: operator%= (CircularInt& c){
	*this=*this%c.current;
	return *this;
}

CircularInt& CircularInt:: operator%= ( int x){
	*this=*this%x;
	return *this;
}

CircularInt CircularInt :: operator-(){
	CircularInt tmp(*this);
	normalization(-current,tmp);
	return tmp;
}



CircularInt& CircularInt::operator++ (){
	if ((current+1)<=end)
		current+=1;
	else{
		current = start;
	}
	return *this;
}

const CircularInt CircularInt::operator++(int x) {
	CircularInt tmp(*this);
	++(*this);
	return tmp;
}


CircularInt& CircularInt::operator--() {
	if ((current-1)>=start)
		current-=1;
	else{
		current = end;
	}
	return *this;
}

const CircularInt CircularInt::operator--(int x) {
	CircularInt tmp(*this);
	--(*this);
	return tmp;
}








