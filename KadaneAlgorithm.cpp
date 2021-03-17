#include <bits/stdc++.h>
using namespace std;
//largest sum of contiguous subarray
int main()
{
    int n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int max=0,maxTemp=0;
    for(int i=0;i<n;i++)
    {
        maxTemp+=a[i];
        if(maxTemp<0)
        maxTemp=0;
        else if(max<maxTemp)
        max=maxTemp;
    }
    cout<<max<<endl;
}