#include<stdio.h>
#include "SimpleLinkedList.c"

int main(void)
{
    int ret = 0;
    LinkedList* myLinkedList = CreateLL();
    LLPrint(myLinkedList);
    ret = LLAdd(myLinkedList, 1);
    printf("ret is %d.\n", ret);
    LLAdd(myLinkedList, 2);
    LLAdd(myLinkedList, 3);
    LLPrint(myLinkedList);
    return 0;
}