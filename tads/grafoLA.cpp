#include <climits>
#include <iostream>
using namespace std;

struct NodoListaLA {
    int destino;
    int peso;
    NodoListaLA* sig;

    NodoListaLA(int v, int p, NodoListaLA* s = NULL) {
        destino = v;
        peso = p;
        sig = s;
    }
};

struct Adyacentes {
    int destino;
    int peso;
    Adyacentes* sig;

    Adyacentes(int v, int p, Adyacentes* s = NULL) {
        destino = v;
        peso = p;
        sig = s;
    }
};

typedef NodoListaLA* ListaAdyLA;

class GrafoLA {
private:
    int V;
    bool dirigido;
    bool ponderado;
    NodoListaLA** vec;

    Adyacentes* copiarListaAdyacencia(NodoListaLA* lista) {
        Adyacentes* ady = NULL;

        while (lista) {
            ady = new Adyacentes(lista->destino, lista->peso, ady);
            lista = lista->sig;
        }

        return ady;
    }

public:
    GrafoLA(int v, bool dirigido = false, bool ponderado = false) {
        this->V = v;
        this->dirigido = dirigido;
        this->ponderado = ponderado;
        this->vec = new NodoListaLA*[v + 1]();
    }

    ~GrafoLA() {
        for (int i = 1; i <= V; i++) {
            NodoListaLA* act = vec[i];

            while (act != NULL) {
                NodoListaLA* borrar = act;
                act = act->sig;
                delete borrar;
            }
        }

        delete[] vec;
    }

    int cantidadVertices() {
        return this->V;
    }

    void insertarArista(int o, int d, int peso = 1) {
        if (!ponderado) peso = 1;

        NodoListaLA* nuevo = new NodoListaLA(d, peso, this->vec[o]);
        this->vec[o] = nuevo;

        if (!this->dirigido) {
            NodoListaLA* inversa = new NodoListaLA(o, peso, this->vec[d]);
            this->vec[d] = inversa;
        }
    }

    Adyacentes* obtenerAdyacentes(int v) {
        return copiarListaAdyacencia(this->vec[v]);
    }
};