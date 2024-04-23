#pragma once

#include "sorting.h"


template <class T>
void SortAlgrthm<T>::print() const {
  for (int i = 0; i < this->size_; i++) {
    this->data_[i].print();
  }
}

template <class T>
void Selection<T>::sort() {
  for (int i = 0; i < this->size_; i++) {
    int minIndx = i;
    for (int j = i+1; j < this->size_; j++) {
      if (this->data_[j] < this->data_[minIndx]) {
        minIndx = j;
      }
      if (minIndx != i) {
        T temp = this->data_[i];
        this->data_.set(i, this->data_[minIndx]);
        this->data_.set(minIndx, temp);    
      }
    }
  }
}

template <class T>
void Selection<T>::trace() {
  std::cout << "Unsorted sequence: ";
  for (int i = 0; i < this->size_; i++) {
    std::cout << this->data_[i] << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < this->size_; i++) {
    std::cout << "Sequence after iteration " << i+1 << ": ";
    for (int k = 0; k < this->size_; k++) {
      std::cout << this->data_[k] << " ";
    }
    std::cout << std::endl;
    int minIndx = i;
    for (int j = i+1; j < this->size_; j++) {
      if (this->data_[j] < this->data_[minIndx]) {
        minIndx = j;
      }
    }
    if (minIndx != i) {
      T temp = this->data_[i];
      this->data_.set(i, this->data_[minIndx]);
      this->data_.set(minIndx, temp);
    }
  }
}


template <class T>
void QuickSort<T>::trace() {
  quickSortTrace(0, this->size_ - 1);
}

