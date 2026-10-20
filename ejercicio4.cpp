#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap.cpp"
#include "tads/grafoLA.cpp"

using namespace std;

struct Modulo {
    int numero;
    int prioridad;
    Modulo(int n, int p) : numero(n), prioridad(p) {}
};

int fHash(Modulo* m) { return m->numero; } 
bool fEq(Modulo* a, Modulo* b) { return a->numero == b->numero; }
int fComp(Modulo* a, Modulo* b) { 
    if (a->prioridad != b->prioridad) return a->prioridad < b->prioridad ? -1 : 1;
    if (a->numero != b->numero) return a->numero < b->numero ? -1 : 1;
    return 0;
}


int main()
{
    int v, a;
    int pos = 1;
    cin >> v >> a;
    int* p = new int[v+1];
    for(int i=1; i<=v; i++) {
        cin >> p[i];
    }    
    
    int* incidencias = new int[v+1];
    int* resultado = new int[v+1];
    GrafoLA* g = new  GrafoLA(v, true, false);
    for(int i=1; i<=v; i++) resultado[i] = -1;
    for(int i=1; i<=a; i++) {
        int u, w;
        cin >> u >> w;
        g->insertarArista(u,w);
        incidencias[w]++;
    }
 
    Heap<Modulo*>* heap = new Heap<Modulo*>(v+a, fComp, fHash, fEq);
    for(int i=1; i<=v; i++) {
        if(incidencias[i]==0) {
            heap->insertar(new Modulo{i, p[i]});
        }
    }
        
    while(!heap->estaVacio()) {
        int elem = heap->tope()->numero;
        heap->eliminar();
        resultado[pos++]=elem;
        Adyacentes* ady = g->obtenerAdyacentes(elem);
        while(ady!=NULL) {
            incidencias[ady->destino]--;
            Modulo * m = new Modulo(ady->destino, p[ady->destino]);
            if(incidencias[ady->destino]==0) heap->insertar(m);
            ady=ady->sig;
        }
    }

    if(pos < v) {
        cout << "imposible" << endl;
    } else {
        for(int i=1; i<=v; i++) cout << resultado[i] << endl;
    }

    delete heap;
    delete g;
    delete [] p;
    delete [] incidencias;
    delete [] resultado;
    return 0;
}