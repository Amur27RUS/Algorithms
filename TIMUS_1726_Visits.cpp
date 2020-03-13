#include <iostream>
using namespace std;

long long n, x[100001], y[100001], ansX = 0, ansY = 0, ans, k;

void swap(long long  arr[], int i, int j){
    long long tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void qSort(long long arr[], int l, int r){
    int i, j;
    long long  m;
    i = l, j = r;
    m = arr[(l + r)/2];
    while(i <= j){
        while (arr[i] < m) i++;
        while (arr[j] > m) j--;
        if (i > j) break;
        swap(arr, i, j);
        i++;
        j--;
    }
    if (l < j) qSort(arr, l, j);
    if (i < r) qSort(arr, i, r);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    qSort(x, 0, n-1);
    qSort(y, 0, n-1);
    for(int i = 1; i < n; i++){
        k = i * (n-i);
        ansX += (x[i] - x[i - 1]) * k * 2;
        ansY += (y[i] - y[i - 1]) * k * 2;
    }
    ans = (ansX + ansY) / (n * (n - 1));
    cout << ans << endl;
    return 0;
}
