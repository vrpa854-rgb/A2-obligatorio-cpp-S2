
#include <iostream>
using namespace std;
#pragma once

template<class K, class V>
class Hash {
    private:
        struct bucket {
            K clave;
            V valor;
            bool estaBorrado;
            bucket(K clave, V valor) : clave(clave), valor(valor), estaBorrado(false) {}
        };
        bucket* * vec;
        int largoVec, cantidad, capacidad;
        float fc; //Factor de carga

        bool esPrimo(int num) {
            if(num<=1) return false;
            else if(num==2) return true;
            else if(num%2==0) return false;
            else {
                for(int i=0; i<=num/2; i+=2){
                    if(i%num==0) {
                        return false;
                    }
                }
            }
            return true;
        }
        int primoSup(int num) {
            while(!esPrimo(++num));
            return num;
        }
    public:
        Hash(int capacidad) {
            this->capacidad = capacidad;
            this->fc = 0.0;
            this->cantidad = 0;
            this->largoVec = primoSup(capacidad);
            this->vec = new bucket*[largoVec]();
        }
    
};