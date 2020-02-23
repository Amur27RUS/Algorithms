#include <iostream>
using namespace std;

int N;
int result = -1;
int arr[20];

void minSumma(int i, int k1, int k2){

    if(i==N){ //Базовый случай
        if(result ==-1){
            result = abs(k1-k2);
        }else{
           if(abs(k1-k2)<result){
               result = abs(k1-k2);
           }
        }
//    cout<<abs(k1-k2) << endl; //строчка для тестирования
    }else{ //Рекурсивный случай
        minSumma(i+1, k1+arr[i],k2);
        minSumma(i+1, k1, k2+arr[i]);

    }
}
int main() {

    scanf("%d\n", &N);
    for(int i=0;i<N;i++) { //Добавляем массы камней в массив
        scanf("%d", &arr[i]);
    }

    minSumma(0, 0, 0);
    printf("%d\n", result);
}
