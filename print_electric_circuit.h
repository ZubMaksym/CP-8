#ifndef CP_8_PRINT_ELECTRIC_CIRCUIT_H
#define CP_8_PRINT_ELECTRIC_CIRCUIT_H
#include <stdio.h>

void printCircuits(){
    printf("First circuit\n");
    printf("●─┬────────▆▆▆──────◠◠◠◠──┬─●\n"
           "  │         R         L     │\n"
           "  │                         │\n"
           "  │               C         │\n"
           "  └───────────────││────────┘\n");

    printf("Second circuit\n");
    printf("●─┬────────▆▆▆──────││──────┬─●\n"
           "  │         R       C       │\n"
           "  │                         │\n"
           "  │      L                  │\n"
           "  └────◠◠◠◠───────────────┘\n");

    printf("Third circuit\n");
    printf("●─┬─────────▆▆▆──────││─────┓\n"
           "  │         R2         C    │\n"
           "  │                         │\n"
           "  █ R1     L                │\n"
           "●─┴──────◠◠◠◠─────────────┘\n");

    printf("Fourth circuit\n");
    printf("●─┬────────▆▆▆──────────────┓\n"
           "  █ R1     R2               │\n"
           "  ┴                         │\n"
           "  ┬ C       L               │\n"
           "●─┴───────◠◠◠◠────────────┚\n");
}

#endif //CP_8_PRINT_ELECTRIC_CIRCUIT_H
