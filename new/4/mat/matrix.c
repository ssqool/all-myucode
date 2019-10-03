#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
   void *data;
   struct s_list *next;
} t_list;
t_list *mx_create_node(void *data);
t_list *mx_create_node(void *data) {
   t_list *new_point = malloc(sizeof(t_list));
   new_point -> data = data;
   new_point -> next = NULL;
   return new_point;
}
void mx_push_front(t_list **list, void *data) {
   t_list *first = mx_create_node(data);
   first -> data = data;
   first -> next = *list;
   *list = first;
}
void mx_push_back(t_list **list, void *data) {
   t_list *end = mx_create_node(data);
   if (*list == NULL) {
       end -> next = NULL;
       return;
   }
   t_list *p = *list;
   while (p -> next != NULL)
       p = p -> next;
   p -> next = end;
}
int mx_list_size(t_list *list) {
 int size = 1;
 while (list -> next != NULL) {
     list = list -> next;
     size++;
 }
 return size;
}
void mx_push_index(t_list **list, void *data, int index) {
 if (index <= 0) {
     mx_push_front(list, data);
 }
 else {
     t_list *way = NULL;
     t_list *temp = *list;
     for (int i = 0; i < index; i++) {
         way = temp;
         temp = temp -> next;
         if (temp == NULL) {
              mx_push_back(&way, data);
              return;
         }
     }
     t_list *new_elem = mx_create_node(data);
     new_elem -> next = temp;
     way -> next = new_elem;
 }
}
int main () {
  t_list *Head;
  char data1[] = "123";
  char data2[] = "456";
  char data3[] = "789";
  t_list *h = Head;
  t_list *way = NULL;
  h = mx_create_node(data1);
  Head = h;
  way = h;
  h = mx_create_node(data2);
  way -> next = h;
  way = h;
  h = mx_create_node(data3);
  way -> next = h;
  for(int i = 0; i <= data3; i++)
  	printf("%s\n", i);
  char data4[] = “hello”;
  mx_push_back(&Head, data4);
  //mx_push_index(&Head, data4, 10);
  //int size_list = mx_list_size(Head);
}