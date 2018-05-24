#include <iostream>  
#include <string>  
std::string res;  
std::string res1;
  
bool string_add(std::string a1, std::string a2)  
{
    if(a1[0] == '-' || a2[0] == '-'){
        return false;
    };
    int OneAdd = 0;
    int temp2  = 0;
    int temp   = 0;  
    int min    = a1.length()<a2.length() ? a1.length() : a2.length();
  
    for(int i=1; i<=min; i++)  
    {  
        OneAdd = (a1[a1.length() - i] - '0' + a2[a2.length() - i] - '0') + temp;  
        temp = OneAdd/10;           
        temp2 = OneAdd % 10;        
        res.push_back(temp2 + '0'); 
    }  
    while((int)a1.length() > min)  
    {  
        OneAdd = a1[a1.length()-1 - min] - '0' + temp;  
        temp = OneAdd/10;             
        temp2 = OneAdd % 10;  
        res.push_back( temp2 + '0' );  
        min++;  
    }  
    while((int)a2.length() > min)  
    {  
        OneAdd = a2[a2.length() - 1 - min] - '0' + temp;  
        temp = OneAdd / 10;  
        temp2 = OneAdd % 10;  
        res.push_back( temp2 + '0' );  
        min++;  
    }  
    for(int i=res.length()-1; i>=0 ;i--)  
    {  
        if(res[i] == ','){
            res[i] = '.';
        }
        res1.push_back(res[i]);
        //std::cout<<res[i];  
    }  
    return true;
}
int  main()  
{  
    std::string a1, a2;
    std::cin>>a1>>a2;
    string_add(a1, a2);
    std::cout<<res1<<std::endl;
    return 0;
} 
