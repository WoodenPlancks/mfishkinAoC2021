#include<stdio.h>

int main(void)
{
    FILE* fp;

    int const windowSize = 3;
    char const filePath[] = "./D1_Input/D1_input.txt";

    int window[windowSize+1];

    int leadingNumInd = 0;
    int currNum=0;
    int incrCount = 0;

    fp = fopen(filePath, "r");

    if(fp == NULL)
    {
        printf("Could not find input text file at location %s.", filePath);
        return -1;
    }

    for(int i=0; i<windowSize+1; i++)
    {
        fscanf(fp, "%d", &currNum);

        window[i] = currNum;

        if(currNum == -1)
        {
            printf("Reached the end of the file before the initial window initialized. Make sure your input has more than %d entries.\n", windowSize+1);
            return 0;
        }
    }

    while(1)
    {
        
        fscanf(fp, "%d", &currNum);

        int leadingNum = window[leadingNumInd];
        int closingNum = window[(leadingNumInd+windowSize)%(windowSize+1)];

        if(closingNum > leadingNum)
        {
            incrCount ++;
        }

        window[leadingNumInd] = currNum;
        leadingNumInd = (leadingNumInd+1)%(windowSize+1);

        if(currNum == -1) 
        {
            printf("Reached the end of the file.\n");
            fclose(fp);
            printf("The depth increases %d times with a window of size %d.\n", incrCount, windowSize);
            return 0;
        }
    }
    

    return 0;
}