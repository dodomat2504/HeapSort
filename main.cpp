#include <iostream>
#include <random>
#include <cmath>
#include <time.h>


static void heapify(int arr[], const int length, const int rootIndex) {
    const int leftIndex = 2 * rootIndex + 1;
    const int rightIndex = 2 * rootIndex + 2;

    if (leftIndex < length && leftIndex >= 0) {
        if (arr[leftIndex] > arr[rootIndex]) {
            const int zw = arr[rootIndex];
            arr[rootIndex] = arr[leftIndex];
            arr[leftIndex] = zw;
            heapify(arr, length, leftIndex);
        }
    }
    if (rightIndex < length && rightIndex >= 0) {
        if (arr[rightIndex] > arr[rootIndex]) {
            const int zw = arr[rootIndex];
            arr[rootIndex] = arr[rightIndex];
            arr[rightIndex] = zw;
            heapify(arr, length, rightIndex);
        }
    }

}

static void buildHeap(int arr[], const int length) {
    for (int i = (length - 2) / 2; i >= 0; i--) {
        heapify(arr, length, i);
    }
}

void heapsort(int arr[], const int length) {
    for (int i = 0; i < length-1; i++) {
        if (i == 0) buildHeap(arr, length);
        else heapify(arr, length - i, 0);

        const int zw = arr[0];
        arr[0] = arr[length-1-i];
        arr[length-1-i] = zw;
    }
}

const int length = 500000;

int main() {
    int arr[length];

    for (int i = 0; i < length; i++) {
        arr[i] = std::rand() % length + 1;
    }

    int start = clock();

    heapsort(arr, length);

    int ende = clock();
    int timeUsed = ((double) (ende - start)) / CLOCKS_PER_SEC*1000;

    std::cout << "Sorted:" << std::endl << std::endl;

    for (int i = 0; i < length; i++) {
        if (i % 500 == 0) std::cout << arr[i] << std::endl;
    }

    std::cout << "Time: " << timeUsed << "ms" << std::endl;

    return 0;
}
