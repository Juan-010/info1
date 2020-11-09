#include <stdio.h>
union convert{
    float ieee_input;
    unsigned int analyzer;
};

struct float_ieee{
    unsigned int mantissa:23;
    unsigned int exp:8;
    unsigned int sign:1;
};

struct float_ieee get_ieee(float);
void print_bits(unsigned int, int);

int main(void){
    float numb;
    union convert input;
    printf("Ingrese un numero real:\n");
    scanf("%f", &numb);

    input.ieee_input = numb;
    print_bits(input.analyzer, 8 * sizeof(unsigned int));
    printf("\n\n");

    struct float_ieee converted = get_ieee(numb);
    printf("Mantisa: ");
    print_bits(converted.mantissa, 23);
    printf(" (%u)\n", converted.mantissa);

    printf("Exponente: ");
    print_bits(converted.exp, 8);
    printf(" (%u)\n", converted.exp);

    printf("Signo: ");
    print_bits(converted.sign, 1);
    printf(" (%u)\n", converted.sign);
    return 0;
}

struct float_ieee get_ieee(float num){
    union convert input = {.ieee_input = num};
    struct float_ieee converter = {.mantissa = input.analyzer, .exp = input.analyzer >> 23, .sign = input.analyzer >> 31};
    return converter;
}
void print_bits(unsigned int num, int bits){
    unsigned int mask = 1 << 31; //1000000 00000000 00000000 000000000
    for(int i = 0; i < 32; i++){
        if (i >= 32 - bits){
            if(!(i % 8) && i != 32 - bits)
                printf(" ");
            printf("%d", mask & num ? 1 : 0);
        }
        mask >>= 1;
    }
}
