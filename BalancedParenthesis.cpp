#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string x)
    {
       int n=x.length();
       stack<char>s;
       bool ans=true;
       for(int i=0;i<n;i++)
       {
           if(x[i]=='{' || x[i]=='(' || x[i]=='[')
           s.push(x[i]);
           else if(x[i]==')')
           {
               if(!s.empty() && s.top()=='(')
               s.pop();
               else
               {
                   ans=false;
                   break;
               }
           }
           else if(x[i]=='}')
           {
               if(!s.empty() && s.top()=='{')
               s.pop();
               else
               {
                   ans=false;
                   break;
               }
           }
           else if(x[i]==']')
           {
               if(!s.empty() && s.top()=='[')
               s.pop();
               else
               {
                   ans=false;
                   break;
               }
           }
       }
       if(!s.empty()) return false;
       return ans;
    }

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(isBalanced(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
} 