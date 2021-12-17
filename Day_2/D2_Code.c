#include <stdio.h>
#include <stdlib.h>

int returnIndexOfFirstSpace(char []);

int main(void)
{
    char const filePath[] = "./D2_Input/D2_input.txt";
    char inputLine[255];

    FILE* fp = fopen(filePath, "r");

    if(fp == NULL)
    {
        printf("Could not find input text file at location %s.", filePath);
        return -1;
    }

    int depth = 0;
    int hPos = 0;
    int aim = 0;

    while (fgets(inputLine, sizeof(inputLine), fp)) 
    {
        int num = strtol(inputLine + getIndexOfFirstSpace(inputLine) + 1, NULL, 10);

        switch(inputLine[0])
        {
            case 'u':
                printf("Going up num: %d.\n", num);
                aim -= num;
                break;
            case 'd':
                printf("Going down num: %d.\n", num);
                aim += num;
                break;
            default:
                printf("Going forward num: %d.\n", num);
                hPos += num;
                depth += aim * num;
                break;
        }
    }

    int prod = depth * hPos;

    printf("\nOutput:\n");
    printf("The final depth is %d. The final horizontal position is %d. \nTheir product is %d.", depth, hPos, prod);

    fclose(fp);

    return 0;
}

int getIndexOfFirstSpace(char* str)
{
    int currInd = 0;

    while(str[currInd] != '\0')
    {
        if(str[currInd] == ' ')
        {
            return currInd;
        }
        currInd++;
    }

    return -1;
}