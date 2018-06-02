#include <stdlib.h>
#include <stdio.h>
 #include <stdio.h>
#include<time.h>
 
 
 int count_ = 0;
 
 void output(int* arrayL, int len) {
     for (int i = 0; i != len; i++)
         printf("%d ", arrayL[i]);
     printf("\n");
 }
 
 void swap(int& a, int& b) {
     int temp = b;
     b = a;
     a = temp;
 }
bool isSwap(int* arrayL, int begin, int end) {
     for (int i = begin; i != end; i++)
         if (arrayL[i] == arrayL[end])
             return false;
 
     return true;
 }
 void fullPermutation(int *arrayL, int k, int len) {
     //k是开始的下标，len代表数组的长度
     if (k == len - 1) {
         output(arrayL, len);
         count_++;
     }
     else {
         for (int i = k; i != len; i++) {
             if (isSwap(arrayL, k, i)) {
                 swap(arrayL[i], arrayL[k]);
                 fullPermutation(arrayL, k + 1, len);
                 swap(arrayL[i], arrayL[k]);
             }
         }
     }
 } 
 /* void fullPermutation(int *arrayL, int k, int len) { */
 /*     //k是开始的下标，len代表数组的长度 */
 /*     if (k == len - 1) { */
 /*         output(arrayL, len); */
 /*         count_++; */
 /*     } */
 /*     else { */
 /*         for (int i = k; i != len; i++) { */
 /*             swap(arrayL[i], arrayL[k]); */
 /*             fullPermutation(arrayL, k + 1, len); */
 /*             swap(arrayL[i], arrayL[k]); */
 /*         } */
 /*     } */
 /* } */
 
 
 int main(int argc, char const *argv[])
 {
     int start = clock();
     {
         int lenOfArray;
         int *arrayL;
         printf("Enter the number lrngth of the array: ");
         scanf("%d", &lenOfArray);
 
         arrayL = (int *)malloc(sizeof(int)*lenOfArray);
         printf("Enter the elements of the array: ");
         for (int i = 0; i != lenOfArray; i++)
             scanf("%d", &arrayL[i]);
 
         fullPermutation(arrayL, 0, lenOfArray);
 
         printf("The total seq number is: %d\n", count_);
     }
     printf("The run time: %.3lfms\n",double(clock()-start)/CLOCKS_PER_SEC);
 
     return 0;
 }
