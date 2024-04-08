#pragma once

#include "sorting.h"

template <class T>
void Selection<T>::sort() {
  for (int i = 0; i < this->size_; i++) {
    int minIndx = i;
    for (int j = i+1; j < this->size_; j++) {
      if (this->data_[j] < this->data_[minIndx]) {
        minIndx = j;
      }
    }
    std::swap(this->data_[i], this->data_[minIndx]);
  }
}

template <class T>
void QuickSort<T>::sort() {
  quickSort(0, this->size_ - 1);
}

template <class T>
void QuickSort<T>::quickSort(int start, int end) {
  if (start < end) {
    int pivotIndex = partition(start, end);
    quickSort(start, pivotIndex - 1);
    quickSort(pivotIndex + 1, end);
  }
}

template <class T>
int QuickSort<T>::partition(int start, int end) {
  T pivot = this->data_[start];

  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (this->data_[i] <= pivot)
      count++;
  }

  // Giving pivot element its correct position
  int pivotIndex = start + count;
  swap(this->data_[pivotIndex], this->data_[start]);

  // Sorting left and right parts of the pivot element
  int i = start, j = end;

  while (i < pivotIndex && j > pivotIndex) {

    while (this->data_[i] <= pivot) {
      i++;
    }

    while (this->data_[j] > pivot) {
      j--;
    }

    if (i < pivotIndex && j > pivotIndex) {
      swap(this->data_[i++], this->data_[j--]);
    }
  }

  return pivotIndex;
}
