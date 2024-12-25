#ifndef CP_8_INPUT_H
#define CP_8_INPUT_H
#include <stdio.h>
#include <stdbool.h>

#define MAX_L 1e7
#define MAX_C 1e5
#define MAX_R 1e6
#define fMIN_FREQ_MAX 1e9
#define fMAX_FREQ_MAX 1e9

double input_L(double L){
    int validInput = 0;
    printf("Enter the value of L(mHn) [0; 1e7]:\n");
    do{
        if (scanf("%lf", &L) == 1 && L <= MAX_L && L > 0){
            fflush(stdin);
            validInput = 1;
        }else{
            printf("Wrong input! You have to enter only NUMBERS in given RANGE!\n");
            fflush(stdin);
        }
    }while(validInput == 0);

    return L;
}

double input_C(double C){
    int validInput = 0;
    printf("Enter the value of C (mcF) [0; 1e5]:\n");
    do{
        if (scanf("%lf", &C) == 1 && C <= MAX_C && C > 0){
            fflush(stdin);
            validInput = 1;
        }else{
            printf("Wrong input! You have to enter only NUMBERS in given RANGE!\n");
            fflush(stdin);
        }
    }while(validInput == 0);

    return C;
}

double input_fMin(double fMin){
    int validInput = 0;
    printf("Enter the frequency (fMin) [0; 1e9]:\nWarning! fMin has to be less than fMax\n");
    do{
        if (scanf("%lf", &fMin) == 1 && fMin <= fMIN_FREQ_MAX && fMin > 0){
            fflush(stdin);
            validInput = 1;
        }else{
            printf("Wrong input! You have to enter only NUMBERS in given RANGE\n");
            fflush(stdin);
        }
    }while(validInput == 0);

    return fMin;
}

double input_fMax(double fMax){
    int validInput = 0;
    printf("Enter the frequency (fMax) [0; 1e9]:\n");
    do{
        if (scanf("%lf", &fMax) == 1 && fMax <= fMAX_FREQ_MAX && fMax > 0){
            fflush(stdin);
            validInput = 1;
        }else{
            printf("Wrong input! You have to enter only NUMBERS in given RANGE\nIn case ");
            fflush(stdin);
        }
    }while(validInput == 0);

    return fMax;
}

double input_df(double df, double fMax, double fMin){
    int validInput = 0;
    double difference = fMax-fMin;
    printf("Enter df [0 < df <= %.2lf]:\n", difference);
    do{
        if (scanf("%lf", &df) == 1 && df > 0 && df <= fMax - fMin){
            fflush(stdin);
            validInput = 1;
        }else{
            printf("Wrong input! You have to enter only NUMBERS in given RANGE\n");
            fflush(stdin);
        }
    }while(validInput == 0);

    return df;
}

double input_R(double R){
    int validInput = 0;
    printf("Enter R(Ohm) [0; 1e6]:\n");
    do{
        if (scanf("%lf", &R) == 1 && R <= MAX_R && R > 0){
            fflush(stdin);
            validInput = 1;
        }else{
            printf("Wrong input! You have to enter only NUMBERS in given RANGE\n");
            fflush(stdin);
        }
    }while(validInput == 0);

    return R;
}

double input_R1(double R1){
    int validInput = 0;
    printf("Enter R1(Ohm) [0; 1e6]:\n");
    do{
        if (scanf("%lf", &R1) == 1 && R1 <= MAX_R && R1 > 0){
            fflush(stdin);
            validInput = 1;
        }else{
            printf("Wrong input! You have to enter only NUMBERS in given RANGE\n");
            fflush(stdin);
        }
    }while(validInput == 0);

    return R1;
}

double input_R2(double R2){
    int validInput = 0;
    printf("Enter R2(Ohm) [0; 1e6]:\n");
    do{
        if (scanf("%lf", &R2) == 1 && R2 <= MAX_R && R2 > 0){
            fflush(stdin);
            validInput = 1;
        }else{
            printf("Wrong input! You have to enter only NUMBERS in given RANGE\n");
            fflush(stdin);
        }
    }while(validInput == 0);

    return R2;
}

int cheskIsfMaxBiggerThanfMin(double fMin, double fMax){
    if (fMax > fMin){
        return 1;
    }else{
        return 0;
    }
}
#endif //CP_8_INPUT_H
