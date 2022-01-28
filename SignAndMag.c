#include<stdio.h>
 
int StrToInt(char str[], int *isNegative)
{
     int integer = 0, i = 0;
     /* for(i=0; input[i] != '\0'; i++)
          length++; */

     if(str[0] == '-')
          *isNegative = 1;   

     if(str[0] == '-' || str[0] == '+')
          i = 1;

     while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
     {
          integer = (integer * 10) + (str[i++] - '0');
     }
          
     return integer;
}

void StrConcat(char str1[], char str2[], char *result)
{
     int i = 0, j = 0;
     while (str1[i] != '\0') {
          result[j] = str1[i];
          i++;
          j++;
     }

     // Insert the second string in the new string
     i = 0;
     while (str2[i] != '\0') {
          result[j] = str2[i];
          i++;
          j++;
     }
     result[j] = '\0';
}

void intToBinary(char *input, char *SignAndMag)
{
     int integer, i = 0, j = 0;
     int *isNegative;
     char bin[100], binary[100];
     integer = StrToInt(input, isNegative);
     for(i=0; integer > 0; i++)
     {  
          bin[i] = integer % 2;
          integer = integer / 2;
     }
     
     for(i=i-1; i>=0; i--)
          binary[j] = bin[i];

     if(isNegative)
          StrConcat("1", binary, SignAndMag);
     else
          StrConcat("0", binary, SignAndMag);
}


int main()
{
     char input[100], SignAndMag[100];
     // char input[1000], binary[1000] = "";

     scanf("%[^\n]s", input);
     intToBinary(input, SignAndMag);

     printf("Sign and Magnitude: ");
     for(int i = 0; SignAndMag[i] != '\0'; i++)
          printf("%c", SignAndMag[i]);

     return 0;
}