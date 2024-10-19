#include <iostream>
#include <string>
#include <stdio.h>
// #include <math.h>
// #include <string.h>
#include <stdlib.h>
#include <set>
#include <time.h>
#include <algorithm>


using namespace std;



int swap(int * a, int * b){ 
    int temp = *a; *a = *b; *b = temp; 
    return 0;
}

int printArray(int * A, int from, int to){
    for (int i = from - 1; ++i <= to; printf("%d ", A[i]));
    printf("\n");
    return 0;
}

int mySort(int k, int * A, int n)
{
    if (n - k <= 0) return 0;
    int med = A[n], push = n;
    int i = k, j = n;
    while (true)
    {
        if (i == j) break;
        if (A[i] > med)
        {
            while (true)
            {
                if (i == j) break;
                if (A[j] < med)
                {
                    swap(&(A[i]), &(A[j])); break;
                }
                else
                {
                    --j;
                }
            }
        }
        else 
        {
            ++i;
        }
    }
    if (i == k) {swap(&(A[i]), &(A[n])); mySort(1 + i, A, n); }
    else if (i - 1 == n) {swap(&(A[i]), &(A[n])); mySort(k, A, i - 2);}
    else {mySort(k, A, i - 1); mySort(i, A, n);}
}

int inspect(int * A, int size, int k) { for (int i = size - k - 1; ++i < size; swap(&(A[i]), &(A[i - size + k]))); return 0; }

int reOrder( int * A, int n) 
{
    int p = 0, q = n - 1, u = A[0];
    while (q - p > 1) 
    {
        int t = (p + q) / 2;
        if (A[t] >= u){
            p = t;
        } else q = t;
        
    }
    return p;
}


