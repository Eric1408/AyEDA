#pragma once

#include <vector>

#include "sequence.h"

template <class T>
class SortAlgrthm {
 protected:
  int size_;
  Block<T> data_;
 public:
  SortAlgrthm() = default;
  SortAlgrthm(const Block<T>& data, int size) : size_(size), data_(data) {}
};


template <class T>
class Selection : public SortAlgrthm<T> {
 public:
  Selection(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
};


template <class T>
class QuickSort : public SortAlgrthm<T> {
 public:
  QuickSort(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
 private:
  int partition(int, int);
  void quickSort(int, int);
};


template <class T>
class HeapSort : public SortAlgrthm<T> {
 public:
  HeapSort(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
};


template <class T>
class ShellSort :public SortAlgrthm<T> {
 public:
  ShellSort(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
 private:
  float alpha_;
};


template <class T>
class RadixSort : public SortAlgrthm<T> {
 public:
  RadixSort(const Block<T>& data, int size) : SortAlgrthm<T>(data, size) {}
  void sort();
};
