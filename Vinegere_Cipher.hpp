#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctype.h>

using namespace std;

//only works with no spaces in between
void VigenereCipher(string plaintext,char* ciphertext,char* keyword)
{
char* keyword_string=(char*)malloc( (plaintext.size())* sizeof(char)  +   1 );


for(int x=0;x<plaintext.size();x++)
    {
    keyword_string[x]=keyword[x%(strlen(keyword) ) ];
    }

    keyword_string[plaintext.size()]='\0';

    int count=0;
    for(int x=0;x<plaintext.size();x++)
        {
        if(  !(plaintext[x]>='a' && plaintext[x]<='z') && !(plaintext[x]>='A' && plaintext[x]<='Z') ) {ciphertext[x]=plaintext[x];continue;}
        ciphertext[x]=(   keyword_string[x] -97 +tolower(plaintext[x])  -97   )%26 + 97 ;
        count++;

        }

        ciphertext[plaintext.size()]='\0';

}




void DeVigenereCipher(string ciphertext,char* deciphertext,char* keyword)
{
char* keyword_string=(char*)malloc( (ciphertext.size())* sizeof(char)  +   1 );
int temp_1,temp_2;

for(int x=0;x<ciphertext.size();x++)
    {
    keyword_string[x]=keyword[x%(strlen(keyword))  ];
    }
    keyword_string[ciphertext.size()]='\0';

    for(int x=0;x<ciphertext.size();x++)
        {
        if(  !(ciphertext[x]>='a' && ciphertext[x]<='z')  ) {deciphertext[x]=ciphertext[x];continue;}
        temp_1=(keyword_string[x] -97);
        temp_2=(ciphertext[x]  -97);
         if(temp_1<temp_2)
            {
            deciphertext[x]=(   temp_2 -temp_1   )%26 + 97 ;

            }
         else if(temp_1>temp_2)
            {
            deciphertext[x]=26-(   temp_1 -temp_2   )%26 + 97 ;

            }
        else
            {
            deciphertext[x]='a';
            }



        }
    deciphertext[ciphertext.size()]='\0';
}


