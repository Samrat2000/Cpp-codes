#include<iostream>
#include<bits/stdc++.h>
#include<ctype.h>

using namespace std;

int main()
{
        int n;
        cin>>n;
        set<string> s;
        for(int i=0;i<=n;i++)
        {
                char ch;
                while((ch=getchar())!='\n')
                {

                        string str;
                        while(isalpha(ch))
                        {
                                str.push_back(tolower(ch));
                                ch=getchar();
                        }
                        if(str.length())
                        {
                                s.insert(str);
                                str.erase();
                        }
                        if(ch=='\n')
                                break;

                }
        }
        cout<<s.size()<<endl;
        for(auto k:s)
                cout<<k<<endl;
}
