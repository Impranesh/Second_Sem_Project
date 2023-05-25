#include <stdio.h>
#include <ctype.h>


char atbash(char ch)
{
    if (isalpha(ch))
    {
        // Determine the offset based on the case of the character
        int offset = isupper(ch) ? 'A' : 'a';
        
        // Apply the Atbash transformation
        return 'Z' - (ch - offset);
    }
    
    // Return the character as is if it's not a letter
    return ch;
}

void atbashCipher(char* message) 
{
    if (message == NULL)
    {
        printf("Invalid message.\n");
        return;
    }
    

    // Process each character in the message


    for (int i = 0; message[i] != '\0'; i++)
    {
        // Apply the Atbash cipher transformation

        message[i] = atbash(message[i]);
    }
}


