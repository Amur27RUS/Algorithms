#include <iostream>
#include <cmath>
#include <climits>
#define PI 3.14159265359
using namespace std;

long n, x[10001], y[10001], p[10001], yMin, pMin;
double agl[10001];

void swap(int i, int j){
    long tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;

    tmp = y[i];
    y[i] = y[j];
    y[j] = tmp;

    tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;

    double tmp2 = agl[i];
    agl[i] = agl[j];
    agl[j] = tmp2;
}

void bubbleSort(){
    for(int i = 1; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(agl[i] > agl[j]){
                swap(i, j);
            }
}


void medianaSolver(){
    swap(0, pMin);

    for(int i = 1; i < n; i++){
        if(x[i] == x[0]) agl[i] = PI/2;
        else if(y[i] == y[0]) agl[i] = 0;
        else agl[i] = atan((double)(y[i]-y[0])/(double)(x[i]-x[0]));
        if(agl[i] < 0) agl[i] = agl[i] + 2*PI;
    }

    bubbleSort();

    cout << p[0] << " " << p[n/2];
}

int main() {

    yMin = LONG_MAX;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
        p[i] = i + 1;
        if(y[i] < yMin || (y[i] == yMin && x[i] < x[pMin])){
            yMin = y[i];
            pMin = i;
        }
    }
    medianaSolver();
}