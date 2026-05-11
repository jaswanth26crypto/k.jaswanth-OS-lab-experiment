#include <stdio.h>

struct Employee
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee e;
    int n;

    fp = fopen("emp.dat", "rb+");

    if (fp == NULL)
        fp = fopen("emp.dat", "wb+");

    printf("Enter Record Number: ");
    scanf("%d", &n);

    printf("Enter ID Name Salary: ");
    scanf("%d %s %f", &e.id, e.name, &e.salary);

    /* Random Access Write */
    fseek(fp, (n - 1) * sizeof(e), 0);
    fwrite(&e, sizeof(e), 1, fp);

    /* Random Access Read */
    fseek(fp, (n - 1) * sizeof(e), 0);
    fread(&e, sizeof(e), 1, fp);

    printf("\nEmployee Details\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Salary: %.2f\n", e.salary);

    fclose(fp);

    return 0;
}