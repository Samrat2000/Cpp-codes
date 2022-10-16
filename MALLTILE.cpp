#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, a;
	cin >> n >> m >> a;
	int x = ceil(n*1.0/a);
	int y = ceil(m*1.0/a);
	cout << (x*y) << endl;
}
