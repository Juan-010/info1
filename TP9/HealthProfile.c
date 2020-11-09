//TP9: Informatización de los registros de salud
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    float min;
    float max;
}range;

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha;

struct HealthProfile{
    char nombre[80];
    char apellido[80];
    char sexo[80];
    fecha nacimiento;
    float altura;
    float peso;
};

float BMI(struct HealthProfile);
int freqMax(struct HealthProfile);
range freqIdeal(struct HealthProfile);
int edad(fecha);
void carga(struct HealthProfile *);
void imprimir(struct HealthProfile *);

int main(void){
    struct HealthProfile paciente;
    struct HealthProfile *p = &paciente;
    carga(p);
    printf("\nFicha Medica HealthProfile\n");
    imprimir(p);
    printf("\nDatos extra\n");
    printf("\nBMI: %.2f\t", BMI(paciente));
    printf("Edad: %d años\n", edad(paciente.nacimiento));
    printf("Frecuencia Cardiaca Maxima: %d bpm\n", freqMax(paciente));
    printf("Frecuencia Cardiaca Ideal: %.2f bpm - %.2f bpm\n", freqIdeal(paciente).min, freqIdeal(paciente).max);
    return 0;
}
void imprimir(struct HealthProfile *p){
    printf("\nNombre: %s %s\t",p-> apellido, p -> nombre);
    printf("Genero: %s\n", p -> sexo);
    printf("Nacimiento: %d/%d/%d\n", p -> nacimiento.dia, p -> nacimiento.mes, p -> nacimiento.anio);
    printf("Altura: %.2f m\t", p -> altura);
    printf("Peso: %.2f kg\n", p -> peso);
    return;
}
float BMI(struct HealthProfile paciente){
    return paciente.peso / (paciente.altura * paciente.altura);
}
void carga(struct HealthProfile *p){
    printf("Ingrese su nombre: ");
    scanf(" %[^\n]s", p->nombre);
    printf("Ingrese su apellido: ");
    scanf(" %[^\n]s", p->apellido);
    printf("Ingrese su genero: ");
    scanf(" %[^\n]s", p->sexo);
    printf("Ingrese su fecha de nacimiento en el sig formato (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &(p -> nacimiento.dia), &(p -> nacimiento.mes), &(p -> nacimiento.anio));
    printf("Ingrese su altura en metros: ");
    scanf("%f", &(p->altura));
    printf("Ingrese su peso en kilogramos: ");
    scanf("%f", &(p->peso));
    return;
}
int edad(fecha nacimiento){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fecha actual = {tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900};

    if(actual.mes < nacimiento.mes || (actual.mes == nacimiento.mes && actual.dia < nacimiento.dia))
        actual.anio--;
    return actual.anio - nacimiento.anio;
}
int freqMax(struct HealthProfile paciente){
    return 220 - edad(paciente.nacimiento);
}
range freqIdeal(struct HealthProfile paciente){
    return (range){freqMax(paciente)*0.5, freqMax(paciente)*0.85};
}
