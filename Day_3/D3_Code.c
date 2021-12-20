#include<stdio.h>

int binaryDigitArrayToDecimal(int*, int);
int twoExp(int);

int main(void)
{
    char const filePath[] = "./D3_Input/D3_input.txt";
    char inputLine[255];
    int tally [255];
    int numDigits;

    int gammaRateDigits[255];
    int epsilonRateDigits[255];

    FILE* fp = fopen(filePath, "r");

    if(fp == NULL)
    {
        printf("Could not find input text file at location %s.", filePath);
        return -1;
    }

    fgets(inputLine, sizeof(inputLine), fp);    
    for(numDigits=0; inputLine[numDigits] != '\n' && inputLine[numDigits] != '\0'; numDigits++);

    for(int i=0; i<numDigits; i++)
    {
        tally[i] = 0;
    }

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
                
        }
    }

    for(int i=0; i<numDigits; i++)
    {
        gammaRateDigits[i] = tally[i] > 0 ? 1 : 0;
        epsilonRateDigits[i] = tally[i] > 0 ? 0 : 1;
    }

    int gammaRate = binaryDigitArrayToDecimal(gammaRateDigits, numDigits);
    int epsilonRate = binaryDigitArrayToDecimal(epsilonRateDigits, numDigits);

    int powerRate = gammaRate * epsilonRate;

    printf("The power rate of the submarine is %d.\n", powerRate);
    
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