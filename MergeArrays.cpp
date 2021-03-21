#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int b[], int n, int m) {
	    int i=n-1, j = 0;
        while(i>=0 && j<m){
            if(a[i]>b[j])
                swap(a[i],b[j]);
            i--,j++;
        }
        sort(a,a+n);
        sort(b,b+m);
	}

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	merge(a,b,n,m);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	for(int i=0;i<m;i++)
		cout<<b[i]<<" ";

}
