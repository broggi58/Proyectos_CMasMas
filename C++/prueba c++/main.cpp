#include <iostream>

using namespace std;

/*
    Se pide que el usuario ingrese un numero por teclado y se lo alamcena en una variable. Se muestra por pantalla el
    doble del numero ingresado. Se hace una pausa hasta que el usuario pulse intro y el programa termina.
*/

int main()
{
    int numero;
    cout << "Escribi un numero perro \n";
    cin >> numero;
    cout << "el doble del numero es : " << numero*2;


    cout << "\n Pulse intro para finalizar." << endl;
    cin.get();
    return 0;
}
