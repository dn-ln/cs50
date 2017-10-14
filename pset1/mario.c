#include <stdio.h>

int main(void)
{
    printf("Height: ");
    int height;
    scanf("%d", &height);
    if (height <= 23) {
        for (int i = 0; i < height; i++) {
            for (int j = i; j + 1 < height; j++) {
                printf(" ");
            }
            for (int k = 0; k <= i; k++) {
                printf("#");
            }
            printf("  ");
            for (int k = 0; k <= i; k++) {
                printf("#");
            }
            for (int j = i; j + 1 < height; j++) {
                printf(" ");
            }
            printf("\n");
        }
    } else if (height > 23 || height < 0) {
        printf("Height: ");
        scanf("%d", &height);
    } else {
        printf("Retry: ");
        scanf("%d", &height);
    }
}