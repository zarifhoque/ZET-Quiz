#include <iostream>
#include <vector>
#include <fstream>
#include "Vinegere_Cipher.hpp"
#include "question_struct.hpp"

using namespace std;




void AddToDAM(vector<qus>&script,string question,string options,string answer)
{
qus temp={question,options,answer};
script.push_back(temp);

}

void RemoveFromDAM(vector<qus>&script,int position)
{
if(position-1>script.size()){return ;}
script.erase(script.begin()+position-1);

}


void PrintDAM(vector<qus>&script)
{
for(int x=0;x<script.size();x++)
    {

    cout<<script[x].question<<endl;
    cout<<script[x].options<<endl;
    cout<<script[x].answer<<endl<<endl;
    }

}

void Serialisation(vector<qus>&script,string filename,string email,int selection_questions)
{


ofstream fp(filename);

    fp<<email<<endl;
    fp<<selection_questions<<endl;
for(int x=0;x<script.size();x++)
    {
    fp<<script[x].question<<endl;
    fp<<script[x].options<<endl;
    fp<<script[x].answer<<endl;


    }

fp.close();


}

void CreateEncryptedDAM(vector<qus>&script,vector<qus>&script_encrpyted,char* key)
{
qus temp_qus;
char temp_cipher_1[100];
char temp_cipher_2[100];
char temp_cipher_3[100];

for(int x=0;x<script.size();x++)
    {
    VigenereCipher(script[x].question,temp_cipher_1,key);

    VigenereCipher(script[x].options,temp_cipher_2,key);
    VigenereCipher(script[x].answer,temp_cipher_3,key);

    temp_qus.question=temp_cipher_1;
    temp_qus.options=temp_cipher_2;
    temp_qus.answer=temp_cipher_3;

    script_encrpyted.push_back(temp_qus);
    }



}



void Deserialisation(vector<qus>&script,char* filename,string* p_email,int* p_seleted_questions)
{
 ifstream fp;
 qus temp;
 string temp_string,temp_string_2;
 int temp_int;


    fp.open(filename);
    getline(fp,temp_string);
    *p_email=temp_string;
    fp>>temp_int;
    *p_seleted_questions=temp_int;
    getline(fp,temp_string_2,'\n');


    while(1)
    {

        getline(fp,temp.question,'\n');
        getline(fp,temp.options,'\n');
        getline(fp,temp.answer,'\n');
        if(fp.eof()!=0)
           {break;}
        script.push_back(temp);
    }

    fp.close();
}




void CreateDecryptedDAM(vector<qus>&script,vector<qus>&script_decrypted,char* key)
{

qus temp_qus;
char temp_cipher_1[100];
char temp_cipher_2[100];
char temp_cipher_3[100];


for(int x=0;x<script.size();x++)
    {
    DeVigenereCipher(script[x].question,temp_cipher_1,key);

    DeVigenereCipher(script[x].options,temp_cipher_2,key);
    DeVigenereCipher(script[x].answer,temp_cipher_3,key);

    temp_qus.question=temp_cipher_1;
    temp_qus.options=temp_cipher_2;
    temp_qus.answer=temp_cipher_3;

    script_decrypted.push_back(temp_qus);
    }





}


void CreateRandomizedDAM(vector<qus>&script,vector<qus>&script_random,int* arr_selected_bool,int no_of_questions_available)
{
for(int x=0;x<no_of_questions_available;x++)
    {
    if(arr_selected_bool[x]==1)
        {
        script_random.push_back(script[x]);
        }
    }



}


void RandomGenerate(int no_of_questions_available,int no_of_questions_selected,int* arr_selected_bool)
{

srand(time(NULL));
for(int x=0;x<no_of_questions_selected;x++)//loops through at least 30 times
    {
    int temp=rand()%no_of_questions_available;//calculates a random value in the range
    if(arr_selected_bool[temp]==0)
        {
        arr_selected_bool[temp]=1;
        }
    else
        {
        x--;
        }

    }





}
