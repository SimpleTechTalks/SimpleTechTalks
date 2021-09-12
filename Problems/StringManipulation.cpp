#include <stdio.h>
#include <string.h>

int calculateWeight(char* s, char* t, int sIndex, int tIndex, int sLen, int tLen)
{
    int min = 0;

    if((sLen-1) < sIndex)
    {
       // we need to insert now
       min = (tLen - tIndex -1);
       printf("inserting all now charcters %d \n", min);
       return (min < 0 ? 0 : min);
    }

    if((tLen-1) < tIndex)
    {
       // we need to delete now
       min = (sLen - sIndex - 1);
       printf("deleting all now charcters %d \n", min);
       return (min < 0 ? 0 : min);
    }

    if(s[sIndex] == t[tIndex])
    {
        // No weight added
        printf("same character found %c %c\n", s[sIndex], t[tIndex]);
        min = calculateWeight(s, t, sIndex+1, tIndex+1, sLen, tLen);
        return min;
    }
    else
    {
        // insert char
        int temp1 = calculateWeight(s, t, sIndex, tIndex+1, sLen, tLen);

        // delete char
        int temp2 = calculateWeight(s, t, sIndex+1, tIndex, sLen, tLen);

        // replace char
        int temp3 = calculateWeight(s, t, sIndex+1, tIndex+1, sLen, tLen);

        // find min weight
        if(temp1 < temp2)
        {
            if(temp1 < temp3)
            {
                printf("Minimum weight is for insert %d \n", temp1);
                min = temp1;
            }
            else
            {
                printf("Minimum weight is for replace %d \n", temp3);
                min = temp3;
            }
        }
        else
        {
            if(temp2 < temp3)
            {
                printf("Minimum weight is for delete %d \n", temp2);
                min = temp2;
            }
            else
            {
                printf("Minimum weight is for replace %d \n", temp3);
                min = temp3;
            }
        }
    }
    return (min + 1);
}

int main()
{
   char source[30];
   char target[30];

   printf("Insert source string \n");
   scanf("%s", source);

   printf("Insert target string \n");
   scanf("%s", target);

   printf("Input string %s %s\n", source, target);

   int sLen = strlen(source);
   int tLen = strlen(target);
   int weight = calculateWeight(source, target, 0, 0, sLen, tLen);
   printf("Final weight is %d \n", weight);
}

