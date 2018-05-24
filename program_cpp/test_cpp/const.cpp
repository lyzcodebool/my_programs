#include <iostream>

using namespace std;
class Point{
public:
    mutable int l;
    Point(int a, int b):x(a), y(b){}
    void init(int m, int n) const;

private:
    mutable int x;
    mutable int y;
};

void Point::init(int m, int n) const{
    this->x = m;
    this->y = n;
}

int main(void){

    Point point(1, 2);
    const Point * const p = &point;
    p->l = 8;

    return 0;
}
