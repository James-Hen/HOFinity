#pragma once

#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

namespace James
{

	template<typename T>
	T gcd(T a, T b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}

	template<typename T>
	T mabs(T a)
	{
		return a < 0 ? -a : a;
	}

	template<typename T>
	class rational
	{
	private:
		T sn, mo;
		bool sign; // true pos, false neg
		void maintain()
		{
			sign = ((sn >= 0) == (mo >= 0));
			sn = mabs(sn);
			mo = mabs(mo);
			T div(gcd(sn, mo));
			sn /= div;
			mo /= div;
		}
		void push_off()
		{
			sn = sign ? sn : -sn;
			sign = true;
		}
	public:
		rational(T ss, T mm, bool si);
		rational(T ss, T mm);
		rational(T a);
		rational() {}
		rational(string a);
		double to_double() const;
		string to_string() const;
		rational inverse() const;
		rational operator - () const;
		rational operator + (const rational a) const;
		rational operator - (const rational a) const;
		rational operator * (const rational a) const;
		rational operator / (const rational a) const;
		rational operator += (const rational a);
		rational operator -= (const rational a);
		rational operator *= (const rational a);
		rational operator /= (const rational a);
		bool operator == (const rational a);
		bool operator > (const rational a);
		bool operator < (const rational a);
		bool operator >= (const rational a);
		bool operator <= (const rational a);
	};

}

//For tests;
//James::rational<int> a, b;
//while (1)
//{
//	cin >> a >> b;
//	cout
//		<< "a + b : " << a + b << ' ' << (a + b).to_double()
//		<< "\na - b : " << a - b
//		<< "\na * b : " << a * b
//		<< "\na / b : " << a / b
//		<< "\na == b : " << (a == b)
//		<< "\na > b : " << (a > b) << endl;
//}
