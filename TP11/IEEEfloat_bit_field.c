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

unsigned int get_ieee_mantissa(float);
unsigned int get_ieee_sign(float);
unsigned int get_ieee_exp(float);
void print_bits(unsigned int, int);

int main(void){
    float numb;
    union convert input;
    printf("Ingrese un numero real:\n");
    scanf("%f", &numb);
    input.ieee_input = numb;
    print_bits(input.analyzer, 8 * sizeof(unsigned int));
    printf("\n\n");

    printf("Mantisa: ");
    print_bits(get_ieee_mantissa(numb), 23);
    printf(" (%u)\n", get_ieee_mantissa(numb));

    printf("Exponente: ");
    print_bits(get_ieee_exp(numb), 8);
    printf(" (%u)\n", get_ieee_exp(numb));

    printf("Signo: ");
    print_bits(get_ieee_sign(numb), 1);
    printf(" (%u)\n", get_ieee_sign(numb));
    return 0;
}

unsigned int get_ieee_mantissa(float num){
    union convert input = {.ieee_input = num};
    struct float_ieee converter = {.mantissa = input.analyzer};
    return converter.mantissa;
}

unsigned int get_ieee_exp(float num){
    union convert input = {.ieee_input = num};
    struct float_ieee converter = {.exp = input.analyzer >> 23};
    return converter.exp;
}

unsigned int get_ieee_sign(float num){
    union convert input = {.ieee_input = num};
    struct float_ieee converter = {.sign = input.analyzer >> 31};
    return converter.sign;
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
