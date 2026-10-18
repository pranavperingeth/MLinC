#define _USE_MATH_DEFINES
#include  <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
int n;
int m;

#define MAX_N 1000
#define MAX_M 10
#define EPOCHS 1000

double arr[MAX_N][MAX_M];
double weights[MAX_M];
double errors[MAX_N];
double a = 0.1;
double b = 0.9;
//double errors[1000];
double gaussian_random(double mean, double stddev) {

    double u1, u2;

    // u1 must not be 0

    do {

        u1 = (double)rand() / RAND_MAX;

    } while (u1 == 0.0);

    u2 = (double)rand() / RAND_MAX;

    // Box-Muller transform

    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

    return mean + stddev * z;

}

void update(void) {
    double grad_w[MAX_M] = {0};
    double grad_b = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            grad_w[j] += (2.0 / n) * errors[i] * arr[i][j];
        }
        grad_b += (2.0 / n) * errors[i];
    }

    for (int j = 0; j < m - 1; j++) {
        weights[j] -= a * grad_w[j];
    }
    b -= a * grad_b;
}
int main(){

    // int n,m;
    srand((unsigned int)time(NULL));
    printf("Enter the number of datapoints and number of features\n");
    scanf("%d %d",&n,&m);


    for(int i = 0 ; i < n ; i ++){
        for(int j = 0; j < m; j++){
            scanf("%lf",&arr[i][j]);
        }   
    }


    

    for (int i = 0; i < m-1; i++) {

        weights[i] = gaussian_random(0.0, 0.01);

        // printf("%f\n", weights[i]);

    }


    for(int p = 0 ; p < EPOCHS; p++) {


    for(int i = 0; i < n; i++){
        double loss = 0.0;
        double pred = 0.0;
        for(int j = 0 ; j < m - 1; j++){

                 pred += arr[i][j]*weights[j];

        }
        pred+=b;
        
        errors[i] = (pred - arr[i][m-1]);
        loss += errors[i] * errors[i]; 

    }

    update();
 if (p % 100 == 0 || p == EPOCHS - 1) {
        printf("epoch %4d  MSE = %f\n", p, loss / n);
    }
    
}


printf("\nTrained parameters:\n");
for (int j = 0; j < m - 1; j++) {
    printf("w[%d] = %f\n", j, weights[j]);
}
printf("b    = %f\n", b);
    return 0;

}

