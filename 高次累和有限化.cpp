#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include "Rational.h"
#include "Bigint.h"
#include "Matrix.h"

using namespace James;
using namespace std;

typedef long long LL;

int main()
{
	int n;
	while (cin >> n)
	{
		long double ans(0);
		for (int i(1); i <= n; ++i)
		{
			ans += long double(1) / (n + i);
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}
