#include <stdio.h>
#include <stdlib.h>

typedef struct customers
{
    int id;
    char password[10];
    int w_money;
} customer;

typedef struct admins
{
    int id;
    char password[10];
} admin;

int checkadminlogin();

int checkcustomerlogin();

void registerCustomer();

int checkdatabase(char* user,char* pass);