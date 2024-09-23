#include"std_types.h"
#include"safety_struct.h"
#include"book_struct.h"
#include"nodes.h"
void delete_node_d(int x)
{
    data_t*temp=current_user_number->data_head;
     if(x==1&&current_user_number->number_books==1)
     {
         free(temp);
     }
     else if(x==1)
    {
       current_user_number->data_head=temp->next;
       (current_user_number->data_head)->prv=0;
        free(temp);
    }
    else
    {
        for(u32 i=1;i<x;i++)
        {
            temp=temp->next;
        }
        (temp->next)->prv=temp->prv;
        (temp->prv)->next=temp->next;
        free(temp);
    }
    (current_user_number->number_books)--;

}




void set_frist_node_d()
{
    data_t*ptr=( data_t*)malloc(sizeof( data_t));
    if(ptr==0){printf("\nno memory valid\n"); return;}
    //printf("\nthe node inserted successfully\n");
    current_user_number->data_head=ptr;
    last_book=ptr;
    ptr->next=0;
    ptr->prv=0;

}
void set_forward_node_d()
{
      if(current_user_number->number_books==0)
      {
       set_frist_node_d();
      }
      else{
          data_t*ptr=( data_t*)malloc(sizeof( data_t));
          if(ptr==0){printf("\nno memory valid\n"); return;}
         // printf("\nthe node inserted successfully\n");
          ptr->next=0;
          last_book->next=ptr;
          ptr->prv=last_book;
          last_book=ptr;
      }

}

///////////////////////////////////////////////////////////////////////////
void delete_node(int x)
{
    safty_t*temp=head;
     if(x==1&&user_numbers==1)
     {
         free(temp);
         head=0;
     }
     else if(x==1)
    {
        head=temp->next;
        free(temp);
    }
    else
    {
        safty_t*temp1=head;
        for(u32 i=1;i<x;i++)
        {
            temp1=temp;
            temp=temp->next;
        }
         temp1->next=temp->next;
         free(temp);
    }
}

void set_frist_node()
{
    safty_t*ptr=(safty_t*)malloc(sizeof( safty_t));
    if(ptr==0){printf("\nno memory valid\n"); return;}
   // printf("\nthe node inserted successfully\n");
    head=ptr;
    ptr->next=0;
    current_user_number=ptr;
}
void set_forward_node()
{
    if(user_numbers==0)
    {
        set_frist_node();
    }
    else
    {
        safty_t*temp=head;
        while(temp->next!=0)
        {
           temp=temp->next;
        }

          safty_t*ptr=( safty_t*)malloc(sizeof( safty_t));
          if(ptr==0){printf("\nno memory valid\n"); return;}
         // printf("\nthe node inserted successfully\n");
          ptr->next=0;
          temp->next=ptr;
          current_user_number=ptr;

    }
}
