#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<bits/stdc++.h>
#include "Teacher part.hpp"
#include "Student Part.hpp"


using namespace std;


COORD coord = {0, 0};


void gotoxy (int x, int y)//Moves the cursor to the specified location for printing
{
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void designing(char *val)//Design function to be called at the beginning
{

    int i=0,j;

    gotoxy(04,0);

    for(j=0;j<20;j++)
    {
        Sleep(20);
        printf("*");
    }

    for(j=0;j<20;j++)
    {
        Sleep(20);
        printf("%c",val[j]);
    }

    for(j=0;j<20;j++)
    {
        Sleep(20);
        printf("*");
    }
}


void login(int *option1)//Login subroutine for teacher
{

  int a=0,i=0;
    char uname[15];
    char c;
    char pword[15],code[15];
    char user[15]="user2020";//hardcoded username
    char pass[15]="pass2020";//hardcoded password
    system("cls");
    char t[25]="TEACHER LOGIN";
    designing(t);
    do
    {
       if(a!=0)
       {
           cout<<"    ********************TEACHER LOGIN********************";
       }
       fflush(stdin);
       printf("\n\nENTER USERNAME:-");
     scanf("%s",uname);
     printf("\nENTER PASSWORD:-");

     while(i<15)
     {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;

          if((int)c>31 &&(int)c<127)
            {
                printf("*");
              i++;
          }

          if(c==8 &&i>0)
            {
               i--;
               printf("\b \b");
          }

        }


      pword[i]='\0';
      //char code=pword;
      i=0;
      //scanf("%s",&pword);
    if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)//if successful
      {       system("COLOR 0D");
          printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
          Beep(800,100);
          Beep(900,100);
          Beep(1000,100);
            Sleep(2000);

          break;
      }
      else//if not successful
      {
        printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
        Beep(800,100);
        Beep(700,100);
        Beep(600,100);
        a++;
            char press;
            cout<<"\nPress Any key to countinue or '0' go to the home page......\n";
            cin>>press;
            if(press=='0')
            {
                *option1=0;
                break;

            }


        }
        system("cls");
    }while(a<=3);


  if (a>3)//This sends you back if wrong password is entered more than 3 times
  {
      printf("\nSorry you have entered the wrong username and password for four times!!!\n");
        printf("Taking you back to the home page then try again with correct pass and user id....");
    getch();
        *option1=0;
  }

    system("cls");

}

void printer(void)//More Designing Functions
{

printf("\n");
  printf("|                                                                  |\n");
  printf("|                *******   *******    *******                      |\n");
  printf("|                     *    *             *                         |\n");
  printf("|                   *      *******       *                         |\n");
  printf("|                 *        *             *                         |\n");
  printf("|                ******    *******       *                         |\n");
  printf("|                                                                  |\n");
  printf("|          *******   *     *    *******    *******                 |\n");
  printf("|          *     *   *     *       *            *                  |\n");
  printf("|          *     *   *     *       *          *                    |\n");
  printf("|          *   * *   *     *       *        *                      |\n");
  printf("|          *******   *******    *******    *******                 |\n");
  printf("|                 **                                               |\n");
 printf("|                    *                                             |\n");
  printf(" -------------------------------------------------------------------\n");
  Sleep(2000);
  system("cls");
   printf("\t\t    *************************************************\n");
  printf("\t\t    *                                               *\n");
  printf("\t\t    *       -----------------------------           *\n");
  printf("\t\t    *          WELCOME TO OUR PROJECT               *\n");
  printf("\t\t    *       -----------------------------           *\n");
  printf("\t\t    *                                               *\n");
  printf("\t\t    *                                               *\n");
  printf("\t\t    *                                               *\n");
  printf("\t\t    *                                               *\n");
  printf("\t\t    *                                               *\n");
  printf("\t\t    *                                               *\n");
  printf("\t\t    *************************************************\n\n\n");}






float give_exam(vector<qus>&script,vector<string>&stu_ans,int *count,vector<string>&stname,vector<string>&stdid,time_t* t);//prototype for exam
float calculate_marks(vector<qus>&script,vector<string>&stu_ans,int total_ans,int *count,vector<string>&stname,vector<string>&stdid);//prototype for calculating exam


