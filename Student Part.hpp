
void checkTXT_Student(string str)
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



void ViewQuestions_Student()
{
system("dir>NOT_AN_EXAM.txt");
std::string text;
ifstream fp;

cout<<"ALL THE TXT FILES IN THE DIRECTORY ARE: \n\n\n\n"<<endl;
    fp.open("NOT_AN_EXAM.txt");
    while(fp.eof()==0)
    {
        getline(fp,text);

        checkTXT_Student(text);



    }



    fp.close();
    char ch;

//    printf("\n\n\nEnter any key to continue..............");
//    fflush(stdin);
    getchar();

}

void StudentChoice(char* filename,char* key)
    {

    ViewQuestions_Student();
    cout<<"What question would you like to answer: ";
    scanf("%s",filename);
    cout<<"What is the key to the question paper: ";
    scanf("%s",key);



    }

void SendEmail(std::string email,float marks,time_t time_start,time_t time_end,std::string ID)
{

ofstream fp("Email.ps1");

string Subject=ID;
string Body="Marks:";
Body+=to_string(marks);
Body+="  Take taken: ";
time_t time_difference=time_end-time_start;
Body+=to_string(time_difference);
Body+="seconds";

fp<<"function Send-Email() {"<<endl;
fp<<""<<endl;
fp<<"Param("<<endl;
fp<<""<<endl;
fp<<"[parameter(mandatory=$true)][string]$To,"<<endl;
fp<<"[parameter(mandatory=$true)][string]$Subject,"<<endl;
fp<<"[parameter(mandatory=$true)][string]$Body"<<endl;
fp<<""<<endl;
fp<<")"<<endl;
fp<<""<<endl;
fp<<"# Get the user credentails"<<endl;
fp<<""<<endl;
fp<<"$username = (Get-Content -Path \"F:\\pass.txt\")[0]"<<endl;


fp<<""<<endl;
fp<<"$password = (Get-Content -Path \"F:\\pass.txt\")[1] | ConvertTo-SecureString -AsPlainText -Force"<<endl;
fp<<""<<endl;
fp<<"# Create hash for email"<<endl;

fp<<""<<endl;

fp<<"$email = @{"<<endl;
fp<<""<<endl;

fp<<"from = $username"<<endl;
fp<<""<<endl;
fp<<"to = $To"<<endl;

fp<<""<<endl;
fp<<"subject = $Subject"<<endl;

fp<<""<<endl;
fp<<"smtpserver = \"smtp.gmail.com\""<<endl;

fp<<""<<endl;

fp<<"body = $Body"<<endl;
fp<<""<<endl;
fp<<"credential = New-Object System.Management.Automation.PSCredential -ArgumentList $username, $password"<<endl;
fp<<""<<endl;
fp<<"usessl = $true"<<endl;

fp<<""<<endl;
fp<<"verbose = $true"<<endl;
fp<<""<<endl;
fp<<"}"<<endl;
fp<<""<<endl;
fp<<"Send-MailMessage @email"<<endl;

fp<<""<<endl;
fp<<"}"<<endl;
fp<<"Send-Email -To "<<"\""<<email<<"\""<<" -Subject "<<"\""<<ID<<"\""<<" -Body "<<"\""<<Body<<"\"";


fp.close();
system("powershell -ExecutionPolicy Bypass -F Email.ps1");


}

