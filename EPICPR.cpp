#include <bits/stdc++.h>

using namespace std;

int main()
{
	int d, y;
	cin >> d >> y;
	while(d--)
	{
		int n;
		cin >> n;
		int tot = 0;
		while(n--)
		{
			int in, out;
			cin >> in >> out;
			if(in > 2160 && out > 2160) tot += (y * (out-in));
			else if(in <= 2160 && out > 2160) tot += (y * (out-2160));
		}
		cout << tot << "\n";
	}
}
