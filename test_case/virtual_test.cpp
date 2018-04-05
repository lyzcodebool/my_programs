#include <iostream>
using namespace std;

class Point{
public:
    virtual void fun(){};
    void print(){};
    int *p;
    int a;
private:

};

int main(void){

    Point *m = NULL;
    m->fun();
    m->print();
    m->p = NULL;

    return 0;
}
