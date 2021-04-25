#ifndef CONCURSANTES_H_INCLUDED
#define CONCURSANTES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int numeroConcursante;
    int anioDeNacimiento;
    char nombre[50];
    char dni[8];
    eFecha fechaPresentacion;
    char temaPresentacion[30];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float puntajePromedio;
}eConcursante;


#endif // CONCURSANTES_H_INCLUDED
