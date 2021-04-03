#include <bits/stdc++.h>
using namespace std;

//Time Complexity O(n), gave segmentation fault in gfg
long long getMaxArea(long long arr[], int n)
    {
    
    //left subarray
    vector <long long > left; //stores index of NSL(Next greater to left)
    stack <pair<long long , int>> s; //pair of NSL and index of NSL
    int pseudoindex=-1;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        left.push_back(pseudoindex);
        
        else if(!s.empty() && s.top().first<arr[i])
        left.push_back(s.top().second);
        
        else if(!s.empty() && s.top().first>=arr[i])
        {
            while(!s.empty() && s.top().first>=arr[i])
            s.pop();
            if(s.empty())
            left.push_back(pseudoindex);
            else
            left.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    
    //right subarray
    vector <long long > right; //stores index of NSR
    stack <pair<long long , int>> st; //pair of NSR and index of NSR
     pseudoindex=n;
    for( int i=n-1;i>=0;i--)
    {
        if(st.empty())
        right.push_back(pseudoindex);
        
        else if(!st.empty() && st.top().first<arr[i])
        right.push_back(st.top().second);
        
        else if(!st.empty() && st.top().first>=arr[i])
        {
            while(!st.empty() && st.top().first>=arr[i])
            st.pop();
            if(st.empty())
            right.push_back(pseudoindex);
            else
            right.push_back(st.top().second);
        }
        st.push({arr[i],i});
    }
    reverse(right.begin(),right.end());
    
    long long  width[n],area[n],maxArea=INT_MIN;
    for(int i=0;i<n;i++)
    {
      width[i]=right[i]-left[i]-1;
      area[i]=width[i]*arr[i];
      maxArea=max(maxArea,area[i]);
    }
    return maxArea;
}


int main()
{
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
    return 0;
}


//Another approach, passed gfg
long long getMaxArea(long long arr[], int n)
    {
       stack<int> st;
       int i;
       long long area=INT_MIN, maxx= INT_MIN;
       int temp;
       for( i=0; i<n; i++)
       {
           while( !st.empty()  && arr[st.top()] > arr[i]){
           temp= st.top();
            st.pop();
            
             if(st.empty()){
                area= arr[temp]* i; //i is rightmost smaller element's index
            }
            else{
                area= arr[temp]* (i-st.top()-1); //st.top() is leftmost smaller element's index
            }
            maxx= max(area, maxx);
           }
           st.push(i);
         }
        while(!st.empty()){
        temp= st.top();
        st.pop();
        if(st.empty()){
            area= arr[temp]* i;
        }
        else{
            area= arr[temp]* (i-st.top()-1);
        }
        maxx= max(area, maxx);
    }
    return maxx;
}