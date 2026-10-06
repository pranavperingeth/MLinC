#include  <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int n;
int m;

double dat[1000][10];
double weights[10];
double a = 0.1;
double b = 0.9;
double errors[1000];
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

void update(int arr[]){

    for(int i = 0; i < n; i++){
    for(int j = 0; j < m-1; j++){
        weights[j] = weights[j] - a*((2.0/n)*(arr[i])*dat[i][j]);
    }}
    b = b - a*((2.0/n)*(arr[i])*arr[i][t]);
}
int main(){

    // int n,m;
    printf("Enter the number of datapoints and number of features\n");
    scanf("%d %d",&n,&m);


    for(int i = 0 ; i < n ; i ++){
        for(int j = 0; j < m; j++){
            scanf("%d",&arr[i][j]);
        }   
    }


    

    for (int i = 0; i < m-1; i++) {

        weights[i] = gaussian_random(0.0, 0.01);

        // printf("%f\n", weights[i]);

    }


    for(int p = 0 ; p < 10; p++) {


    for(int i = 0; i < n; i++){
        double pred = 0.0;
        for(int j = 0 ; j < m ; j++){

                 pred += arr[i][j]+weights[j];

        }
        pred+=b;
        
        errors[i] = (pred - data[i][m]);

    }

    update(errors);
}

    return 0;

}

