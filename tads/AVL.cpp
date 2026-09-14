

template <class T>
class AVL {
    private:
        struct Nodo {
            T dato;
            Nodo* izq;
            Nodo* der;
            int altura;
            
            Nodo(T dato, Nodo* izq, Nodo* der, int altura) : dato(dato), izq(izq = NULL), der(der = NULL), altura(altura = 0) {};
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

        bool InsertarRec(T dato, Nodo*& nodoActual) {
            bool insertado = false;
            if (nodoActual==NULL){
                nodoActual = new Nodo(dato);
                return true;
            } else if(Comparar(dato,nodoActual->dato) < 0) {
                insertado = InsertarRec(dato, nodoActual->izq);
            } else if (Comparar(dato,nodoActual->dato) > 0) {
                insertado = InsertarRec(dato, nodoActual->der);
            }
            //TODO: Qué hacer en el caso de que sean iguales? En principio no hacemos nada

            if(insertado) {
                nodoActual->altura = 1 + max(Altura(nodoActual->izq), Altura(nodoActual->der))

                int alturaIzq = Altura(nodoActual->izq);
                int alturaDer = Altura(nodoActual->der); 
                //Detectar desbalances
                if(alturaIzq-alturaDer > 1 && Comparar(nodoActual->izq->dato,dato) < 0) {
                    RotacionIzq(nodoActual);
                } else if(alturaIzq-alturaDer > 1 && Comparar(nodoActual->izq->dato,dato) > 0) {
                    RotacionDerIzq(nodoActual);
                } else if(alturaIzq-alturaDer < -1 && Comparar(nodoActual->der->dato,dato) < 0) {
                    RotacionDer(nodoActual);
                } else if(alturaIzq-alturaDer < -1 && Comparar(nodoActual->der->dato,dato) > 0) {
                    RotacionIzqDer(nodoActual);
                }
            }
        }
    public:
        AVL(int (*fComp)(T,T)) {
            this->raiz = NULL;
            this->capacidad = 0;
            this->fComp = fComp;
        }

        ~AVL(){
            while(this->raiz!=NULL){
                Nodo* aux = this->raiz;
                if(aux->der!=NULL){
                    this->raiz = aux->der;
                } else if(aux->izq!=NULL) {
                    this->raiz = aux->izq;
                }
                delete aux;
            }
        }
        void Insertar(T dato) {
            if(InsertarRec(dato, this->raiz, 0)) {
                this->capacidad++;
            }

        }
};