#include<stdio.h>
#include<string.h>
#include"std_types.h"
#include"book_struct.h"
#include"safety_struct.h"
#include"nodes.h"
#include"sorting.h"
/*
the program is library has users
ever user has his books alone (he can add,delete,edit,view...)
users can not have same username
users can  have same password
*/
//book id can not repeated in same user name
/*
login-->if you have account already
sign in--> create a new account
delete account-->delete every think in user's library(all book inserted in this account and username )
*/
/*
sorting
(1)time sorting(first in first out).
(2)inverse time sorting(first in last out).
(3)id sorting.---->(string)
(4)book name sorting.
*/

s32 main()
{
     printf("******************************************");
     printf("\n************welcome to library************");
     printf("\n******************************************");
     sign_in();

     while(1)
     {
        u8 mode;
        printf("\n\nselect what mode you need\n(1)add book.\n(2)delete book. \n(3)edit book. \n(4)view books.\n(5)sorting and view books.\n(6)logout.\n(7)exit from library.");
        scanf(" %c",&mode);
        switch(mode)
        {
          case '1':

              add_book();
              break;
          case '2':
              delete_book();
              break;
            case '3':
              edit_book();
              break;
          case '4':
              view_books();
              break;
          case '5':
              sorting_and_view();
              break;
          case '6':
              {  printf("\ndone");
                 u8 x;
                 logout:
                 printf("\n\ndo you need\n  (1)login.\n  (2)sign in.\n  (3)delete account. \n  (4)exit from library.");
                 scanf(" %c",&x);
                 switch(x)
                 {
                    case '1':
                        login();
                        if (user_numbers==0)
                        {
                           goto logout;
                        }
                        break;
                    case '2':
                        sign_in();
                        break;
                    case '3':
                        delete_account();
                        goto logout;
                        break;
                    case '4':
                        printf("\n*************************************************");
                        printf("\n*********************goodbye*********************");
                        printf("\n*************************************************");
                        return 0;
                        break;
                    default:
                       printf("\nthis input not valid");
                       break;

                 }
              }
              break;
          case '7':
               printf("\n*************************************************");
               printf("\n*********************goodbye*********************");
               printf("\n*************************************************");
              return 0;
              break;
          default:
              printf("\nthis input not valid");
              break;
        }
     }


}
