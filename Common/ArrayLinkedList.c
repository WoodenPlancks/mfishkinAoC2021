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

    prev->next = CreateLLNode(value);

    list->len++;
    return value;
}


// Delete a node with the *value* from the *list*.
int LLDelete(LinkedList* list, int value)
{
    LLNode* curr;
    LLNode* prev;

    // HEAD* --> [1] --> NULL

    if(list->head == NULL)
    {
        printf("ERROR: Can't delete value %d from an empty list!\n", value);
        return -1;
    }

    if(list->head->val == value)
    {
        list->head = list->head->next;
        list->len--;
        return value;
    }

    curr = list->head;
    prev = list->head;

    while(curr != NULL)
    {
        if(curr->val == value)
        {
            prev->next = curr->next;
            list->len--;
            return value;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Couldn't find value %d in the list.\n", value);
    return -1;
}

// Print the LinkedList - with some formatting!
int LLPrint(LinkedList* list)
{
    LLNode* curr;

    curr = list->head;

    printf("HEAD* --> ");

    while(curr != NULL)
    {
        printf("[%d] --> ", curr->val);
        curr = curr->next;
    }

    printf("NULL\n");
}