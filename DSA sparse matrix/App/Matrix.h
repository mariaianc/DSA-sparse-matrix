#pragma once

//DO NOT CHANGE THIS PART
#include <tuple>
typedef int TElem;
typedef std::tuple <int, int, TElem> Tuple;
#define NULL_TELEM 0

class Matrix {

private:
	int Lines;
	int Cols;
	Tuple* values;//dinamic array care tine triplete linie coloana valoare
	int size;//nr diferite de 0
	int capacity;//cat incate in dinamic array


public:
	//constructor
	Matrix(int nrLines, int nrCols);
	~Matrix();//destructor
	Matrix(const Matrix& m);
	Matrix& operator=(const Matrix& m);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

};
