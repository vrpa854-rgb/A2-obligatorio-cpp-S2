#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap.cpp"

using namespace std;

int comparar(long long a, long long b) { 
    return a < b ? -1 : a > b ? 1 : 0 ; 
}

int main()
{
    int cantidad;
    cin >> cantidad;
    Heap<long long> minHeap(cantidad, comparar);
    for (int i = 0; i < cantidad; i++) {
        long long valor;
        cin >> valor;
        minHeap.insertar(valor);
    }

    long long total = 0;
    while (minHeap.tamanio() > 1) {
        long long tope1 = minHeap.tope();
        minHeap.eliminar();
        long long tope2 = minHeap.tope();
        minHeap.eliminar();
        total += tope1 + tope2;
        minHeap.insertar(tope1 + tope2);
    }

    cout << total << endl;
}