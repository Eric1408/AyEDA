#include "../include/menu.h"

Menu::Menu () {
  std::cout << Menu::INIT_STR;
  std::string line;
  std::getline(std::cin, line);

  unsigned table_size;
  DispersionFunction<long>* fd;
  ExplorationFunction<long>* fe{nullptr};
  unsigned block_size{0};

  std::smatch match;
  if (std::regex_search(line, match, Menu::fdPattern)) {
    table_size = toPrime(std::stoi(match[1]));
    
    if (match[2] == Menu::MODULE) {
      fd = new fdModule<long>(table_size);
    } else if (match[2] == Menu::SUM) {
      fd = new fdSum<long>(table_size);
    } else if (match[2] == Menu::PSEUDO) {
      fd = new fdPseudo<long>(table_size);
    }
    
    if (match[4] == Menu::BLOCK) {
      block_size = std::stoi(match[5]);
      if (match[6] == Menu::LINEAL_EXP) {
        fe = new feLineal<long>;
      } else if (match[6] == Menu::DOUBLE_EXP) {
        fe = new feDouble<long>;
      } else if (match[6] == Menu::DOUBLE_HASH_EXP) {
        fe = new feDoubleHash<long>(fd);
      } else if (match[6] == Menu::REHASH_EXP) {
        fe = new feReHash<long>(table_size);
      }
    }
  } 
  hash_table_ = new HashTable<long>(table_size, fd, fe, block_size);
}

bool Menu::isPrime(unsigned number) {
  if (number <= 1) {
    return false;
  }

  for (unsigned i = 2; i < number; i++) {
    if (number % i == 0) return false;
  }

  return true;
}

unsigned Menu::toPrime(int number) {
  while (!isPrime(number)) {
    number--;
  }
  
  return number;
} 

void Menu::start () {
  unsigned option;

  do {
    std::cout << Menu::MENU_STR;
    std::cin >> option;
    switch (option) {
    case 1:
      insert();
      break;
    case 2:
      search();
      break;
    case 3: 
      printMenu();
      break;
    case 4:
      stop();
      break;
    default:
      std::cerr << "Opcion no valida" << std::endl;
      break;
    }
  } while (option != 3);
  
}

void Menu::insert () {
  std::cout << "Metodo insertar\n";
  long number;
  std::cout << "Numero a insertar: ";
  std::cin >> number;
  
  if (hash_table_->insert(number)) {
    std::cout << "Numero insertado en la posicion: " << HashTable<long>::POSITION << std::endl;
  } else {
    std::cout << "Numero no insertado\n";
  }
}

void Menu::search() {
  std::cout << "Metodo buscar\n";
  long number;
  std::cout << "Numero a buscar: ";
  std::cin >> number;

  if (hash_table_->search(number)) {
    std::cout << "Numero encontrado en la posicion: " << HashTable<long>::POSITION << std::endl;
  } else {
    std::cout << "Numero no encontrado\n";
  }
}

void Menu::stop() {
  std::cout << "Saliendo del programa\n";
  exit(0);
}

void Menu::printMenu () {
  hash_table_->print();
}

const std::string Menu::MENU_STR = "=============================== MENU ===============================\n"
                                   "Insertar[1]           Buscar[2]         Tabla[3]            Parar[4]\n" 
  "Seleciona una opcion: ";
const std::string Menu::INIT_STR = "INTRODUZCA:\n"
  "Tamaño de la tabla\n"
  "Funcion de dispersion (modulo - suma - pseudoaleatoria[pseudo])\n"
  "Tecnica de dispersion (lista - bloque)\n"
  "Tamaño de bloque\n"
  "Funcion de exploracion (lineal - cuadratica - dobleHash - redispersion)\n"
  "EJEMPLO -> 100 pseudo bloque 10 lineal\n\n";

const std::regex Menu::fdPattern = std::regex("(\\d+)\\s+(\\w+)\\s+(lista|(bloque)\\s+(\\d+)\\s+(\\w+))");

const std::string Menu::MODULE = "modulo";
const std::string Menu::SUM = "suma";
const std::string Menu::PSEUDO = "pseudo";

const std::string Menu::LIST = "lista";
const std::string Menu::BLOCK = "bloque";

const std::string Menu::LINEAL_EXP = "lineal";
const std::string Menu::DOUBLE_EXP = "cuadratica";
const std::string Menu::DOUBLE_HASH_EXP = "dobleHash";
const std::string Menu::REHASH_EXP = "redispersion";