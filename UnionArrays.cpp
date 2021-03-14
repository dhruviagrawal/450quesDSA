#include <bits/stdc++.h>
using namespace std;

void ArrayUnion(int a[], int b[], int n, int m);

//prints intersection array
void ArrayIntersection(int a[], int b[], int n, int m)
{
    int i=0,j=0,c[n+m],k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        i++;
        else if(a[i]>b[j])
        j++;
        else //if element is equal
        {
            c[k]=a[i];
            k++;
            i++;
            j++;
        }
    }
    cout <<"Intersection of two arrays is : ";
    for(int i=0;i<k;i++)
    cout<<c[i]<<" ";
    cout<<endl;
}

//prints union array
void ArrayUnion(int a[], int b[], int n, int m)
{
    int i=0,j=0,k=0,c[n+m];
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else if(a[i]>b[j])
        {
            c[k]=b[j];
            j++;
            k++;
        }
        else //if element is equal
        {
            c[k]=a[i];
            k++;
            i++;
            j++;
        }
    }
    //to accept remaining elements in union array
    while(i<n)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m)
    {
        c[k]=b[j];
        j++;
        k++;
    }

    //printing union array but taking care that only distinct elements are considered
    cout <<"Union of two arrays is: ";
    for(int i=0;i<k;i++)
    {
        if(c[i]!=c[i+1])
        cout<<c[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n,m,unionCount=0;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<m;i++)
    cin>>b[i];
    ArrayIntersection(a,b,n,m);
    ArrayUnion(a,b,n,m);
    return 0;
}