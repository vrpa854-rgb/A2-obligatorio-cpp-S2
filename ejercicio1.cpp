#include <string>
#include <iostream>
#include <cstring>
#include "tads/AVL.cpp"

using namespace std;

int compareInts(long long a, long long b) {
    return a < b ? -1 : a > b ? 1 : 0;
}

int compareStr(string a, string b){
    return a.compare(b);
}

int main()
{
    int n;
    AVL<long long> * monedas = new AVL<long long>(compareInts);
    AVL<string> * pinturas = new AVL<string>(compareStr);
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string accion, tipo, v1, v2;
        cin >> accion >> tipo >> v1;

        //Decido
        if (accion == "ALTA")
        {
            if (tipo == "M")
            {
                long long valor = stoll(v1);
                monedas->Insertar(valor);
            }
            else if (tipo == "P")
            {
                pinturas->Insertar(v1);
            }
        }
        else if (accion == "BUSCAR")
        {
            if (tipo == "M")
            {
                long long valor = stoll(v1);
                cout << (monedas->Existe(valor) ? "si" : "no") << endl;
            }
            else if (tipo == "P")
            {
                cout << (pinturas->Existe(v1) ? "si" : "no") << endl;
            }
        }
        else if (accion == "RANGO")
        {
            cin >> v2;
            if (tipo == "M")
            {
                long long desde = stoll(v1);
                long long hasta = stoll(v2);
                monedas->InOrderRango(desde, hasta);
            }
            else if (tipo == "P")
            {
                pinturas->InOrderRango(v1, v2);
            }
        }
    }

    return 0;
}