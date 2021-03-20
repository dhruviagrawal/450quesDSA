#include <bits/stdc++.h>
using namespace std;

//Complexity O(n)
int minJumps(int a[],int n)
{
    if(a[0]==0) return -1;
    //maxReachable stores maximum Reachable index
    //jumps stores number of jumps needed to reach maximum reachable index
    //stepsPossible stores steps which are still possible
    int maxReachable, stepsPossible, jumps;

    maxReachable=a[0];
    jumps=1;
    stepsPossible=a[0];

    for(int i=1;i<n;i++)
    {
       if(i==(n-1))
       return jumps;
       
       maxReachable=max(maxReachable , i+a[i]);
       stepsPossible--;

       if(stepsPossible==0)
       {
          jumps++;
          if(i>=maxReachable)
          return -1; //failure case, its stuck, cant take steps enough to reach end of array eg- 1 0 0 0 6 8

          stepsPossible = maxReachable-i;
       }
    }
    return jumps;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int result=minJumps(a,n);
}
