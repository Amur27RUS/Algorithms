#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int k, sum = 0;
    cin >> k;
    int* limits = new int[k];
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        limits[i] = c;
        sum += c;
    }
    int index = -1, LIndex = -1;
    for (int i = 0; i < sum; i++) {
        int max = 0;
        for (int j = 0; j < k; j++) //ищем максимум
            if (j != LIndex && limits[j] > max) {
                max = limits[j];
                index = j;
            }
        LIndex = index;
        cout << index + 1 << " ";
        limits[index]--;
    }
}