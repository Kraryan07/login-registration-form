#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string username,password,Email;
    string searchname,searchpass,searchemail;
    fstream file;
    public:
    void login();
    void signin();
    void forgot();
}obj;

 int main(){
    char choise;
    cout<<"\n1- Login";
    cout<<"\n2- Sign-up";
    cout<<"\n3- Forget-password";
    cout<<"\n4- Exit ";

    cout<<"\n Enter your choise::";
    cin>>choise;

    switch(choise){
        case '1':
            cin.ignore();
            obj.login();
        break;
        case '2':
            cin.ignore();
            obj.signin();
        break;
        case '3':
           cin.ignore();
           obj.forgot();
        break;
        case '4':
           return 0;
        break;
        default:
        cout<<"Invalid option";
    }
 }
 void temp:: signin(){
    cout<<"\n Enter your username ::";
    getline(cin,username);

    cout<<"\nEnter your Email Adderes ::";
    getline(cin,Email);

    cout<<"\nEnter your Password ::";
    getline(cin,password);
   
    file.open("loginData.txt",ios::out|ios::app);
    file<<username<<"*"<<password<<"*"<<Email<<endl;
    file.close();
 }

 void temp::login(){
    
    cout<<"-----------LOGIN---------";
    cout<<"\n Enter your Username::";
    getline(cin,searchname);
    cout<<"\n Enter your Password::";
    getline(cin,searchpass);

    file.open("loginData.txt",ios::in);
    getline(file,username,'*');
    getline(file,password,'*');
    getline(file,Email,'\n');
    while(!file.eof()){
       if(username==searchname){
        if(password==searchpass){
            cout<<"\nLogin Successful-";
            cout<<"\n username :"<<username;
            cout<<"\n Email :"<<Email;

        }
        else{
            cout<<"Password is incorrect";
        }
       }
    getline(file,username,'*');
    getline(file,password,'*');
    getline(file,Email,'\n');
    }
    file.close();
 }
 void temp::forgot(){
   cout<<"\n Enter your Username:";
   getline(cin,searchname);
   cout<<"\n Enter your Email:";
   getline(cin,searchemail);
   
   file.open("loginData.txt",ios::in);
//    getline(file,username,'*')
    getline(file,username,'*');
    getline(file,password,'*');
    getline(file,Email,'\n');
    while(!file.eof()){
       if(searchname==username){
        if(searchemail==Email){
           cout<<"\naccount found---"<<endl;
           cout<<"passsword :"<<password<<endl;
        }
        else{
            cout<<"Accuont not found \n";
        }
       }
       else{
        cout<<"\nno such username \n";
       }
    getline(file,username,'*');
    getline(file,password,'*');
    getline(file,Email,'\n');
    }
    file.close();
 }