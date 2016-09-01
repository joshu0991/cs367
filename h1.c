// Joshua Lilly
// CS 367
// Homework 1
// 8/30/2016

#include <stdio.h>
#include <stdlib.h>

void swap (int* p_kArray, int index1, int index2)
{
    while (index1 >= 0 && p_kArray[index2] < p_kArray[index1])
    {
        int temp = p_kArray[index2];
        p_kArray[index2--] = p_kArray[index1];
        p_kArray[index1--] = temp;   
    }
}

int getKthValue(const int* const p_orgArray, const int p_size, const int p_k)
{
    int* kthArray = malloc(p_k * sizeof(int));

    unsigned i;
    for (i = 0; i < p_size; ++i)
    {
       // get the next value from the array.
       int val = p_orgArray[i];
       
       // we need to fill up the k array which
       // is always possible since n > k
       if (i < p_k)
       {
           kthArray[i] = val;
           
           // swap the value down to its position.
           swap(kthArray, i-1, i);
       }
       else
       {
           // if we are here we know the array is full 
           // and that if the element at index k-1 > val
           // element k-1 will be pushed off the end since
           // the array is sorted in asending order.
           
           // if the value is less than the current kth value
           if (val < kthArray[p_k-1])
           {
               // just insert at the end since k will be
               // pushed off the end of the array .
               kthArray[p_k-1] = val;
 
               // just swap the index into it's new position.
               swap(kthArray, p_k-2, p_k-1);
           }
       }
    }

    // one indexed
    int k = kthArray[p_k-1];
    free(kthArray);
    return k;
} 

int main()
{
    // the number to find
    int k = 0;

    // the number of integers to read.
    int n = 0;

    scanf("%d", &k);
    scanf("%d", &n);

    int* numsRead = malloc(n * sizeof(int));

    if (n <= 0)
    {
        printf("Bad size!\n");
        return 1;
    }

    if (k <= 0 || k > n)
    {
        printf("Bad index!\n");
        return 1;
    }

    if (k > n)
    {
        printf("Bad index!\n");
        return 1;
    }

    // read in the variables.
    int counter = 0;
    while (counter < n)
    {
        scanf("%d", &numsRead[counter++]);
    }
 
    // find the kth smallest from the given data.
    int kthValue = getKthValue(numsRead, n, k);
    printf("The %dst/rd/th smallest element is: %d\n", k, kthValue);
    free(numsRead);
    return 0;
}
