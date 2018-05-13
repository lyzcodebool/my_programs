#include <iostream>
#include <list>
#include <vector>

using namespace std;

void josephus(int total, int from, int count)
{
    list<int> pNode;
    list<int>::iterator it;
    int i;
    for(i = 0; i < total; i++)
    {
        pNode.push_back(i);
    }

    it = pNode.begin();
    for(i = 1; i < from; ++i)
    {
        it++;
        if(it == pNode.end()){
            it = pNode.begin();
        }
    }
    
    while(pNode.size() != 0){
        for(i = 1; i < count; i ++)
        {
            it++;
            if(it == pNode.end()){
                it = pNode.begin();
            }
        }
        cout<<"淘汰："<<*it<<endl;
        it = pNode.erase(it);
        if(it == pNode.end()){
            it = pNode.begin();
        }
    }
}

int main()
{
    josephus(13, 1, 3);
    return 0;
}
