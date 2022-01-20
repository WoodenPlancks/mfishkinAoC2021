#include <stdio.h>
#include <stdlib.h>
#include "../Common/SimpleLinkedList.c"

int binaryDigitArrayToDecimal(int*, int);
int twoExp(int);

int main(void)
{
    char const filePath[] = "./D3_Input/D3_input.txt";
    char inputLine[255];
    int tally [255];
    int oxyGenTally [255];
    int carScrTally [255];
    int currNum[255];
    int numDigits;

    int gammaRateDigits[255];
    int epsilonRateDigits[255];

    LinkedList* oxyGenRatingList = CreateLL();
    LinkedList* carScrRatingList = CreateLL();

    FILE* fp = fopen(filePath, "r");

    if(fp == NULL)
    {
        printf("Could not find input text file at location %s.", filePath);
        return -1;
    }

    // getting the length of the input line

    fgets(inputLine, sizeof(inputLine), fp);    
    for(numDigits=0; inputLine[numDigits] != '\n' && inputLine[numDigits] != '\0'; numDigits++);

    for(int i=0; i<numDigits; i++)
    {
        tally[i] = 0;
    }

    fclose(fp);

    fp = fopen(filePath, "r");

    while (fgets(inputLine, sizeof(inputLine), fp)) 
    {
        for(int i=0; inputLine[i] != '\0' && inputLine[i] != '\n'; i++)
        {
            int currDigit = inputLine[i] - 48;
            if(currDigit == 1)
            {
                tally[i]++;
            }
            else
            {
                tally[i]--;
            }
            currNum[i] = currDigit;
        }

        LLAdd(oxyGenRatingList, binaryDigitArrayToDecimal(currNum, numDigits));
        LLAdd(carScrRatingList, binaryDigitArrayToDecimal(currNum, numDigits));
    }

    for(int i=0; i<numDigits; i++)
    {
        gammaRateDigits[i] = tally[i] >= 0 ? 1 : 0;
        epsilonRateDigits[i] = tally[i] >= 0 ? 0 : 1;
    }

    int gammaRate = binaryDigitArrayToDecimal(gammaRateDigits, numDigits);
    int epsilonRate = binaryDigitArrayToDecimal(epsilonRateDigits, numDigits);

    int powerRate = gammaRate * epsilonRate;

    printf("The power rate of the submarine is %d.\n", powerRate);

    fclose(fp);

    for(int i=0; i<numDigits; i++)
    {
        oxyGenTally[i] = tally[i];
        carScrTally[i] = tally[i];
    }

    int addBack = 0;

    for(int bitCriteriaInd=0; bitCriteriaInd<numDigits && oxyGenRatingList->len > 1; bitCriteriaInd++)
    {
        int bitCriterion = oxyGenTally[bitCriteriaInd] > 0 ? 1 : 0;
        int exp = numDigits - bitCriteriaInd - 1;
        int thres = twoExp(exp);
        
        int ret = bitCriterion == 1 ? LLDeleteFirstLT(oxyGenRatingList, thres) : LLDeleteFirstGT(oxyGenRatingList, thres);
        int listDecr = bitCriterion == 0 ? 0 : thres;
        addBack += listDecr;
        while(ret != -1 && oxyGenRatingList->len>1)
        {
            for(int i=0; i<numDigits; i++)
            {
                oxyGenTally[numDigits - 1 - i] += ((ret>>i)&1) == 1 ? -1 : 1;
            }
            ret = bitCriterion == 1 ? LLDeleteFirstLT(oxyGenRatingList, thres) : LLDeleteFirstGT(oxyGenRatingList, thres);
        }
        LLSubtractFromAll(oxyGenRatingList, listDecr);
    }
    LLAddToAll(oxyGenRatingList, addBack);

    addBack = 0;

    for(int bitCriteriaInd=0; bitCriteriaInd<numDigits && carScrRatingList->len > 1; bitCriteriaInd++)
    {
        int bitCriterion = carScrTally[bitCriteriaInd] >= 0 ? 1 : 0;
        int exp = numDigits - bitCriteriaInd - 1;
        int thres = twoExp(exp);
        
        int ret = bitCriterion == 0 ? LLDeleteFirstLT(carScrRatingList, thres) : LLDeleteFirstGT(carScrRatingList, thres);
        int listDecr = bitCriterion == 0 ? 0 : thres;
        addBack += listDecr;
        while(ret != -1 && carScrRatingList->len>1)
        {
            for(int i=0; i<numDigits; i++)
            {
                carScrTally[numDigits - 1 - i] += ((ret>>i)&1) == 1 ? -1 : 1;
            }
            ret = bitCriterion == 0 ? LLDeleteFirstLT(carScrRatingList, thres) : LLDeleteFirstGT(carScrRatingList, thres);
        }
        LLSubtractFromAll(carScrRatingList, listDecr);
    }
    LLAddToAll(carScrRatingList, addBack);

    int oxygenGeneratorRating = LLDeleteFirstGT(oxyGenRatingList, -1);
    int carbonScrubbingRating = LLDeleteFirstGT(carScrRatingList, -1);
    int lifeSupportRating = oxygenGeneratorRating * carbonScrubbingRating;

    printf("The oxygen generator rating of the submarine is %d.\n", oxygenGeneratorRating);
    printf("The carbon scrubbing rating of the submarine is %d.\n", carbonScrubbingRating);
    printf("The life support rating of the submarine is %d.\n", lifeSupportRating);
}

int binaryDigitArrayToDecimal(int* arr, int len)
{
    int sum = 0;

    for(int ind=len-1; ind>-1; ind--)
    {
        sum += arr[ind] * twoExp(len - 1 - ind);
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