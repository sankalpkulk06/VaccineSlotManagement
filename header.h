#include<stdlib.h>
struct user_details
{   
    long long int Aadhar_Card_No;
    char First_Name[20];
    char Last_Name[20];
    long long int Phone_No;
    int Age;
    int Level_of_Vaccination;
    int Address[100];
    char uname[20];
    char pword[20];
    char hospital_name[10];

};
typedef struct user_details user_t;
void login();
long long int l_signup();
void l_display();       //for troubleshooting
void l_displayAll();    //for troubleshooting
long long int l_check(char a[], char b[]);
void logout();
void quit();

int char_check(char*);

void slotBooking(long long int);
void gotoxy(short x, short y);
void display_file();
void appendSlot(int num);
void modify(long long int, char*);

void main_menu(long long int, int);

