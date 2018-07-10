#include<iostream>
#include<string.h>

using namespace std;
class CMyString
{
public:
    CMyString(char *pData = NULL);
    CMyString(const CMyString& str);
    CMyString &operator = (const CMyString &r);
        
    ~CMyString(void);
private:
    char *pData;
};

CMyString &CMyString ::operator = (const CMyString &r)
{
    if(this == &r)
        return *this;
    delete []pData;
    pData = NULL;
    
    pData = new char[strlen(r.pData) + 1];
    strcpy(pData, r.pData);
    return *this;
}

int main()
{
    return 0;
}

