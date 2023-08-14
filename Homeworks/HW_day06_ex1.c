#include <stdio.h>

double cube_root(double num) {
    if (num == 0.0) return 0.0;
    if (num < 0.0) return -cube_root(-num);

    double low = 0.0;
    double high = num;
    double mid;

    double precision = 0.001;

    while (high - low > precision) {
        mid = (low + high) / 2;
        double cube = mid * mid * mid;

        if (cube == num) {
            return mid;
        } else if (cube < num) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return (low + high) / 2;
}

int main() {
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);

    double result = cube_root(num);
    printf("Cube root of %lf is %lf\n", num, result);

    return 0;
}