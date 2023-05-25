#include <stdio.h>
#include <string.h>
#include "kamran.h"
#include "pranesh.h"

int main() {
    printf("Welcome to Universal Cipher Decoder\n"); // Enter name of program

    int op = 0;
    printf("1. Polybius square cipher\n");
    printf("2. Vigenere cipher\n");
    printf("3.Atbash ciper\n);
           
    // Add your code here

    printf("Select one of the above number (for exiting press -1): ");
    scanf("%d", &op);

    printf("1. Encode\n2. Decode\nSelect one of the above: ");
    int met;
    scanf("%d", &met);

    switch (op) {
        case 1:
            if (met == 1) {
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                encryptPolybius(message);
                break;
            } else {
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                decryptPolybius(message);
                break;
            }

        case 2:
            if (met == 1) {
                char key[100];
                printf("Enter Key: ");
                scanf("%s", key);
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                vigenereEncrypt(message, key);
                printf("%s\n",message);
                break;
            } else {
                char key[100];
                printf("Enter Key: ");
                scanf("%s", key);
                printf("Enter Message: ");
                char message[100];
                scanf("%s", message);
                vigenereDecrypt(message, key);
                printf("%s\n",message);
                break;
            }
        case 3:{
            if(met==1){
            
    char message[1000];
    
    // for taking input from user in string  
    
    char ch;
    int count=0;
    while(ch!='\n')
    {
        scanf("%c",&ch);
        message[count]=ch;
        count ++;
    }
    message[count-1]='\0';
    
    
    printf("Original message: %s\n", message);
    
    // Apply the Atbash cipher
    atbashCipher(message);
    
    printf("Ciphered message: %s\n", message);
    
    break;
      }
        }
        default:
            printf("Invalid Choice!\n");
            break;
    }

    return 0;
}
