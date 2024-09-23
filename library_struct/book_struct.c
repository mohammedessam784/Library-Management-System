#include"std_types.h"
#include"safety_struct.h"
#include"book_struct.h"
#include"nodes.h"
#include"sorting.h"
data_t*last_book=0;

void add_book()
{
      set_forward_node_d();/*create node to (pointer last_book) */
      printf("\nenter the name of the book:");
      scanf(" %[^\n]s",last_book->book_name);
      printf("\nenter the name of the auther:");
      scanf(" %[^\n]s",last_book->auther_name);
      printf("\nenter the id of the book:");
      scanf(" %s",last_book->book_id);
      ////book id can not repeated in same user name
       while(1)
       {
           if(id_test(last_book->book_id,-1))
           {
               printf("\nthis id is already exists\nenter anther id :");
               scanf(" %s",last_book->book_id);
           }
           else
           {
               break;
           }

       }
      ////
      printf("\nenter the prise of the book:");
      scanf(" %i",&(last_book->book_prise));
      printf("\nbook %d information was added successfully to \"%s\" library",++(current_user_number->number_books),current_user_number->username);

}
void view_books()
{/*default sorting(time)*/
   time_sorting();
}

void delete_book()
{
    u8 x[30];
    printf("\nenter the id of the book you want to remove : ");
    scanf( " %s",x);
    u16 i=0,flag=0;
    data_t*temp=current_user_number->data_head;
    //iterate to find id of delete book
    for(i=1;i<=current_user_number->number_books;++i)
    {
        if(!strcmp(x,temp->book_id))
        {
            flag=1;
            delete_node_d(i);
            printf("\nthe book was deleted from \"%s\" library",current_user_number->username);
            break;
        }
        else
        {
            temp=temp->next;
        }
    }

     if(0==flag)
     {
      printf("\nthis book not found ");
     }
}

//test to check the id can not repeated
u32 id_test(u8 z[],u32 ff)
{
    data_t*x=current_user_number->data_head;
    for(u32 i=1;i<=(current_user_number->number_books);++i)
    {
        if(i==ff)
        {
           x=x->next;
           continue;
        }
       else if(!strcmp(z,x->book_id))
       {
           return 1;
       }
       else
       {
          x=x->next;
       }
    }
    return 0;

}
void edit_book()
{

     if (current_user_number->number_books==0)
    {
        printf("\nno book added to \"%s\" library\n",current_user_number->username);
        return;
    }
    else{}

    u8 x[30];
    printf("\nenter the id of the book you want to edit : ");
    scanf( " %s",x);
    u16 i=0,flag=0;
    data_t*temp=current_user_number->data_head;
    //iterate to find id of edit book
    for(i=1;i<=current_user_number->number_books;++i)
    {
        if(!strcmp(x,temp->book_id))
        {
            flag=1;
            break;
        }
        else
        {
            temp=temp->next;
        }
    }

     if(0==flag)
     {
      printf("\nthis book not found ");
     }
     else
     {
      printf("\nenter the name of the book:");
      scanf(" %[^\n]s",temp->book_name);
      printf("\nenter the name of the auther:");
      scanf(" %[^\n]s",temp->auther_name);
      printf("\nenter the id of the book:");
      scanf(" %s",temp->book_id);
      ////book id can not repeated in same user name
       while(1)
       {
           if(id_test(temp->book_id,i))
           {
               printf("\nthis id is already exists\nenter anther id :");
               scanf(" %s",temp->book_id);
           }
           else
           {
               break;
           }

       }
      ////
      printf("\nenter the prise of the book:");
      scanf(" %i",&(temp->book_prise));
      printf("\nbook %d information was edited successfully in \"%s\" library",i,current_user_number->username);

     }
}





