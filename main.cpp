#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "Linked_List.h"
#include "Sort.h"

int main()
{
    srand(time(NULL));

    int sizeA = rand() % 10 + 5; int sizeB = rand() % 10 + 5;

    int * A = (int*) malloc(sizeA * sizeof(int)); int * B = (int*) malloc(sizeB * sizeof(int));

    for (int i = -1; ++i < sizeA; A[i] = rand() % 100); for (int i = -1; ++i < sizeB; B[i] = rand() % 100 + 50);

    mySort(0, A, sizeA - 1); mySort(0, B, sizeB - 1); 

    printf("ArrayA: "); printArray(A, 0, sizeA - 1); printf("ArrayB: "); printArray(B, 0, sizeB - 1);

    node * a = NULL, * b = NULL; 

    for (int i = sizeA; --i >=0; insert(&a, newNode(A[i]))); for (int i = sizeB; --i >=0; insert(&b, newNode(B[i])));

    printf("ListA: "); printList(a); printf("ListB: "); printList(b); 

    node * r = merge(a, b);

    

    printf("ListA: "); printList(a); printf("ListB: "); printList(b); printf("ListR: "); printList(r); 


    return 0;
}