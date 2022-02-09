#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

char filename2[] = {"accounts_db.dat"};

void display_citizen(long long int aadh)
{
    FILE *fp;
    user_t user;

    fp = fopen(filename2, "rb");
    while (1)
    {
        fread(&user, sizeof(user), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (user.Aadhar_Card_No == aadh)
        {
            // printf("\n\n\nName: %s %s\n", user.First_Name, user.Last_Name);
            // printf("Aadhaar card number: %lld\n", user.Aadhar_Card_No);
            // printf("Phone number: %lld\n", user.Phone_No);
            // printf("Age %d\n", user.Age);
            // printf("City: %s\n\n\n", user.Address);
            // printf("----------------------------\n\n\n");
            // switch (user.Level_of_Vaccination)
            // {
            // case 0:
            //     printf("Not vaccinated\n\n\n");
            //     break;

            // case 1:
            //     printf("First dose completed\n\n\n");
            //     break;

            // case 2:
            //     printf("Second dose completed\n\n\n");
            //     break;

            // case 3:
            //     printf("First dose scheduled\n\n\n");
            //     break;

            // case 4:
            //     printf("Second dose scheduled\n\n\n");
            //     break;

            // default:
            //     printf("error\n\n\n");
            //     break;
            // };

            // printf("----------------------------");
            // break;

            // found = 1;
            printf("Name: %s %s\n", user.First_Name, user.Last_Name);
            printf("Aadhaar card number: %lld\n", user.Aadhar_Card_No);
            printf("Phone number: %lld\n", user.Phone_No);
            printf("Age %d\n", user.Age);
            printf("City: %s\n\n\n", user.Address);
            printf("Vaccination status: ");
            printf("\n----------------------------\n");
            switch (user.Level_of_Vaccination)
            {
            case 0:
                printf("Not vaccinated\n");
                break;

            case 1:
                printf("First dose completed\n");
                break;

            case 2:
                printf("Second dose completed\n");
                break;

            case 3:
                printf("First dose scheduled\n");
                break;

            case 4:
                printf("Second dose scheduled\n");
                break;

            default:
                printf("error\n");
                break;
            };
            printf("Center: %s\n", user.hospital_name);
            printf("----------------------------");
            break;
        }
    }
    printf("\n\nPress any key to return to main menu\n");
    getch();
}

void admin()
{
    FILE *fp;
    user_t user;
    long long int Aadhar_Card_No, found = 0;
    fp = fopen(filename2, "rb");
    printf("\nEnter the Aadhar_Card_No:");
    scanf("%lld", &Aadhar_Card_No);
    while (1)
    {
        fread(&user, sizeof(user), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (user.Aadhar_Card_No == Aadhar_Card_No)
        {
            found = 1;
            printf("Name: %s %s\n", user.First_Name, user.Last_Name);
            printf("Aadhaar card number: %lld\n", user.Aadhar_Card_No);
            printf("Phone number: %lld\n", user.Phone_No);
            printf("Age %d\n", user.Age);
            printf("City: %s\n\n\n", user.Address);
            printf("Vaccination status: ");
            printf("\n----------------------------\n");
            switch (user.Level_of_Vaccination)
            {
            case 0:
                printf("Not vaccinated\n");
                break;

            case 1:
                printf("First dose completed\n");
                break;

            case 2:
                printf("Second dose completed\n");
                break;

            case 3:
                printf("First dose scheduled\n");
                break;

            case 4:
                printf("Second dose scheduled\n");
                break;

            default:
                printf("error\n");
                break;
            };
            printf("Center: %s\n", user.hospital_name);
            printf("----------------------------");
            break;
        }
    }
    if (found == 0)
    {
        printf("\nSorry No Record Found\n\n\n");
    }
    else
    {
        printf("\n\nUpdate user vaccination status? (y/n) :");
        char ch = getch();
        if (ch == 'y' || ch == 'Y')
        {
            modify(Aadhar_Card_No, "Not assigned");
            printf("Vaccination status successfully updated\n\n\n");
        }
    }
    printf("\nPress any key to return to main menu\n");
    getch();
    fclose(fp);
}