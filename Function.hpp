#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdexcept>
#include <utility>

using std::swap;

template<typename T>
T max(T *arr, size_t size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (max<arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

template<typename T>
T min(T *arr, size_t size) {
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return max;
}

template<typename T>
void Sort(T *arr, size_t size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

template<typename T>
void insert(T *arr, size_t size, size_t index, T number) {
    if (index >= size)
        throw std::out_of_range("Index is out of range");
    arr[index] = number;
}

template<typename T>
size_t BinareSearch(T *arr, size_t size, T number) {
    size_t low = 0, high = size - 1;
    while (low <= high) {
        size_t mid = (low + high) / 2;
        int guess = arr[mid];
        if (number == guess) {
            return mid;
        } else if (guess > number) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

template<typename T>
void print(T *arr, size_t size) {
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


#endif //FUNCTION_H