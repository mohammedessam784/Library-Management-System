#include"std_types.h"
#include"safety_struct.h"
#include"book_struct.h"
#include"nodes.h"
safty_t safty;
u32 user_numbers=0;
safty_t * current_user_number=0;
safty_t *head=0;



void sign_in()
{
    set_forward_node();

    printf("\nplease enter your username :");
    scanf(" %s",current_user_number->username);
    ////username can not repeated
    while(1)
       {
           if(sign_in_test())
           {
               printf("\nthis username is already exists\nenter anther username :");
               scanf(" %s",current_user_number->username);
           }
           else
           {
               break;
           }
       }
    ////
    printf("\nplease enter your password :");
    // scan password and appear as #
    u32 i=0;
    u8 ch;
    while((ch=_getch())!=13)
    {
       current_user_number->password[i]=ch;
        i++;
        printf("#");
    }
    current_user_number->password[i]='\0';

    printf("\nyour username and password saved");
    printf("\n************welcome to \"%s\" library************\n",current_user_number->username);
    current_user_number->number_books=0;
    user_numbers++;
}

void login()
{
    if (user_numbers==0)
    {
        printf("\nthere no accounts \nplease create a new account ");
        return;
    }
    else{}
    u8 username_check[30];
    printf("\nenter your username :");
    scanf(" %s",username_check);
    u32 flag=1;
    safty_t *temp=head;
    for(u32 i=0;i<user_numbers;++i)
    {
        if (!strcmp(temp->username,username_check))
         {
            flag=0;
            current_user_number=temp;
            password_test();
            printf("\n************welcome to \"%s\" library************\n",current_user_number->username);
            break;
         }
         else
         {
           temp=temp->next;
         }

    }

    if(flag)
    {
     printf("\nwrong username\ntry again :");
     login();
     return;
    }
     else{}


}

//الفانكشن دي بتتاكد ان الباسورد صح ولا لا
void password_test()
{    u8 password_check[30];
     printf("\nenter your password :");
    // scan password and appear as #
    u32 i=0;
    u8 ch;
    while((ch=_getch())!=13)
    {
       password_check[i]=ch;
        i++;
        printf("#");
    }
    password_check[i]='\0';

     while(strcmp(current_user_number->password,password_check))
     {
         if(strcmp(current_user_number->password,password_check))
         {
             printf("\nwrong password\ntry again :");
              // scan password and appear as #
              u32 i=0;
              u8 ch;
              while((ch=_getch())!=13)
              {
              password_check[i]=ch;
              i++;
              printf("#");
              }
             password_check[i]='\0';
         }

     }
}

s32  sign_in_test()
{
    safty_t *temp=head;
    for(u32 i=0;i<user_numbers;++i)
    {
       if(!strcmp(current_user_number->username,temp->username))
       {
           return 1;
       }
       else
        {
       temp=temp->next;
        }
    }

    return 0;
}



void delete_account()
{
    u8 x[30];
    printf("\nenter username of the account you want to remove : ");
    scanf( " %s",x);
    safty_t*temp =head;
    u32 flag=0;
    for(u32 i=1;i<=user_numbers;++i)
    {
        if(!strcmp(x,temp->username))
        {
            flag=1;
            current_user_number=temp;
            break;
        }
        else
        {
           temp=temp->next;
        }
    }
    ////////////
     if(0==flag)
     {
      printf("\nthis account not found ");
      current_user_number=head;
      return;
     }
     else
     {
        password_test();
     }
////////////


    while(current_user_number->number_books)
    {
        delete_node_d(1);
    }

     temp =head;
     for(u32 i=1;i<=user_numbers;++i)
     {
         if(!strcmp(current_user_number->username,temp->username))
        {
            delete_node(i);
            printf("\nthe account was deleted ");
            user_numbers--;
            break;
        }
        else
        {
            temp=temp->next;
        }
     }
     current_user_number=head;
}

