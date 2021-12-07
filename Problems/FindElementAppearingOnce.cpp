#include <iostream>

/*
 * In a given array each element appears thrice except one which appears only once.
 * Find the element appearing once.
 */

int main()
{
    int B[] = {1,1,1,2,2,2,4,3,4,3,4,3,6,7,6,6};
    int    ones = 0 ;
    int    twos = 0 ;
    int not_threes;
    int x ;

   for(int i=0; i< (sizeof(B)/sizeof(B[0])); i++ )
   {
   		x =  B[i];
        twos |= ones & x ;
        ones ^= x ;
        not_threes = ~(ones & twos) ;
        ones &= not_threes ;
        twos &= not_threes ;
    }

    printf("\n unique element = %d \n", ones );
 
    return 0;

}