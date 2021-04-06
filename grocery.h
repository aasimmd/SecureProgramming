#include <stdio.h>
#include <stdlib.h>

typedef struct customers
{
    char id[10];
    char password[10];
    int w_money;
    struct customers* next;
} customer;

extern customer *cu;
extern customer *tmp;

int checkadminlogin();

int checkcustomerlogin();

void registerCustomer();

int checkdatabase(char* user,char* pass);

void read_db_from_file();

void add_to_file();

int printall();