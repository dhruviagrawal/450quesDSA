#include <bits/stdc++.h>
using namespace std; 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int min,max;
        
        if(a[0]>a[1])
        {
           min=a[1];
           max=a[0];
        }
        else
        {
            min=a[0];
            max=a[1];
        }

        for(i=2;i<n-1;i+=2)
        {
            if(a[i]<a[i+1])
            {
                 if(a[i]<min) min=a[i];
                 if(a[i+1]>max) max=a[i+1];
            }
            else
            {
                if(a[i]>max) max=a[i];
                if(a[i+1]<min) min=a[i+1];
            }
        }
        cout<<"Minimum is "<< min << endl;
        cout<<"Maximum is "<< max << endl;
    }
    return 0;
}