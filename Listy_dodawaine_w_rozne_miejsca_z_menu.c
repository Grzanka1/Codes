#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Lista{
    int data;
    struct Lista *next;
}list;

void add_on_last(list **first, int data){
    if ((*first)==NULL){
        (*first)=malloc(sizeof(list));
        (*first)->data=data;
        (*first)->next=NULL;
    }
    else{
        list *actual, *element;
        actual=(*first);
        while(actual->next!=NULL){
            actual=actual->next;
        }
        element=malloc(sizeof(list));
        element->data=data;
        element->next=NULL;
        actual->next=element;
    }
}
void add_on_first (list **first, int data){
    if ((*first)==NULL){
        (*first)=malloc(sizeof(list));
        (*first)->data=data;
        (*first)->next=NULL;
    }
    else{
        list *element;
        element=malloc(sizeof(list));
        element->next=(*first);
        element->data=data;
        (*first)=element;
    }
}
void print(list **first){
    list *wsk=(*first);
    while (wsk!=NULL){
        printf("%d ", wsk->data);
        wsk=wsk->next;
    }
    printf("\n");
}
void delete_element(list **first, int data){
    list* wsk=(*first);
    while (wsk->next!=NULL){
        if(wsk->data==data){
            list *usuwany=(*first);
            (*first) = wsk->next;
            free(usuwany);
            break;
        }
        if(wsk->next->data==data){
            list *usuwany=wsk->next;
            wsk->next=usuwany->next;
            free(usuwany);
            break;
        }
        else{
            wsk=wsk->next;
        }
    }
}
void add_elsewhere(list **first, int where, int data){
    list* wsk=(*first);
    if ((*first)==NULL){
        (*first)=malloc(sizeof(list));
        (*first)->data=data;
        (*first)->next=NULL;
    }
    else{
        int n=0;
        int flag=0;
        while (wsk->next!=NULL){
            if(n==0 && n==where){
                flag=1;
                break;
            }
            n=n+1;
            if (n==where){
                flag=1;
                break;
            }
            wsk=wsk->next;


        }
        if (flag==1){
            list* element;
            element=malloc(sizeof(list));
            if (n==0){
                element->next=(*first);
                element->data=data;
                (*first)=element;
            }
            else{
                //list*temp=wsk->next
                element->data=data;
                element->next=wsk->next;
                wsk->next=element;
            }
        }
    }
}
void sort(list**first){
    list *wsk=(*first);
    int temp;
    list *following=wsk->next;

    for (; wsk!=NULL; wsk=wsk->next){
       for (; following!=NULL; following=following->next){
            if (wsk->data > following->data){
              temp=wsk->data;
              wsk->data=following->data;
              following->data=temp;
           }
        }
    }
}
int main (void)
{


    list *first=NULL;
    int i =1;

    for (;i<6;i++){
        add_on_last(&first, 100-i);
    }

    int n;
    char option = 'c';
    int where;
    char cle_buffor[2];
    bool hasEnded = false;
    while(!hasEnded){
          //system("clear");
        printf("co chcesz robic?\n");
        printf("a - dodaj liczbe na poczatek\n");
        printf("d - usun dana liczbe\n");
        printf("p - dodaj liczbe w dowolnym miejscu\n");
        printf("x - wyjscie\n");
        scanf("%c",&option);
        switch(option){
            case 'a':
            printf("Podaj liczbê: \n");
            scanf("%d", &n);
            fgets(cle_buffor, 2, stdin);
            add_on_first(&first, n);
            break;
        case 'p':
            printf("Podaj gdzie: \n");
            scanf("%d", &where);
            fgets(cle_buffor, 2, stdin);
            printf("Podaj liczbê: \n");
            scanf("%d", &n);
            fgets(cle_buffor, 2, stdin);
            add_elsewhere(&first,where-1,n);
            break;
        case 'd':
            printf("Podaj liczbê: \n");
            scanf("%d", &n);
            fgets(cle_buffor, 2, stdin);
            delete_element(&first, n);
            break;
        case 'x':
            hasEnded = true;
            break;
        default:
             break;

          }

    }
    print (&first);
    /*add_on_first(&first, 2334);
    print (&first);

    add_on_first(&first, 4234);
    print (&first);
    delete_element(&first, 97);
    print (&first);
    sort(&first);
    print (&first);
    int where=6;
    add_elsewhere(&first,where-1,3);
    print (&first);*/
    return 0;


}
