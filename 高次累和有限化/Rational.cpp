#include "Rational.h"

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
inline double James::rational<T>::to_double() const
{
	return double(this->sn) / this->mo * (this->sign ? 1 : -1);
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
