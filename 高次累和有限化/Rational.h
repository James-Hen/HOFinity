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
		long double to_double() const;
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

	template<typename T>
	inline istream & operator>>(istream & is, rational<T> & a)
	{
		string obj;
		is >> obj;
		a = rational<T>(obj);
		return is;
	}

	template<typename T>
	inline ostream & operator<<(ostream & os, const rational<T> & a)
	{
		os << a.to_string();
		return os;
	}

	template<typename T>
	rational<T>::rational(T ss, T mm, bool si) : sn(ss), mo(mm), sign(si) {}

	template<typename T>
	rational<T>::rational(T ss, T mm) : sn(ss), mo(mm)
	{
		maintain();
	}

	template<typename T>
	rational<T>::rational(T a) : sn(a), mo(1)
	{
		maintain();
	}

	template<typename T>
	inline James::rational<T>::rational(string a)
	{
		stringstream obj;
		obj << a;
		if (a[0] == '-')
		{
			char k;
			obj >> k;
			sign = false;
		}
		else
		{
			sign = true;
		}
		int x;
		char k;
		obj >> x;
		sn = x;
		obj >> k >> x;
		mo = x;
	}

	template<typename T>
	inline rational<T> rational<T>::inverse() const
	{
		return rational(this->mo, this->sn, this->sign);
	}

	template<typename T>
	inline string James::rational<T>::to_string() const
	{
		stringstream obj;
		string ans;
		if (!this->sign)
		{
			obj << '-';
		}
		obj << this->sn << '/' << this->mo;
		getline(obj, ans);
		return ans;
	}

	template<typename T>
	inline long double James::rational<T>::to_double() const
	{
		return  long double(this->sn) / this->mo * (this->sign ? 1 : -1);
	}

	template<typename T>
	rational<T> rational<T>::operator-() const
	{
		rational<T> ans(*this);
		ans.sign = !ans.sign;
		return ans;
	}

	template<typename T>
	rational<T> rational<T>::operator+(const rational ano) const
	{
		rational<T> ans(*this), a(ano);
		ans.push_off();
		a.push_off();
		T lcmm(ans.mo / gcd(ans.mo, a.mo) * a.mo);
		ans.sn = lcmm / ans.mo * ans.sn + lcmm / a.mo * a.sn;
		ans.mo = lcmm;
		ans.maintain();
		return ans;
	}

	template<typename T>
	rational<T> rational<T>::operator-(const rational a) const
	{
		return *this + (-a);
	}

	template<typename T>
	rational<T> rational<T>::operator*(const rational a) const
	{
		rational<T> ans(*this);
		ans.sign = (a.sign == ans.sign);
		T gd1(gcd(ans.sn, a.mo)), gd2(gcd(ans.mo, a.sn));
		ans.mo = ans.mo / gd2 * a.mo / gd1;
		ans.sn = ans.sn / gd1 * a.sn / gd2;
		return ans;
	}

	template<typename T>
	rational<T> rational<T>::operator/(const rational a) const
	{
		return *this * a.inverse();
	}

	template<typename T>
	inline rational<T> rational<T>::operator+=(const rational a)
	{
		return (*this = *this + a);
	}

	template<typename T>
	inline rational<T> rational<T>::operator-=(const rational a)
	{
		return (*this = *this - a);
	}

	template<typename T>
	inline rational<T> rational<T>::operator*=(const rational a)
	{
		return (*this = *this * a);
	}

	template<typename T>
	inline rational<T> rational<T>::operator/=(const rational a)
	{
		return (*this = *this / a);
	}

	template<typename T>
	inline bool rational<T>::operator==(const rational a)
	{
		return (sign == a.sign && mo == a.mo && sn == a.sn);
	}

	template<typename T>
	inline bool rational<T>::operator>(const rational a)
	{
		if (sign != a.sign)
		{
			return sign == 0;
		}
		bool ans;
		ans = (sn * a.mo > mo * a.sn);
		return sign > 0 ? ans : !ans;
	}

	template<typename T>
	inline bool rational<T>::operator<(const rational a)
	{
		return !(*this > a || *this == a);
	}

	template<typename T>
	inline bool rational<T>::operator>=(const rational a)
	{
		return !(*this < a);
	}

	template<typename T>
	inline bool rational<T>::operator<=(const rational a)
	{
		return !(*this > a);
	}

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
