#include <iostream>
using namespace std;

int i = 1;

class MyCls{
public:
    MyCls():m_nFor(m_nThd), m_nSec(i++), m_nFir(i++), m_nThd(i++){
        m_nThd = i;
    }
    void echo(){
        cout<<m_nFor<<m_nSec<<m_nFir<<m_nThd<<endl;
        cout<<"result:"<<m_nFir+m_nSec+m_nThd+m_nFor<<endl;
    }
private:
    int &m_nFor;
    int m_nSec;
    int m_nFir;
    int m_nThd;
};

int main()
{
    MyCls oCls;
    oCls.echo();

    return 0;
}
