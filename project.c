#include <stdio.h>
#include <stdlib.h> //standard library like rand()
#include <time.h> //date and time

// Prime check 
int isPrime(int n) {
    if (n <= 1) //prime or not
        return 0;
    for (int i = 2; i * i <= n; i++) { //
        if (n % i == 0) 
            return 0;
    }
    return 1; // if no divisor by any number, the number is 1.
} //output: returns 1 or 0

// Game logic
void playRound() {
    int hidden = rand() % 90 + 10; /* rand() gives long numbers and is not in programmers control
                                     rand()% 90 gives number between 0-89. any number divided by 90 gives remainder from 0 to 89.
                                     adding 10 so the number choice start from 10 to 99 cause we need 2 digit number*/ 
    int cluesUsed = 0; 
    int score = 50;
    int option, guess; // player menu choice, final answer

    printf("\nNEW ROUND\n");
    printf("A 2-digit number has been chosen.\n");

    while (cluesUsed < 5) { //user can take 5 maximum clues
        printf("\nChoose a clue:\n");
        printf("1. Is it even?\n");
        printf("2. Is it divisible by 3?\n");
        printf("3. Is it divisible by 5?\n");
        printf("4. Make final classification\n"); 
        printf("Enter choice: ");
        scanf("%d", &option);

        if (option == 4) //moves to final answer
            break;

        cluesUsed++; //clues increasing
        score -= 5; //score decreasing

        switch (option) {
            case 1:
                printf("Clue: %s\n", (hidden % 2 == 0) ? "Even" : "Odd"); //whether even or odd
                break;
            case 2:
                printf("Clue: %s\n", (hidden % 3 == 0) ? "Divisible by 3" : "Not divisible by 3"); //whether divisible by 3
                break;
            case 3:
                printf("Clue: %s\n", (hidden % 5 == 0) ? "Divisible by 5" : "Not divisible by 5"); //whether divible of 5
                break;
            default:
                printf("Invalid option (no clue used).\n");
                cluesUsed--; //cancels penalty if invalid choice
                score += 5; 
        }
    }

    printf("\nFinal Classification:\n");
    printf("1. Prime\n"); //if user thinks number is prime they will select this
    printf("2. Composite Even\n"); //for even composite number 
    printf("3. Composite Odd\n"); //for odd composite number 
    printf("Enter your answer: ");
    scanf("%d", &guess);

    //checking number
    int prime = isPrime(hidden);

    if (guess == 1 && prime) {
        printf("Correct! Number was %d.\n", hidden);
        score += 20;
    }
    else if (guess == 2 && hidden % 2 == 0 && !prime) {
        printf("Correct! Number was %d.\n", hidden);
        score += 20;
    }
    else if (guess == 3 && hidden % 2 != 0 && !prime) {
        printf("Correct! Number was %d.\n", hidden);
        score += 20;
    }
    else {
        printf("Wrong! Number was %d.\n", hidden);
        score -= 15;
    }

    printf("Round Score: %d\n", score);
}

//rules
void displayRules() {
    printf("\nGAME RULES\n");
    printf("1. Guess the type of number generated.\n");
    printf("2. How the game works? \n");
    printf("i. The computer secretly selects a two-digit number (10-99).\n");
    printf("ii. The player cannot see the number.\n");
    printf("iii. The player starts each round with 50 points.\n");
    printf("iv. The player may ask for clues about the number.\n");
    printf("3. Options for player to classify the number:\n");
    printf("   1 -> Prime\n");
    printf("   2 -> Even (Not Prime)\n");
    printf("   3 -> Odd (Not Prime)\n");
    printf("4.The player starts each round with 50 points.\n");
    printf("a) Each clue used: -5 pointes\n");
    printf("b) Correct Answer  : +20 points\n");
    printf("c) Wrong Answer    : -15 points\n");
}

// Main menu
int main() {
    int choice;
    srand(time(0)); //random number generation so number changes everytime(starts generating number using current time)

    do {
        printf("\nNUMBER DETECTIVE GAME\n");
        printf("1. Play Game\n");
        printf("2. Game rules\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            playRound();
        else if(choice == 2)
            displayRules();
        else if (choice == 3)
            printf("Goodbye!\n");
        else
            printf("Invalid choice!\n");

    } while (choice != 3); //repeat menu until exit is selected

    return 0;
}