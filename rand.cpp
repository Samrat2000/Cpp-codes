#include <cstdlib> 
#include <ctime> 
#include <iostream>

using namespace std;

int main() 
{ 
    srand((unsigned)time(0)); 
    int i;
    
    for(i=0;i<10;i++)
     cout<<((rand()%6)+1)<<endl; 
    
}
