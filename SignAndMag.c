#include <stdio.h>

int StrToInt(char str[], int *isNegative) {
     int integer = 0, i = 0;

     if (str[0] == '-')
          *isNegative = 1;

     if (str[0] == '-' || str[0] == '+')
          i = 1;

     while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
          integer = (integer * 10) + (str[i++] - '0');
     }

     return integer;
}

void print_array(int *binary, int bit) {

     for (int i = 0; i < bit; i++) {
          printf("%d", binary[i]);
     }
     printf("\n");
}

void print_array_char(char *binary, int bit) {

     for (int i = 0; i < bit; i++) {
          printf("%d", binary[i]);
     }
     printf("\n");
}

void StrConcat(char *str1, char str2[], char *result) {
     int i = 0, j = 0;
     while (str1[i] != '\0') {
          result[j++] = str1[i++];
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

void intToBinary(char *input, char *SignAndMag) {
     int integer = 0, i = 0, j = 1;
     int *isNegative = 0;
     int bin[100];
     integer = StrToInt(input, isNegative);
     for (i = 0; integer > 0; i++) {
          bin[i] = integer % 2;
          integer /= 2;
     }

     SignAndMag[0] = isNegative ? 1 : 0;
     for (i = i - 1; i >= 0; i--)
          SignAndMag[j++] = bin[i];
     print_array_char(SignAndMag, j);
}

int main() {
     char input[100], SignAndMag[100];
     scanf("%[^\n]s", input);
     intToBinary(input, SignAndMag);
     return 0;
}
