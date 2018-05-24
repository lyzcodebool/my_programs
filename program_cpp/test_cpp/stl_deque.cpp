#include <iostream>
#include <deque>

 using namespace std;

int main(void)
{
    deque<int> d {1, 2, 3, 4, 5}, d1, d2, d3;
    deque<int>::iterator it;
    for(it = d.begin(); it != d.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //倒置队列
    deque<int>::reverse_iterator i;
    for(i = d.rbegin(); i != d.rend(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    //operator = 
    cout<<"operator = ....."<<endl;
    d1 = d;
    deque<int>::reverse_iterator num;
    for(num = d1.rbegin(); num != d1.rend(); num++){
        cout<<*num<<" ";
    }
    cout<<endl;


    //拷贝assion
    cout<<"insert and copy by assgin...."<<endl;
    d2.assign(2, 8);//将两个8拷贝进队列
    for(num = d2.rbegin(); num != d2.rend(); num++){
        cout<<*num<<" ";
    }
    cout<<endl;
    d2.assign(d1.begin(), d1.begin()+3);
    for(num = d2.rbegin(); num != d2.rend(); num++){
        cout<<*num<<" ";
    }
//    cout<<d2[1]<<d2.at(10)<<" ";//operator[]下标运算符重载+边界检查
    cout<<endl;


    //insert data
    cout<<"insert data by insert...."<<endl;
    d2.insert(d2.begin(), 3, 3); 
    int a[10] = {100, 101, 102, 103};
    d2.insert(d2.end(), a, a+3);
    for(num = d2.rbegin(); num != d2.rend(); num++){
        cout<<*num<<" ";
    }
    cout<<endl;

    //detele data...
    cout<<"detele data by erase ...."<<endl;
    d2.erase(d2.begin(), d2.end());
    for(num = d2.rbegin(); num != d2.rend(); num++){
        cout<<*num<<" ";
    }
    cout<<endl;

    //insert data
    cout<<"insert data by push_back and push_front...."<<endl;
    d2.push_back(1);
    d2.push_front(2);
    for(num = d2.rbegin(); num != d2.rend(); num++){
        cout<<*num<<" ";
    }
    cout<<endl;

    cout<<"detele data by pop_back and pop_front...."<<endl;
    d2.pop_back();
    d2.pop_front();
    for(num = d2.rbegin(); num != d2.rend(); num++){
        cout<<*num<<" ";
    }
    cout<<endl;

    //resize deque...
    cout<<"resize deque...."<<endl;
    cout<<"d.size() = "<<d.size()<<endl;
    d.resize(d.size()+5);
    cout<<"d.resize() after = "<<d.size()<<endl;
    
    cout<<"resize after...."<<endl;
    for(it = d.begin(); it != d.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //swap deque
    cout<<"swap deque by swap...."<<endl;
    d1.swap(d);//swap(d1, d2);
    cout<<"swap after d1:"<<endl;
    for(it = d.begin(); it != d.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"swap after d:"<<endl;
    for(num = d1.rbegin(); num != d1.rend(); num++){
        cout<<*num<<" ";
    }
    cout<<endl;

    return 0;
}
