#include <stdio.h>
#include <math.h>

int main() {

int amount;

float nums[4];

char oper;

printf ("How many numbers do you want in your equation? 2-4: ");
scanf("%d", &amount);

switch (amount) {

case 2:
	printf("Type a 2 number equation using +, -, *, /, or ^: ");
	scanf("%f %c %f", &nums[0], &oper, &nums[1]);
	switch (oper) {
        
        case '+':
        printf("%g\n", nums[0] + nums[1]);
	return 0;
        
        case '-':
        printf("%g\n", nums[0] - nums[1]);
        return 0;
        
        case '*':
        printf("%g\n", nums[0] * nums[1]);
        return 0;
        
        case '/':
        printf("%g\n", nums[0] / nums[1]);
        return 0;

	case '^':
	printf("%g\n", pow(nums[0], nums[1]));
	return 0;
         
        default:
        printf("Invalid input\n");
	return 0;
        }

case 3:
	printf("Type a 3 number equation using +, -, *, or /: ");
	scanf("%f %c %f %c %f", &nums[0], &oper, &nums[1], &oper, &nums[2]);
        switch (oper) {

        case '+':
        printf("%g\n", nums[0] + nums[1] + nums[2]);
        return 0;
 
        case '-':
        printf("%g\n", nums[0] - nums[1] - nums[2]);
        return 0;
 
        case '*':
        printf("%g\n", nums[0] * nums[1] * nums[2]);
        return 0;
 
        case '/':
        printf("%g\n", nums[0] / nums[1] / nums[2]);
        return 0;
 
        default:
        printf("Invalid input\n");
	return 0;
        }

case 4:
	printf("Type a 4 number equation using +, -, *, or /: ");
	scanf("%f %c %f %c %f %c %f", &nums[0], &oper, &nums[1], &oper, &nums[2], &oper, &nums[3]);
	switch (oper) {

	case '+':
	printf("%g\n", nums[0] + nums[1] + nums[2] + nums[3]);
	return 0;

	case '-':
	printf("%g\n", nums[0] - nums[1] - nums[2] - nums[3]);
	return 0;

	case '*':
	printf("%g\n", nums[0] * nums[1] * nums[2] * nums[3]);
	return 0;

	case '/':
	printf("%g\n", nums[0] / nums[1] / nums[2] / nums[3]);
	return 0;

	default:
	printf("Invalid input\n");
	return 0;
	}
	}
}
