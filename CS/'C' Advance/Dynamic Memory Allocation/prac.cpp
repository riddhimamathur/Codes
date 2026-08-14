#include <stdio.h>
#include <string.h>

enum employee_type {exchange, regular};
union data {
    int hostelroom;
    char country[30];
};
struct employee 
{
    int id;
    char name[50];
    float salary;
    enum employee_type type;
    union data d;
};

int main()
{
    struct employee e1;
    struct employee *ptr;
    e1.id = 1027;
    strcpy(e1.name,"Aman");
    e1.salary = 320000;
    e1.type = exchange;
    e1.d.hostelroom = 31;
    strcpy(e1.d.country, "Paris");
    ptr = &e1;

    printf("Name: %s | employee id : %d\ | employee sly : %.1f | employee type : %d | hostelroom : %d | country = %s ",ptr->name,ptr->id,ptr->salary, ptr->type, ptr->d.hostelroom,ptr->d.country);
    return 0;
}
