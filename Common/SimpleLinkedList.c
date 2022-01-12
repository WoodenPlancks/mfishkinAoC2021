#include<stdio.h>
#include<stdlib.h>


// --------- Data Structures --------- 
// Single-link node.
typedef struct 
{
    struct LLNode* next;
    int val;
} LLNode;


// The linkedlist itself is a head and a length.
typedef struct
{
    LLNode* head;
    int len;

} LinkedList;


// --------- Function Headers --------- 
int LLAdd(LinkedList*, int);

// --------- Functions --------- 
// Initialization function.
LinkedList* CreateLL(void)
{
    LinkedList* list;

    list = (LinkedList*) malloc(sizeof(LinkedList));
    list->len = 0;
    list->head = NULL;

    return list;
}


// Create a node. To be used in the LLAdd function to grow the list.
struct LLNode* CreateLLNode(int datum)
{
    LLNode* node;

    node = (LLNode*) malloc(sizeof(LLNode));
    node->next = NULL;
    node->val = datum;

    return node;
}


// Add a node with the *value* into the *list*.
int LLAdd(LinkedList* list, int value)
{
    LLNode* curr;
    LLNode* prev;

    if(list->len == 0)
    {
        list->head = CreateLLNode(value);
        list->len++;
        return value;
    }

    curr = list->head;
    prev = list->head;

    while(curr != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    printf("prev is %p\n", prev);
    printf("prev->next is %p\n", prev->next);
    printf("prev->val is %d\n", prev->val);
    prev->next = CreateLLNode(value);

    list->len++;
    return value;
}

int LLPrint(LinkedList* list)
{
    LLNode* curr;

    curr = list->head;

    printf("Printing linked list...\n");
    printf("[ HEAD ] --> ");

    while(curr != NULL)
    {
        printf("[ %d ] --> ", curr->val);
        curr = curr->next;
    }

    printf("NULL\n\n");
}