#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Arbiter{
    char *lastname;
    int id;
}Arbiter;

typedef struct List{
   Arbiter *value;
   struct List *next;
}List;

void pause(){
    printf("nacisnij c aby kontynuowaæ\n");
    while(getchar() != 'c');
}

void show(Arbiter *arbiter){
   printf("Sêdzia: %s\nID: %d \n", arbiter->lastname, arbiter->id);
}

void showAll(List *head){
    if(head->next != NULL){
    show(head->next->value);
    printf("\n");
    showAll(head->next);
    }
}

Arbiter* create(char name[30]){
    Arbiter *arbiter = (Arbiter *) malloc(sizeof(Arbiter));
    arbiter->lastname = (char *) malloc(sizeof(char)*31);
    strcpy(arbiter->lastname, name);
    return arbiter;
}

void add(List *head, char name[30]){

   if(head->next == NULL){
    head->next = (List *) malloc(sizeof(List));
    //head->next->value = (Arbiter *) malloc(sizeof(Arbiter));
    head->next->value = create(name);
    head->next->value->id = head->value->id + 1;
   } else {
    add(head->next, name);
   }
}

int main(void){
   List *head = (List *) malloc(sizeof(List));
   head->value = (Arbiter *) malloc(sizeof(Arbiter));
   head->value->id = 0;

   char lastname[30];
   char option = 'c';
   bool hasEnded = false;
   while(!hasEnded){
      //system("clear");
      printf("co chcesz robiæ?\n");
      printf("a - dodaj sêdziego\n");
      printf("p - poka¿ sêdziow\n");
      printf("x - wyjœcie\n");
      scanf("%c",&option);
      switch(option){
         case 'a':
         printf("Podaj nazwisko: \n");
         scanf("%s", &lastname);
         add(head, lastname);
         break;
     case 'p':
         showAll(head);
         pause();
         break;
     case 'x':
         hasEnded = true;
         break;
    default:
         break;

      }
   }
   return 0;
}
