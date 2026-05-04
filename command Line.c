#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int total = 0;
    int i;

    // Minimum check: program + name + at least 1 mark
    if (argc < 3) {
        printf("Usage: %s <Name> <marks...>\n", argv[0]);
        return 1;
    }

    // Student name
    char *name = argv[1];

    // Add marks
    for (i = 2; i < argc; i = i + 1) {
        int mark = atoi(argv[i]);   // convert string ? int
        total = total + mark;
    }

    // Display
    printf("Student Name: %s\n", name);
    printf("Total Marks: %d\n", total);

    return 0;
}