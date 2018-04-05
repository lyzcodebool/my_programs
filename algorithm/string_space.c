#include <stdio.h>
#include <stdlib.h>

void trans_space(char *src, int length){
    if(src == NULL || length <= 0){
        return;
    }
    int true_length = 0;
    int space_count = 0;
    int i = 0;
    while(src[i] != '\0'){
        ++true_length;
        if(src[i] == ' '){
            ++space_count;
        }
        ++i;
    }
    int newlength = true_length + space_count*2;
    while(true_length >= 0 && newlength > true_length){
        if(src[true_length] != ' '){
        src[newlength --] = src[true_length];
        }
        else{
            src[newlength --] = '0';
            src[newlength --] = '2';
            src[newlength --] = '%';
        }
        --true_length;
    }

}


int main(void)
{
    char str[10] = "abs dsr";
    trans_space(str, 10);
    printf("%s\n", str);


    return 0;
}
