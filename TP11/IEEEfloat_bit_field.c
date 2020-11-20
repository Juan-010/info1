//TP11: Visualización del formato de una variable de tipo float usando el formato IEEE754 con Campos de Bits
#include <stdio.h>
struct float_ieee{
    unsigned int mantissa:23;
    unsigned int exp:8;
    unsigned int sign:1;
};
union convert{
    float ieee_input;
    struct float_ieee analyzer;
};
unsigned int get_ieee_mantissa(float);
unsigned int get_ieee_sign(float);
unsigned int get_ieee_exp(float);
void print_bits(unsigned int, int, char *);

int main(void){
    float numb;
    printf("Ingrese un numero real: ");
    scanf("%f", &numb);
    struct float_ieee input;

    input.mantissa = get_ieee_mantissa(numb);
    input.exp = get_ieee_exp(numb);
    input.sign = get_ieee_sign(numb);

    print_bits(input.sign, 1, " ");
    print_bits(input.exp, 8, " ");
    print_bits(input.mantissa, 23, "\n\n");

    printf("Mantisa: ");
    print_bits(input.mantissa, 23, " ");
    printf("(%u)\n", input.mantissa);

    printf("Exponente: ");
    print_bits(input.exp, 8, " ");
    printf("(%u)\n", input.exp);

    printf("Signo: ");
    print_bits(input.sign, 1, " ");
    printf("(%u)\n", input.sign);
    return 0;
}

unsigned int get_ieee_mantissa(float num){
    union convert input = {num};
    return input.analyzer.mantissa;
}

unsigned int get_ieee_exp(float num){
    union convert input = {num};
    return input.analyzer.exp;
}

unsigned int get_ieee_sign(float num){
    union convert input = {num};
    return input.analyzer.sign;
}

void print_bits(unsigned int num, int bits, char *c){
    unsigned int mask = 1 << 31; //1000000 00000000 00000000 000000000
    for(int i = 0; i < 32; i++, mask >>= 1)
        if (i >= 32 - bits)
            printf("%d", mask & num ? 1 : 0);
    printf("%s", c);
}
