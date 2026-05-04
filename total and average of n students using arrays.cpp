#include <stdio.h>

int main() {
    int n;
    int marks[100];   // array to store marks
    int i;
    int total = 0;
    float average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // STEP 1: Read marks
    for (i = 0; i < n; i = i + 1) {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    // STEP 2: Calculate total
    for (i = 0; i < n; i = i + 1) {
        total = total + marks[i];
    }

    // STEP 3: Calculate average
    average = (float)total / n;

    // STEP 4: Display results
    printf("Total = %d\n", total);
    printf("Average = %.2f\n", average);

    return 0;
}
