#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptPolybius(char *message) {
    char alphabet[6][6] = {
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X'},
        {'Y', 'Z', '0', '1', '2', '3'},
        {'4', '5', '6', '7', '8', '9'}
    };

    int i, j;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = toupper(message[i]);

        if (ch >= 'A' && ch <= 'Z') {
            for (j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    if (ch == alphabet[j][k]) {
                        printf("%d%d", j + 1, k + 1);
                        break;
                    }
                }
            }
        }
        else if (ch >= '0' && ch <= '9') {
            printf("%c", ch);
        }
        else {
            printf("%c", ch);
        }
    }
}

void decryptPolybius(char *message) {
    char alphabet[6][6] = {
        {'A', 'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P', 'Q', 'R'},
        {'S', 'T', 'U', 'V', 'W', 'X'},
        {'Y', 'Z', '0', '1', '2', '3'},
        {'4', '5', '6', '7', '8', '9'}
    };

    int i;
    int row, col;

    for (i = 0; message[i] != '\0'; i += 2) {
        if (isdigit(message[i]) && isdigit(message[i + 1])) {
            row = message[i] - '0' - 1;
            col = message[i + 1] - '0' - 1;

            if (row >= 0 && row < 6 && col >= 0 && col < 6) {
                printf("%c", alphabet[row][col]);
            }
            else {
                printf("%c%c", message[i], message[i + 1]);
            }
        }
        else {
            printf("%c%c", message[i], message[i + 1]);
        }
    }
}

void vigenereEncrypt(char *message, const char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int messageIndex = message[i] - base;
            int keyIndex = toupper(key[j]) - 'A';

            message[i] = (messageIndex + keyIndex) % 26 + base;
        }
    }
}

void vigenereDecrypt(char *message, const char *key) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int messageIndex = message[i] - base;
            int keyIndex = toupper(key[j]) - 'A';

            message[i] = (messageIndex - keyIndex + 26) % 26 + base;
        }
    }
}
