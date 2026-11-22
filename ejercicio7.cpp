#include <iostream>
using namespace std;

bool esSolucionTrivial(int ini, int fin) {
    return ini >= fin;
}

long long solucionTrivial() {
    return 0;
}

int dividir(int ini, int fin) {
    return ini + (fin - ini) / 2;
}

long long mergear(int* dorsales, int* aux, int ini, int medio, int fin) {
    long long remontadas = 0;
    //Ambas mitades ya están ordenadas
    int j = medio + 1;
    for (int i = ini; i <= medio; i++) {
        while (j <= fin && (long long)dorsales[i] > 2LL * dorsales[j]) j++;
        remontadas += j - (medio + 1);
    }

    int i = ini;
    j = medio + 1;
    int k = ini;
    while (i <= medio && j <= fin) {
        if (dorsales[i] <= dorsales[j]) aux[k++] = dorsales[i++];
        else aux[k++] = dorsales[j++];
    }
    while (i <= medio) aux[k++] = dorsales[i++];
    while (j <= fin) aux[k++] = dorsales[j++];
    for (int s = ini; s <= fin; s++) dorsales[s] = aux[s];

    return remontadas;
}

long long dyc(int* dorsales, int* aux, int ini, int fin) {
    if (esSolucionTrivial(ini, fin)) return solucionTrivial();
    int medio = dividir(ini, fin);
    long long remontadasIzq = dyc(dorsales, aux, ini, medio);
    long long remontadasDer = dyc(dorsales, aux, medio + 1, fin);
    return remontadasIzq + remontadasDer + mergear(dorsales, aux, ini, medio, fin);
}

int main() {
    int n;
    cin >> n;
    int* dorsales = new int[n];
    int* aux = new int[n];
    for (int i = 0; i < n; i++) cin >> dorsales[i];

    cout << dyc(dorsales, aux, 0, n - 1) << endl;

    delete[] dorsales;
    delete[] aux;
    return 0;
}