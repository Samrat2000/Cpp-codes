#include <iostream>

using namespace std;

int main(void)
{
	char str[1000];
	cout << "Enter string B: ";
	cin >> ws;
	cin.getline(str,1000);
	//cout << str << endl;
	char s[100];
	cout << "Enter string A: ";
	cin >> ws;
	cin.getline(s,100);
	int i=0, j=0, s_len=0;
	while(s[i]!='\0'){
		s_len++;
		i++;
	}
	//cout << "s length is : " << s_len;
	int count=0;
	int begin=0,end=0;
	for(i=0;i<s_len;) {
		int k=0, j=i;
		while(str[k]!='\0'){
			//cout << j%s_len << endl;
			if(str[k]!=s[j%s_len]) 
			{
				count=0;
				break;
			}
			if(j%s_len==0 || k==0) count++;
			j++;
			k++;
			if(str[k]=='\0')
			{
				cout << count << endl;
				exit(0);
			}	
		}
		i++;
	}
	cout << count << endl;
	
}
