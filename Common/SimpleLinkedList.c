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

    if(list->head == NULL)
    {
        printf("ERROR: Can't delete value %d from an empty list!\n", value);
        return -1;
    }

    if(list->head->val == value)
    {
        list->head = list->head->next;
        list->len--;
        return curr->val;
    }

    curr = list->head;
    prev = list->head;

    while(curr != NULL)
    {
        if(curr->val == value)
        {
            prev->next = curr->next;
            list->len--;
            return curr->val;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Couldn't find value %d in the list.\n", value);
    return -1;
}

int LLDeleteFirstGT(LinkedList* list, int value)
{
    LLNode* curr;
    LLNode* prev;

    if(list->head == NULL)
    {
        printf("ERROR: Can't delete value %d from an empty list!\n", value);
        return -1;
    }

    if(list->head->val > value)
    {
        int headVal = list->head->val;
        list->head = list->head->next;
        list->len--;
        return headVal;
    }

    curr = list->head;
    prev = list->head;

    while(curr != NULL)
    {
        if(curr->val > value)
        {
            prev->next = curr->next;
            list->len--;
            return curr->val;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Couldn't find values greater than %d in the list.\n", value);
    return -1;
}


int LLDeleteFirstLT(LinkedList* list, int value)
{
    LLNode* curr;
    LLNode* prev;

    if(list->head == NULL)
    {
        printf("ERROR: Can't delete value %d from an empty list!\n", value);
        return -1;
    }

    if(list->head->val < value)
    {
        int headVal = list->head->val;
        list->head = list->head->next;
        list->len--;
        return headVal;
    }

    curr = list->head;
    prev = list->head;

    while(curr != NULL)
    {
        if(curr->val < value)
        {
            int currVal = curr->val;
            prev->next = curr->next;
            list->len--;
            return currVal;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Couldn't find values lesser than %d in the list.\n", value);
    return -1;
}

int LLSubtractFromAll(LinkedList* list, int subtractor)
{
    LLNode* curr;

    curr = list->head;

    while(curr != NULL)
    {
        curr->val -= subtractor;
        curr = curr->next;
    }

    return 0;

}


int LLAddToAll(LinkedList* list, int addition)
{
    LLNode* curr;

    curr = list->head;

    while(curr != NULL)
    {
        curr->val += addition;
        curr = curr->next;
    }

    return 0;

}

int LLPop(LinkedList* list)
{
    if(list == NULL)
    {
        printf("Cannot pop: invalid LinkedList.\n");
        return -1;
    }
    LLNode* curr;
    curr = list->head;

    if(list->head == NULL)
    {
        printf("Cannot pop from empty LinkedList.\n");
        return -1;
    }

    return LLDeleteFirstGT(list, -1);

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