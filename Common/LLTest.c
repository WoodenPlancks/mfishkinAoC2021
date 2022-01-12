#include<stdio.h>
#include "SimpleLinkedList.c"

int main(void)
{
    int ret = 0;

    LinkedList* myLinkedList = CreateLL();
    LLPrint(myLinkedList);

    ret = LLAdd(myLinkedList, 1);
    LLAdd(myLinkedList, 2);
    LLAdd(myLinkedList, 3);
    LLPrint(myLinkedList);

    LLDelete(myLinkedList, 2);
    LLPrint(myLinkedList);

    LLDelete(myLinkedList, 4);
    LLPrint(myLinkedList);

    LLDelete(myLinkedList, 3);
    LLPrint(myLinkedList);

    LLDelete(myLinkedList, 1);
    LLPrint(myLinkedList);

    LLDelete(myLinkedList, 1);
    LLPrint(myLinkedList);


    return 0;
}