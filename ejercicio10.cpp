#include <iostream>
#include <string>
using namespace std;

void generarNuevoMapa(string* acertijo, int k, int* letrasDistintas, int* indiceLetra, bool* esInicial) {
    bool* letrasUsadas = new bool[26]();
    for (int j = 0; j < 11; j++) letrasDistintas[j] = -1;
    letrasDistintas[10] = 0;
    for (int j = 0; j < 26; j++) indiceLetra[j] = -1;
    for (int j = 0; j < 10; j++) esInicial[j] = false;

    int largoMaximo = 0;
    for (int i = 0; i <= k; i++)
        if ((int)acertijo[i].length() > largoMaximo) largoMaximo = acertijo[i].length();

    for (int c = 0; c < largoMaximo; c++) {
        for (int i = 0; i <= k; i++) {
            int largo = acertijo[i].length();
            if (c < largo) {
                int letra = acertijo[i][largo - 1 - c] - 'A';
                if (!letrasUsadas[letra]) {
                    letrasUsadas[letra] = true;
                    indiceLetra[letra] = letrasDistintas[10];
                    letrasDistintas[letrasDistintas[10]] = letra + 'A';
                    letrasDistintas[10]++;
                }
            }
        }
    }
    for (int i = 0; i <= k; i++)
        if (acertijo[i].length() > 1) esInicial[indiceLetra[acertijo[i][0] - 'A']] = true;

    delete[] letrasUsadas;
}

long long* generarIntento(string* acertijo, int* indiceLetra, int* numeroLetra, int k) {
    long long* nuevoIntento = new long long[k + 1]();
    for (int i = 0; i <= k; i++) {
        long long numeroPalabraActual = 0;
        for (int j = 0; j < (int)acertijo[i].length(); j++) {
            int numeroLetraActual = numeroLetra[indiceLetra[acertijo[i][j] - 'A']];
            numeroPalabraActual = numeroPalabraActual * 10 + numeroLetraActual;
        }
        nuevoIntento[i] = numeroPalabraActual;
    }
    return nuevoIntento;
}

bool esSolucion(string* acertijo, int* letrasDistintas, int* indiceLetra, int* numeroLetra, int indiceMapa, int k) {
    //Aún no se le asignó número a todas las letras
    if (indiceMapa < letrasDistintas[10]) return false;
    long long* intento = generarIntento(acertijo, indiceLetra, numeroLetra, k);
    long long suma = 0;
    for (int i = 0; i < k; i++) suma += intento[i];
    bool cierra = (suma == intento[k]);
    delete[] intento;
    return cierra;
}

bool esMejor(long long* intento, long long* mejorSolucion, int k) {
    if (intento[k] != mejorSolucion[k]) return intento[k] < mejorSolucion[k];
    for (int i = 0; i < k; i++)
        if (intento[i] != mejorSolucion[i]) return intento[i] < mejorSolucion[i];
    return false;
}

void procesarSolucion(string* acertijo, int* indiceLetra, int* numeroLetra, bool& haySolucion, long long* mejorSolucion, int k) {
    long long* intento = generarIntento(acertijo, indiceLetra, numeroLetra, k);
    if (!haySolucion || esMejor(intento, mejorSolucion, k)) {
        haySolucion = true;
        for (int i = 0; i < k + 1; i++) mejorSolucion[i] = intento[i];
    }
    delete[] intento;
}

bool columnasValidas(string* acertijo, int* indiceLetra, int* numeroLetra, int k) {
    int largoMaximo = 0;
    for (int i = 0; i <= k; i++)
        if ((int)acertijo[i].length() > largoMaximo) largoMaximo = acertijo[i].length();

    long long acarreo = 0;
    for (int c = 0; c < largoMaximo; c++) {
        long long suma = acarreo;
        for (int i = 0; i <= k; i++) {
            int largo = acertijo[i].length();
            if (c < largo && numeroLetra[indiceLetra[acertijo[i][largo - 1 - c] - 'A']] == -1)
                return true;
        }
        for (int i = 0; i < k; i++) {
            int largo = acertijo[i].length();
            if (c < largo) suma += numeroLetra[indiceLetra[acertijo[i][largo - 1 - c] - 'A']];
        }
        int largoResultado = acertijo[k].length();
        int cifraResultado = (c < largoResultado)
            ? numeroLetra[indiceLetra[acertijo[k][largoResultado - 1 - c] - 'A']] : 0;
        if (suma % 10 != cifraResultado) return false;
        acarreo = suma / 10;
    }
    return acarreo == 0;
}

