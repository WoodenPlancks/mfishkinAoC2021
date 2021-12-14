#include<stdio.h>

int main(void)
{
    FILE* fp;
    int prev = 0;
    int curr = 0;
    int incrCount = -1;

    char filePath[] = "./D1_Input/D1_input.txt";

    fp = fopen(filePath, "r");

    if(fp == NULL)
    {
        printf("Could not find input text file at location %s.", filePath);
        return -1;
    }

    while(curr != -1)
    {
        fscanf(fp, "%d", &curr);
        if(curr > prev)
        {
            incrCount++;
        }
        printf("%d, %d\n", prev, curr);
        prev = curr;
    }
    
    fclose(fp);

    printf("The depth increases %d times.", incrCount);
    return 0;
}