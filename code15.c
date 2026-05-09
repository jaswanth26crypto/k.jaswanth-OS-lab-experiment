#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 10

struct User
{
    char uname[20];
    char files[MAX_FILES][20];
    int fileCount;
};

struct User users[MAX_USERS];
int userCount = 0;


void createUser()
{
    printf("Enter user name: ");
    scanf("%s", users[userCount].uname);

    users[userCount].fileCount = 0;
    userCount++;

    printf("User created successfully\n");
}


void createFile()
{
    char uname[20], fname[20];
    int found = 0;

    printf("Enter user name: ");
    scanf("%s", uname);

    for(int i = 0; i < userCount; i++)
    {
        if(strcmp(users[i].uname, uname) == 0)
        {
            printf("Enter file name: ");
            scanf("%s", fname);

            strcpy(users[i].files[users[i].fileCount], fname);
            users[i].fileCount++;

            printf("File created successfully\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("User not found\n");
}


void display()
{
    printf("\n----- Two Level Directory -----\n");

    for(int i = 0; i < userCount; i++)
    {
        printf("\nUser: %s\n", users[i].uname);

        if(users[i].fileCount == 0)
        {
            printf("No files\n");
        }
        else
        {
            for(int j = 0; j < users[i].fileCount; j++)
            {
                printf("%s\n", users[i].files[j]);
            }
        }
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Create User\n");
        printf("2. Create File\n");
        printf("3. Display Directory\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createUser();
                break;

            case 2:
                createFile();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}