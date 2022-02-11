#include <stdio.h>
#include <stdlib.h>
#include "../Common/SimpleLinkedList.c"

int binaryDigitArrayToDecimal(int*, int);
int twoExp(int);

int main(void)
{
    char const filePath[] = "./D3_Input/D3_input.txt";
    char inputLine[255];
    int numDigits = 0;
    int numLines = 1;
    int ** numberArr;

    FILE* fp = fopen(filePath, "r");

    if(fp == NULL)
    {
        printf("Could not find input text file at location %s.", filePath);
        return -1;
    }

    // getting the length of the input line
    fgets(inputLine, sizeof(inputLine), fp);    
    for(numDigits=0; inputLine[numDigits] != '\n' && inputLine[numDigits] != '\0'; numDigits++);

    // getting the number of input lines
    while (fgets(inputLine, sizeof(inputLine), fp)) 
    {
        numLines++;
    }
    fclose(fp);

    numberArr = (int**)malloc(sizeof(int*)*(numLines));
    for(int i=0; i<numLines; i++)
    {
        numberArr[i] = (int*)malloc(sizeof(int)*(numDigits));
    }

    printf("Array is %dx%d\n", numLines, numDigits);

    fp = fopen(filePath, "r");
    int lineInd = 0;
    while (fgets(inputLine, sizeof(inputLine), fp) && lineInd<numLines) 
    {
        for(int i=0; inputLine[i] != '\0' && inputLine[i] != '\n'; i++)
        {
            int currDigit = inputLine[i] - 48;
            numberArr[lineInd][i] = currDigit == 1 ? 1 : -1;
        }
        lineInd++;
    }
    fclose(fp);

    print2DArray(numberArr, numLines, numDigits);
    printf("\n\n");

    int linesRemaining = numLines;
    while(linesRemaining > 1)
    {
        for(int i=0; i<numDigits; i++)
        {
            int colTally = 0;
            for(int j=0; j<numLines; j++)
            {
                colTally += numberArr[j][i];
            }

            int bitCriteria = colTally >= 0 ? 1 : -1;

            for(int j=0; j<numLines; j++)
            {
                if(numberArr[j][i] == bitCriteria)
                {
                    for(int ii=0; ii<numDigits; ii++)
                    {
                        numberArr[j][ii] = 0;
                    }
                    linesRemaining--;
                }
                if(linesRemaining <= 1)
                {
                    break;
                }
            }
        }
    }

    int resCarbon = -1;

    for(int i=0; i<numLines; i++)
    {
        if(numberArr[i][0] != 0)
        {
            resCarbon = binaryDigitArrayToDecimal(numberArr[i], numDigits);
        }
    }

    printf("resCarbon is %d\n", resCarbon);

    fp = fopen(filePath, "r");
    lineInd = 0;
    while (fgets(inputLine, sizeof(inputLine), fp) && lineInd<numLines) 
    {
        for(int i=0; inputLine[i] != '\0' && inputLine[i] != '\n'; i++)
        {
            int currDigit = inputLine[i] - 48;
            numberArr[lineInd][i] = currDigit == 1 ? 1 : -1;
        }
        lineInd++;
    }
    fclose(fp);

    print2DArray(numberArr, numLines, numDigits);

    linesRemaining = numLines;
    while(linesRemaining > 1)
    {
        for(int i=0; i<numDigits; i++)
        {
            int colTally = 0;
            for(int j=0; j<numLines; j++)
            {
                colTally += numberArr[j][i];
            }

            int bitCriteria = colTally >= 0 ? 1 : -1;

            for(int j=0; j<numLines; j++)
            {
                if(numberArr[j][i] == -1*bitCriteria)
                {
                    for(int ii=0; ii<numDigits; ii++)
                    {
                        numberArr[j][ii] = 0;
                    }
                    linesRemaining--;
                }
                if(linesRemaining<=1)
                {
                    break;
                }
            }
        }
    }

    int resOxygen = -1;

    for(int i=0; i<numLines; i++)
    {
        if(numberArr[i][0] != 0)
        {
            resOxygen = binaryDigitArrayToDecimal(numberArr[i], numDigits);
        }
    }

    print2DArray(numberArr, numLines, numDigits);
    printf("%d\n", resOxygen);

    printf("\n\n%d\n\n", resOxygen*resCarbon);

   

    // Freeing the numbers array.
    for(int i=0; i<numLines; i++)
    {
        free(numberArr[i]);
    }
    free(numberArr);

}

int print2DArray(int** arr, int nrow, int ncol)
{
    return 0;
    for(int i=0; i<nrow; i++)
    {
        for(int j=0; j<ncol; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
};

int bitsInListAtIndex(LinkedList* list, int index, int numDigits)
{
    LinkedList* temp = LLCopy(list);
    int holder = LLPop(temp);
    int score = 0;

    while(holder != -1)
    {
        int bitExtract = ((holder >> (numDigits - index - 1)) & 1);
        score += bitExtract == 1 ? 1 : -1;
        holder = LLPop(temp);
    }

    free(temp);

    return (score);
}

int binaryDigitArrayToDecimal(int* arr, int len)
{
    int sum = 0;

    for(int ind=0; ind<len; ind++)
    {
        int val = arr[ind] == 1 ? 1 : 0;
        sum += val * twoExp(len - 1 - ind);
    }
    return sum;

}

int twoExp(int exp)
{
    int res = 1;
    for(int i=0; i<exp; i++)
    {
        res *= 2;
    }
    return res;
}