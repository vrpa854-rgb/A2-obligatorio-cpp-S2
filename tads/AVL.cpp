

template <class T>
class AVL {
    private:
        struct Nodo {
            T dato;
            Nodo* izq;
            Nodo* der;
            int altura;
            
            Nodo(T dato, Nodo* izq = NULL, Nodo* der = NULL, int altura = 0) : dato(dato), izq(izq), der(der), altura(altura) {};
        };
        Nodo* raiz;
        int capacidad;
        int (*fComp)(T,T);

        int Comparar(T dato1, T dato2) {
            return fComp(dato1, dato2);
        }
        
        int Altura(Nodo* nodo) {
            return nodo!=NULL?nodo->altura:0;
        }

        Nodo * rotacionDerecha(Nodo * B) {
            Nodo * A = B->izq;
            Nodo * T2 = A->der;
            B->izq = T2;
            A->der = B;
            //Recalculo altura
            B->altura = 1 + max(Altura(B->izq), Altura(B->der));
            A->altura = 1 + max(Altura(A->izq), Altura(A->der));
            return A;
        }
        
        Nodo * rotacionIzquierda(Nodo * A) {
            Nodo * B = A->der;
            Nodo * T2 = B->izq;
            A->der = T2;
            B->izq = A;
            //Recalculo altura
            A->altura = 1 + max(Altura(A->izq), Altura(A->der));
            B->altura = 1 + max(Altura(B->izq), Altura(B->der));
            return B;
        }

        bool InsertarRec(T dato, Nodo*& nodoActual) {
            bool insertado = false;
            if (!nodoActual){
                nodoActual = new Nodo(dato);
                nodoActual->altura = 1;
                return true;
            } else if(Comparar(dato,nodoActual->dato) < 0) {
                insertado = InsertarRec(dato, nodoActual->izq);
            } else if (Comparar(dato,nodoActual->dato) > 0) {
                insertado = InsertarRec(dato, nodoActual->der);
            }

            if(insertado) {
                nodoActual->altura = 1 + max(Altura(nodoActual->izq), Altura(nodoActual->der));

                int alturaIzq = Altura(nodoActual->izq);
                int alturaDer = Altura(nodoActual->der); 
                bool desbalanceoIzq = alturaIzq-alturaDer > 1; // 2
                bool desbalanceoDer = alturaIzq-alturaDer < -1; // -2
                //Detectar desbalances
                if(desbalanceoIzq) {
                    if(Comparar(dato, nodoActual->izq->dato) < 0) {
                        nodoActual = rotacionDerecha(nodoActual);
                    } else {
                        nodoActual->izq = rotacionIzquierda(nodoActual->izq);
                        nodoActual = rotacionDerecha(nodoActual);
                    }
                } else if(desbalanceoDer) {
                    if(Comparar(dato, nodoActual->der->dato) > 0) {
                        nodoActual = rotacionIzquierda(nodoActual);
                    } else {
                        nodoActual->der = rotacionDerecha(nodoActual->der);
                        nodoActual = rotacionIzquierda(nodoActual);
                    }
                }
            }

            return insertado;
        }

        void inOrderRec(Nodo*& nodoActual) {
            if(!nodoActual) return;
            inOrderRec(nodoActual->izq);
            cout << nodoActual->dato << endl;
            inOrderRec(nodoActual->der);
        }
        void destruirRec(Nodo* nodoActual) {
            if(!nodoActual) return;
            destruirRec(nodoActual->izq);
            destruirRec(nodoActual->der);
            delete nodoActual;
        }
    public:
        AVL(int (*fComp)(T,T)) {
            this->raiz = NULL;
            this->capacidad = 0;
            this->fComp = fComp;
        }

        ~AVL(){
            destruirRec(this->raiz);
        }
        void Insertar(T dato) {
            if(InsertarRec(dato, this->raiz)) {
                this->capacidad++;
            }
        }

        
        void inOrder() {
            cout << "InOrder: ";
            inOrderRec(raiz);
            cout << "\n";
        }
};