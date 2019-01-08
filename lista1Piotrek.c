#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Person{
    char *name;
    int index;
}Person;

typedef struct List{
   Person *value;
   struct List *next;

}List;

void pause(){
        printf("Nacisniej c by kontynuowac\n");
        while( getchar() != 'c' );
}

void show(Person *person){
   printf("Imie: %s\nIndex: %d\n", person -> name, person -> index);

}

void showAll(List *head){
   if(head -> next != NULL){
    show(head -> next -> value);
    showAll(head -> next);
   }
}

Person* create(char name[30]){
    Person *person = (Person *) malloc(sizeof(Person));
    person -> name = (char *) malloc(sizeof(char) * 31);
    strcpy(person -> name, name);
    return person;
}

void add(List *head, char name[30]){
    if(head -> next != NULL){
        add(head -> next, name);
    } else {
        head -> next = (List *) malloc(sizeof(List));
        head -> next -> value = create(name);
        head -> next -> value -> index = head -> value -> index + 1;
    }

}


int main(void){
   List *head = (List *) malloc(sizeof(List));
   head -> value =(Person *) malloc(sizeof(Person));
   showAll(head);
   head -> value -> index = 0;
   char option = 's';

    char name[30];
    int index;

    bool hasEnded = false;
    while(!hasEnded){
        //system("clear");
        printf("Co chcesz robic?\n");
        printf("a - dodaj\n");
        printf("d - usun\n");
        printf("p - pokaz\n");
        printf("s - posortuj\n");
        printf("x - wyjdz\n");
        scanf("%c", &option);

         switch (option){
                case 'a':
                        printf("Podaj imie: ");
                        scanf("%s",&name);
                        add(head, name);
                        break;
                case 'p':
                        showAll(head);
                        pause();
                        break;
                case 's':
                        //sort(head);
                        showAll(head);
                        pause();
                        break;
                case 'd':
                        printf("Lista:\n");
                        showAll(head);
                        printf("Podaj indeks do usuniêcia: ");
                        scanf("%d", &index);
                        //delete(head, index);
                        break;
                case 'x':
                        hasEnded = true;
                        break;
                default:
                        printf("Nie ma takiej instrukcji!\n");
                        break;


         }
   }
   return 0;
}
