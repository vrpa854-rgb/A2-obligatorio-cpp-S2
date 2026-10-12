#include <cassert>
#include "Hash.cpp"

template<class T>
class Heap{
    private:
        T* vec;
        int cap;
        int primeroLibre; // int ultimoOcupado
        int (*fComp)(T,T);
        Hash<T,int>* hashPosiciones;

        void swap(int posA, int posB){
            T auxA = vec[posA];
            T auxB = vec[posB];
            vec[posA] = auxB;
            vec[posB] = auxA;
            hashPosiciones->Actualizar(auxA, posB);
            hashPosiciones->Actualizar(auxB, posA);
        }

        int comparar(int posA, int posB){
            return fComp(vec[posA],vec[posB]);
        }
        void flotar(int pos){
            // CB1: estoy en raiz pos == 1 return
            if(pos == 1) return;
            // buscar posicion del padre
            int posPadre = pos / 2;
            // comparar lo que haya en la posPadre con lo que haya en pos
            // CB2: si el padre es menor o igual que el hijo return
            if(comparar(pos, posPadre)>=0) return;
            swap(pos, posPadre);
            flotar(posPadre);
        }

        void hundir(int pos){
            // CB1: estoy en hoja return
            if(pos * 2 >= primeroLibre) return;
            // buscar posicion del hijo menor
            int posHijoMenor = pos * 2;
            if(posHijoMenor + 1 < primeroLibre && comparar(posHijoMenor + 1, posHijoMenor)<0){
                posHijoMenor = posHijoMenor + 1; // el menor es el hijo derecho
            }
            // comparar lo que haya en la pos con lo que haya en posHijoMenor
            // CB2: si el hijo es mayor o igual que el padre return
            if(comparar(posHijoMenor, pos)>=0) return;
            swap(pos, posHijoMenor);
            hundir(posHijoMenor);
        }
public:
    Heap(int unaCap, int (*fComp)(T,T), int (*fHash)(T), bool (*fEq)(T,T)){
        // inicializar memoria
        primeroLibre = 1;// programo en funcion de si es 0 o 1 el primero de mi heap
        cap = unaCap;
        vec = new T[cap + 1];
        this->fComp=fComp;
        this->hashPosiciones = new Hash<T,int>(this->cap, fHash, fEq);
    }
    ~Heap(){
        // eliminar memoria
        delete[] vec;
        delete hashPosiciones;
    }

    void insertar(T elemento){
        assert(primeroLibre <= cap);
        vec[primeroLibre] = elemento;
        hashPosiciones->Insertar(elemento,primeroLibre);
        primeroLibre++;
        flotar(primeroLibre - 1);
    }

    void eliminar(){
        assert(primeroLibre > 1);
        swap(1, primeroLibre - 1);
        primeroLibre--; // eliminar logicamente el ultimo elemento
        hundir(1);
        hashPosiciones->Borrar(vec[primeroLibre]);
    }

    void cambiarPrioridad(T elemento){
        int pos = hashPosiciones->Recuperar(elemento);
        vec[pos] = elemento;
        flotar(pos);
        hundir(pos);
    }

    int tamanio(){
        return primeroLibre - 1;
    }

    bool estaVacio(){
        return primeroLibre == 1;
    }
    
    T tope(){
        assert(primeroLibre > 1);
        return vec[1];
    }
};