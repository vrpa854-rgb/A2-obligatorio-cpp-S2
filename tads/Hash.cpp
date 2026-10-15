#include <iostream>
using namespace std;

template<class K, class V>
class Hash {
    private:
        struct bucket{
            K clave;
            V valor;
            bucket* sig;

            bucket(K clave, V valor) : clave(clave), valor(valor), sig(nullptr){}
        };

        bucket* * vec;
        int largoVec, cantidad, capacidad;
        float fc;
        int(*fHash)(K);
        bool(*fEq)(K,K);

        bool esPrimo(int num) {
            if(num<=1) return false;
            else if(num==2) return true;
            else if(num%2==0) return false;
            else {
                for (int i = 3; i <= num/2; i+=2)
                {
                    if(num%i==0){
                        return false;
                    }
                }
            }
            return true;
        }

        int primoSup(int num){
            while(!esPrimo(++num));
            return num;
        }

        void Rehash() {
            //Crear un nuevo vector
            int nCapacidad = this->capacidad*2;
            int nLargoVec = primoSup(nCapacidad);
            bucket ** nVec = new bucket*[nLargoVec]();

            //Rehash - recorre la lista e inserta al principio
            for(int i=0; i<this->largoVec; i++) {
                bucket* nodo = vec[i];
                while(nodo){
                    bucket* sig = nodo->sig;
                    int pos = abs(fHash(nodo->clave)) % nLargoVec;
                    nodo->sig = nVec[pos];
                    nVec[pos] = nodo;
                    nodo = sig;
                }
            }   
            
            //Eliminar el anterior y actualizar
            delete [] this->vec;
            this->vec = nVec;
            this->largoVec = nLargoVec;
            this->capacidad = nCapacidad;
        }

    public:
        Hash(int capacidad, int(*fHash)(K), bool(*fEq)(K,K)){
            this->fHash=fHash;
            this->capacidad = capacidad;
            this->fc = 0.0;
            this->cantidad = 0;
            this->largoVec = primoSup(capacidad);
            this->vec = new bucket*[this->largoVec]();
            this->fEq = fEq;
        }

        bool EsVacia(){
            return cantidad == 0;
        }

        // Pre: !Existe(clave)
        void Insertar(K clave, V valor){
            int pos = abs(fHash(clave)) % largoVec;
            bucket* nuevo = new bucket(clave, valor);
            nuevo->sig = vec[pos];
            vec[pos] = nuevo;
            cantidad++;
            fc=(float)cantidad/capacidad;
            if(fc>=0.7){
                Rehash();
            }
        }

        bool Existe(K clave){
            int pos = abs(fHash(clave)) % largoVec, posInicial = pos;
            bucket* aux = vec[pos];
            while(aux){
                if(fEq(aux->clave,clave)){
                    return true;
                }
                aux = aux->sig;
            }
            return false;
        }

        // Pre: Existe(clave)
        V Recuperar(K clave){
            int pos = abs(fHash(clave)) % largoVec;
            bucket* aux = vec[pos];
            while(!fEq(aux->clave,clave)){
                aux = aux->sig;
                
            }
            return aux->valor;
        }

        void Actualizar(K clave, V nuevoValor){
            int pos = abs(fHash(clave)) % largoVec;
            bucket* aux = vec[pos];
            while(!fEq(aux->clave,clave)){
                aux = aux->sig;
            }
            aux->valor = nuevoValor;
        }

        // Pre: Existe(clave)
        void Borrar(K clave){
            int pos = abs(fHash(clave)) % largoVec;
            bucket* aux = vec[pos];
            bucket* ant = nullptr;
            while(aux && !fEq(aux->clave,clave)){
                ant = aux;
                aux = aux->sig;
            }
            if(ant){
                ant->sig = aux->sig;
            } else {
                vec[pos] = aux->sig;
            }
            delete aux;
            cantidad--; 
            fc=(float)cantidad/capacidad;
        }

        void Mostrar(){
            for (int i = 0; i < largoVec; i++)
            {
                bucket* aux = vec[i];
                if(!aux){
                    cout << "VACIO" << endl;
                } else {
                    while(aux){
                        cout << "(" << aux->clave << "," << aux->valor << ") ";
                        aux = aux->sig;
                    }
                    cout << endl;
                }
            }
        }
};