#include <iostream>
using namespace std;

template<class K, class V>
class Hash {
    private:
        struct bucket{
            K clave;
            V valor;
            bool estaBorrado;

            bucket(K clave, V valor) : clave(clave), valor(valor), estaBorrado(false){}
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

            //Rehash
            for(int i=0; i<this->largoVec; i++) {
                bucket* nodo = vec[i];
                if(!node) continue;

                //No precisa pasarlos
                if(nodo->estaBorrado) {
                    delete nodo;
                    continue;
                }

                int pos = abs(fHash(nodo->clave)) % nLargoVec;
                while(nVec[pos]){
                    pos=(pos+1)%nLargoVec;
                }
                nVec[pos] = nodo;
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
            bucket* aux;
            bool meVoy = false;
            while(!meVoy){
                aux = vec[pos];
                if(!aux){
                    vec[pos]=new bucket(clave, valor);
                    meVoy=true;
                }else if(aux->estaBorrado){
                    aux->estaBorrado=false;
                    aux->clave = clave;
                    aux->valor = valor;
                    meVoy=true;
                }else{
                    pos=(pos+1)%largoVec;
                }
            }
            cantidad++;
            fc=(float)cantidad/capacidad;
            if(fc>=0.7){
                Rehash();
            }
        }

        bool Existe(K clave){
            int pos = abs(fHash(clave)) % largoVec, posInicial = pos;
            bucket* aux;
            while(true){
                aux = vec[pos];
                if(!aux){
                    return false;
                } else if(aux->estaBorrado || !fEq(aux->clave,clave)) {
                    pos=(pos+1)%largoVec;
                    if(pos == posInicial){
                        return false;
                    }
                } else {
                    return true;
                }
            }
        }

        // Pre: Existe(clave)
        V Recuperar(K clave){
            int pos = abs(fHash(clave)) % largoVec, posInicial = pos;
            bucket* aux;
            while(true){
                aux = vec[pos];
                if(aux->estaBorrado || !fEq(aux->clave,clave)) {
                    pos=(pos+1)%largoVec;
                } else {
                    return aux->valor;
                }
            }
        }

        void Actualizar(K clave, V nuevoValor){
            int pos = abs(fHash(clave)) % largoVec, posInicial = pos;
            bucket* aux;
            while(true){
                aux = vec[pos];
                if(aux->estaBorrado || !fEq(aux->clave,clave)) {
                    pos=(pos+1)%largoVec;
                } else {
                    aux->valor = nuevoValor;
                    return;
                }
            }
        }

        // Pre: Existe(clave)
        void Borrar(K clave){
            int pos = abs(fHash(clave)) % largoVec, posInicial = pos;
            bucket* aux;
            while(true){
                aux = vec[pos];
                if(aux->estaBorrado || !fEq(aux->clave,clave)) {
                    pos=(pos+1)%largoVec;
                } else {
                    aux->estaBorrado=true;
                    return;
                }
            }
        }

        void Mostrar(){
            for (int i = 0; i < largoVec; i++)
            {
                bucket* aux = vec[i];
                if(!aux){
                    cout << "VACIO" << endl;
                } else if(aux->estaBorrado){
                    cout << "BORRADO" << endl;
                } else {
                    cout << "(" << aux->clave << "," << aux->valor << ")" << endl;
                }
            }
        }
};