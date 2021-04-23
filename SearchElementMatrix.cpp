#include<bits/stdc++.h>
using namespace std;

//Approach 1-does not use 'The first integer of each row is greater than the last integer of the previous row' property
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(); //row size
        int c=matrix[0].size(); //column size
        int i=0,j=c-1;
        while(i<r && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                j--; //traverses left of row
            else
                i++; //traverses down the column
        }
        return false;
    }
int main()
{
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        int ele;
        cin>>ele;
        bool ans = searchMatrix(matrix, ele);
        cout<<ans<<endl;
    }
    return 0;
}

//Approach 2
//Time complexity O(log n*m)
//Space Complexity O(1)
/*bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size()) return false;
            
        int r=matrix.size();
        int c=matrix[0].size();
        
        int low=0,high=(r*c)-1; //all elements are sorted
        while(low<=high)
        {
            int mid=(low+high)/2; //imaginary index
            if(matrix[mid/c][mid%c]==target) //mid/c gives row and mid%c gives column of element
                return true;
            else if(matrix[mid/c][mid%c]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false; 
    }
*/