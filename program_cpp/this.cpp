#include <iostream>
/*this 在开始构造前产生，在函数执行完释放*/
class Point{
    int x, y;
public:
    Point(int a, int b):x(a),y(b){}
    void MovePoint(int m, int n){
        this->x += m;
        this->y += n;
    }
    void Print(){
        std::cout<<this->x<<" "<<this->y<<std::endl;
    }
    ~Point();
};
Point::~Point(){}

int main(void)
{
    Point print(10, 10);
    print.MovePoint(2, 2);
    print.Print();
    return 0;
}
