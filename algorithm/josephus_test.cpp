#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void josephus(int total, int num, list<int> count1)
{
    if(total < 0|| total > 10)
        return;
    list<int> pNode;
    list<int>::iterator it;
    int i;
    for(i = 0; i < total; i++)
    {
        pNode.push_back(i);
    }

    it = pNode.begin();
    /* for(i = 1; i < from; ++i) */
    /* { */
    /*     it++; */
    /*     if(it == pNode.end()){ */
    /*         it = pNode.begin(); */
    /*     } */
    /* } */
    
    /* while(pNode.size() != 0){ */
    /*     for(i = 1; i < count; i ++) */
    /*     { */
    /*         it++; */
    /*         if(it == pNode.end()){ */
    /*             it = pNode.begin(); */
    /*         } */
    /*     } */
    /*     cout<<"淘汰："<<*it<<endl; */
    /*     it = pNode.erase(it); */
    /*     if(it == pNode.end()){ */
    /*         it = pNode.begin(); */
    /*     } */
    /* } */
    list<int>::iterator ct;
    while(pNode.size() != 0){
        for(unsigned long i = 1; i < count1.size(); i++)
        {
            it++;
            if(it == pNode.end()){
                it = pNode.begin();
            }
            if(it == *ct){
                ct++;
                if(ct == count1.end()){
                    ct = count1.begin();
                }

            }

        }
    }

}

int main()
{
    josephus(13, 1, 3);
    return 0;
}
