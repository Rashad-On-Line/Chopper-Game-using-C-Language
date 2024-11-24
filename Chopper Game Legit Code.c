#include <stdio.h>

int arr[8][8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};
int chopper, a = 0, i, j, row, column;

void print_arr() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}

void set_chopper(int row, int column) {
    row--;
    column--;

    // Rescue the entire row
    for (i = 0; i < 8; i++) {
        arr[row][i] = 0;
    }

    // Rescue the entire column
    for (i = 0; i < 8; i++) {
        arr[i][column] = 0;
    }
}

int count_rescued() {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    printf("Each house in the matrix has a terrorist...\n");
    printf("-------------------------------\n");

    print_arr();

    printf("-------------------------------\n");
    printf("How many choppers to land? : ");
    scanf("%d", &chopper);
    printf("\n");

    for (j = 1; j <= chopper; j++) {
        printf("Enter the coordinates to land the chopper %d [x,y = 1-8] :  ", j);
        scanf("%d %d", &row, &column);
        printf("\n");

        // Set the chopper at the specified position
        set_chopper(row, column);

        printf("-------------------------------\n");
        print_arr();
        printf("-------------------------------\n");

        // Count the number of rescued hostages
        a = count_rescued();
        printf("Number of hostages rescued: %d\n\n", a);
    }

    return 0;
}