int main()
{


    int i=0;

  time_t t;
  time(&t);
  char customername;
  char choice=0;

    system("cls");
    system("COLOR 0A");

    char d[25]="WELCOME TO ZET QUIZ";


    designing(d);
    printer();
    for(i=0;i<80;i++)
    printf("-");
    system("COLOR 0B");
  printf("\nCurrent date and time : %s",ctime(&t));
  for(i=0;i<80;i++)
    printf("-");

  printf(" \n Press any key to continue:");
  getch();
    system("cls");

while (1)      // INFINITE LOOP
  {
    system("cls");
    //setcolor(10);
    for(i=0;i<80;i++)
      printf("-");
    printf("\n");
    printf("   ****************************  |MAIN MENU|  *************************** \n");
    for(i=0;i<80;i++)
      printf("-");
    printf("\n");

    printf("\n\n");
    printf("\n-------------------------");

    printf(" \n Enter 1 -> Teacher  Mode");
    printf(" \n Enter 2 -> Student  Mode");
    printf(" \n Enter 0 -> Exit");

    printf("\n-------------------------");
    printf("\n");

    for(i=0;i<80;i++)
      printf("-");

      printf("\nCurrent date and time : %s",ctime(&t));

      for(i=0;i<80;i++)
      printf("-");

    printf("\nEnter your choice:");




            scanf("%d",&choice);







        switch(choice)
        {




            case 1://Teacher Part Begins
            {
            int option1=10;
            login(&option1);
            system("cls");
            if(option1==10){TeacherMode();}


            break;
            }

            case 2://Student Part Begins
            {

                vector<qus>script;//this will contain the questions
                vector<qus>script_decrypted;//this will contain the decrypted exam paper
                vector<qus>script_randomized;//this will contain the randomized exam paper
                string email;//email name stored for a particular exam
                char filename[100];//filename stored for a particular exam
                char key[100];//password given by student
                int selected_questions;//variable containing number of questions selected by teacher
                vector<string>stu_ans;//this will contain the answers
                int count=0,option;//random variables
                vector<string>stname;//student name
                vector<string>stdid;//student id



                system("cls");



                StudentChoice(filename,key);//Functions that display student information
                Deserialisation(script,filename,&email,&selected_questions);//Encrypted Question brought forward
                CreateDecryptedDAM(script,script_decrypted,key);//Decryption Happens

                int arr[script_decrypted.size()];
                for(int x=0;x<script_decrypted.size();x++){arr[x]=0;}

                RandomGenerate(script_decrypted.size(),selected_questions,arr);//problem is here

                CreateRandomizedDAM(script_decrypted,script_randomized,arr,script_decrypted.size());//Random Question Set generated
                int x=script_randomized.size();
                time_t t_start;
               float  marks=give_exam(script_randomized,stu_ans,&x,stname,stdid,&t_start);
                time_t t_end;
                time(&t_end);

                SendEmail(email,marks, t_start,t_end,stdid[0]);

                system("cls");

                cout<<"\n\n\n\n";
                cout<<setw(100)<<"The exam is done";

          Beep(370,465);
          Beep(370,232);
          Beep(554,232);
          Beep(494,465);
          Beep(440,465);
          Beep(415,465);
          Beep(415,232);
          Beep(415,232);
          Beep(494,465);
          Beep(440,232);
          Beep(415,232);
          Beep(370,465);
          Beep(370,232);
          Beep(880,232);
          Beep(831,232);
          Beep(880,232);
          Beep(831,232);
          Beep(880,232);


                break;
            }

            case 0:
            {
                return 0;
                break;
            }


        }



    }

    fflush(stdin);
    system("cls");
    printf("Going back to home page.....");
    Sleep(2000);
}

