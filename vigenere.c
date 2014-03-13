/*
*
*pset2, vigenere
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
    //Check for missing or multipart alpha keyword
    if(argc != 2)
    {
        printf("Vigenere usage: ./vigenere alpha-only keyword\n");
        return 1;
    }
    
    //Check for alpha-only keyword and convert upper case chars in keyword to lower case
    for(int x = 0, y = strlen(argv[1]); x < y; x++)
    {
        if(isalpha(argv[1][x]))
        {
        }
        else
        {
            printf("Vigenere usage: ./vigenere alpha-only keyword\n");
            return 1;
        }
        
        if(isupper(argv[1][x]))
        {
            argv[1][x] = tolower(argv[1][x]);
        }
    }

    string p = GetString(); //prompt user for plaintext
    string k = argv[1]; //set and initiate variable with key    
    int plen = strlen(p); //length of plaintext
    int klen = strlen(k); //length of key word
    int ki = 0; //key work index variable
    int counter = 0; //counter variable
    
    //set key word to loop, only over alpha chars
    for(int i = 0, j = plen; i < j; i++)
    {
        if(isalpha(p[i]))
        {
            ki = counter % klen;
            counter++;
        }
        
        int m = p[i]; //index of plaintext
        
        //begin writing cypertext of alpha only chars while maintaining case
        if(isalpha(m))
        {
            //If char is uppercase
            if(isupper(m))
            {
                printf("%c", ((m - 65) + (k[ki] - 97)) % 26 +65);
            }
            //Else if char is lowercase
            else if(islower(m))
            {
                printf("%c", ((m - 97) + (k[ki] - 97)) % 26 +97);
            }
        }
        //Else if char is non-alpha char
        else
        {
            printf("%c", m);
        }
    }
    printf("\n");   
}
