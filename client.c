#include "grocery.h"

int main()
{
    printf("Enter your choice : \n");
    printf("1. Login\n");
    printf("2. Register\n");
    int lr;
    scanf("%d",&lr);
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
                    break;
                
                case 2:
                    achk = checkadminlogin();
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
    return 0;
}