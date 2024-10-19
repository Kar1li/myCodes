#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct NODE {
    int val;
    struct NODE * next;
} node;

node * newNode(int n)
{
    node * new_node = (node *) malloc(sizeof(node));
    new_node->val = n; new_node->next = NULL;
    return new_node;
}

int insert(node ** head, node * newNode)
{
    newNode->next = *head;
    *head = newNode;
    return 0;
}

node * merge(node * a, node * b)
{
    if (a == NULL || b == NULL) return NULL;
    else
    {
        node * i, *j, *p = (a->val < b->val) ? a : b; node * r = p;
        i = p->next;
        j = (a->val < b->val) ? b : a;
        while (true)
        {
            if (i->val > j->val) {node * temp = i; i = j; j = temp;}
            p->next = i; p = i;
            if (i->next == NULL) {p->next=j;break;}
            else i = i->next;
        }
        return r;
    }   
    
}

int printList(node * head)
{
    if (head == NULL) return 0;
    node * i = head;
    while (true)
    {
        printf("%d ", i->val);
        if (i ->next == NULL) { printf("\n"); return 0;}
        i = i->next;
    }
}



