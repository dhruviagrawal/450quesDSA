 #include <bits/stdc++.h>
 using namespace std;
 
 //TimeComplexity-O(n)
 //SpaceComplexity-O(1)

 //BruteForce- Generate all possible combinations and linearly traverse anf find the next permutation. O(n!*n)

//Optimal- Intuition is in dictionary order,it will always be increasing order from back even if for a few moments.
 vector<int> nextPermutation(vector<int>& a) 
 {
        int n=a.size(),k,l;
        //traverse backwards
        for(k=n-2;k>=0;k--)
        {
            if(a[k]<a[k+1])
                break;//find breakpoint
        }
        if(k<0)
            reverse(a.begin(),a.end());//corner case tells us there is no breakdown. last ranked combination is taken. So reverse it to take next(i.e. the first combination)
        else
        {
            for(l=n-1;l>=0;l--)
            {
                if(a[l]>a[k])
                    break;
            }
            swap(a[l],a[k]);//to form greater prefix
            reverse(a.begin()+k+1,a.end());//to find the lowest ranked combination
        }
        return a;
        
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int> res=nextPermutation(v);
    for(int i=0;i<n;i++)
    cout<<res[i]<<" ";
    return 0;
}