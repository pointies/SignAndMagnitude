#include <stdio.h>

void padding(int *binary) {
    for (int i = 0; i < 4; i++)
        binary[i] = 0;
}

int StrToInt(char str[], int *isNegative) {
    int integer = 0, i = 0;
    *isNegative = 0;
    
    if (str[0] == '-')
        *isNegative = 1;

    if (str[0] == '-' || str[0] == '+')
        i = 1;
    
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        integer = (integer * 10) + (str[i++] - '0');
    
    return integer;
}
/* 
void print_array(int *binary, int bit) {
    
    for (int i = 0; i < bit; i++) {
        printf(",%d:%d,", i, binary[i]);
    }
    printf("\n");
}
*/
void printArray(char *binary, int bit) {
    printf("Sign and Magnitude: ");
    for (int i = 0; i < bit; i++) {
        printf("%d", binary[i]);
    }
    printf("\n\n");
}
/* 
void StrConcat(char *str1, char str2[], char *result) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        result[j++] = str1[i++];
    }
    
    i = 0;
    while (str2[i] != '\0') {
        result[j] = str2[i];
        i++;
        j++;
    }
    result[j] = '\0';
}
*/
void intToBinary(char *input, char *SignAndMag, int isNegative) {
    int integer = 0, i = 0, j = 0;
    int bin[4];
    padding(bin);
    integer = StrToInt(input, &isNegative);

    for (i = 0; integer > 0; i++) {
        bin[i] = integer % 2;
        integer /= 2;
    }
    
    bin[3] = isNegative ? 1 : 0;
    for (i = 3; i >= 0; i--)
        SignAndMag[j++] = bin[i];
    printArray(SignAndMag, j);
}

int main() {
    char input[100], SignAndMag[100];
    int isNegative = 0;

    printf("\n\nEnter number: ");
    scanf("%s", input);
    
    intToBinary(input, SignAndMag, isNegative);
    return 0;
}