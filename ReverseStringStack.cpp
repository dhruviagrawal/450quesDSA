#include <bits/stdc++.h>
using namespace std;

//Reverse a string using Stack
//Time Complexity O(n)
//Space Complexity O(n)

//returns the address of the reversed string
char* reverse(char *str, int len)
{
    stack <char> s;
    for(int i=0;i<len;i++)
        s.push(str[i]);
    
    for(int i=0;i<len;i++)
    {
        str[i] = s.top();
        s.pop();
    }
    
    return str;
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[100];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        cout<<ch;
        cout<<endl;
    }
    return 0;
}