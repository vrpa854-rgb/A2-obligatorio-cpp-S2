#include <string>
#include <iostream>
#include "tads/AVL.cpp"

using namespace std;

int compareInts(int a, int b) {
    return a < b ? -1 : a > b ? 1 : 0;
}

int compareStr(string a, string b){
    return a.compare(b);
}
int main()
{
    int n;
    AVL<int> * monedas = new AVL(compareInts);
    AVL<string> * pinturas = new AVL(compareStr);
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string comando;
        cin >> comando;
        if (comando == "ALTA")
        {
            cin >> comando;
            if (comando == "M")
            {
                int valor;
                cin >> valor;
                monedas->Insertar(valor);
            }
            else if (comando == "P")
            {
                string valor;
                cin >> valor;
                pinturas->Insertar(valor);
            }
        }
        else if (comando == "BUSCAR")
        {
            cin >> comando;
            if (comando == "M")
            {
                int valor;
                cin >> valor;
                cout << (monedas->Existe(valor) ? "si" : "no") << endl;
            }
            else if (comando == "P")
            {
                string valor;
                cin >> valor;
                cout << (pinturas->Existe(valor) ? "si" : "no") << endl;
            }
        }
        else if (comando == "RANGO")
        {
            cin >> comando;
            if (comando == "M")
            {
                int desde, hasta;
                cin >> desde >> hasta;
                monedas->InOrderRango(desde, hasta);
            }
            else if (comando == "P")
            {
                string desde, hasta;
                cin >> desde >> hasta;
                pinturas->InOrderRango(desde, hasta);
            }
        }
    }
}