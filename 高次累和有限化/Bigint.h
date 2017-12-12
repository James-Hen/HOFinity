#pragma once

#include <cstdlib>

namespace James
{

	class bigint
	{
	private:
		static const int power = 4;
		static const int base = 10000;
		bool sign; // true pos, false neg
		struct node
		{
			int val;
			node * frnt, *nxt;
		};
		node * bottom, *topper;
		void delbit();
		void addbit();
	public:
		bigint();
		bigint(long long int a);
	};

	inline void bigint::delbit()
	{
		topper = topper->frnt;
		delete topper->nxt;
	}

	inline void bigint::addbit()
	{
		topper->nxt = new node;
		topper = topper->nxt;
	}

	James::bigint::bigint()
	{
		bottom = new node;
		topper = bottom;
		topper->val = 0;
		topper->frnt = nullptr;
		topper->nxt = nullptr;
	}

	inline bigint::bigint(long long int a)
	{
		bottom = new node;
		topper = bottom;
		topper->val = 0;
		topper->frnt = nullptr;
		topper->nxt = nullptr;
		while (a % base)
		{
			topper->val = a % base;
			a /= base;
			addbit();
		}
	}

}
