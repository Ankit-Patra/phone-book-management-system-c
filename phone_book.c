#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
    struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    long int mble_no;
    char sex[8];
    char mail[100];
    char citision_no[20];
};
void menu();
void got();
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();
int main()
{
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
    printf("\t\t**********WELCOME TO PHONEBOOK*************");

    printf("\n\n\t\t\t  MENU\t\t\n\n");
    printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search\t6.Delete\n");

    switch (getch())
    {
    case '1':
        addrecord();
        break;
    case '2':
        listrecord();
        break;
    case '3':
        exit(0);
        break;
    case '4':
        modifyrecord();
        break;
    case '5':
        searchrecord();
        break;
    case '6':
        deleterecord();
        break;
    default:
        system("cls");
        printf("\nEnter 1 to 6 only");
        printf("\nEnter any key to continue");
        getch();

        menu();
    }
}
void addrecord()
{
    system("cls");
    FILE *f;
    struct person p;
    printf("\t*****Adding New Record to the Phonebook*****\n");
    f = fopen("project", "ab+");
    printf("\n--------------------------------------");
    printf("\nEnter name: ");
    got(p.name);
    printf("\nEnter the address: ");
    got(p.address);
    printf("\nEnter father's name: ");
    got(p.father_name);
    printf("\nEnter mother's name: ");
    got(p.mother_name);
    printf("\nEnter phone no.:");
    scanf("%ld", &p.mble_no);
    printf("Enter sex:");
    got(p.sex);
    printf("\nEnter e-mail:");
    got(p.mail);
    printf("\nEnter citizen no:");
    got(p.citision_no);
    fwrite(&p, sizeof(p), 1, f);
    printf("\n--------------------------------------");
    fflush(stdin);
    printf("\nRecord Saved Successfully!");
    printf("\n--------------------------------------");

    fclose(f);

    printf("\nEnter any key to continue");

    getch();
    system("cls");
    menu();
}
void listrecord()
{
    system("cls");
    printf("\t*****List of Records in the Phonebook*****\n");
    printf("\n--------------------------------------");
    struct person p;
    FILE *f;
    f = fopen("project", "rb");
    if (f == NULL)
    {
        printf("\nfile opening error in listing :");
        exit(1);
    }
    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        printf("\nYOUR RECORD IS");
        printf("\nName=%s\nAdress=%s\nFather name=%s\nMother name=%s\nMobile no=%ld\nSex=%s\nE-mail=%s\nCitizen no=%s", p.name, p.address, p.father_name, p.mother_name, p.mble_no, p.sex, p.mail, p.citision_no);
        getch();
        // system("cls");
    }
    fclose(f);
    printf("\n--------------------------------------");
    printf("\nEnter any key to continue");
    getch();
    system("cls");
    menu();
}
void searchrecord()
{
    system("cls");
    printf("\t*****Searching a Record in the Phonebook*****\n");
    struct person p;
    FILE *f;
    char name[100];
    f = fopen("project", "rb");
    if (f == NULL)
    {
        printf("\n error in opening\a\a\a\a");
        exit(1);
    }
    printf("\nEnter name of person to search\n");
    got(name);
    printf("\n--------------------------------------\n");
    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if (strcmp(p.name, name) == 0)
        {
            printf("\n\tDetail Information About %s", name);
            printf("\n\nName:%s\naddress:%s\nFather name:%s\nMother name:%s\nMobile no:%ld\nsex:%s\nE-mail:%s\nCitizen no:%s", p.name, p.address, p.father_name, p.mother_name, p.mble_no, p.sex, p.mail, p.citision_no);
            printf("\n--------------------------------------");
        }
        else
        {
            printf("\nContact not found\n");
            printf("\n--------------------------------------");
        }
    }
    fclose(f);
    printf("\nEnter any key to continue");
    getch();
    system("cls");
    menu();
}
void deleterecord()
{
    system("cls");
    printf("\t*****Deleting a Record from the the Phonebook*****\n");
    struct person p;
    FILE *f, *ft;
    int flag;
    char name[100];
    f = fopen("project", "rb");
    if (f == NULL)
    {

        printf("CONTACT'S DATA NOT ADDED YET.");
    }
    else
    {
        ft = fopen("temp", "wb+");
        if (ft == NULL)

            printf("file opening error");
        else

        {

            printf("\n--------------------------------------\n");
            printf("ENTER CONTACT'S NAME:");
            got(name);

            fflush(stdin);
            while (fread(&p, sizeof(p), 1, f) == 1)
            {
                if (strcmp(p.name, name) != 0)
                    fwrite(&p, sizeof(p), 1, ft);
                if (strcmp(p.name, name) == 0)
                    flag = 1;
            }
            fclose(f);
            fclose(ft);
            if (flag != 1)
            {
                printf("\nNO CONACT'S RECORD TO DELETE.");
                remove("temp.txt");
            }
            else
            {
                remove("project");
                rename("temp.txt", "project");
                printf("\nRECORD DELETED SUCCESSFULLY.");
                printf("\n--------------------------------------");
            }
        }
    }
    printf("\nEnter any key to continue");

    getch();
    system("cls");
    menu();
}

void modifyrecord()
{
    system("cls");
    printf("\t*****Modifying a Record in the Phonebook*****\n");
    int c;
    FILE *f;
    int flag = 0;
    struct person p, s;
    char name[50];
    f = fopen("project", "rb+");
    if (f == NULL)
    {

        printf("CONTACT'S DATA NOT ADDED YET.");
        exit(1);
    }
    else
    {
        system("cls");
        printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
        got(name);
        while (fread(&p, sizeof(p), 1, f) == 1)
        {
            if (strcmp(name, p.name) == 0)
            {

                printf("\n Enter name:");
                got(s.name);
                printf("\nEnter the address:");
                got(s.address);
                printf("\nEnter father's name:");
                got(s.father_name);
                printf("\nEnter mother's name:");
                got(s.mother_name);
                printf("\nEnter phone no:");
                scanf("%ld", &s.mble_no);
                printf("\nEnter sex:");
                got(s.sex);
                printf("\nEnter e-mail:");
                got(s.mail);
                printf("\nEnter citizen no\n");
                got(s.citision_no);
                fseek(f, -sizeof(p), SEEK_CUR);
                fwrite(&s, sizeof(p), 1, f);
                flag = 1;
                break;
            }
            fflush(stdin);
        }
        if (flag == 1)
        {
            printf("\n your data id modified");
        }
        else
        {
            printf(" \n data is not found");
        }
        fclose(f);
    }
    printf("\n Enter any key to continue");
    getch();
    system("cls");
    menu();
}
void got(char *name)
{

    int i = 0, j;
    char c, ch;
    do
    {
        c = getch();
        if (c != 8 && c != 13)
        {
            *(name + i) = c;
            putch(c);
            i++;
        }
        if (c == 8)
        {
            if (i > 0)
            {
                i--;
            }
            system("cls");
            for (j = 0; j < i; j++)
            {
                ch = *(name + j);
                putch(ch);
            }
        }
    } while (c != 13);
    *(name + i) = '\0';
}