#include <stdio.h>
#include <math.h>
#include "windows.h"
#include "print_electric_circuit.h"
#include "calculation.h"
#include "input.h"

typedef struct complex{
    double real;
    double imaginary;
}complex;

complex complexDivision(complex a, complex b) {
    complex result;
    double denominator = b.real * b.real + b.imaginary * b.imaginary;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
    result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
    return result;
}

void printComplexResult(complex num){
    printf("%e+i*%e\n", num.real, num.imaginary);
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    do{
        double R = 0, R1 = 0, R2 = 0, L = 0, C = 0;
        double fMin =0, fMax = 0, df = 0, f0 = 0, f = 0;;
        double omega = 0;
        complex Z = {0, 0}, numerator = {0, 0}, denominator = {0, 0};
        char circuitChoice = 0;
        int i = 0;
        int isfMaxCorrect;
        int isCorrectfMinfMax = 0;

        printf("M E R R Y   C H R I S T M A S !\n\n");

        _flushall();

        printf("This program calculates complex resistance in given circuits depending on current frequency:\n");

        printf("Choose circuit(1-4)\n");
        printCircuits();

        do{
            circuitChoice = getchar();
            fflush(stdin);
            switch (circuitChoice) {
                case '1':
                case '2':
                    R = input_R(R);
                    break;
                case '3':
                case '4':
                    R1 = input_R1(R1);
                    R2 = input_R2(R2);
                    break;
                default:
                    printf("Invalid choice, try again:\n");
                    circuitChoice = 1;
                    break;
            }
        }while (circuitChoice == 1);

        L = input_L(L);

        C = input_C(C);

        fMin = input_fMin(fMin);

        fMax = input_fMax(fMax);

        do{
            isfMaxCorrect = cheskIsfMaxBiggerThanfMin(fMin, fMax);
            if (isfMaxCorrect == 1){
                printf("Success\n");
                isCorrectfMinfMax = 1;
            }else{
                printf("Wrong input fMax must be greater than fMin!\n");
                fMin = input_fMin(fMin);
            }
        }while(isCorrectfMinfMax == 0);


        df = input_df(df, fMax, fMin);

        f0 = calculateFrequency(L, C);
        printf("Resonant frequency = %g\n", f0);
        f = fMin;

        do {
            omega = 2.0 * M_PI * f;
            switch (circuitChoice) {
                case '1':{
                    numerator.real = L / C;
                    denominator.real = R;
                    numerator.imaginary = -R / (omega * C);
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complexDivision(numerator, denominator);
                    break;
                }
                case '2':{
                    numerator.real = L / C;
                    denominator.real = R;
                    numerator.imaginary = R / (omega * C);
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complexDivision(numerator, denominator);
                    break;
                }
                case '3':{
                    numerator.real = R1 * R2;
                    denominator.real = R1 + R2;
                    numerator.imaginary = R1 * (omega * L - 1.0 / (omega * C));
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complexDivision(numerator, denominator);
                    break;
                }
                case '4':{
                    numerator.real = R1 * R2 + L / C;
                    denominator.real = R1 + R2;
                    numerator.imaginary = omega * L * R1 - R2*R2 / (omega * C);
                    denominator.imaginary = omega * L - 1.0 / (omega * C);
                    Z = complexDivision(numerator, denominator);
                    break;
                }
                default:{
                    printf("Wrong input!\nYou have to choose one of the circuits");
                    break;
                }
            }

            printf("f%d:%g\t", i+1, f);
            printf("df%d:%g\t", i+1, df);
            printf("Z[%d]: ", i+1);
            printComplexResult(Z);
            f+=df;
            i++;
        }while (f<=fMax);

        printf("\n\nWant to calculate a new circuit? (y-yes) or press any other key to exit \n");

    }while (getchar() == 'y');

    return 0;

}