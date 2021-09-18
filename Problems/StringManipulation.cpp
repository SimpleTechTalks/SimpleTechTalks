/********************************************************************************
 *
 * Find Minimum number of operations required to convert string1 to string2.
 * Only insert and delete character operations are allowed.
 * 
 ********************************************************************************/ 

#include <stdio.h>
#include <string.h>

int calculateWeight(char* s, char* t, int sIndex, int tIndex, int sLen, int tLen)
{
    int min = 0;

    if((sLen-1) < sIndex)
    {
       // we need to insert now
       min = (tLen - tIndex);
       //printf("inserting all now charcters %d \n", min);
       return (min < 0 ? 0 : min);
    }

    if((tLen-1) < tIndex)
    {
       // we need to delete now
       min = (sLen - sIndex);
       //printf("deleting all now charcters %d \n", min);
       return (min < 0 ? 0 : min);
    }

    if(s[sIndex] == t[tIndex])
    {
        // No weight added
        //printf("same character found %c %c\n", s[sIndex], t[tIndex]);
        min = calculateWeight(s, t, sIndex+1, tIndex+1, sLen, tLen);
        return min;
    }
    else
    {
        // insert char
        int temp1 = calculateWeight(s, t, sIndex, tIndex+1, sLen, tLen);

        // delete char
        int temp2 = calculateWeight(s, t, sIndex+1, tIndex, sLen, tLen);

        // find min weight
        if(temp1 < temp2)
        {
            //printf("Minimum weight is for insert %d \n", temp1);
            min = temp1;
        }
        else
        {
            //printf("Minimum weight is for delete %d \n", temp2);
            min = temp2;
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

   printf("Input string %s Target String %s\n", source, target);

   int sLen = strlen(source);
   int tLen = strlen(target);
   int weight = calculateWeight(source, target, 0, 0, sLen, tLen);
   printf("Final weight is %d \n", weight);
}

