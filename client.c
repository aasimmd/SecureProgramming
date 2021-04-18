#include "grocery.h"


int main()
{
    read_db_from_file();
    char buff[15];
    //printall();
    printf("Enter your choice : \n");
    printf("1. Login\n");
    printf("2. Register\n");
    gets(buff);
    int lr=atoi(buff);
    switch (lr)
    {
        case 1:
            printf("Enter choice : \n");
            printf("1. Customer\n");
            printf("2. Admin\n");
            int ac,cchk,achk;
            scanf("%d", &ac);
            switch (ac)
            {
                case 1:
                    cchk = checkcustomerlogin();
                    printf("%d\n",cchk);
                    if(cchk==1)
                    {
                        printf("%s\n", tmp->id);
                        printf("%d", tmp->w_money);
                        cart();
                    }
                    break;
                
                case 2:
                    achk = checkadminlogin();
                    printf("%d\n",achk);
                    if(achk)
                        admin();
                    break;

                default:
                    printf("Invalid option");
                    break;
            }
            break;

        case 2:
            registerCustomer();
            break;
        
        default:
            printf("Invalid Option");
            break;
    }

    add_to_file();
    return 0;
}