#include <bits/stdc++.h>
using namespace std; 

//Reversing a string
string reverseWord(string str)
{
   int start=0,end=str.size()-1;
   while(start<=end)
   {
      swap(str[start],str[end]);
      start++;
      end--;
   }
   return str;
}

int main()
{
    string s;
    cin>>s;
    cout << reverseWord(s) << endl;
    
}