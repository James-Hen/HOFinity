#pragma once

#include <iostream>

using namespace std;

namespace James
{

	template<typename T>
	class matrix
	{
	private:
		T * * root;
		int lnes, cols;
	public:
		matrix(int m, int n);
		T * operator [] (int ind);
		void print();
		void Gauss();
	};

	template<typename T>
	inline matrix<T>::matrix(int m, int n) : lnes(m), cols(n)
	{
		root = new T * [m];
		for (int i(0); i < m; ++i)
		{
			root[i] = new T [n];
		}
	}

	template<typename T>
	inline T * matrix<T>::operator[](int ind)
	{
		return root[ind];
	}

	template<typename T>
	void James::matrix<T>::print()
	{
		for (int i(0); i < 80; ++i) cout << '-';
		cout << endl;
		for (int i(0); i < lnes; ++i)
		{
			cout << "|\t";
			for (int j(0); j < cols; ++j)
			{
				cout << root[i][j] << "\t";
			}
			cout << "\t|\n";
		}
		for (int i(0); i < 80; ++i) cout << '-';
		cout << endl;
	}

	template<typename T>
	void James::matrix<T>::Gauss()
	{
		for (int i(0); i < lnes; ++i)
		{
			for (int j(i + 1); j < cols; ++j)
			{
				root[i][j] /= root[i][i];
			}
			root[i][i] = 1;
			for (int x(i + 1); x < lnes; ++x)
			{
				for (int j(i + 1); j < cols; ++j)
				{
					root[x][j] -= root[x][i] / root[i][i] * root[i][j];
				}
				root[x][i] = 0;
			}
		}
		for (int i(lnes - 1); i >= 0; --i)
		{
			for (int j(0); j < i; ++j)
			{
				root[j][cols - 1] -= root[j][i] / root[i][i] * root[i][cols - 1];
				root[j][i] = 0;
			}
		}
	}

}
