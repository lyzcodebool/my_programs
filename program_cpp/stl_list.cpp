#include <iostream>
#include <list>
using namespace std;

int main(void)
{

    list<int> l1{1, 2, 3, 4}, l2{0, 2, 6, 9};
    cout<<"merge l1 and l2 && sorted && detele l2..."<<endl;
   // l1.merge(l2);

    list<int>::iterator it;
    for(it = l1.begin(); it != l1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it = l2.begin(); it != l2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    l2.merge(l1,[](int n1,int n2){return n1<n2;});
        cout << "l2.merge(a1,comp):"<<endl;
        for(it = l2.begin();it!=l2.end();it++){
        cout << *it << " ";
    }
    cout << endl;



    list<int> a1{3, 4, 2}, a2{3, 5, 8};
    //c1.splice(c1.beg,c2)      将c2连接在c1的beg位置,释放c2
    a1.splice(a1.begin(), a2);
    cout << "a1.merge(a2):"<<endl;;
    for(it = a1.begin();it!=a1.end();it++){
        cout << *it << " ";
    }
    cout << endl;

    //c1.splice(c1.beg,c2,c2.beg)      将c2的beg位置的元素连接到c1的beg位置，并且在c2中施放掉beg位置的元素
    
    list<int> c1{3, 4, 2}, c2{3, 5, 8};
    c1.splice(c1.begin(), c2,++c2.begin());
    cout << "c1.merge(c2):"<<endl;;
    for(it = c1.begin(); it!=c1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    //预测结果：5342

    //c1.splice(c1.beg,c2,c2.beg,c2.end)      将c2的[beg,end)位置的元素连接到c1的beg位置并且释放c2的[beg,end)位置的元素
    list<int> d1{3, 4, 2}, d2{3, 5, 8};
    d1.splice(d1.begin(), d2, d2.begin(), d2.end());
    cout << "d1.merge(d2):"<<endl;;
    for(it = d1.begin(); it!=d1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //remove(num)             删除链表中匹配num的元素。
    d1.remove(3);
    cout<<"after remove 3"<<endl;
    for(it = d1.begin(); it!=d1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    //remove_if(comp)       删除条件满足的元素,参数为自定义的回调函数。
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(5);
    d1.remove_if([](int n){return n < 6;});
    cout<<"after remove_if n<6:"<<endl;
    for(it = d1.begin(); it!=d1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //reverse()       反转链表
    d1.push_front(111);
    d1.push_front(10);
    d1.push_front(9);
    d1.push_front(5);
    d1.push_front(2);
    d1.push_front(3);
    d1.push_front(4);
    cout<<"befor reverse:"<<endl;
    for(it = d1.begin(); it!=d1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    cout<<"after reverse:"<<endl;
    d1.reverse();
    for(it = d1.begin(); it!=d1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    //unique()       删除相邻的元素,注意：只删除有序链表的相邻的相同元素
    list<int> test{1, 1, 3, 3, 3, 5, 5, 3, 6};
    cout<<"test unique befor:"<<endl;
    for(it = test.begin(); it!=test.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    test.unique();
    cout<<"test after unique:"<<endl;
    for(it = test.begin(); it!=test.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    //c.sort()       将链表排序，默认升序 c.sort(comp)       自定义回调函数实现自定义排序
    list<int> m{2, 3, 1, 8, 4};
    cout<<"after sort:"<<endl;
    m.sort();
    for(it = m.begin(); it!=m.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    cout<<"after c,sort(comp):"<<endl;
    m.sort([](int n1, int n2){return n1>n2;});
    for(it = m.begin(); it!=m.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
