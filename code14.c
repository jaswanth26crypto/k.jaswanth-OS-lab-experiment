#include <stdio.h>
#include <string.h>

#define MAX 50

char files[MAX][20];
int count = 0;


void createFile()
{
    char fname[20];

    printf("Enter file name: ");
    scanf("%s", fname);

    strcpy(files[count], fname);
    count++;

    printf("File created successfully\n");
}


void deleteFile()
{
    char fname[20];
    int found = 0;

    printf("Enter file name to delete: ");
    scanf("%s", fname);

    for(int i = 0; i < count; i++)
    {
        if(strcmp(files[i], fname) == 0)
        {
            found = 1;

            for(int j = i; j < count-1; j++)
            {
                strcpy(files[j], files[j+1]);
            }

            count--;
            printf("File deleted successfully\n");
            break;
        }
    }

    if(!found)
        printf("File not found\n");
}


void searchFile()
{
    char fname[20];
    int found = 0;

    printf("Enter file name to search: ");
    scanf("%s", fname);

    for(int i = 0; i < count; i++)
    {
        if(strcmp(files[i], fname) == 0)
        {
            found = 1;
            printf("File found\n");
            break;
        }
    }

    if(!found)
        printf("File not found\n");
}

void displayFiles()
{
    printf("\nFiles in Directory:\n");

    if(count == 0)
    {
        printf("Directory is empty\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        printf("%s\n", files[i]);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Single Level Directory ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createFile();
                break;

            case 2:
                deleteFile();
                break;

            case 3:
                searchFile();
                break;

            case 4:
                displayFiles();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}