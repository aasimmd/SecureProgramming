#include "grocery.h"
#include <string.h>
int checkadminlogin(){
    printf("admin\n");
    return 1;
}

int checkcustomerlogin(){
    char loginid[100],password[100];
    int flag;
    printf("Enter your Login ID: ");
    fflush(stdin);
    gets(loginid);
    printf("Enter your password: ");
    fflush(stdin);
    gets(password);
    fflush(stdin);
    printf("Your Creds are %s %s \n",&loginid,&password);
    flag = checkdatabase(loginid,password);
    return flag;
}


int checkdatabase(char * loginid,char * password){
    FILE *fp;
    fp=fopen("customerdata.txt","r");
    char userpass[20];
    char user[100], pass[100];
    while (fgets(userpass, sizeof(userpass), fp)) {
        int i=0,j=0;
        while(userpass[i] != ','){
            user[i] = userpass[i];
            i++;
        }
        user[i++] = '\0';
        while(userpass[i] != '\n'){
            pass[j] = userpass[i];
            i++;
            j++;
        }
        /* printf("username %s database%s \n",loginid,user);
        printf("username--%s--database%s-- \n",password,pass); */
        pass[j] = '\0';
        if (strcmp(user,loginid) == 0){
            if(strcmp(pass,password) ==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return -1;
        }
    }
    
}

void registerCustomer(){
    printf("register\n");
}