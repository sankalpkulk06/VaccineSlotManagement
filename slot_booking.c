#include <stdio.h>
#include <windows.h> // gotoxy()
#include <conio.h>   // getch(), delay()
#include <ctype.h>   // toupper(), tolower()
#include <string.h>  //strcmp(), strcpy(), strlen()
#include <stdlib.h>
#include "header.h"

void gotoxy(short x, short y)
{
    COORD position = {x, y}; // sets coordinates (x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void slotBooking(long long int aadh)
{
    int num = 0;

    system("cls");
    printf("\n\n\n\t\t\t\t\t ----------------- SLOT BOOKING -----------------\n");
    gotoxy(20, 7);
    printf("Serial Number");
    gotoxy(45, 7);
    printf("Hospital");
    gotoxy(70, 7);
    printf("Vaccine");
    gotoxy(95, 7);
    printf("Slots");
    printf("\n==================================================================================================================================\n");
    // Row information
    display_file();
    char hospital[10];
    do
    {
        printf("\n\nEnter Hospital name: ");
        scanf("%s", hospital);
        printf("\n");
        // appendSlot(num);
        printf("\n\n");
    } while (strcmp(hospital, "A") != 0);
    modify(aadh, hospital);
    printf("Slot booked\n\n\n");
    printf("Enter any key to return to Main menu\n\n\n\n");
    getch();
}

void display_file()
{
    FILE *fp = fopen("hospitals.csv", "r");

    if (!fp)
        printf("\nCan't open file\n");

    else
    {

        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer, 1024, fp))
        {
            column = 0;
            row++;

            if (row == 1)
                continue;

            // Splitting the data
            char *value = strtok(buffer, ", ");

            while (value)
            {
                // Column 1
                if (column == 0)
                {
                    printf("\t\t\t");
                }

                // Column 2
                if (column == 1)
                {
                    printf("\t\t\t");
                }

                // Column 3
                if (column == 2)
                {
                    printf("\t\t    ");
                }

                // Column 4
                if (column == 3)
                {
                    printf("\t\t\t");
                }

                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }

            printf("\n");
        }

        // Close the file
        fclose(fp);
    }
    // return 0;
}

char filename1[] = {"accounts_db.dat"};
void modify(long long int aadh, char *hospital)
{
    FILE *fp, *fp1;
    user_t user;
    int id, found = 0, count = 0, Aadhar = 0;

    fp = fopen(filename1, "rb");
    fp1 = fopen("temp1.dat", "wb");

    while (1)
    {
        fread(&user, sizeof(user), 1, fp);

        if (feof(fp))
        {
            break;
        }
        if (user.Aadhar_Card_No == aadh)
        {
            found = 1;
            if (user.Level_of_Vaccination == 0)
                user.Level_of_Vaccination = 3;
            else if (user.Level_of_Vaccination == 1)
                user.Level_of_Vaccination = 4;
            else if (user.Level_of_Vaccination == 3)
                user.Level_of_Vaccination = 1;
            else if (user.Level_of_Vaccination == 4)
                user.Level_of_Vaccination = 2;
            strcpy(user.hospital_name, hospital);
            fwrite(&user, sizeof(user), 1, fp1);
        }
        else
        {
            fwrite(&user, sizeof(user), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if (found == 0)
    {
        printf("\n\nSorry No Record Found\n\n");
    }
    else
    {
        fp = fopen(filename1, "wb");
        fp1 = fopen("temp1.dat", "rb");

        while (1)
        {
            fread(&user, sizeof(user), 1, fp1);

            if (feof(fp1))
            {
                break;
            }
            fwrite(&user, sizeof(user), 1, fp);
        }
    }
    fclose(fp);
    fclose(fp1);
}