//TP11: Visualización del formato de una variable de tipo float usando el formato IEEE754
#include <stdio.h>
union convert{
    float ieee_input;
    unsigned int analyzer;
};
unsigned int get_ieee_mantissa(float);
unsigned int get_ieee_sign(float);
unsigned int get_ieee_exp(float);
void print_bits(unsigned int, int, char *);

int main(void){
    float numb;
    printf("Ingrese un numero real:\n");
    scanf("%f", &numb);

    unsigned int mantisa = get_ieee_mantissa(numb);
    unsigned int exp = get_ieee_exp(numb);
    unsigned int sign = get_ieee_sign(numb);

    print_bits(sign, 1, " ");
    print_bits(exp, 8, " ");
    print_bits(mantisa, 23, "\n\n");

    printf("Mantisa: ");
    print_bits(mantisa, 23, " ");
    printf("(%u)\n", mantisa);

    printf("Exponente: ");
    print_bits(exp, 8, " ");
    printf("(%u)\n", exp);

    printf("Signo: ");
    print_bits(sign, 1, " ");
    printf("(%u)\n", sign);
    return 0;
}

unsigned int get_ieee_mantissa(float num){
    union convert input = {.ieee_input = num};
    unsigned int mask = 0x7FFFFF; //0000(0) 0000(0) 0111(7) 1111(F) 1111(F) 1111(F) 1111(F) 1111(F)
    return input.analyzer & mask;
}

unsigned int get_ieee_exp(float num){
    union convert input = {.ieee_input = num};
    for (int i = 0; i < 23; i++){
        input.analyzer >>= 1;
    }
    unsigned int mask = 0xFF; //0000(0) 0000(0) 0000(0) 0000(0) 0000(0) 0000(0) 1111(F) 1111(F)
    return input.analyzer & mask;
}

unsigned int get_ieee_sign(float num){
    union convert input = {.ieee_input = num};
    for (int i = 0; i < 31; i++){
        input.analyzer >>= 1;
    }
    return input.analyzer;
}
void print_bits(unsigned int num, int bits, char *c){
    unsigned int mask = 1 << 31; //1000000 00000000 00000000 000000000
    for(int i = 0; i < 32; i++, mask >>= 1)
        if (i >= 32 - bits)
            printf("%d", mask & num ? 1 : 0);
    printf("%s", c);
}
