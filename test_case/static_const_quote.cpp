#include <iostream>

using namespace std;

class Point{
public:
    Point( int y): d(y){
        cout<<"构造"<<endl;
    };
    Point &operator = (const Point &a);
    void test1(int a){
        a++;
    }
    void test2(Point b){
        cout<<b.a<<endl;
    }

    void test3(Point &c){
        cout<<c.a<<endl;
    }
    Point(const Point &b);
    ~Point(){
        cout<<"析构"<<endl;
    }
private:
    const int a = 10;
    const static int b;
    static const int c;
    int d;
};

const int Point::b = 10;
const int Point::c = 20;
Point & Point::operator= (const Point &a)
{
    cout<<"赋值运算符重载"<<endl;
    return *this;
}
Point::Point(const Point &b){
    cout<<"拷贝"<<endl;
}
int main(void)
{
    Point pl(10);
    int p = 10;
    //pl.test1(p);
    pl.test2(pl);
    //pl.test3(pl);

    return 0;
}
