#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, r1;
    double x2, y2, r2;
    printf("Type coordinates and radius of first circle\n");
    printf("in this order: x1 y1 r1\n");
    printf("(radius must be more than 0)\n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);

    printf("Now do the same with parameters with second circle\n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    if (r1 <= 0 || r2 <= 0) {
        printf("Wrong radius input!");
        return 0;
    }

    
    if (x1 == x2 && y1 == y2) {
        printf("One circle inside other one!\n");
        return 0;
    }
    else {
        double a1 = (x2 - x1);
        double a2 = (y2 - y1);
        double distance = sqrt(a1 * a1 - a2 * a2);
        double catch_error = 0.01;
        if (distance - (r1 + r2) < 0) {
            printf("Circles intersects at two points\n");
            return 0;
        }
        else if (distance - (r1 + r2) < catch_error || distance - (r1 + r2) > catch_error) {
            printf("Circles touches\n");
            return 0;
        }
        else {
            printf("Circles have no common points!\n");
            return 0;
        }
    }
    
    
    
}