#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <ostream>
#include <stdexcept>
#include "TableEntry.h" 
#include "/Users/dafnealexandraceballosospina/Downloads/ListLinked.h"  
#include "Dict.h"

template <typename V>
class HashTable : public Dict<V> {
private:
    int n;  // Número de elementos almacenados
    int max;  // Tamaño de la tabla hash (número de cubetas)
    ListLinked<TableEntry<V> >* table;  // Array de punteros a listas enlazadas

    // Función hash: devuelve la posición en la tabla
    int h(std::string key) {
        int ascii_sum = 0;
        for (char c : key) {
            ascii_sum += static_cast<int>(c);
        }
        return ascii_sum % max;  // Índice hash
    }

public:
    // Constructor
    HashTable(int size) : n(0), max(size) {
        table = new ListLinked<TableEntry<V> >[max];
    }

    // Destructor
    ~HashTable() {
        delete[] table;  // Liberar memoria dinámica
    }

    // Implementación de métodos de Dict<V>
    void insert(std::string key, V value) override {
        int index = h(key);
        TableEntry<V> entry(key, value);
        if (table[index].contains(entry)) {
            throw std::runtime_error("Key already exists in the hash table.");
        }
        table[index].push_front(entry);  // Insertar al inicio de la lista
        ++n;
    }

    V search(std::string key) override {
        int index = h(key);
        TableEntry<V> entry(key);  // Entrada con solo clave
        if (table[index].contains(entry)) {
            return table[index].find(entry).value;
        }
        throw std::runtime_error("Key not found in the hash table.");
    }

    V remove(std::string key) override {
        int index = h(key);
        TableEntry<V> entry(key);
        if (!table[index].contains(entry)) {
            throw std::runtime_error("Key not found in the hash table.");
        }
        TableEntry<V> removed = table[index].remove(entry);
        --n;
        return removed.value;
    }

    int entries() override {
        return n;
    }

    // Método propio: capacidad de la tabla
    int capacity() {
        return max;
    }

    // Sobrecarga de operador []
    V operator[](std::string key) {
        return search(key);  // Usa el método search para devolver el valor
    }

    // Sobrecarga de operador <<
    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& ht) {
        for (int i = 0; i < ht.max; ++i) {
            out << "Bucket " << i << ": ";
            if (!ht.table[i].empty()) {
                out << ht.table[i];  // Imprime la lista enlazada
            } else {
                out << "(empty)";
            }
            out << std::endl;
        }
        return out;
    }
};

#endif  // HASHTABLE_H

