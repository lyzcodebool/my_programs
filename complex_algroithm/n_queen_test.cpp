#include <iostream>
#include <math.h>
#define N 4
using namespace std;;

int site[N];            //保存各列行后放置的位置，第i列第site[i]行
int iCount = 0;         //用来统计总共有多少中方法
void queens(int n);     //执行并放置第n列的回溯函数, 参数n表示第n列
bool isValid(int n);    //判断第n列的皇后是否与其他皇后冲突,冲突返回false，不冲突返回true
void output();          //找到一个可行的解以后把可行解输出

//n皇后问题 回溯法递归实现
void queens(int n)//n表示从第几列开始
{
    int i;
    if(n == N){
        output();
        return;
    }
    for(i = 1; i <= N; ++i)
    {
              //如果第n列放置成功
        site[n] = i;         //保证每一列皇后放置都是从第一行开始尝试
        if(isValid(n))
            queens(n + 1);   //开始下一列
    }
}

bool isValid(int n)
{
    for(int j = 0; j < n; ++j)
    {
        if(site[n] == site[j] || (site[n]-site[j]) ==(n-j) || (site[n]-site[j]) ==(j-n))  
            return false;
    }
    return true;
}

void output()
{
    iCount ++;
    cout<<"iCount = "<<iCount<<endl;

    for(int i = 0; i < N; ++i){
        cout<<site[i];
    }
    cout<<endl;
}
int main(void)
{
    queens(0);

    return 0;
}
