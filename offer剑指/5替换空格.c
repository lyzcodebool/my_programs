#include <stdio.h>
/* length是字符数组string的总容量 */
void ReplaceBlank(char string[], int length)
{
    if(string == NULL || length < 0)
        return ;
    /* orginalLength是字符串string的实际长度 */
    int orginalLength = 0;
    int numOfBlank = 0;
    int i = 0;
    while(string[i] != '\0')
    {
        ++orginalLength;
        if(string[i] == ' ')
            ++numOfBlank;
        ++i;
    }

    /* new为把空格替换成%20之后的长度 */
    int newLength = orginalLength + numOfBlank * 2;
    if(newLength > length)
        return;
    int indedxOfOrginal = orginalLength;
    int indexOfNew = newLength;
    while(indedxOfOrginal >= 0 && indexOfNew > indedxOfOrginal)
    {
        if(string[indedxOfOrginal] == ' '){
            string[indexOfNew] = '0';
            string[--indexOfNew] = '2';
            string[--indexOfNew] = '%';
        }else{
            string[indexOfNew] = string[indedxOfOrginal];
        }
        --indexOfNew;
        --indedxOfOrginal;
    }

}
int main()
{
}

