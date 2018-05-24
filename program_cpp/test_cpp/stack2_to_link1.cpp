#include <iostream>
#include <stack>
//两个栈实现一个队列
using namespace std;

class CQueue{
public:
    CQueue(){};
    ~CQueue(){};

    void appendTail(const CQueue& node);
    CQueue deteleHead();
private:
    stack<CQueue> stack1;
    stack<CQueue> stack2;
};


void CQueue::appendTail(const CQueue &node){
    stack1.push(node);
}

CQueue CQueue::deteleHead(){
    if(stack2.size() > 0){
        while(stack1.size() > 0){
            CQueue &data = stack2.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size() == 0){
        cout<<"empty"<<endl;
    }
    CQueue head = stack2.top();
    stack2.pop();

    return head;
}

int main()
{


    return 0;
}

