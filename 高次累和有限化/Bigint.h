#pragma once

#include <cstdlib>

namespace James
{

	class bigint
	{
	private:
		static const int int_max = 2147483647;
		bool sign; // true pos, false neg
		struct node
		{
			int val;
			node * frnt, * nxt;
		};
		node * bottom, * topper;
	public:
		bigint();
	};

}
