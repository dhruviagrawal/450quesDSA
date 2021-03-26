#include<bits/stdc++.h>
using namespace std;

//Time Complexity-O(n1+n2+n3)
//Space Complexity-O(1)
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0;
            vector <int> v;
            while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]==B[j] && B[j]==C[k])
                {
                  v.push_back(A[i]);
                  i++;j++;k++;
                }
                else if(A[i]<B[j]) i++;
                else if(B[j]<C[k]) j++;
                else k++;
               
               //to take only distinct elements
                while(A[i]==A[i-1])i++;
                while(B[j]==B[j-1])j++;
                while(C[k]==C[k-1])k++;
                
            }
              return v;
        }

int main()
{
     int n1,n2,n3;
     cin>>n1>>n2>>n3;
     vector<int>ans;
     int a[n1],b[n2],c[n3];
     for(int i=0;i<n1;i++)
     cin>>a[i];
     for(int i=0;i<n2;i++)
     cin>>b[i];
     for(int i=0;i<n3;i++)
     cin>>c[i];
     ans=commonElements(a,b,c,n1,n2,n3);
     for(int i=0;i<ans.size();i++)
     cout<<ans[i]<<" ";
}