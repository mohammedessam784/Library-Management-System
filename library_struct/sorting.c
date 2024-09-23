#include"std_types.h"
#include"book_struct.h"
#include"safety_struct.h"
#include"nodes.h"


void time_sorting()
{
     printf("\ninformation \"%s\" library\n",current_user_number->username);
    if (current_user_number->number_books==0)
    {
        printf("\nno book added to \"%s\" library\n",current_user_number->username);
        return;
    }
    else{}
    data_t*x=current_user_number->data_head;
    for(u16 i=0;i<current_user_number->number_books;++i)
    {
        printf("\nbook %d information: ",1+i);
        printf("\nthe name of the book: %s",x->book_name);
        printf("\nthe name of the auther: %s",x->auther_name);
        printf("\nthe id of the book: %s",x->book_id);
        printf("\nthe prise of the book: %i",x->book_prise);
        printf("\n_______________________________");
        x=x->next;
    }

}
void inverse_time_sorting()
{
     printf("\ninformation \"%s\" library\n",current_user_number->username);
    if (current_user_number->number_books==0)
    {
        printf("\nno book added to \"%s\" library\n",current_user_number->username);
        return;
    }
    else{}
    data_t*x=last_book;
    for(u32 i=0;i<current_user_number->number_books;++i)
    {
        printf("\nbook %d information: ",1+i);
        printf("\nthe name of the book: %s",x->book_name);
        printf("\nthe name of the auther: %s",x->auther_name);
        printf("\nthe id of the book: %s",x->book_id);
        printf("\nthe prise of the book: %i",x->book_prise);
        printf("\n_______________________________");
        x=x->prv;
    }
}
void id_sorting()
{
    printf("\ninformation \"%s\" library\n",current_user_number->username);
    if (current_user_number->number_books==0)
    {
        printf("\nno book added to \"%s\" library\n",current_user_number->username);
        return;
    }
    else{}

    typedef struct temp_id
    {
      u8 book_name[30];
      u8 auther_name[30];
      u8 book_id[30];
      u32 book_prise;
    }temp_id_t;

    temp_id_t * p=malloc(current_user_number->number_books*sizeof( temp_id_t));
    if(p==0){printf("\nno memory valid\n"); return;}

     data_t*x=last_book;
    for(u32 i=0;i<current_user_number->number_books;++i)
    {
       strcpy((p+i)->book_name,x->book_name);
       strcpy((p+i)->auther_name,x->auther_name);
       strcpy((p+i)->book_id,x->book_id);
       (p+i)->book_prise=x->book_prise;
        x=x->prv;
    }

    for(u32 i=0;i<current_user_number->number_books-1;++i)
    {
         for(u32 j=i+1;j<current_user_number->number_books;++j)
         {
           if(strcmp(p[i].book_id,p[j].book_id)==1)
           {
                temp_id_t temp1=p[i];
                p[i]=p[j];
                p[j]=temp1;

           }
           else{}

         }

    }

    for(u32 i=0;i<current_user_number->number_books;++i)
      {
         printf("\nbook %d information: ",1+i);
        printf("\nthe name of the book: %s",(p+i)->book_name);
        printf("\nthe name of the auther: %s",(p+i)->auther_name);
        printf("\nthe id of the book: %s",(p+i)->book_id);
        printf("\nthe prise of the book: %i",(p+i)->book_prise);
        printf("\n_______________________________");
      }

      free(p);
}

void book_name_sorting()
{
     printf("\ninformation \"%s\" library\n",current_user_number->username);
    if (current_user_number->number_books==0)
    {
        printf("\nno book added to \"%s\" library\n",current_user_number->username);
        return;
    }
    else{}

    typedef struct temp_book_name
    {
      u8 book_name[30];
      u8 auther_name[30];
      u8 book_id[30];
      u32 book_prise;
    }temp_book_name_t;

    temp_book_name_t * p=malloc(current_user_number->number_books*sizeof( temp_book_name_t));
    if(p==0){printf("\nno memory valid\n"); return;}

     data_t*x=last_book;
    for(u32 i=0;i<current_user_number->number_books;++i)
    {
       strcpy((p+i)->book_name,x->book_name);
       strcpy((p+i)->auther_name,x->auther_name);
       strcpy((p+i)->book_id,x->book_id);
       (p+i)->book_prise=x->book_prise;
        x=x->prv;
    }

    for(u32 i=0;i<current_user_number->number_books-1;++i)
    {
         for(u32 j=i+1;j<current_user_number->number_books;++j)
         {
           if(strcmp(p[i].book_name,p[j].book_name)==1)
           {
                temp_book_name_t temp1=p[i];
                p[i]=p[j];
                p[j]=temp1;

           }
           else{}

         }

    }


    for(u32 i=0;i<current_user_number->number_books;++i)
      {
         printf("\nbook %d information: ",1+i);
        printf("\nthe name of the book: %s",(p+i)->book_name);
        printf("\nthe name of the auther: %s",(p+i)->auther_name);
        printf("\nthe id of the book: %s",(p+i)->book_id);
        printf("\nthe prise of the book: %i",(p+i)->book_prise);
        printf("\n_______________________________");
      }

      free(p);
}
void sorting_and_view()
{
    u8 sw_sortig='1';
    sw_sort:
    printf("\n\nselect type of sorting you need\n   (1)time sorting(first in first out).\n   (2)inverse time sorting(first in last out). \n   (3)id sorting.\n   (4)book name sorting.");
        scanf(" %c",&sw_sortig);
     switch(sw_sortig)
    {
    case '1':
        time_sorting();
        break;
    case '2':
        id_sorting();
        break;
    case '3':
        id_sorting();
        break;
    case '4':
        book_name_sorting();
        break;
    default:
        printf("\n   this input not valid");
        goto sw_sort;
        break;
    }

}
