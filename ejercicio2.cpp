#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Hash.cpp"

using namespace std;

int funcHash(string clave) {
    unsigned long long h = 0;
    for (int i = 0; i < clave.length(); i++) {
        h = 31 * h + clave[i];
    }
    return h;
}

string armarClave(const string& palabra) {
    int conteo[26] = {0};
    for (int i = 0; i < palabra.length(); i++) {
        conteo[palabra[i] - 'a']++;
    }
    string clave(26, 'a');
    for (int i = 0; i < 26; i++) {
        clave[i] = 'a' + conteo[i];
    }
    return clave;
}

bool igual(string a, string b) {
    return a == b;
}

int main()
{
    int n;
    cin >> n;

    Hash<string, int> tabla(2*n, funcHash, igual);
    int cajonesDistintos = 0;
    int maxCajon = 0;

    for (int i = 0; i < n; i++) {
        string palabra;
        cin >> palabra;
        string clave = armarClave(palabra);

        if (tabla.Existe(clave)) {
            int nueva = tabla.Recuperar(clave) + 1;
            tabla.Actualizar(clave, nueva);
            if (nueva > maxCajon) maxCajon = nueva;
        } else {
            tabla.Insertar(clave, 1);
            cajonesDistintos++;
            if (maxCajon < 1) maxCajon = 1;
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string palabra;
        cin >> palabra;
        string clave = armarClave(palabra);
        if (tabla.Existe(clave)) {
            cout << tabla.Recuperar(clave) << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    cout << cajonesDistintos << " " << maxCajon << "\n";
    return 0;
}