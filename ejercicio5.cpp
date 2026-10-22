#include <string>
#include <iostream>
#include <limits>
#include "tads/MFSet.cpp"
#include "tads/Heap.cpp"

using namespace std;

struct Arista {
    int o;
    int d;
    int peso;
    Arista(int o, int d, int peso) : o(o), d(d), peso(peso){}
};
int fComp(Arista* a, Arista* b) {
    return a->peso < b->peso ? -1 : a->peso > b->peso ? 1 : 0;
}

int main()
{
    int v, e;
    cin >> v >> e;
    if(v!=1) {
        Heap<Arista*>* minHeap = new Heap<Arista*>(v+e, fComp);
        for(int i=1; i<=e; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            minHeap->insertar(new Arista(u,v,w));
        }

        MFSet* set = new MFSet(v+1);
        long long resultado = 0;
        int countSenderos = 0;
        while(!minHeap->estaVacio() && countSenderos < v-1) {
            Arista* a = minHeap->tope();
            minHeap->eliminar();

            if(set->find(a->o) != set->find(a->d)) {
                set->merge(a->o,a->d);
                resultado += a->peso;
                countSenderos++;
            }
        }
        
        bool conexo = true;
        for(int i=2; i<=v && conexo; i++)
            if(set->find(1) != set->find(i))
                conexo = false;
        
        if(conexo) 
            cout << resultado << endl;
        else
            cout << "imposible" << endl;
        

        delete set;
        delete minHeap;
    } else {
        cout << 0 << endl;
    }

    return 0;
}