#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


typedef struct Person{
    char name[20];
    char lastname[30];
    int index;
    //struct Person *next;
}Person;

typedef struct List{
        Person *value;
        struct List *next;
}List;

void show(Person *person){
    printf("Nazwisko: %s\nImie: %s\nIndeks: %d\n\n",person -> lastname, person -> name, person -> index);
}

void showAll(List *people){
    if(people -> next  != NULL){
        show(people -> next -> value);
        showAll(people -> next);
    }
}

Person* create(char name[20], char lastname[30]){

    Person *person = malloc(sizeof(Person));
    strcpy(person -> name, name);
    strcpy(person -> lastname, lastname);
    return person;
}

int lengthOfList(List *list, int number){
    if(list -> next == NULL) return number;
    else return lengthOfList(list -> next, number + 1);
}

int len(List *list){
    return lengthOfList(list, 0);
}

int freeIndex(List *list, int i, List *first){
    if(list -> next  == NULL) return i;
    if(list -> next -> value -> index != i){
        return freeIndex(list -> next, i, first);
    } else if (list -> next -> value -> index == i, first){
        return freeIndex(first, ++i, first);
    }
}


bool personCompare(Person *p1, Person *p2){
    char fullName1[50];
    strcpy(fullName1, p1 -> lastname);
    strcat(fullName1, p1 -> name);

    char fullName2[50];
    strcpy(fullName2, p2 -> lastname);
    strcat(fullName2, p2 -> name);

    int length1 = strlen(fullName1);
    int length2 = strlen(fullName2);

    int length = (length1 > length2) ? length2 : length1;
    for(int i = 0; i < length; i++){
        if( fullName1[i] > fullName2[i]) return true;
        else if(fullName1[i] < fullName2[i]) return false;
    }
    return false;


    //return strcmp(fullName1, fullName2);
}


void addAtEnd(List *list, Person *person){
        if(list -> next == NULL){
        list -> next = (List *) malloc(sizeof(List));
        list -> next -> value = person;
    } else {
        addAtEnd(list -> next, person);
    }
}
/*
void alphaAdd(List *list, Person *person){
    if(len(list) == 0) addAtEnd(list, person);
    else{
        if( ! personCompare(person, list -> next -> value)){

            //person -> next = malloc(sizeof(Person));
            person -> next = list -> next -> value;

            list -> next = (List *) malloc(sizeof(List));
            list -> next -> value = person;

        } else {
            alphaAdd(list -> next, person);
        }
    }
}
*/

void add(List *list, char name[20], char lastname[30]){
    Person *person = create(name, lastname);
    person -> index = freeIndex(list, 1, list);
    addAtEnd(list, person);
}

void delete(List *list, int index){
    if(list -> next -> value != NULL){
        if(list -> next -> value -> index == index){
            list -> next = list -> next -> next;
        } else {
            delete(list -> next, index);
        }
    }
}

void bubblesort(List *list, List *nextIteration){
    if(nextIteration != NULL){
       if(list -> next != NULL){
          if(list -> next -> next != NULL){
             Person p1 = *list -> next -> value;
         Person p2 = *list -> next -> next -> value;
         if( personCompare(&p1,&p2)){
                    *list -> next -> value = p2;
            *list -> next -> next -> value = p1;
         }
          }
          bubblesort(list -> next, nextIteration);
       }
       bubblesort(nextIteration, nextIteration -> next);
    }

}

void sort(List *list){
   bubblesort(list, list -> next);
}

void pause(){
    printf("Nacisniej c by kontynuowac\n");
        while( getchar() != 'c' );
}

int main(void){

    List *head = (List *) malloc(sizeof(List));

    char option = 's';

    char name[20];
    char lastname[30];
    int index;

    bool hasEnded = false;
    while(!hasEnded){
    system("clear");
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
                printf("Podaj nazwisko: ");
                scanf("%s", &lastname);
            add(head, name, lastname);
            break;
                case 'p':
                    showAll(head);
            pause();
            break;
        case 's':
            sort(head);
            showAll(head)
            pause();
            break;
        case 'd':
            printf("Lista:\n");
            showAll(head);
            printf("Podaj indeks do usuniêcia: ");
            scanf("%d", &index);
            delete(head, index);
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
