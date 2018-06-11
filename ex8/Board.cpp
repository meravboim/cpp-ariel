#include <iostream>
#include "Board.h"

using namespace std;


istream& operator>> (istream& is, Board& b){
	string line;
	is>>line;
	int len=line.length();
	int i=0;
	bool check= true;
   	while (i<len){
		if(check){
			Board tmp{(unsigned int)line.length()};
			b=tmp;
			check=false;
		}
		for (int j=0; j<line.length(); j++){
			b.my_board[i][j]=line.at(j);
		}
		i++;
		is>>line;
   	}
	
	return is;
	
}

string Board::draw(int const n){
	file_num++;
	while(true){
		ifstream f("draw"+to_string(file_num)+".ppm");
		if(!f.good())
			break;
		else
			file_num++;
			
	}
	string file_name="draw"+to_string(file_num)+".ppm";
  	ofstream imageFile(file_name, ios::out | ios::binary);
  	imageFile << "P6" << endl <<n<<" " <<n<< endl << 255 << endl;
  	RGB image[n*n];
	int cell_size=(n-size+1)/size;
  	for (int j = 0; j < n; ++j)  {  // row
    		for (int i = 0; i < n; ++i) { // column
			image[n*j+i].red = (255);
			image[n*j+i].blue = (255);
			image[n*j+i].green = (255);
			if(i%cell_size==0||(j)%cell_size==0){
      				image[n*j+i].red = (0);
				image[n*j+i].blue = (0);
				image[n*j+i].green = (0);
			}
   		 }
  	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(my_board[i][j]=='X'){
				int row=(i)*cell_size+1;
				int col=(j)*cell_size+1;
				for(int p=(n*row)+col; p<((n*row+col)+(n*cell_size)); p+=n+1){
      							image[p].red = (0);
							image[p].blue = (0);
							image[p].green = (0);

				}
				row+=cell_size;
				for(int p=(n*row)+col; p>((n*row+col)-(n*cell_size)); p=p+1-n){
      							image[p].red = (0);
							image[p].blue = (0);
							image[p].green = (0);

				}
			}
				
			if(my_board[i][j]=='O'){
				int row=(i)*cell_size+1;
				int col=(j)*cell_size+1;
				int r=(cell_size-(cell_size/10))/2;

				int mid_x=(col+col+cell_size)/2;
				int mid_y=(row+row+cell_size)/2;
			
				for (int k = row; k < row+cell_size; ++k)  {  // row
    					for (int l =col; l < col+cell_size; ++l) { // column
						int dis=sqrt((k-mid_y)*(k-mid_y)+(l-mid_x)*(l-mid_x));
						if(dis>r-1&&dis<r+1){
							image[n*k+l].red = (0);
							image[n*k+l].blue = (0);
							image[n*k+l].green = (0);
						}
					}	
				}
			}
		
		}
	}	
  	imageFile.write(reinterpret_cast<char*>(&image), 3*n*n);
  	imageFile.close();
	return file_name;
}



ostream& operator<< (ostream& os, const Board& b){

	for (int i = 0; i < b.size; i++){
		for (int j = 0; j < b.size; j++){
    			os << b.my_board[i][j];
		}
		os<<"\n";
	}
	return os;
}

Cell& Board::operator[] (Coordinate p){
	if(p.x>=size || p.y>=size)
		throw IllegalCoordinateException(p);
	return my_board[p.x][p.y];
}

Board& Board::operator=(char c){
	if(c!='.')
		throw IllegalCharException(c);
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
    			my_board[i][j]=c;
		}
	}
	return (*this);
}

Board& Board::operator=(Board b){
	size=b.size;
	my_board= new Cell* [size];
	for (int i = 0; i < size; i++){
    		my_board[i] = new Cell[size];
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
    			my_board[i][j]=b.my_board[i][j];
		}
	}
	return (*this);
}
	







