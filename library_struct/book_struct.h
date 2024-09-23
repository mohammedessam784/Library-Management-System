#ifndef BOOK_INVENTORY_H
#define BOOK_INVENTORY_H
typedef struct Ddata
{
 u8 book_name[30];
 u8 auther_name[30];
 u8 book_id[30];
 u32 book_prise;
 struct Ddata*next;
 struct Ddata*prv;
}data_t;

extern data_t*last_book;



void add_book();//book id can not repeated in same user name
void view_books();
//void delete_book();
u32 id_test(u8 z[],u32 ff);
#endif