float calculate_marks(vector<qus>&script,vector<string>&stu_ans,int total_ans,int *count,vector<string>&stname,vector<string>&stdid)//This calculates marks after exam is given
{
    int mark=0;
    for(int i=0;i<*count;i++)
    {
       if(stu_ans[i][0]==script[i].answer[0])
         mark++;
    }
    system("cls");
    float obtained= mark-(total_ans-mark)*.25;
    float percent= (obtained/(*count))*100;
    Beep(500,500);

    string rsl="RESULT";
system("Color 0D");
    gotoxy(20,3);
cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 "<<rsl<<" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
//    show_mouse();
gotoxy(20,5);
cout<<"\xDB\xDB\xDB\xDB\xB2  Name: "<<stname[0];
gotoxy(20,7);
cout<<"\xDB\xDB\xDB\xDB\xB2  ID: "<<stdid[0];
gotoxy(20,9);
cout<<"\xDB\xDB\xDB\xDB\xB2 Total correct answers: "<<mark;
gotoxy(20,11);
cout<<"\xDB\xDB\xDB\xDB\xB2 Total incorrect answers: "<<total_ans-mark;
gotoxy(20,13);
cout<<"\xDB\xDB\xDB\xDB\xB2 Total marks obtained: "<<obtained;
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 Achieved: %.2f%%",percent);
gotoxy(20,17);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,20);
    printf("press Enter to continue......");
    getch();
    return obtained;

}


float give_exam(vector<qus>&script,vector<string>&stu_ans,int *count,vector<string>&stname,vector<string>&stdid,time_t* t)//This is where the exam takes place
{  int total_ans=0;
   string x,y;
  int delay;
for(int a=0;a<script.size();a++)
{
    stu_ans.push_back("x");
}
  cout<<"Put your name: "<<endl;
  fflush(stdin);
  getline(cin,x);
  stname.push_back(x);
  cout<<"Your Student Id: "<<endl;
  fflush(stdin);
  cin>>y;
  stdid.push_back(y);
  printf("Exam duration:");
  cin>>delay;
  system("cls");

  printf("Your Exam wil Start In :->\n\n");
 system("COLOR 0B");
  printf("|                 *******         |\n");
  printf("|                       *         |\n");
  printf("|                 *******         |\n");
  printf("|                       *         |\n");
  printf("|                 *******         |\n");
  Sleep(1000);
  system("cls");
  printf("Your Exam wil Start In :->\n\n");
  system("COLOR 0A");
  printf("|                 *******         |\n");
  printf("|                       *         |\n");
  printf("|                 *******         |\n");
  printf("|                 *               |\n");
  printf("|                 *******         |\n");
  Sleep(1000);
   system("cls");
   printf("Your Exam wil Start In :->\n\n");
   system("COLOR 0C");
  printf("|                  //||          |\n");
  printf("|                 // ||          |\n");
  printf("|                    ||          |\n");
  printf("|                 ___||___       |\n");

  Sleep(1000);
   system("cls");




  time_t d;
  time(&d);



    time_t start_time;
    time_t current_time;

    time(&start_time);
    *t=start_time;
    time(&current_time);

    double diff = 0;


       //  diff = difftime(current_time, start_time);
    while(1)
    { cout<<"EXAM PAPER"<<endl;
      cout<<"Starting Time was : "<<ctime(&start_time)<<endl;
      cout<<"Time is : "<<ctime(&current_time)<<endl;
      cout<<"-->Questions:"<<endl;
      cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
      for(int i=0;i<script.size();i++)
      {
        cout<<i+1<<". "<<script[i].question<<endl;
      }
      cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
      cout<<"\n Enter the no of the question you like to answer or press '0' to submit: ";
      int i;
      cin>>i;
      system("cls");

      if(i==0)
       break;
      else if(i<=script.size())
      {
        cout<<"\t\t\t"<<script[i-1].question<<endl<<endl;
        cout<<"\t\t\t"<<script[i-1].options<<endl<<endl;
        cout<<"Ans=>> ";
        string x;
        cin>>x;
        system("cls");
        time(&current_time);
         diff = difftime(current_time, start_time);
        if(diff<delay)
          stu_ans[i-1]=x;
        else {
            printf("Times up");
            Sleep(1500);

            break;
        }
        total_ans++;
      }


    }

   return calculate_marks(script,stu_ans,total_ans ,count,stname,stdid);
}

