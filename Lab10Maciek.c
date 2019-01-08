#include <stdio.h>
typedef struct{
    int dzien;
    int miesiac;
    int rok;
}przeglad;

typedef enum {czerwony, czarny, niebieski} kolor;

/*typedef struct{
    char marka[30];
    char naped[30];
    char drzwi[30];
    kolor kolor_auta;
    int cena;
    przeglad termin[10];
}osobowka;
typedef struct{
    char marka[30];
    int ladownosc;
    int liczba_osi;
    double dlugosc;
    int cena;
    przeglad termin[10];
}ciezarowka;
typedef struct{
    char marka[30];
    int liczba_miejsc;
    double dlugosc;
    int cena;
    przeglad termin[10];
}autobus;*/

typedef struct{
    char naped[30];
    char drzwi[30];
    kolor kolor_auta;
}osobowka;

typedef struct{
    int liczba_miejsc;
    double dlugosc;
}autobus;

typedef struct{
    int ladownosc;
    int liczba_osi;
    double dlugosc;
}ciezarowka;
typedef union{
    osobowka osob;
    autobus autob;
    ciezarowka ciezar;
}rodzaj;
typedef struct{
    char marka[30];
    int cena;
    przeglad termin[10];
    int selektor_unii;
    rodzaj jakie_auto;

}pojazd;





int main (void){
    osobowka trzy[3];
    //autobus *p=trzy;
    //p->marka="elo";
    //trzy->liczba_miejsc=32;
    trzy->kolor_auta="czerwony";
    printf("%s", trzy->kolor_auta);

}
