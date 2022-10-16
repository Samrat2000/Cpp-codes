#include <iostream> 

//#include <bitset>
//#define ll long long int
using namespace std;
 
#define B2(n) n, n + 1, n + 1, n + 2 
#define B4(n) B2(n) \, B2(n + 1), B2(n + 1), B2(n + 2) 
#define B6(n) B4(n) \, B4(n + 1), B4(n + 1), B4(n + 2) 
  
// Lookup table that store the reverse of each table 
unsigned int lookuptable[256] = { B6(0), B6(1), B6(1), B6(2) }; 
  
// function countset Bits Using lookup table 
// ans return set bits count 
unsigned int countSetBits(int N) 
{ 
    // first chunk of 8 bits from right 
    unsigned int count = lookuptable[N & 0xff] + 
  
                         // second chunk from  right 
                         lookuptable[(N >> 8) & 0xff] +  
                           
                         // third and fourth chunks 
                         lookuptable[(N >> 16) & 0xff] +  
                         lookuptable[(N >> 24) & 0xff]; 
    return count; 
} 
int main()
{
 	int t;
 	cin >> t;
 	while(t--){
 		for (int i = 0; i < 256; i++) 
        lookuptable[i] = (i & 1) + lookuptable[i / 2];
 		unsigned int n;
		cin >> n;
    	cout << countSetBits(n) << endl;
 
	}
	return 0;
}
