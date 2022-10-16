#include <iostream> 
#define ll long long int
using namespace std;
 
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		ll x,y;
		cin >> x >> y;
		ll l = lcm(x,y);
		ll a = l/x - 1;
		ll b = l/y - 1;
		cout << (a+b) << endl;
	}
	return 0;
}
