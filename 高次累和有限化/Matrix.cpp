#include "Matrix.h"

template<typename T>
inline matrix<T>::matrix(int m, int n) : lnes(m), cols(n)
{
	root = new T[m][n];
}

template<typename T>
inline T * matrix<T>::operator[](int ind)
{
	return root[ind];
}
