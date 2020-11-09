//TP10: Inventario de Herramientas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES PARA inCheck
#define SILENT 1
#define NON_SILENT 0

typedef struct{
    int record;
    char nombre[80];
    int cantidad;
    float costo;
}herramienta;

int inCheck(int, int, int);
FILE *init(char *);
void print(FILE *);
void borrar(FILE *, int);
void create(FILE *, int);
int menu(void);
int float_int_compare(float, int);

int main(void){
    FILE *fp = fopen("hardware.dat", "rb+");
    if(fp == NULL){
        puts("El archivo \"hardware.dat\" no existe. Creando...");
        fp = init("hardware.dat");
    }
    int salir = 0;
    enum mode {PRINT = 1, CREATE, DELETE, OVERWRITE, QUIT};
    do{
        switch((enum mode) menu()){
            case PRINT:
                print(fp);
                break;
            case CREATE:
                printf("Ingrese el numero de registro del archivo que quiere crear/modificar: ");
                create(fp, inCheck(1,100, SILENT));
                break;
            case DELETE:
                printf("Ingrese el numero de registro a borrar\n");
                borrar(fp, inCheck(1,100, SILENT));
                break;
            case OVERWRITE:
                printf("Estas seguro? Los datos se perderan. Escribe S para confirmar: ");
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'S'){
                    puts("Sobreescribiendo...");
                    init("hardware.dat");
                }
                else
                    puts("Abortando...");
                break;
            case QUIT:
                salir = 1;
                break;
        }
    }while(!salir);
    fclose(fp);
    return 0;
}

int inCheck(int min, int max, int mode){
    int out;
    if (mode == NON_SILENT)
        printf("Su eleccion: ");
    do{
        scanf("%d", &out);
        if(out < min || out > max)
            printf("Opcion Invalida, intente nuevamente\n");
    }while(out < min || out > max);
    return out;
}

FILE *init(char *archivo){
    herramienta *inicial = calloc(100, sizeof(herramienta));
    for (int i = 0; i < 100; i++)
        *(inicial + i) = (herramienta) {i+1, "\0", 0, 0};
    FILE *file = fopen(archivo, "wb");
    fwrite(inicial, sizeof(herramienta), 100, file);
    free(inicial);
    return fopen(archivo, "rb+");
}

void print(FILE *file){
    int count = 0;
    herramienta tmp;
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < 100; i++){
        fread(&tmp, sizeof(herramienta), 1, file);
        if(tmp.cantidad != 0){
            count++;
            printf("\n%d\t%20s\t%d\t%.2f\n", tmp.record, tmp.nombre, tmp.cantidad, tmp.costo);
        }
    }
    if(count == 0)
        puts("\nNo hay registros aun...");
}

void borrar(FILE *file, int reg){
    herramienta tmp = (herramienta){reg, {(char)0}, 0, 0};
    fseek(file, sizeof(herramienta)*(reg-1), SEEK_SET);
    fwrite(&tmp, sizeof tmp, 1, file);
}

void create(FILE *file, int reg){
    herramienta tmp;
    int cantidad;
    float costo;
    char nombre[80];

    fseek(file, sizeof(herramienta)*(reg-1), SEEK_SET);
    fread(&tmp, sizeof tmp, 1, file);

    puts("\nBienvenido a la creacion/modificacion de registros!");
    puts("Si quiere mantener alguno de los datos, ingrese 0.");
    puts("De lo contrario, será modificado.");
    puts("Nota: Aquellos elementos sin cantidad serán guardados pero no listados");

    printf("\nIngrese el nombre de la Herramienta: ");
    scanf(" %[^\n]s", nombre);
    if (nombre[0] != '0')
        strcpy(tmp.nombre, nombre);

    printf("Ingrese la cantidad de esa herramienta: ");
    scanf("%d", &(cantidad));
    if (cantidad != 0)
        tmp.cantidad = cantidad;

    printf("Ingrese el costo unitario de la herramienta: ");
    scanf("%f", &(costo));
    if (!float_int_compare(costo, 0))
        tmp.costo = costo;

    fseek(file,sizeof(herramienta)*(reg-1), SEEK_SET);
    fwrite(&tmp, sizeof(herramienta), 1, file);
}

int menu(void){
    puts("\nMenu Principal\n");
    puts("1 - Mostrar Registros");
    puts("2 - Modificar/Crear Registro");
    puts("3 - Borrar Registro");
    puts("4 - Sobreescribir Archivo");
    puts("5 - Salir");
        return inCheck(1, 5, NON_SILENT);
}

int float_int_compare(float number, int value){
    const float error = 0.0005;
    return (number > (value - error) && number < (value + error));
}
//Thats a lot of lines
