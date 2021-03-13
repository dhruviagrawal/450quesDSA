#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int lb, int ub);

//returns kth smallest number
int kthSmallest(int a[],int lb,int ub,int k)
{
    if(k>0 && k<=(ub-lb+1))
    {
        int q=partition(a,lb,ub);//returns position of pivot(index)
        int pos=q-lb+1; //gives absolute position
        if(k==pos)
        return a[q];
        
        else if(k<pos)
        return kthSmallest(a,lb,q-1,k);
        
        else
        return kthSmallest(a,q+1,ub,k-pos);
    }
}

int partition(int a[], int lb, int ub)
{
    int pivot=a[ub],p=lb;
    for(int j=lb;j<=(ub-1);j++)
    {
        if(a[j]<=pivot)
        {
            swap(a[p],a[j]); //sorts the array till left of pivot so as to count the absolute position of pivot
            p++;
        }
    }
    swap(a[p],a[ub]); //swaps pivot to its position if array was sorted in ascending order
    return p;
}

int main()
{
    int n,i,k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"Enter the value of k"<<endl;
    cin>>k;
    cout<<"kth smalllest element is :"<<kthSmallest(a,0,n-1,k);
    return 0;
}


