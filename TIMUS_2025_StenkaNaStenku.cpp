#include <iostream>
using namespace std;

int main() {

    int l, k, N, z, y, x;
    scanf("%d\n", &N);

    for(int i=0;i<N;i++) {
        scanf("%d %d", &l, &k);

        if (l % k == 0) {
            z=l/k; //Кол-во человек в одной команде
            printf("%d\n", l * (l - z) / 2);
        }else{
            z = l/k;
            y = l - (k*z); //Кол-во лишних игроков
            x = k - y; //убираем из команд лишних игроков(т е оставляем для игрока команду)

            printf("%d\n", ((l-z)*x*z + (l-z-1)*(z+1)*y)/2);

        }

    }
}
