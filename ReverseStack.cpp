#include <bits/stdc++.h>
using namespace std;

//reverse stack
//can use another stack and keep on popping and pushing to another stack. will be O(n) space complexity
//So we use Recursion for o(1) space complexity
void insertAtBottom(stack <int> ,int);
void reverse(stack <int> s)
{
    if(s.empty())
    return;

    int topElement=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,topElement);
}

void insertAtBottom(stack <int> &s,int ele);
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }

    int topEle=s.top();
    s.pop();
    insertAtBottom(s,ele);
    s.push(topEle);
}

int main()
{
    stack <int> s;
    s.push(5);
    s.push(6);
    s.push(2);
    reverse(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}