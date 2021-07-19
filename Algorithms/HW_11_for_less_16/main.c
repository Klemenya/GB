#include <stdio.h>
#include <stdlib.h>


void clearArr(char* str) {
    for(int i = 0; i < 100; i++) {
        str[i] = 0;
    }
}

char* encCaesar(char* string, int key) {
    int i = 0;

    while(string[i] > 0) {
        char temp = string[i] + (char)key;
        if (temp > 122) {
            string[i] = 96 + (temp % 122);
            i++;
        } else if (string[i] <= 90 && temp > 90) {
            string[i] = 64 + (temp % 90);
            i++;
        } else {
            string[i] = temp;
            i++;
        }
    }
    return string;
}

char* decCaesar(char* string, int key) {
    int i = 0;
    while(string[i] > 0) {
        char temp = string[i] - (char)key;
        if (temp < 65) {
            string[i] = 90 - (key - string[i] % 65 - 1);
            i++;
        } else if (string[i] >= 97 && string[i] <= 122 && temp < 97) {
            string[i] = 122 - (key - string[i] % 97 - 1);
            i++;
        } else {
          string[i] = temp;
          i++;
        }
    }
    return string;
}


void Caesar() {
    char mas[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key = 4;
    printf("---   HW 16 task 1   ---\n         Caesar \n");
    printf("------------------------");
    printf("\n%s - Original message", mas);
    printf("\n%s - Caesar encryption", encCaesar(mas, key));
    printf("\n%s - Caesar decryption", decCaesar(mas, key));
}


char result[100];
char forDecrypt[100];

char* encrypt(char* str, int key, int size) {
    clearArr(result);
    int columns = (size % key == 0) ? size / key : size / key + 1;
    int i = 0;
    while(str[i] > 0) {
        int posY = i / key;
        int posX = i % key;
        int index = posX * columns + posY;
        result[index] = str[i++];
    }
    return result;
}

char* decrypt(char* str, int key, int size) {
    char res[100];
    clearArr(res);
    int i = 0;
    int columns = (size % key == 0) ? size / key : size / key + 1;
    while(str[i] > 0) {
        int posY = i / columns;
        int posX = i % columns;
        int index = posX * key + posY;
        res[index] = result[i++];
    }
    printf("\n%s - permutation decryption\n", res);
    return res;
}

int stringSize(char* str) {
    int size = 0;
    while(str[size] > 0) {
        size++;
    }
    return size;
}

void permutationCrypt() {
    char input[100] = "abcdefghijklmnopqrst";
    int key = 4;
    int size = stringSize(input);

    printf("\n\n---   HW 16 task 2   ---\n");
    printf("      Permutation\n");
    printf("------------------------\n");
    printf("%s - Original message", input);
    printf("\n%s - permutation encryption", encrypt(input, key, size));
    decrypt(result, key, size);
}


int main()
{
    Caesar();
    permutationCrypt();
    return 0;
}
