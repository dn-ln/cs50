#include <stdio.h>
#include <math.h>

int main(void) {
    printf("Number: ");
    long double number;
    scanf("%Lf", &number);
    int power = floor(log10(number));
    int digits = power + 1;
    if (digits == 13 || digits == 15 || digits == 16) {
        int if_odd = 1;
        int odd = 0;
        int even = 0;
        long double store_number = number;
        while (store_number > 1) {
            int digit = fmod(store_number, 10);
            if (if_odd) {
                odd += digit;
                if_odd = 0;
            } else {
                int new_digit = digit * 2;
                int digit_sum = floor(new_digit / 10) + new_digit % 10 ;
                even += digit_sum;
                if_odd = 1;
            }
            store_number /= 10;
        }
        if ((odd + even) % 10 == 0) {
            int head1 = number / pow(10, power);
            int head2 = number / pow(10, (power - 1));
            if ((digits == 16 || digits == 13) && head1 == 4) {
                printf("VISA\n");
            } else if (digits == 16 && (head2 > 50 || head2 < 56)) {
                printf("MASTERCARD\n");
            } else if (digits == 15 && (head2 == 34 || head2 == 37)) {
                printf("AMEX\n");
            } else {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("Number: ");
        scanf("%Lf", &number);
    }
}
