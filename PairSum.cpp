#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int a[], int n, int k) {
        sort(a,a+n);
        int i=0,j=n-1,c=0;
        while(i<j)
        {
            int s=a[i]+a[j];
            if(s<k)i++; //if sum is less, we take a larger element for sum
            else if(s>k) j--; //if sum is greater, we take a smaller element for sum
            else
            {
                // Find the frequency of a[i]
                int x=a[i],xx=i;
                while(i<j && a[i]==x)
                i++;
                
                // Find the frequency of a[j]
                int y = a[j], yy = j;
                while (j >= i and a[j] == y)
                j--;
                
                // If a[i] and a[j] are same
                // then remove the extra number counted
                if (x == y) {
                int temp = i - xx + yy - j - 1;
                c += (temp * (temp + 1)) / 2;
                }
                else
                c += (i - xx) * (yy - j);
                
            }
        }
        return c;
    }

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int ans=getPairsCount(a,n,k);
    cout<<ans<<endl;
    return 0;
}