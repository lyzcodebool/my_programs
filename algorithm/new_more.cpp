#include <iostream>

using namespace std;

int main(void)
{
    float *p = NULL;
    while(1){
        p = new float[10000000];
        /* cout<<"eat mermory"<<endl; */
        if(p == NULL){ 
        cout<<"eat mermory"<<endl;
         } 
    }

    return 0;
}
