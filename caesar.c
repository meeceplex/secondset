/*
*
*pset2, caeser
*
*by Chad M. Meece via edx
*
*meeceplex@live.com
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{  
    //Return 1 if user fails to provide input for key, otherwise set key. 
    if(argc != 2)
    {
        printf("\"Caeser\" usage: ./caesar key. Exiting program.\n");
        return 1;
    }
    //Get input string to encrypt.
    else
    {
        int key = atoi(argv[1]);
        string p = GetString();
                
        //Encrpyt string p (plaintext) using key.
        for(int i = 0, len = strlen(p); i < len; i++)
        {
            int m = p[i];
            //Verify char is apha char
            if(isalpha(m))
            {
                //If char is uppercase
                if(isupper(m))
                {
                    printf("%c", ((m -65) + key) % 26 +65);
                }
                //Else if char is lowercase
                else if(islower(m))
                {
                    printf("%c", ((m-97) + key) % 26 +97);
                }
            }
            //Else if char is non-alpha char
            else
            {
                printf("%c", m);
            }
        }
    }  
    printf("\n");   
}