long long cotaInferiorResultado(string* acertijo, int* indiceLetra, int* numeroLetra, int k) {
    long long cota = 0;
    int largo = acertijo[k].length();
    for (int j = 0; j < largo; j++) {
        int numero = numeroLetra[indiceLetra[acertijo[k][j] - 'A']];
        if (numero == -1) numero = (j == 0 && largo > 1) ? 1 : 0;
        cota = cota * 10 + numero;
    }
    return cota;
}

bool puedoPodar(string* acertijo, int* indiceLetra, int* numeroLetra, bool& haySolucion, long long* mejorSolucion, int k) {
    if (!columnasValidas(acertijo, indiceLetra, numeroLetra, k)) return true;
    if (haySolucion && cotaInferiorResultado(acertijo, indiceLetra, numeroLetra, k) > mejorSolucion[k]) return true;
    return false;
}

bool puedoRealizarIntento(int* letrasDistintas, bool* esInicial, int indiceMapa, bool* numerosUsados, int numeroActual) {
    //El indice se pasa de la cantidad de letras distintas
    if (indiceMapa >= letrasDistintas[10]) return false;
    //El número ya está usado
    if (numerosUsados[numeroActual]) return false;
    //Palabra de más de una letra empieza con 0? => no
    if (numeroActual == 0 && esInicial[indiceMapa]) return false;
    return true;
}

void hacerIntento(int* numeroLetra, int indiceMapa, bool* numerosUsados, int numeroActual) {
    numeroLetra[indiceMapa] = numeroActual;
    numerosUsados[numeroActual] = true;
}

void deshacerIntento(int* numeroLetra, int indiceMapa, bool* numerosUsados, int numeroActual) {
    numeroLetra[indiceMapa] = -1;
    numerosUsados[numeroActual] = false;
}

void backtracking(string* acertijo, int* letrasDistintas, int* indiceLetra, bool* esInicial, int* numeroLetra,
                  int indiceMapa, bool* numerosUsados, bool& haySolucion, long long* mejorSolucion, int k) {
    if (!puedoPodar(acertijo, indiceLetra, numeroLetra, haySolucion, mejorSolucion, k)) {
        if (esSolucion(acertijo, letrasDistintas, indiceLetra, numeroLetra, indiceMapa, k))
            procesarSolucion(acertijo, indiceLetra, numeroLetra, haySolucion, mejorSolucion, k);
        else {
            for (int i = 0; i < 10; i++) {
                if (puedoRealizarIntento(letrasDistintas, esInicial, indiceMapa, numerosUsados, i)) {
                    hacerIntento(numeroLetra, indiceMapa, numerosUsados, i);
                    backtracking(acertijo, letrasDistintas, indiceLetra, esInicial, numeroLetra,
                                 indiceMapa + 1, numerosUsados, haySolucion, mejorSolucion, k);
                    deshacerIntento(numeroLetra, indiceMapa, numerosUsados, i);
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        bool haySolucion = false;
        int k;
        cin >> k;
        string* acertijo = new string[k + 1];
        for (int j = 0; j < k + 1; j++) cin >> acertijo[j];

        int* letrasDistintas = new int[11];//Uso la última posición para saber la cantidad de letras
        int* indiceLetra = new int[26];
        bool* esInicial = new bool[10];
        generarNuevoMapa(acertijo, k, letrasDistintas, indiceLetra, esInicial);

        int* numeroLetra = new int[10];
        for (int j = 0; j < 10; j++) numeroLetra[j] = -1;
        bool* numerosUsados = new bool[10]();
        long long* solucion = new long long[k + 1]();

        backtracking(acertijo, letrasDistintas, indiceLetra, esInicial, numeroLetra, 0,
                     numerosUsados, haySolucion, solucion, k);

        if (haySolucion) {
            for (int j = 0; j < k; j++) {
                cout << solucion[j];
                if (j != k - 1) cout << " + ";
            }
            cout << " = " << solucion[k] << endl;
        } else {
            cout << "imposible" << endl;
        }

        delete[] acertijo; delete[] letrasDistintas; delete[] indiceLetra; delete[] esInicial;
        delete[] numeroLetra; delete[] numerosUsados; delete[] solucion;
    }
    return 0;
}