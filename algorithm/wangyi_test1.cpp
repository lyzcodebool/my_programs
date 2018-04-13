#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    long long  a = 0;
    int count = 0;
    int r;
    cin>>r;
    cout<<__INT_MAX__<<endl;;
    int j = 0;
    for(int i = 1; i <= r; i++){
        j++;
        if(a >= 0 && j <= 9){
            a = a*10 + i;
            cout<<a<<" "<<endl;
            if(a % 3 == 0){
                ++count;
            }
        }else if(a >= 0 && j > 9){
            cout<<"---------------------"<<a*100<<" "<<i<<endl;
            a = a*100 + i;
            cout<<a<<" "<<endl;
            j = 0;
        }else{
            cout<<"out of range"<<endl;
            break;
        }
    }
    cout<<endl;
    cout<<"count = "<<count<<endl;


    return 0;
}
