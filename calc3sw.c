#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calchead.h"

int amount;
float nums[4];
char oper;
char ans;

int main() {
    ask();
}

void ask() {
    printf("How many numbers do you want in your equation? 2-4: ");
    scanf("%d", &amount);
    suit();
}

void suit() {
if (amount == 2) {
    printf("Type a 2 number equation using +, -, *, /, or ^: ");
	scanf("%f %c %f", &nums[0], &oper, &nums[1]);
	switch (oper) {
        
        case '+':
        printf("%g\n", nums[0] + nums[1]);
		leave();
        break;
        
        case '-':
        printf("%g\n", nums[0] - nums[1]);
		leave();
        break;
        
        case '*':
        printf("%g\n", nums[0] * nums[1]);
		leave();
        break;
        
        case '/':
        printf("%g\n", nums[0] / nums[1]);
		leave();
        break;

		case '^':
		printf("%g\n", pow(nums[0], nums[1]));
		leave();
        break;
         
        default:
        printf("\nInvalid input");
        leave();
        }
}

if (amount == 3) {
    printf("Type a 3 number equation using +, -, *, or /: ");
	scanf("%f %c %f %c %f", &nums[0], &oper, &nums[1], &oper, &nums[2]);
        switch (oper) {

        case '+':
        printf("%g\n", nums[0] + nums[1] + nums[2]);
		leave();
        break;
 
        case '-':
        printf("%g\n", nums[0] - nums[1] - nums[2]);
		leave();
        break;

        case '*':
        printf("%g\n", nums[0] * nums[1] * nums[2]);
		leave();
        break;
 
        case '/':
        printf("%g\n", nums[0] / nums[1] / nums[2]);
		leave();
        break;
 
        default:
        printf("\nInvalid input");
        leave();
        }
}

if (amount == 4) {
    printf("Type a 4 number equation using +, -, *, or /: ");
	scanf("%f %c %f %c %f %c %f", &nums[0], &oper, &nums[1], &oper, &nums[2], &oper, &nums[3]);
	switch (oper) {

	case '+':
	printf("%g\n", nums[0] + nums[1] + nums[2] + nums[3]);
	leave();
    break;

	case '-':
	printf("%g\n", nums[0] - nums[1] - nums[2] - nums[3]);
	leave();
    break;

	case '*':
	printf("%g\n", nums[0] * nums[1] * nums[2] * nums[3]);
	leave();
    break;

	case '/':
	printf("%g\n", nums[0] / nums[1] / nums[2] / nums[3]);
	leave();
    break;

	default:
	printf("\nInvalid input");
	leave();
	}
}
}

void leave() {
    printf("Would you like to do another calculation? y/n: ");
    scanf("\n%c", &ans);

    switch (ans) {
        case 'y':
        ask();
        break;

        case 'n':
        exit(0);
        break;

        default:
        printf("\nInvalid input");
        exit(1);
        break;
    }
    }