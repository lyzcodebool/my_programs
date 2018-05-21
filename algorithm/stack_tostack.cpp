#include <iostream>
#include <stack>
using namespace std;

void reverse(stack<int> &A, stack<int> &B)
{
    int min = A.top();
    for(int i = 0; i < (int)A.size(); i++)
    {
        min = A.top();
        A.pop();
        while(!A.empty()){
            B.push(A.top());
            A.pop();
        }
        A.push(min);
        while(!B.empty()){
            A.push(B.top());
            B.pop();
        }
    }
}

int main(void)
{
    stack<int> StackA, StackB;
    for(int i = 0; i < 10; ++i)
    {
        StackA.push(i);
    }
    for(int i = 0; i < 10; ++i){
        cout<<StackA.top();
        StackA.pop();
    }
    cout<<endl;
    for(int i = 0; i < 10; ++i)
    {
        StackA.push(i);
    }
    reverse(StackA, StackB);
    for(int i = 0; i < 10; ++i){
        cout<<StackA.top()<<endl;
        StackA.pop();
    }
}
