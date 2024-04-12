#include <iostream>
#include <fstream>

#include "nif.h"
#include "sorting.h"
#include "sequence.h"
#include "sortAlgrthmLibrary.h"

void print(const Block<NIF>& data, int size) {
  for (int i = 0; i < size; i++) {
    data[i].print();
  }
}

void menu(int argc, char* argv[]) {
  int size;
  std::string ord, init, trace, file;
  
  // parse arguments
  for (int i = 1; i < argc; ++i) {
    if (std::string(argv[i]) == "-size") {
      size = std::stoi(argv[i+1]);
    } else if (std::string(argv[i]) == "-ord") {
      ord = argv[i+1];
    } else if (std::string(argv[i]) == "-init") {
      init = argv[i+1];
      if (init == "file") {
        file = argv[i+2];
      }
    } else if (std::string(argv[i]) == "-trace") {
      trace = argv[i+1];
    }
  }


  // -size
  Block<NIF> data(size);

  // -init
  if (init == "manual") {
    std::cout << "Enter " << size << " NIFs" << std::endl;
    std::string nif;
    for (int i = 0; i < size; i++) {
      std::cin >> nif;
      data.insert(NIF(nif));
    }
  } else if (init == "random") {
    for (int i = 0; i < size; i++) {
      data.insert(NIF::random());
    }
  } else if (init == "file") {
    std::ifstream f(file);
    if (!f) {
      std::cerr << "Error: file not found" << std::endl;
      return;
    }
    for (int i = 0; i < size; i++) {
      std::string nif;
      f >> nif;
      data.insert(NIF(nif));
    }
  }
  print(data, size);

  // -ord
  SortAlgrthm<NIF>* sort;
  if (ord == "selection") {
    sort = new Selection<NIF>(data, size);
    //sort->print();
  } else if (ord == "quick") {
    sort = new QuickSort<NIF>(data, size);
  } else if (ord == "heap") {
    sort = new HeapSort<NIF>(data, size);
  } else if (ord == "shell") {
    sort = new ShellSort<NIF>(data, size);
  } else if (ord == "radix") {
    sort = new RadixSort<NIF>(data, size);
  }

  // -trace
  if (trace == "y") {
    sort->trace();
  } else {
    sort->sort();
  }

  std::cout << "Sorted\n";
  sort->print();
}

int main(int argc, char* argv[]) {
  srand(time(nullptr));
  if (argc > 10 || argc < 9) {
    std::cerr << "Usage: " << argv[0] << " -size <s> -ord <m> -init <i> [f] -trace <y|n>" << std::endl;
    return 1;
  } 
  
  menu(argc, argv);

  return 0;
}
