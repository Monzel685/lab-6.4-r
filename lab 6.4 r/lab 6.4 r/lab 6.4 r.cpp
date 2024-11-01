#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void create(double* arr, int SIZE, double MIN, double MAX, int i) {
    if (i < SIZE) {
        arr[i] = MIN + (double)rand() / RAND_MAX * (MAX - MIN);
        create(arr, SIZE, MIN, MAX, i + 1);
    }
}

void printArray(double* arr, const int SIZE, int i) {
    if (i < SIZE) {
        cout << setw(10) << fixed << setprecision(2) << arr[i];
        printArray(arr, SIZE, i + 1);
    }
    else {
        cout << endl;
    }
}

int minAbsIndex(double* arr, int SIZE, int i, int minIndex) {
    if (i >= SIZE) return minIndex;
    if (abs(arr[i]) < abs(arr[minIndex])) minIndex = i;
    return minAbsIndex(arr, SIZE, i + 1, minIndex);
}

double sumAfterFirstNegative(double* arr, int SIZE, int i, bool foundNegative, double sum) {
    if (i >= SIZE) return sum;
    if (foundNegative) sum += abs(arr[i]);
    if (arr[i] < 0 && !foundNegative) foundNegative = true;
    return sumAfterFirstNegative(arr, SIZE, i + 1, foundNegative, sum);
}

void compressArray(double* arr, double* tempArr, int SIZE, double a, double b, int i, int& newSize) {
    if (i >= SIZE) {
        for (int j = newSize; j < SIZE; j++) arr[j] = 0;
        return;
    }
    if (arr[i] < a || arr[i] > b) tempArr[newSize++] = arr[i];
    compressArray(arr, tempArr, SIZE, a, b, i + 1, newSize);
}

void copyArray(double* arr, double* tempArr, int SIZE, int i) {
    if (i >= SIZE) return;
    arr[i] = tempArr[i];
    copyArray(arr, tempArr, SIZE, i + 1);
}

int main() {
    srand((unsigned)time(NULL));

    int SIZE;
    double a, b;
    cout << "Enter size: ";
    cin >> SIZE;
    cout << "Enter a and b: ";
    cin >> a >> b;

    double* arr = new double[SIZE];
    double* tempArr = new double[SIZE];
    create(arr, SIZE, -20, 20, 0);

    printArray(arr, SIZE, 0);

    int minIndex = minAbsIndex(arr, SIZE, 0, 0);
    cout << "Index of min absolute element: " << minIndex << endl;

    double sum = sumAfterFirstNegative(arr, SIZE, 0, false, 0.0);
    cout << "Sum of absolute values after first negative: " << sum << endl;

    int newSize = 0;
    compressArray(arr, tempArr, SIZE, a, b, 0, newSize);
    copyArray(arr, tempArr, SIZE, 0);
    printArray(arr, SIZE, 0);

    delete[] arr;
    delete[] tempArr;

    return 0;
}
