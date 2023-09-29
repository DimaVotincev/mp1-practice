#include <stdio.h>
#include <math.h>
/*
Test cases

Test1
input:
0 0 10
999 999 1
output:

Test2
input:
0 0 10
11 0 1
output:

Test3
input:
0 0 10
12 0 3
output:

Test4
input:
0 0 5
1 1 10
output:

Test5
input:
0 0 5
3 0 2
output:


*/
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
    double a1 = (x2 - x1);
    double a2 = (y2 - y1);
    double distance = sqrt(a1 * a1 - a2 * a2);
    double catch_error = 0.01;
    if (abs((distance + r1) - r2) < catch_error || abs((distance + r2) - r1) < catch_error) {
        printf("One circle inside other one and touch at one dot!");
        
        return 0;
    }
    else if ((x1 == x2 && y1 == y2) || abs(r1 - (distance+r2) < catch_error))  {
        printf("One circle inside other one!\n");
        return 0;
    }

    else {
        
        
        
        
        
        if ((distance - (r1 + r2)) < 0) {
            printf("Circles intersects at two points\n");
            return 0;
        }
        else if ((abs(distance - (r1 + r2)) < catch_error)) {
            printf("Circles touches\n");
            return 0;
        }
        else {
            printf("Circles have no common points!\n");
            return 0;
        }
    }



}
