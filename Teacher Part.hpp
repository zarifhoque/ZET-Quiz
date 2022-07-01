#include <iostream>
#include <vector>
#include <fstream>
#include "DAM_Management.hpp"
#include <windows.h>
#include <filesystem>
#include <string>
#define MAXLEN_KEY 100
#define MAXLEN_FILENAME 100



using namespace std;

void TeacherMode();
void CreateQuestionPaper();
void ViewQuestions();
void checkTXT(string str);



void TeacherMode(void)
{
int choice;
while(1)
    {
//    cout<<"1.Create a Question Paper\n2.View all Questions in directory\n3.Exit\nEnter Choice:"<<endl;
cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
cout<<"  	 ****************************  |Teacher's Section|  ***************************"<<endl;
cout<<"-----------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;

cout<<"-----------------------------------------------"<<endl;
cout<<"1. Create a Question Paper"<<endl;
cout<<"2. View All the Questions in the Directory"<<endl;
cout<<"3. Exit"<<endl;
cout<<"----------------------------------------------"<<endl;

cout<<endl<<"Enter Choice: ";

    scanf("%d",&choice);
    system("cls");
    if(!(choice>=1 && choice<=3)){fflush(stdin);continue;}

    if(choice==1)
        {
        Sleep(500);
        CreateQuestionPaper();
        }
    else if(choice==2)
        {
        Sleep(500);
        ViewQuestions();
        }
    else if(choice==3)
        {
        Sleep(500);
        break;
        }


    }


}

void CreateQuestionPaper()
{
int choice;


vector<qus>paper;
vector<qus>paper_encrpyted;
while(1)
    {
   cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
   cout<<"  	 ****************************  |Question Creation|  ***************************"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;

   cout<<"-----------------------------------------------"<<endl;
   cout<<"1. Add a Question"<<endl;
   cout<<"2. Remove a Question"<<endl;
   cout<<"3. View All Questions so far"<<endl;
   cout<<"4. Finalise this paper"<<endl;
   //cout<<"5. Take qustions from a file"<<endl;
   cout<<"----------------------------------------------"<<endl;

   cout<<"Enter Choice: ";
    scanf("%d",&choice);
    system("cls");
    if(!(choice>=1 && choice<=5)){fflush(stdin);continue;}
    if(choice==1)
        {
        string question,options,answer;
        cout<<"Enter Question: ";
        fflush(stdin);
        getline(cin,question,'\n');
        cout<<"Enter Options: ";
        fflush(stdin);
        getline(cin,options,'\n');
        cout<<"Enter Answer: ";
        fflush(stdin);
        getline(cin,answer,'\n');
        AddToDAM(paper,question,options,answer);
        system("cls");
        }
    else if(choice==2)
        {
        int number;
        cout<<"Print the question you would like to remove: ";
        cin>>number;
        RemoveFromDAM(paper,number);
        system("cls");
        }
    else if(choice==3)
        {
        char ch;
        PrintDAM(paper);
        printf("Enter any key to continue..............");
        fflush(stdin);
        getchar();
        system("cls");

        }
    else if(choice==4)
        {
        string confirm;
        cout<<"Are you sure: (Y/N) ";
        cin>>confirm;
        system("cls");
        if(confirm=="Y")
            {
            char password[MAXLEN_KEY];
            fflush(stdin);
            cout<<"Enter the encryption key(use a single word and lowercase letters): ";
            scanf("%s",password);
            cout<<endl;

            char filename[MAXLEN_FILENAME];
            fflush(stdin);
            cout<<"Enter the filename of the question paper(include .txt and avoid multi-word name): ";
            scanf("%s",filename);
            cout<<endl;

            string email;
            fflush(stdin);
            cout<<"Enter the email of the teacher: ";
            cin>>email;
            cout<<endl;


            int selected_questions;
            fflush(stdin);

            do
                {
                cout<<"Enter how many questions will be selected: ";
                cin>>selected_questions;
                }
            while(selected_questions>paper.size());



            CreateEncryptedDAM(paper,paper_encrpyted,password);
            Serialisation(paper_encrpyted,filename,email,selected_questions);
            system("cls");
            break;

            }
        else if(choice==5)
        {
             ifstream fp;
            fp.open("question.txt");
    int i=0;
    while(fp.eof()==0)
    {    
        qus q;
        getline(fp,q.question);
        getline(fp,q.options);
        getline(fp,q.answer);
        paper.push_back(q);
    }
    fp.close();
        }
        else
            {
            continue;
            }



        }


    }




}

void ViewQuestions()
{
system("dir>NOT_AN_EXAM.txt");
std::string text;
ifstream fp;

cout<<"ALL THE TXT FILES IN THE DIRECTORY ARE: \n\n\n\n"<<endl;
    fp.open("NOT_AN_EXAM.txt");
    while(fp.eof()==0)
    {
        getline(fp,text);
        checkTXT(text);
    }

    fp.close();
    char ch;

    printf("\n\n\nEnter any key to continue..............");
    fflush(stdin);
    getchar();
    system("cls");
}

void checkTXT(string str)
{
int pos;
if(str.size()==0){return ;}
for(int x=0;x<str.size()-3;x++)
    {

    if(str[x]=='.' && str[x+1]=='t' && str[x+2]=='x' && str[x+3]=='t')
        {
        pos=x+3;
        x--;
        while(str[x]!=' '){x--;}
        for(int y=x;y<=pos;y++){cout<<str[y];}
        cout<<endl;
        break;
        }

    }

}
