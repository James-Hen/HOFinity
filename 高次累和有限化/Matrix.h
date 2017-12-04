#pragma once

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
	};

}
