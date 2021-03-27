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
            int ac;
            scanf("%d", &ac);
            switch (ac)
            {
                case 1:
                    int cchk = checkcustomerlogin();
                    break;
                
                case 2:
                    int achk = checkadminlogin();
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