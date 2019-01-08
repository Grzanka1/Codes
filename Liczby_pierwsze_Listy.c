#include <stdio.h>
#include <stdlib.h>
typedef struct element {
struct element *next;
unsigned long val;
} el_listy;
el_listy *first;

void dodaj_do_listy (el_listy *lista, unsigned long liczba)
{
el_listy *wsk, *nowy;
wsk = lista;
while (wsk->next != NULL)
{
wsk = wsk->next; /* przesuwamy wsk a¿ znajdziemy ostatni element */
}
nowy = malloc (sizeof(el_listy));
nowy->val = liczba;
nowy->next = NULL;
wsk->next = nowy; /* podczepiamy nowy element do ostatniego z listy */
}
void wypisz_liste(el_listy *lista)
{
el_listy *wsk=lista;
while( wsk != NULL )
{
printf ("%lu\n", wsk->val);
wsk = wsk->next;
}
}
int jest_pierwsza(el_listy *lista, int liczba)
{
el_listy *wsk;
wsk = first;
while (wsk != NULL) {
if ((liczba%wsk->val)==0) return 0;
wsk = wsk->next;
}
return 1;
}
int main ()
{
unsigned long i = 3; /* szukamy liczb pierwszych w zakresie od 3 do 1000 */
const unsigned long END = 1000;
first = malloc (sizeof(el_listy));
first->val = 2;
first->next = NULL;
for (;i!=END;++i) {
if (jest_pierwsza(first, i))
dodaj_do_listy (first, i);
}
wypisz_liste(first);
return 0;
}
