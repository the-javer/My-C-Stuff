#include <stdio.h>

int main() {

float numA;

float numB;

int oper;

printf("Type an operator using numbers (1=+, 2=-, 3=*, 4=/): ");
scanf("%d", &oper);

if (oper == 1) {
printf("Type in your first number: ");
scanf("%f", &numA);
printf("Type in your second number: ");
scanf("%f", &numB);
printf("%f\n", numA + numB);
}

if (oper == 2) {
printf("Type in your first number: ");
scanf("%f", &numA);
printf("Type in your second number: ");
scanf("%f", &numB);
printf("%f\n", numA - numB);
}

if (oper == 3) {
printf("Type in your first number: ");
scanf("%f", &numA);
printf("Type in your second number: ");
scanf("%f", &numB);
printf("%f\n", numA * numB);
}

if (oper == 4) {
printf("Type in your first number: ");
scanf("%f", &numA);
printf("Type in your second number: ");
scanf("%f", &numB);
printf("%f\n", numA / numB);
}

return 0;
}
