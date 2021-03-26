#include <bits/stdc++.h>
using namespace std;

//Time Complexity O(n)
int maxProfit(vector<int>& prices) {
       int profit=0,minPrice=INT_MAX;
        for(auto x:prices)
        {
            minPrice=min(minPrice,x);
            profit=max(profit,x-minPrice);
        }
        return profit;
    }

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int profit=maxProfit(v);
    cout<<profit<<endl;
}