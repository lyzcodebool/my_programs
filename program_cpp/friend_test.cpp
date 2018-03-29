#include <iostream>

class Point{
public:
    Point(int x, int y);
    Point(const Point &a);
    Point &operator = (const Point &a);
    void print();
    friend void newval(class Point &cpy);
    ~Point();
private:
    int x, y;
};

Point::Point(int x, int y){
    this->x = x;
    this->y = y;
};
Point::Point(const Point &a){
    this->x = a.x;
    this->y = a.y;
};
Point::~Point(){};
Point & Point::operator=(const Point &a){
    if(this == &a)
        return *this;
    this->x = a.x;
    this->y = a.y;

    return *this;
}
void Point::print(){
    std::cout<<this->x<<" "<<this->y<<std::endl;
}
void newval(class Point &cpy){
    std::cout<<cpy.x<<" "<<cpy.y<<std::endl;
}

int main()
{
    Point point(10, 10);
    Point &cpy = point;
    newval(cpy);
    return 0;
}
