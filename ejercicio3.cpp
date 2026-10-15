#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap.cpp"

using namespace std;

int comparar(int a, int b) { 
    return a - b; 
}
int hashInt(int a) { 
    return a; 
}
bool igualInt(int a, int b) { 
    return a == b;
 }

int main()
{
    int cantidad;
    cin >> cantidad;
    Heap<int> minHeap(cantidad, comparar, hashInt, igualInt);
    for (int i = 0; i < cantidad; i++) {
        int valor;
        cin >> valor;
        minHeap.insertar(valor);
    }

    int total = 0;
    while (minHeap.tamanio() > 1) {
        int tope1 = minHeap.tope();
        minHeap.eliminar();
        int tope2 = minHeap.tope();
        minHeap.eliminar();
        total += tope1 + tope2;
        minHeap.insertar(tope1 + tope2);
    }

    cout << total << endl;
}