#include <stdio.h>
//21BCE5126
int main() {
    int arr[100], reversed_arr[100];
    int n, i, j;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse the elements
    for (i = n - 1, j = 0; i >= 0; i--, j++) {
        reversed_arr[j] = arr[i];
    }

    printf("The original array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThe reversed array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", reversed_arr[i]);
    }
    printf("\n");
    
    return 0;
}

