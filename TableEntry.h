#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    // Atributos públicos
    std::string key;  // Clave del par
    V value;          // Valor del par

    // Constructores
    TableEntry(std::string key, V value) : key(key), value(value) {}
    TableEntry(std::string key) : key(key), value(V()) {} // Valor predeterminado de V
    TableEntry() : key(""), value(V()) {} // Clave vacía, valor predeterminado

    // Sobrecarga de operadores de igualdad
    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key == te2.key; // Comparación solo por clave
    }

    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return !(te1 == te2); // Usar la implementación de operator==
    }

    // Sobrecarga de operadores relacionales
    friend bool operator<(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key < te2.key; // Comparar por clave
    }

    friend bool operator<=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key <= te2.key; // Comparar por clave
    }

    friend bool operator>(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key > te2.key; // Comparar por clave
    }

    friend bool operator>=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        return te1.key >= te2.key; // Comparar por clave
    }

    // Sobrecarga del operador de flujo de salida
    friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
        out << te.key << " -> " << te.value; // Formato de impresión
        return out;
    }
};

#endif // TABLEENTRY_H
