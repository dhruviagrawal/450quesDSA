#include <bits/stdc++.h>
using namespace std;

/* 
LinkedList cycle method!-most optimal

2 5 9 6 9 3 8 9 7 1

we traverse-
2-9-1-5-3-6-8-9-7-9
A cycle is created

Take two pointers-slow & fast
slow takes one step at a time
fast takes two steps at a time

whenever they collide,
take fast pointer to start and make it move one by one alongwith the slow pointer

They will collide where the duplicate element is present
*/

//Time Complexity O(n)
//Space Complexity O(1)
int findDuplicate(vector <int> & nums) {
          int slow=nums[0];
          int fast=nums[0];
        
          do
          {
              slow=nums[slow];
              fast=nums[nums[fast]];
          }
        while(slow!=fast);
        
        fast=nums[0];
        
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;
    }

int main()
{
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    cout<<findDuplicate(v)<<endl;
}

/* Naive approach-sort array and adjacent elements
Time Complexity would have been O(n log n) and Space Complexity O(1)
It will also distort the array */

/* 
Another approach-
Time Complexity O(n)
Space Complexity O(n)

Form a frequency array calculating frequency of no. of times element is present. If more than once, that is the duplicate array.

int findDuplicate(vector<int> nums) 
    {
        int n=nums.size();
        int Frequency[n+1]={0};
        for(int i=0;i<n;i++)
        {
            if(Frequency[nums[i]]==0)
            Frequency[nums[i]]++;
            else
                return nums[i];
        }
        return -1;
    }

*/