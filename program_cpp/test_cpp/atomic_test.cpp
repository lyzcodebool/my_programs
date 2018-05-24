#include <iostream>
#include <boost/thread/thread.hpp>
#include <time.h>
#include <atomic>
#include <thread>
//模拟用户点击量
using namespace std;

long total = 0;
boost::mutex m;
void click_onin()
{   
    for(int i = 0; i < 2; ++i)
    {
    m.lock();
        total += 1;
    m.unlock();
    }   
}

int main(void)
{
    //计时开始
    clock_t start = clock();

    //模拟一百个线程点击
    boost::thread_group grp;
    for(int i = 0; i < 10; i++)
    {
        grp.create_thread(click_onin);
    }
    grp.join_all();
    clock_t finish = clock();
    cout<<"result:"<<total<<endl;
    cout<<"time:"<<finish-start<<endl;

    m.~mutex();
    return 0;
}

