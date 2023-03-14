#include "Matrix.h"
#include <exception>
#include <stdexcept>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {

	Lines = nrLines;
	Cols = nrCols;
	values = new Tuple[1];
	size = 0;
	capacity = 1;
}

Matrix::~Matrix()
{
	delete[] values;
}

Matrix::Matrix(const Matrix& m) // : Lines(m.lines)
{
	Lines = m.Lines;
	Cols = m.Cols;
	values = new Tuple[m.capacity];
	for (int i = 0; i < m.size; i++)
	{
		values[i] = m.values[i];
	}
	capacity = m.capacity;
	size = m.size;

}

Matrix& Matrix::operator=(const Matrix& m)//theta(size)
{
	Lines = m.Lines;
	Cols = m.Cols;
	delete[] values;
	values = new Tuple[m.capacity];
	for (int i = 0; i < m.size; i++)
	{
		values[i] = m.values[i];
	}
	capacity = m.capacity;
	size = m.size;
	return *this;
}


int Matrix::nrLines() const {
	return Lines;
}


int Matrix::nrColumns() const {
	return Cols;
}


TElem Matrix::element(int i, int j) const {
	if (i < 0 or i >= Lines or j < 0 or j >= Cols)
	{
		throw out_of_range("Out of range cell in matrix");
	}
	
	//incearca cu cautare binara 
	for (int k = 0; k < size; k++) //O(size)
	{
		if (get<0>(values[k]) == i && get<1>(values[k]) == j) return get<2>(values[k]);
	}
	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
	if (i < 0 or i >= Lines or j < 0 or j >= Cols)
	{
		throw out_of_range("Out of range cell in matrix");
	}
	for (int k = 0; k < size; k++) //O(size)
	{
		if (get<0>(values[k]) == i && get<1>(values[k]) == j)
		{
			TElem prev = get<2>(values[k]);//acceseaza valoarea de pe poz i j si o retine in prev 
			values[k] = Tuple(i, j, e);
			return prev;
		}
	}
	Tuple nou(i, j, e);//Tuple nou = Tuple(i,j,e);
	if (size == capacity) {
		capacity = capacity * 2;
		Tuple* new_vector = new Tuple[capacity];
		for (int k = 0; k < size; k++)
		{
			new_vector[k] = values[k];
		}
		delete[] values;
		values = new_vector;
	}
	int k = 0;
	while (k < size && values[k] < nou)
	{
		k++;
		}
	int poz = k;
	for (int k = size; k > poz; k--)
	{
		values[k] = values[k - 1];
	}
	size = size + 1;
	values[poz] = Tuple(i, j, e);
	//cauti ultimu care e mai mic retii pozitia il pui acolo si muti restu tot in dreapta si dupa returnezi prev value care e null telem
	return NULL_TELEM;
}


