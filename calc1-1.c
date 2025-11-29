#include <stdio.h>
#include <math.h>

int main() {

float numA;

float numB;

char oper;

printf("Type a 2 number equation using +, -, *, /, or ^: ");
scanf("%f %c %f", &numA, &oper, &numB);

switch (oper) {

case '+':
printf("%g\n", numA + numB);
break;

case '-':
printf("%g\n", numA - numB);
break;

case '*':
printf("%g\n", numA * numB);
break;

case '/':
printf("%g\n", numA / numB);
break;

case '^':
printf("%g\n", pow(numA, numB));
break;

default:
printf("Invalid input\n");
}

return 0;
}
