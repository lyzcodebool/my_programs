#include <iostream>
class Point1{
public:
    Point1(int a, int b):x(a), y(b){}
    friend class Point2;
private:
    int x, y;
};

class Point2{
public:
    void print(const Point1 &a){
        std::cout<<a.x<<" "<<a.y<<std::endl;
    }
private:
    int x, y;
};

int main(void)
{
    class Point2 a;
    Point1 point(10, 10);
    Point1 &b = point;

    a.print(b);

    return 0;
}
