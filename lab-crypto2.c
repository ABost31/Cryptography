#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#define MIN_CHAR 33
#define MAX_CHAR 126
#define LENGTH 5 

struct MyStruct{
    char secret[LENGTH];
};

void crack_code(char target[]) {
    char guess[LENGTH] = {MIN_CHAR, MIN_CHAR, MIN_CHAR, MIN_CHAR, '\0'}; 
    int cracked = 0;

    for (int i = MIN_CHAR; i <= MAX_CHAR; i++) {
        for (int j = MIN_CHAR; j <= MAX_CHAR; j++) {
            for (int k = MIN_CHAR; k <= MAX_CHAR; k++) {
                for (int l = MIN_CHAR; l <= MAX_CHAR; l++) {
                    guess[0] = i;
                    guess[1] = j;
                    guess[2] = k;
                    guess[3] = l;

                    if (strcmp(guess, target) == 0) {
                        cracked = 1;
                        printf("Code cracked! The code is: %s\n", guess);
                        return;
                    }
                }
            }
        }
    }

    if (!cracked) {
        printf("Code not found.\n");
    }
}

int main() {
    char secret[LENGTH];  
    struct MyStruct len;  
    char name[] = "Abraham Ostos\n";
    char Lab_task[] = "Lab 2 Option B, Q1\n";
    char course[] = "CISC 5650\n";
    printf("Name = %s\n", name);
    printf("Lab Task = %s\n", Lab_task);
    printf("Course = %s\n", course);
    printf("\n Enter a 4-character secret key: ");
    scanf("%4s", secret);  
    
    if (strlen(secret) == 4) {  
        printf("Cracking the code...\n");
        clock_t start_time, end_time;
        double time_taken;
        start_time = clock();
        crack_code(secret);
        end_time = clock();
    
        time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time taken to crack the code: %.4f seconds\n", time_taken);
          
    } else {
        printf("Error: Secret key must be exactly 4 characters long.\n");
        exit(0);
    }

    return 0;
}