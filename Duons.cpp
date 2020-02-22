#include <iostream>
using namespace std;

void DuonsSolver(int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1){
    int A = a1;
    int B = b1;
    int C = c1;
    int D = d1;
    int E = e1;
    int F = f1;
    int G = g1;
    int H = h1;

    if(A + C + F + H != E + D + B + G){
        printf("IMPOSSIBLE");
        return;
    }

    while(A+C+H+F+B+D+E+G != 0){
        if(A>0 && E > 0){
            A--;
            E--;
            printf("AE-\n");
        }

        if(A>0 && D > 0){
            A--;
            D--;
            printf("AD-\n");
        }

        if(A>0 && B > 0){
            A--;
            B--;
            printf("AB-\n");
        }

        if(C>0 && B > 0) {
            C--;
            B--;
            printf("CB-\n");
        }

        if(C>0 && G > 0){
            C--;
            G--;
            printf("CG-\n");
        }

        if(C>0 && D >0){
            C--;
            D--;
            printf("CD-\n");
        }

        if(B>0 && F > 0){
            B--;
            F--;
            printf("BF-\n");
        }

        if(D>0 && H > 0){
            D--;
            H--;
            printf("DH-\n");
        }

        if(E>0 && H >0){
            E--;
            H--;
            printf("EH-\n");
        }

        if(E>0 && F > 0){
            E--;
            F--;
            printf("EF-\n");
        }

        if(F>0 && G > 0){
            F--;
            G--;
            printf("FG-\n");
        }

        if(G>0 && H >0){
            G--;
            H--;
            printf("GH-\n");
        }

        if(A>0 && G >0){
            A--;
            G--;
            printf("EF+\n");
            printf("AE-\n");
            printf("FG-\n");
        }

        if(B>0 && H > 0){
            B--;
            H--;
            printf("EF+\n");
            printf("FB-\n");
            printf("EH-\n");
        }

        if(C>0 && E > 0){
            C--;
            E--;
            printf("FG+\n");
            printf("GC-\n");
            printf("EF-\n");
        }

        if(D>0 && F >0){
            D--;
            F--;
            printf("EH+\n");
            printf("DH-\n");
            printf("FE-\n");

        }

    }
}

int main() {

    int arr[8];

    for (int i = 0; i < 8; i++) { //Добавляем значения в массив
        scanf("%d", &arr[i]);
    }

    DuonsSolver(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);

}