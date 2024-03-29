#include <stdio.h>

int syndrome, divisor;

int syndrome, divisor;

int division(int tempdividend, int tempdivisor) {
    int quotient = 1;

    if (tempdivisor == tempdividend) {
        syndrome = 0;
        return 1;
    } else if (tempdividend < tempdivisor) {
        syndrome = tempdividend;
        return 0;
    }   

    do{

        tempdivisor = tempdivisor << 1;
        quotient = quotient << 1;

     } while (tempdivisor <= tempdividend);


     /* Call division recursively */
    quotient = quotient + division(tempdividend - tempdivisor, divisor);

    return quotient;
} 


int main() {
    int dividend;

    printf ("\nEnter the Dividend: ");
    scanf("%d", &dividend);
    printf("\nEnter the Divisor: ");
    scanf("%d", &divisor);   

    printf("\n%d / %d: quotient = %d", dividend, divisor, division(dividend, divisor));
    printf("\n%d / %d: syndrome = %d", dividend, divisor, syndrome);
    //getch();
}
