#include <iostream>

using namespace std;

class C{
    public:
        C(int i):i(i){
            cout<<"C constructor."<<endl;
        }

        ~C(){
            cout<<"C destructor."<<endl;
        }

        void *operator new(size_t size, void *p, const string &str){
            cout << "In our own operator new." << endl;
            cout<<str<<endl;
            if(!p){
                cout<<"指针为空"<<endl;
                return ::operator new(size);
            }

            return p;
        }
        
        void operator delete(void *p){
            cout<<"we shoule do noing in operator detele"<<endl;
            //如果取消下一行注释，程序会在执行的时候crash
//            ::operator delete(p);
        }
        void fun(){
            cout<<"hello object: i: "<<i<<endl;
        }
    private:
        int i;
};

int main(void)
{
    cout <<sizeof(int)<<endl;
    int a = 0x01020304;
    char buf[sizeof(C)-1];//这里试图用3个字节来存放4个字节的对象
    int b = 0x04030201;
    C *pc = new(buf, "Yeah, I'm crazy") C(0xFEDCBA98);

    pc->fun();

    delete pc;
}
