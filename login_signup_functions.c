#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include "header.h"

void placeholder();

char filename[] = {"accounts_db.dat"};

void login()
{
    int choice = 0;
    system("cls");
    while (((choice != 1) && (choice != 2)) && (choice != 3))
    {
        long long int aadh_vaxx;
        int vaxx;
        long long int aadh;
        printf("1. Login\n\n");
        printf("2. Signup\n\n");
        printf("3. Exit application\n\n\nEnter choice: ");
        scanf("%d", &choice);
        printf("\n\n");
        if (choice == 1)
        {
            char uname[20];
            char pword[20];
            printf("Enter username: ");
            scanf("%s", uname);
            fflush(stdin);
            printf("Enter password: ");
            scanf("%s", pword);
            fflush(stdin);
            aadh_vaxx = l_check(uname, pword);
            aadh = aadh_vaxx / 10;
            vaxx = aadh_vaxx % 10;
            if (aadh)
            {
                main_menu(aadh, vaxx);
            }
            else
            {
                printf("Username or Password wrong");
            }
        }
        else if (choice == 2)
        {
            aadh_vaxx = l_signup();
            aadh = aadh_vaxx / 10;
            vaxx = aadh_vaxx % 10;
            main_menu(aadh, vaxx);
        }
        else if (choice == 3)
        {
            quit();
        }
        else
        {
            printf("Invalid\n\n");
        }
    }
}

//_____________________________________________________________Login tools_____________________________________________________________________________
long long int l_check(char u[20], char p[20])
{
    FILE *fp;
    user_t user;
    long long int success = 0;

    fp = fopen(filename, "rb");

    while (1)
    {
        fread(&user, sizeof(user), 1, fp);

        if (feof(fp))
        {
            success = 0;
            break;
        }
        if (strcmp(user.uname, u) == 0)
        {
            if (strcmp(user.pword, p) == 0)
            {
                success = ((user.Aadhar_Card_No) * 10) + (user.Level_of_Vaccination);
                break;
            }
        }
    }
    return success;
}

//____________________________________________________________sign-up tools____________________________________________________________________________

long long int l_signup()
{
    FILE *fp;
    user_t user;
    bool invalid;
    strcpy(user.hospital_name, "Not assigned");

    fp = fopen(filename, "ab");
    invalid = 0;
    long long int aadh;
    system("cls");
    printf("---------- SIGN UP ---------- \n\n\n");
    do
    {
        if (invalid == 1)
            printf("\n\nEntered Number is invalid.\n");
        printf("\nEnter Aadhaar Card number: ");
        scanf("%lld", &user.Aadhar_Card_No);
        aadh = user.Aadhar_Card_No;
        invalid = 1;
    } while ((user.Aadhar_Card_No / 100000000000) < 2 || (user.Aadhar_Card_No / 100000000000) >= 10);

    invalid = 0;
    do
    {
        if (invalid == 1)
            printf("\n\nEntered name is invalid.\n");
        printf("\nEnter first name: ");
        scanf("%s", user.First_Name);
        fflush(stdin);
        invalid = 1;
    } while (char_check(user.First_Name) == 0);

    invalid = 0;
    do
    {
        if (invalid == 1)
            printf("\n\nEntered name is invalid.\n");
        printf("\nEnter last name: ");
        scanf("%s", user.Last_Name);
        fflush(stdin);
        invalid = 1;
    } while (char_check(user.Last_Name) == 0);

    invalid = 0;
    do
    {
        if (invalid == 1)
            printf("\n\nEntered Number is invalid.\n");
        printf("\nEnter Phone number: ");
        scanf("%lld", &user.Phone_No);
        invalid = 1;
    } while ((user.Phone_No / 1000000000) < 1 || (user.Phone_No / 1000000000) >= 10);

    invalid = 0; //could implement an exit condition when age <18
    do
    {
        if (invalid == 1)
        {
            if (user.Age < 0)
                printf("\n\nEntered age is invalid.\n");
            else
                printf("\nOnly 18+ are eligible for vaccination\n");
        }
        printf("\nEnter age: ");
        scanf("%d", &user.Age);
        invalid = 1;
    } while (user.Age < 18 || user.Age > 130);

    printf("\n0 = Not vaccinated\n1 = First dose completed\n2 = Second dose completed\n\n");
    invalid = 0;
    do
    {
        if (invalid == 1)
            printf("Entered value is invalid.\n");
        printf("\nEnter vaccination level: ");
        scanf("%d", &user.Level_of_Vaccination);
        aadh = (aadh * 10) + user.Level_of_Vaccination;
        invalid = 1;
    } while (user.Level_of_Vaccination < 0 || user.Level_of_Vaccination > 2);

    invalid = 0;
    do
    {
        if (invalid == 1)
            printf("Entered city name is invalid.\n");
        printf("\nEnter city name: ");
        scanf("%s", user.Address);
        fflush(stdin);
        invalid = 1;
    } while (char_check(user.Address) == 0);

    printf("\nEnter username: ");
    scanf("%s", user.uname);
    fflush(stdin);

    printf("\nEnter password: ");
    scanf("%s", user.pword);
    fflush(stdin);

    fwrite(&user, sizeof(user), 1, fp);
    fclose(fp);
    return aadh;
}

//__________________________________________________________Entry checking tools_______________________________________________________________________

int char_check(char *str) //res = 1 all chars
{
    int res = 1;
    while (*str != '\0' && res != 0)
    {
        res = isalpha(*str);
        str++;
    }
    return res;
}

//_________________________________________________________Troubleshooting tools_______________________________________________________________________

void l_displayAll()
{
    FILE *fp;
    user_t t;

    fp = fopen("temp1.dat", "rb");

    printf("fName\tlName\tAge\tuname\tpword\n\n");

    while (1)
    {
        fread(&t, sizeof(t), 1, fp);

        if (feof(fp))
        {
            break;
        }
        printf("%s\t", t.First_Name);
        printf("%s\t", t.Last_Name);
        printf("%d\t", t.Age);
        printf("%s\t", t.uname);
        printf("%s\t", t.pword);
        printf("%lld\t", t.Aadhar_Card_No);
        printf("%d\n\n", t.Level_of_Vaccination);
        //printf("%s\t\n\n",t.email_id);
    }
    printf("========================================================\n\n");

    fclose(fp);
}

void placeholder()
{
    printf("Placeholder");
}
//____________________________________________________________main_menu___________________________________________________________________________________
void main_menu(long long int aadh, int vaxx)
{
    short int choice;
    do
    {
        system("cls");

        printf("\n\n---------- MAIN MENU ----------\n\n\n");
        printf("1. Slot booking\n");
        printf("2. View account information\n");
        printf("3. Logout\n\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            printf("%d\n", vaxx);
            if (vaxx == 3 || vaxx == 4)
            {
                system("cls");
                printf("Slot already booked, please check user info\n");
                quit();
            }
            else if (vaxx == 2)
            {
                system("cls");
                printf("Both doses taken\n");
                quit();
            }
            else
                slotBooking(aadh);
            break;

        case 2:
            if (aadh == 1)
                admin();
            else
                display_citizen(aadh);
            break;

        case 3:
            logout();
            break;

        default:
            printf("Invalid input, please try again\n\n");
            break;
        }
    } while (choice < 3);
}

void quit()
{
    system("cls");
    printf("\n\nEnter any key to exit");
    getch();
}

void logout()
{
    system("cls");
    login();
}