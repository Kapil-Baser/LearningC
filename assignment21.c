#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    char *title;
    char *first_name;
    char *last_name;
    int id;
    int ssn;
};

struct employees
{
    struct employee emp[2];
};

void get_emp_data(struct employees *e, int idx);
void print_employee(struct employees *p);

int main(void)
{
    struct employees employee_s;
    for (int i = 0; i < 2; i++)
    {
        get_emp_data(&employee_s, i);
    }
    print_employee(&employee_s);
    return 0;
}

void get_emp_data(struct employees *e, int idx)
{
    char buf[64] = {0};
    size_t i;
    printf("Enter the employee's first name: ");
    if (!fgets(buf, 64, stdin))
    {
        printf("Error: could not read input\n");
        exit(1);
    }
    i = strlen(buf);
    buf[i - 1] = '\0';
    e->emp[idx].first_name = strdup(buf);
    printf("Enter the employee's last name: ");
    if (!fgets(buf, 64, stdin))
    {
        printf("Error: could not read input\n");
        exit(1);
    }
    i = strlen(buf);
    buf[i - 1] = '\0';
    e->emp[idx].last_name = strdup(buf);
    printf("Enter employee's ID number: ");
    if (!fgets(buf, 64, stdin))
    {
        printf("Error: could not read input\n");
        exit(1);
    }
    e->emp[idx].id = atoi(buf);
    
    printf("Enter the last four digits of employee's SSN: ");
    if (!fgets(buf, 64, stdin))
    {
        printf("Error: could not read input\n");
        exit(1);
    }
    e->emp[idx].ssn = atoi(buf);
    printf("Enter the employee's job title (do not include the word 'Engineer'): ");
    if (!fgets(buf, 64, stdin))
    {
        printf("Error: could not read input\n");
        exit(1);
    }
    i = strlen(buf);
    buf[i - 1] = '\0';
    e->emp[idx].title = strdup(buf);
}

void print_employee(struct employees *p)
{
    for(int i = 0; i < 2; i++)
    {
        printf("Employee information for %s %s:\n", p->emp[i].first_name, p->emp[i].last_name);
        printf("ID: %d\n", p->emp[i].id);
        printf("SSN: %d\n", p->emp[i].ssn);
        printf("Title: %s Engineer\n", p->emp[i].title);
    }
    
}