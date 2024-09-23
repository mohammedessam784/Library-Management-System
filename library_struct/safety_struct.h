#ifndef SAFETY_H
#define SAFETY_H

typedef struct Ssafty
{
 u8 username[30];
 u8 password[30];
 u32 number_books;
 struct Ssafty *next;
 data_t* data_head;
}safty_t;

extern safty_t safty;
extern u32 user_numbers;
extern safty_t * current_user_number;
extern safty_t *head;




/*
login-->if you have account already
sign in--> create a new account
*/
void login();
void sign_in();
void password_test();
s32  sign_in_test();
void delete_account();



#endif





