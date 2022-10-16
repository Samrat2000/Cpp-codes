 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n,l=-1;
    scanf("%d",&n);
    char s[n][85];
    for(int i=0;i<n;i++)
    scanf(" %[^\n]",s[i]); 
    for(int i=n-1;i>=0;i--)
    {
        l=-1;
        for(int j=strlen(s[i])-1;j>=0;j--)
        {
            l++;
            if((s[i][j]==' ')||j==0)
            {
                for(int k=j;k<=j+1+l;k++)
                {
                    if((s[i][k]>='a'&&s[i][k]<='z')||(s[i][k]>='A'&&s[i][k]<='Z'))
                    printf("%c",s[i][k]);
                    else
                    continue;
                }
                printf(" ");
                l=-1;
            }
        }
        printf("\n");
    }
}
