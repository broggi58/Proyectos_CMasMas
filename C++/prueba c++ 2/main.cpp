#include <iostream>
#include <cstdio>

using namespace std;
/*
    Se piden 2 numeros por teclado y se alamcenan en 2 variables. Luego se muestra por pantalla la suma entre ellos.
    Se hace una pausa hasta que el usuario pulse intro y el programa termina.
*/

int main()
{
    int num_a,num_b;
    cout << "Escribi un numero a: ";
    cin >> num_a;
    fflush(stdin);
    cout << "\nEscribi un numero B: ";
    cin >> num_b;
    fflush(stdin);
    cout << "\n" << num_a <<"+"<< num_b <<"=" << num_a+num_b;


    cout << "\n Pulse intro para finalizar" << endl;
    cin.get();
    return 0;
}
