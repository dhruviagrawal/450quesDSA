#include<bits/stdc++.h>
using namespace std;
//Insert an element at the bottom of stack, without using any other data structure
//Recursion is used
void insertAtBottom(stack <int> &s, int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }

    //all the items are held in function call stack 
    //after reaching end of stack, above if pushes the element at bottom
    int topEle=s.top();
    s.pop();
    insertAtBottom(s, ele);
    
    //pushing elements back from the fumction call stack
    s.push(topEle);

}

int main()
{
    int ele;
    cin>>ele;
    stack<int>s;
    s.push(5);
    s.push(3);
    s.push(2);
    insertAtBottom(s, ele);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}