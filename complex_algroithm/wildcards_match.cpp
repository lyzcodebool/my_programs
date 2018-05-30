#include <iostream>
#include <string.h>
#include <stdlib.h>

//带通配符的字符串匹配
//动态规划

using namespace std;

bool  wildcards_match(const char *str, const char *strpattern)
{
    int nStr = strlen(str);
    int nPatt = strlen(strpattern);
    int **pTable = new int *[nStr + 1];
    for(int k = 0; k  <= nStr; k++){               //二维数组
        pTable[k] = new int [nPatt + 1];
        memset(pTable[k], 0, (nPatt + 1)*sizeof(int));
    }

    //边界问题
    if(strpattern[0] == '*'){
        for(int i = 0; i < nPatt; ++i){
            pTable[0][i] = true;
        }
    }
    pTable[0][0] = true;
    for(int j = 1; j <= nPatt; ++j){
        for(int i = 1; i <= nStr; ++i){
            if((strpattern[j - 1] == '?' && str[i - 1] != '\0') || strpattern[j-1] == str[i-1]){
                pTable[i][j] = pTable[i-1][j-1];
            }else if(strpattern[j-1] == '*'){
                if(pTable[i][j-1] == true || pTable[i-1][j] == true || pTable[i-1][j-1] == true){
                    pTable[i][j] = true;
                }
            }
        }
    }
    bool ret = (pTable[nStr][nPatt] == true? true:false);
    for(int i = 0; i <= nStr; ++i)
        delete []pTable[i];
    delete []pTable;

    return ret;
}


int main(int argc, char **argv)
{
    /* if(argc < 3){ */
    /*     cout<<"please input two stringi"<<endl; */
    /*     exit(1); */
    /* } */
    
    /* if(wildcards_match(argv[1], argv[2])) */
    /*     cout<<argv[1]<<"  and  "<<argv[2]<<"  matched  "<<endl; */
    /* else */
    /*     cout<<argv[1]<<"  and  "<<argv[2]<<"  unmatched  "<<endl; */

    char *str1 = "abc";
    char *str2 = "*";
    char *str3 = "?bc";
    char *str4 = "a?c";
    char *str5 = "a*";
    if(wildcards_match(str1, str2))
        cout<<str1<<"  and  "<<str5<<"  matched  "<<endl;
    else
        cout<<str1<<"  and  "<<str5<<"  unmatched  "<<endl;
    return  0;
}
