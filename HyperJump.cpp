#include <iostream>
using namespace std;

//TIMUS TASK :)

int main() {
    int N, sum, maxSumm;
    sum = 0;
    maxSumm = 0;

    scanf("%d\n", &N);
    int arr[N];

    for(int i=0;i<N;i++) { //Добавляем значения в массив
        scanf("%d", &arr[i]);
    }

    for(int i=0;i<N;i++){
        sum += arr[i];
        if(sum <0){
            sum = 0;
        }else{
            if(sum>maxSumm){
                maxSumm = sum;
            }
        }
    }
    printf("%d", maxSumm);
}
