#include <iostream>
using namespace std;


class Players{
private:
    int** matrix;
    int N;
    int size;

    void add_figure(int x, int y) {
        int tmp_x = x % 2;
        int tmp_y = y % 2;

        if (tmp_x == 1 && tmp_y == 1) {
            matrix[x - 1][y - 1] = matrix[x - 1][y] = matrix[x][y - 1] = N++;

        }
        else if (tmp_x == 0 && tmp_y == 0) {
            matrix[x + 1][y + 1] = matrix[x + 1][y] = matrix[x][y + 1] = N++;

        }
        else if (tmp_x == 0 && tmp_y == 1) {
            matrix[x + 1][y] = matrix[x][y - 1] = matrix[x + 1][y - 1] = N++;

        }
        else if (tmp_x == 1 && tmp_y == 0) {
            matrix[x - 1][y] = matrix[x][y + 1] = matrix[x - 1][y + 1] = N++;

        }
    }

    void mainSolve(int rowsStart, int colsStart, int x, int y, int size){
        int newSize = size/2; //Делим матрицу на 2 части

        if (size == 2) { //Выход из рекурсии
            add_figure(rowsStart + x % 2, colsStart + y % 2);
            return;
        }

        if (x >= newSize && y >= newSize) {
            mainSolve(rowsStart + newSize, colsStart + newSize, x - newSize, y - newSize, newSize);

            matrix[rowsStart + newSize - 1][colsStart + newSize - 1] =
            matrix[rowsStart + newSize][colsStart + newSize - 1] =
            matrix[rowsStart + newSize - 1][colsStart + newSize] = N++;

            mainSolve(rowsStart, colsStart + newSize, newSize - 1, 0, newSize);
            mainSolve(rowsStart, colsStart, newSize - 1, newSize - 1, newSize);
            mainSolve(rowsStart + newSize, colsStart, 0, newSize - 1, newSize);

        }else if (x < newSize && y < newSize) {
            mainSolve(rowsStart, colsStart, x, y, newSize);

            matrix[rowsStart + newSize][colsStart + newSize] =
            matrix[rowsStart + newSize][colsStart + newSize - 1] =
            matrix[rowsStart + newSize - 1][colsStart + newSize] = N++;

            mainSolve(rowsStart + newSize, colsStart + newSize, 0, 0, newSize);
            mainSolve(rowsStart, colsStart + newSize, newSize - 1, 0, newSize);
            mainSolve(rowsStart + newSize, colsStart, 0, newSize - 1, newSize);

        }else if (x < newSize && y >= newSize) {
            mainSolve(rowsStart, colsStart + newSize, x, y - newSize, newSize);

            matrix[rowsStart + newSize][colsStart + newSize] =
            matrix[rowsStart + newSize][colsStart + newSize - 1] =
            matrix[rowsStart + newSize - 1][colsStart + newSize - 1] = N++;

            mainSolve(rowsStart, colsStart, newSize - 1, newSize - 1, newSize);
            mainSolve(rowsStart + newSize, colsStart + newSize, 0, 0, newSize);
            mainSolve(rowsStart + newSize, colsStart, 0, newSize - 1, newSize);

        }else {
            mainSolve(rowsStart + newSize, colsStart, x - newSize, y, newSize);

            matrix[rowsStart + newSize][colsStart + newSize] =
            matrix[rowsStart + newSize - 1][colsStart + newSize] =
            matrix[rowsStart + newSize - 1][colsStart + newSize - 1] = N++;

            mainSolve(rowsStart, colsStart, newSize - 1, newSize - 1, newSize);
            mainSolve(rowsStart + newSize, colsStart + newSize, 0, 0, newSize);
            mainSolve(rowsStart, colsStart + newSize, newSize - 1, 0, newSize);
        }

    }

public:
    Players (int** matrix, int size) {
        this->matrix = matrix;
        this->size = size;
        N = 1;
    }

    void solve(int x, int y) {
        mainSolve(0, 0, x, y, size);
    }

};

int main() {
    int n, x, y;
    scanf("%d\n", &n);
    scanf("%d %d", &x, &y);

    int count = 1 << n;
    int** matrix = new int*[count];

    for (int i = 0; i < count; i++) {
        matrix[i] = new int[count];
        for (int j = 0; j < count; j++)
            matrix[i][j] = 0;
    }

    Players players(matrix, count);

    players.solve(x - 1, y - 1);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

