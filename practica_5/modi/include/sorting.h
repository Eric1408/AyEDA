#pragma once

#include "sequence.h"

template <class T>
class SortAlgrthm {
 protected:
  int size_;
  Block<T> data_;
 public:
  SortAlgrthm() = default;
  SortAlgrthm(const Block<T>& data, int size) : data_(data), size_(size) {}
  virtual void sort() = 0;
  virtual void trace() = 0;

  void print() const;
};


template <class T>
class Selection : public SortAlgrthm<T> {
 public:
  Selection(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
  void trace();
};


template <class T>
class QuickSort : public SortAlgrthm<T> {
 public:
  QuickSort(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
  void trace();
 private:
  int partition(int, int);
  int partitionTrace(int, int);
  void quickSort(int, int);
  void quickSortTrace(int, int);
};


template <class T>
class HeapSort : public SortAlgrthm<T> {
 public:
  HeapSort(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
  void trace();
 private:
  void heapify(int, int);
  void buildHeap();
};


template <class T>
class ShellSort :public SortAlgrthm<T> {
 public:
  ShellSort(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {
    std::cout << "Enter alpha[0-1]: ";
    std::cin >> alpha_;
    if (alpha_ < 0 || alpha_ > 1) {
      std::cerr << "Error: invalid alpha" << std::endl;
      exit(1);
    }
  }
  void sort();
  void trace();
 private:
  void shellSort(int);
  void shellSortTrace(int);
  float alpha_;
};


template <class T>
class RadixSort : public SortAlgrthm<T> {
 public:
  RadixSort(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
  void trace();
 private:
  void countingSort(int);
  void countingSortTrace(int);
};
