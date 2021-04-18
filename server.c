#include "grocery.h"
#include <string.h>

customer *cu;
customer *tmp;

int clear_input_buffer(void)
{
    int ch;
    while(((ch=getchar())!=EOF) && (ch != '\n'));
    return ch;
}

int checkadminlogin()
{
    char buff[15];
    int pass = 0;
    
    printf("\nEnter the password : \n");
    clear_input_buffer();
    gets(buff);

    if(strcmp(buff, "admin"))
    {
        printf ("\nWrong Password \n");
    }
    else
    {
        printf ("\nCorrect Password \n");
        pass = 1;
    }

    if(pass)
    {
        return(1);
    }
    else{
        return(0);
    }
}


void admin()
{
    printf("Welcome Admin!\nYou are now authorized to make changed\n");
}


int checkcustomerlogin()
{
    char loginid[100],password[100];
    int flag;
    printf("Enter your Login ID: ");
    scanf("%d\n",&flag);
    gets(loginid);
    printf("Enter your password: ");
    gets(password);
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
    printf("Registration\n");
    int amount;
    customer *temp=(customer*)malloc(sizeof(customer));

    char loginid[100],password[100];
    int flag;
    printf("Enter your Login ID: ");
    scanf("%d\n",&flag);
    gets(loginid);
    printf("Enter your password: ");
    gets(password);
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

void cart()
{
    //int sum_total;
    printf("\n\nSelect the items you want to buy : \n");
    printf("1. TOMATOES(1kg)-45Rs\n");
    printf("2. ONIONS(1kg)-30Rs\n");
    printf("3. RICE(2kgs)-15Rs\n");
    printf("4. SUGAR(3kgS)-96Rs\n");
    printf("5. POTATO(1KG-29Rs\n");
    int a;
    int q;
    scanf("%d",&a);
    printf("Enter quantity(kg) : ");
    scanf("%d",&q);

    switch (a)
    {
        case 1:
            if (tmp->w_money-(45*q)>=0)
            {
                tmp->w_money-=(45*q);
                printf("YOUR REMAINING BALANCE IS %d\n",tmp->w_money);
            }
            else
                printf("YOU HAVE INSUFFICIENT FUNDS, PLEASE ADD MONEY TO PROCEED WITH CART\n");
            break;

        case 2:
            if (tmp->w_money-(30*q)>=0)
            {
                tmp->w_money-=(30*q);
                printf("YOUR REMAINING BALANCE IS %d\n",tmp->w_money);
            }
            else
                printf("YOU HAVE INSUFFICIENT FUNDS, PLEASE ADD MONEY TO PROCEED WITH CART\n");
            break;

        case 3:
            if (tmp->w_money-(15*q)>=0)
            {
                tmp->w_money-=(15*q);
                printf("YOUR REMAINING BALANCE IS %d\n",tmp->w_money);
            }
            else
                printf("YOU HAVE INSUFFICIENT FUNDS, PLEASE ADD MONEY TO PROCEED WITH CART\n");
            break;

        case 4:
            if (tmp->w_money-(96*q)>=0)
            {
                tmp->w_money-=(96*q);
                printf("YOUR REMAINING BALANCE IS %d\n",tmp->w_money);
            }
            else
                printf("YOU HAVE INSUFFICIENT FUNDS, PLEASE ADD MONEY TO PROCEED WITH CART\n");
            break;

        case 5:
            if (tmp->w_money-(29*q)>=0)
            {
                tmp->w_money-=(29*q);
                printf("YOUR REMAINING BALANCE IS %d\n",tmp->w_money);
            }
            else
                printf("YOU HAVE INSUFFICIENT FUNDS, PLEASE ADD MONEY TO PROCEED WITH CART\n");
            break;

        default:
            printf("Invalid option\n");
            break;
    }
}