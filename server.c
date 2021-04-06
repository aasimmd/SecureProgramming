#include "grocery.h"
#include <string.h>

customer *cu;
customer *tmp;

int checkadminlogin()
{
    char loginid[100],password[100];
    printf("Enter your Login ID: ");
    fflush(stdin);
    gets(loginid);
    printf("Enter your password: ");
    fflush(stdin);
    gets(password);
    fflush(stdin);

    FILE* fp=fopen("admindata.txt","r");
    if(!fp)
        printf("Error in opening file");
	char line[1024];
	int lc=0;
	for(char c=getc(fp); c!=EOF; c=getc(fp)) //counting number of lines in the database
	{
		if(c=='\n')
			++lc;
	}
    rewind(fp);
	int i=0;

    char user[100], pass[100];
    while (fgets(line,1024,(FILE*)fp) && i < lc) 
    {
        strcpy(user, strtok(line, ","));
        strcpy(pass, strtok(NULL, "\n"));
		
		if (strcmp(user,loginid) == 0)
        {
            if(strcmp(pass,password) ==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return -1;
        }
    }
	fclose(fp);
}


int checkcustomerlogin()
{
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


int checkdatabase(char * loginid,char * password)
{
    tmp=(customer*)malloc(sizeof(customer));
	tmp=cu;
	while (tmp != NULL) 
	{
		if (strcmp(tmp->id,loginid) == 0)
        {
            if(strcmp(tmp->password,password) ==0)
				return 1;
		}
		tmp = tmp->next; 
	}
	return 0;
    
}

void registerCustomer()
{
    printf("register\n");

    char loginid[100],password[100];
    int amount;
    customer *temp=(customer*)malloc(sizeof(customer));
    
    printf("Enter your Login ID: ");
    fflush(stdin);
    gets(loginid);
    printf("Enter your password: ");
    fflush(stdin);
    gets(password);
    fflush(stdin);
    printf("Enter your amount depositing: ");
    fflush(stdin);
    scanf("%d",&amount);
    
    strcpy(temp->id, loginid);
    strcpy(temp->password, password);
    temp->w_money = amount;
	temp->next=NULL;
	if(cu==NULL)
		{cu=temp;}
	else{
		temp->next=cu;
		cu=temp;
	}
}

void add_to_file()
{   
    FILE* fp1=fopen("customerdata.txt","w");
    if(!fp1)
        printf("Error in opening file");
    while(cu!=NULL)
    {
        fprintf(fp1,"%s,%s,%d\n", cu->id, cu->password, cu->w_money);
        cu=cu->next;
    }
    fclose(fp1);
}

void read_db_from_file()
{
    
    FILE* fp=fopen("customerdata.txt","r");
    if(!fp)
        printf("Error in opening file");
	char line[1024];
	int lc=0;
	for(char c=getc(fp); c!=EOF; c=getc(fp)) //counting number of lines in the database
	{
		if(c=='\n')
			++lc;
	}
    rewind(fp);
	int i=0;

    char user[100], pass[100];
    int money;
    customer *temp=(customer*)malloc(sizeof(customer));
    while (fgets(line,1024,(FILE*)fp) && i < lc) 
    {
        strcpy(temp->id, strtok(line, ","));
        strcpy(temp->password, strtok(NULL, ","));
        temp->w_money = atoi(strtok(NULL, "\n"));
		temp->next=NULL;
		
		
		if(cu==NULL)
		{cu=temp;}
		
		else
		{
			temp->next=cu;
			cu=temp;
		}
		
		i++;
		temp=NULL;
		temp=(customer*)malloc(sizeof(customer));
    }
	free(temp);
	fclose(fp);
}

int printall()
{
	customer *temp=(customer*)malloc(sizeof(customer));
	temp=cu;
	while (temp != NULL) 
	{
		printf("%s %s %d\n", temp->id, temp->password, temp->w_money);
        temp=temp->next;
	}
    free(temp);
	return 0;
}