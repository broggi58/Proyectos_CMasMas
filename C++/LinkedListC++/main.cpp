#include <iostream>
struct t_nodo {
int numero;
t_nodo *siguiente;
};
using namespace std;
void limpiar_buffer()
{
    int ch;
while ((ch = fgetc(stdin)) != EOF) ;
}
void insertar_al_principio (struct t_nodo *&p)
{
struct t_nodo *nuevo_nodo;
/* Creamos el nuevo nodo */
nuevo_nodo = new struct t_nodo;
/* Rellenamos los campos de datos */
cout << "\nEscriba un numero: ";
limpiar_buffer();
cin >> nuevo_nodo->numero;
/* Insertamos el nuevo nodo al principio de la lista */
/* El campo 'siguiente' del nuevo nodo apunta al mismo nodo
que 'p', es decir, que 'principio'. */
nuevo_nodo->siguiente = p;
/* 'p', es decir, 'principio', apunta al nuevo nodo. */
p = nuevo_nodo;
}
void insertar_al_final (struct t_nodo *&p)
{
struct t_nodo *nuevo_nodo;
/* 'aux' sirve para recorrer la lista */
struct t_nodo *aux;
/* Creamos el nuevo nodo */
nuevo_nodo = new struct t_nodo;
/* Rellenamos los campos de datos */
cout << "\nEscriba un numero: ";
limpiar_buffer();
cin >> nuevo_nodo->numero;
/* El campo siguiente es igual a NDLL porque va a ser el ultimo
nodo de la lista. */
nuevo_nodo->siguiente = NULL;
/* Insertamos el nuevo nodo al final de la lista */
/* Si 'p' es distinto de NDLL es que la lista no esta vacia. */
if (p!=NULL)
    {
/* con ‘aux' recorremos la lista desde 'p', es decir, desde el 'principio',
en busca del ultimo nodo, que tiene el campo siguiente a NULL. */
aux = p;
while (aux->siguiente != NULL)
{
aux = aux->siguiente;
}
/* El campo siguiente del ultimo nodo apunta al nuevo nodo */
aux->siguiente = nuevo_nodo;
}
else
{
/* Si la lista esta vacia 'p', es decir,
'principio' apunta al nuevo nodo. */
p = nuevo_nodo;
}
}
void insertar_ordenado (struct t_nodo *&p)
{
struct t_nodo *nuevo_nodo;
/* 'anterior' y 'actual' se utilizan para recorrer la lista y
encontrar la posición donde insertar el nuevo nodo. */
struct t_nodo *anterior;
struct t_nodo *actual;
/* Creamos el nuevo nodo */ nuevo_nodo = new struct t_nodo;
/* Rellenamos los campos de datos */
cout << "\nEscriba un numero:"<< endl;
limpiar_buffer();
cin >> nuevo_nodo->numero;
/* Insertamos el nuevo nodo al final de la lista */
/* 'actual' apunta inicialmente a 'p', que es 'principio' */
actual = p;
/* Mientras no se llegue al final de la lista (actual!=NULL) y el
numero del nodo en el que nos encontramos sea menor que el numero
del nodo nuevo (actual->numero < nuevo_nodo->numero) avanzamos
por la lista. */
while ((actual!=NULL) && (actual->numero < nuevo_nodo->numero))
    {
/* 'anterior' apunta al mismo nodo que 'actual' */
anterior = actual;
/* Hacemos que 'actual' apunte al siguiente nodo */ actual
= actual->siguiente;
}
/* Si 'actual' es igual a 'p' es que hay que insertarlo
al principio. */ if (actual==p)
{
nuevo_nodo->siguiente = p;
p = nuevo_nodo;
}
else
{
/* Si no se inserta al principio, se inserta entre
'anterior' y 'actual', de forma que el siguiente a
'anterior' es el nuevo nodo y el siguiente al nuevo nodo
es 'actual'. */ anterior->siguiente = nuevo_nodo;
nuevo_nodo->siguiente = actual;
}
}
void borrar (struct t_nodo *&p)
{
/* 'anterior' y 'actual' se utilizan para recorrer la
lista y encontrar el nodo a eliminar. */
struct t_nodo *anterior;
struct t_nodo *actual;
int numero;
/* Pedimos el numero a borrar de la lista */
cout << "\nEscriba un numero: ";
cin >> numero;
/* Borramos el nodo correspondiente al numero indicado
por el usuario. */
/* 'actual' apunta inicialmente a 'p', que es 'principio' */
actual = p;
/* Mientras no se llegue al final de la lista (actual!=NULL) y el
numero del nodo en el que nos encontramos sea distinto del numero
buscado (actual->numero != numero) avanzamos por la lista */
while ((actual!=NULL) && (actual->numero != numero))
{
/* 'anterior' apunta al mismo nodo que 'actual' */
anterior = actual;
/* Hacemos que 'actual' apunte al siguiente nodo */
actual = actual->siguiente;
}
/* Si 'actual' es distinto de NULL es que el numero
buscado esta en la lista y 'actual' apunta a su nodo */
if (actual!=NULL)
{
/* Si 'actual' es igual a 'p' es que el nodo a borrar
es el primero. */
if (actual==p)
!
/* Hacemos que 'p' apunte al siguiente nodo
a borrar y el campo siguiente lo ponemos a
NULL. Después borramos el nodo liberando su
memoria. */
p = actual->siguiente;
actual->siguiente = NULL;
delete actual;
}
else
{
/* Hacemos que en nodo anterior al que queremos
borrar apunte al siguiente del que queremos
borrar. El campo siguiente el nodo a borrar lo
ponemos a NULL. Después borramos el nodo liberando
su memoria. */ anterior->siguiente =
actual->siguiente; actual->siguiente = NULL;
delete actual;
}
}
void buscar (struct t_nodo *&p)
{
/* 'actual' se utiliza para recorrer la lista */
struct t_nodo *actual;
/* 'encontrado' indica si se ha encontrado el
numero (encontrado vale 1) o no (encontrado vale
0). Partimos del supuesto de que no se ha
encontrado. */
int encontrado = 0;
int numero;
/* Pedimos el numero a buscar en la lista */
cout << "\nEscriba un numero: ";
cin >> numero;
/* Buscamos el nodo correspondiente al numero indicado
por el usuario. */
/* 'actual' apunta inicialmente a 'p', que es
'principio' */ actual = p;
/* Mientras no se llegue al final de la lista
(actual!=NULL) y no se encuentre el numero buscado
(encontrado == 0) seguimos recorriendo las lista. */
while ( (actual!=NULL) && (encontrado == 0))
{
/* Si encontramos el numero damos el valor 1 a
encontrado. */
if (actual->numero == numero) encontrado = 1;
/* Hacemos que 'actual' apunte al siguiente nodo */
actual = actual->siguiente;
}
/* Mostramos un mensaje indicando si el numero buscado
esta o no en la lista. */
if (encontrado == 1)
cout << "\nEl numero esta en la lista";
else
cout << "\nEl numero no esta en la lista";
}
void mostrar (struct t_nodo *&p)
{
/* 'actual' se utiliza para recorrer la lista */
struct t_nodo *actual;
/* 'actual' apunta inicialmente a 'p', que es
'principio' */ actual = p;
/* Si 'p' es igual a NULL es que la lista esta vacia */
if (p==NULL)
    {
cout << "\nLa lista esta vacia."<<endl;}
{
else
{
/* Si la lista no esta vacia la recorremos
y mostramos el campo numero. */
while (actual!=NULL)
{
cout << actual->numero << " ";
actual = actual->siguiente;
}
}
}
void borrar_todo (struct t_nodo *&p)
{
/* 'nodo_a_borrar' se apunta al nodo a borrar */
struct t_nodo *nodo_a_borrar;
while (p!=NULL)
{
/* Hacemos que el 'nodo_a_borrar' apunte al
primer nodo */ nodo_a_borrar = p;
/* Hacemos que ' p' apunte al siguiente nodo a
borrar y el campo siguiente lo ponemos a NULL.
Después borramos el nodo liberando su memoria.
*/ p = p->siguiente; nodo_a_borrar->siguiente =
NULL; delete nodo_a_borrar;
}
}

int main (void)
{
struct t_nodo *principio = NULL;
cout << "\n -- Insertar al principio ---- ";
insertar_al_principio (principio);
cout << "\n --- Insertar al final ---";
insertar_al_final (principio);
cout << "\n --- Insertar ordenado ---";
insertar_ordenado (principio);
cout << "\n --- Borrar ---";
borrar (principio);
cout << "\n --- Buscar ---";
buscar (principio);
cout << "\n --- Mostrar --";
mostrar (principio);
borrar_todo (principio);
/* Hacemos una pausa hasta que el usuario pulse Intro */
fflush(stdin);
cout << "\nPulse Intro para finalizar...";
cin.get();
return 0;
}