template <class T>
void QuickSort<T>::quickSortTrace(int start, int end) {
  if (start < end) {
    int pivotIndex = partition(start, end);

    std::cout << "After partition at index " << pivotIndex << ": ";
    for (int i = start; i <= end; ++i) {
      std::cout << this->data_[i] << " ";
    }
    std::cout << std::endl;

    quickSortTrace(start, pivotIndex - 1);
    quickSortTrace(pivotIndex + 1, end);
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
  T pivot = this->data_[end];
  int i = start - 1;
  for (int j = start; j < end; j++) {
    if (this->data_[j] < pivot) {
      i++;
      T temp = this->data_[i];
      this->data_.set(i, this->data_[j]);
      this->data_.set(j, temp);
    }
  }
  T temp = this->data_[i + 1];
  this->data_.set(i + 1, this->data_[end]);
  this->data_.set(end, temp);

  return i + 1;
}

template <class T>
void HeapSort<T>::trace() {
  buildHeap();
  std::cout << "Heap construido:\n";
  this->print(); // Imprimir el estado del arreglo después de construir el heap

  for (int i = this->size_ - 1; i >= 0; i--) {
    T temp = this->data_[0];
    this->data_.set(0, this->data_[i]);
    this->data_.set(i, temp);
    std::cout << "Intercambio realizado en la posición " << i << ":\n";
    this->print(); // Imprimir el estado del arreglo después de cada intercambio
    heapify(i, 0);
    std::cout << "Heapify realizado en la posición " << i << ":\n";
    this->print(); // Imprimir el estado del arreglo después de aplicar heapify
  }
}

template <class T>
void HeapSort<T>::sort() {
  buildHeap();
  for (int i = this->size_ - 1; i >= 0; i--) {
    T temp = this->data_[0];
    this->data_.set(0, this->data_[i]);
    this->data_.set(i, temp);
    heapify(i, 0);
  }
}

template <class T>
void HeapSort<T>::buildHeap() {
  for (int i = this->size_/2 - 1; i >= 0; i--) {
    heapify(this->size_, i);
  }
}

template <class T>
void HeapSort<T>::heapify(int n, int i) {
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if (left < n && this->data_[left] > this->data_[largest]) {
    largest = left;
  }
  if (right < n && this->data_[right] > this->data_[largest]) {
    largest = right;
  }
  if (largest != i) {
    T temp = this->data_[i];
    this->data_.set(i, this->data_[largest]);
    this->data_.set(largest, temp);
    heapify(n, largest);
  }
}

template <class T>
void ShellSort<T>::trace() {
  int delta = this->size_ * alpha_;
  while (delta > 0) {
    delta = delta / 2;
    shellSortTrace(delta);
  }
}

template <class T>
void ShellSort<T>::shellSortTrace(int delta) {
  for (unsigned i = delta; i < this->data_.size(); i++) {
    T temp = this->data_[i];
    int j = i;
    while (j >= delta && this->data_[j - delta] > temp) {
      this->data_.set(j, this->data_[j - delta]);
      j -= delta;
    }
    this->data_.set(j, temp);
    std::cout << "After iteration " << i - delta << ":\n";
    this->print(); // Imprimir el estado del arreglo después de cada iteración del bucle
  }
}

template <class T>
void ShellSort<T>::sort() {
  if (alpha_ < 0 || alpha_ > 1) {
    std::cerr << "Invalid alpha value" << std::endl;
    return;
  }

  int delta = this->data_.size() * alpha_;
  while (delta > 0){
    delta = delta / 2;
    shellSort(delta);
  }
}

template <class T>
void ShellSort<T>::shellSort(int delta) {
  for (unsigned i = delta; i < this->data_.size(); i++) {
    T temp = this->data_[i];
    int j = i;
    while (j >= delta && this->data_[j - delta] > temp) {
      this->data_.set(j, this->data_[j - delta]);
      j -= delta;
    }
    this->data_.set(j, temp);
  }
}

template <class T>
void RadixSort<T>::trace() {
  T max = this->data_[0];
  for (unsigned i = 1; i < this->data_.size(); i++) {
    if (this->data_[i] > max) {
      max = this->data_[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSortTrace(exp);
    std::cout << "After iteration " << exp << ":\n";
    this->print(); // Imprimir el estado del arreglo después de cada iteración
  }
}

template <class T>
void RadixSort<T>::countingSortTrace(int exp) {
  unsigned size = this->data_.size();
  Block<T> output(size);
  int count[10] = {0};
  
  // Trama antes de contar los elementos
  std::cout << "Before counting elements:\n";
  this->print();

  // Contar los elementos
  for (unsigned i = 0; i < this->data_.size(); i++) {
    count[(this->data_[i] / exp) % 10]++;
  }

  // Trama después de contar los elementos
  std::cout << "After counting elements:\n";
  for (int i = 0; i < 10; i++) {
    std::cout << count[i] << " ";
  }
  std::cout << std::endl;

  // Acumular los conteos
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  // Trama después de acumular los conteos
  std::cout << "After accumulating counts:\n";
  for (int i = 0; i < 10; i++) {
    std::cout << count[i] << " ";
  }
  std::cout << std::endl;

  // Reorganizar los elementos en el arreglo de salida
  for (int i = this->data_.size() - 1; i >= 0; i--) {
    output.set(count[(this->data_[i] / exp) % 10] - 1, this->data_[i]);
    count[(this->data_[i] / exp) % 10]--;
  }

  // Trama después de reorganizar los elementos
  std::cout << "After reorganizing elements:\n";
  for (int i = 0; i < this->data_.size(); i++) {
    std::cout << output[i] << " ";
  }

  // Copiar los elementos reorganizados al arreglo original
  for (unsigned i = 0; i < this->data_.size(); i++) {
    this->data_.set(i, output[i]);
  }
}

template <class T>
void RadixSort<T>::countingSort(int exp) {
  unsigned size = this->data_.size();
  Block<T> output(size);
  int count[10] = {0};
  for (unsigned i = 0; i < this->data_.size(); i++) {
    count[(this->data_[i] / exp) % 10]++;
  }
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }
  for (int i = this->data_.size() - 1; i >= 0; i--) {
    output.set(count[(this->data_[i] / exp) % 10] - 1, this->data_[i]);
    count[(this->data_[i] / exp) % 10]--;
  }
  for (unsigned i = 0; i < this->data_.size(); i++) {
    this->data_.set(i, output[i]);
  }

}

template <class T>
void RadixSort<T>::sort() {
  T max = this->data_[0];
  
  for (unsigned i = 1; i < this->data_.size(); i++) {
    if (this->data_[i] > max) {
      max = this->data_[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(exp);
  }
}
