#include "include/ft_printf.h"
#include <stdio.h>

int main(void) {
    // Testes para inteiros
    ft_printf("Teste 1: %%d -> %d\n", 42);
    ft_printf("Teste 2: %%+d -> %+d\n", 42);
    ft_printf("Teste 3: %%-d -> %-d\n", 42);
    ft_printf("Teste 4: %% d -> % d\n", 42);

    // Testes para strings
    ft_printf("Teste 5: %%s -> %s\n", "Hello, world!");
    ft_printf("Teste 6: %%10s -> %10s\n", "Pad");
    ft_printf("Teste 7: %%.5s -> %.5s\n", "Precision");

    // Testes para caracteres
    ft_printf("Teste 8: %%c -> %c\n", 'A');

    // Testes para ponteiros
    int x = 42;
    ft_printf("Teste 9: %%p -> %p\n", &x);

    // Testes para hexadecimal
    ft_printf("Teste 10: %%x -> %x\n", 255);
    ft_printf("Teste 11: %%X -> %X\n", 255);

    // Testes para unsigned
    ft_printf("Teste 12: %%u -> %u\n", 3000000000U);

    // Testes de mistura
    ft_printf("Teste 13: %%s e %%d -> %s tem %d anos\n", "Alice", 30);
    printf("Teste 13: %%s e %%d -> %s tem %d anos\n", "Alice", 30);

    ft_printf("Teste com quebra de linha\n");
    ft_printf("Teste com quebra de linha\n");

    return 0;
}
