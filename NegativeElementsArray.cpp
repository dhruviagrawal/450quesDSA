#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int i=0,j=n-1,b[n];
    for(int k=0;k<n;k++)
    {
      if(a[i]<0)
      {
          b[i]=a[k];
          i++;
      }  
      else
      {
          b[j]=a[k];
          j--;
      }
    }
    for(int k=0;k<n;k++)
    cout<<b[k]<<" ";
    
    return 0;
}