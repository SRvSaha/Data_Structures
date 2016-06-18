/*
 * @author     : SRvSaha
 * Filename    : binaryToDecimal.c
 * Timestamp   : 22:09 17-June-2016 (Friday)
 * Description : To find the equivalent binary representation of a decimal number.
 *
 */
#include <stdio.h>
int decimalToBinary(int number){
    int binary[8]; // Upto 8 bit only for simplicity purpose
    int output = 0;
    int i=1,j,quotient;
    quotient = number;
    while(quotient != 0)
    {
        binary[i++] = quotient % 2;
        quotient /= 2;
    }
    for(j = i-1; j>0; j--)
    {
        output = output*10 + binary[j];
    }
    return output;
}
int main(){
    int num1;
    scanf("%d",&num1);
    printf("%d\n",decimalToBinary(num1));
    return 0;
}
