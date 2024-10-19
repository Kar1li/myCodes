
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct NODE node;

node * newNode(int n);

int insert(node ** head, node * newNode);

node * merge(node * a, node * b);

int printList(node * head);