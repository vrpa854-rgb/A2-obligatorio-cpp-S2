#include <string>
#include <iostream>
#include <limits>
#include "./tads/Hash.cpp"

using namespace std;

/* Restricciones
-Greedy
-O(N) temporal PC
-O(N) espacial PC
*/
int main() {
    int n;//OE(1)
    cin >> n;
    int* placas = new int[n+1](); // OE(N)
    int* res = new int[n+1](); // OE(N)
    int* cantidades = new int[1001](); //OE(1) //1000 porque los números van de 0 a 1000
    bool hayPares = false;
    for(int i=0; i<=1000; i++) {
        cantidades[i]=0;
    }
    for(int i=1; i<=n;i++) { //OT(N)
        int a;
        cin >> a;
        placas[i] = a;
        cantidades[a]++;
        
        if(!hayPares && cantidades[a] >= 2) hayPares = true;
    }

    int posRes = 0;
    if(hayPares) {
        for(int i=1; i<=n; i++) {//OT(N)
            int idxMaxPares = -1;
            for(int k=0; k<=1000; k++) { //OT(1)
                if(cantidades[k] >= 2 && k > idxMaxPares) {
                    idxMaxPares = k;
                }
            }
            if(idxMaxPares != -1) {
                cantidades[idxMaxPares] -=2; //Resto cantidades pares porque lo usaré dos veces
                res[posRes] = idxMaxPares;
                posRes++;
            }
        }
    }
    int placaCentro = -1;
    //Hay una placa centro?
    for(int k=0; k<=1000; k++) { //OT(1)
        if(cantidades[k] == 1 && k > placaCentro) {
            placaCentro = k;
        }
    }
    
    if(hayPares) {
        for(int i=0; i<posRes; i++) {
            cout << res[i] << " ";
        }
    }

    if(placaCentro != -1) {
        cout << placaCentro; 
        if(hayPares) cout << " ";
    }

    if(hayPares) {
        for(int i=posRes-1; i>=0; i--) {
            cout << res[i];
            if(i!=0) cout << " ";
        }
    }
    cout << endl;

    delete[] res;
    delete[] cantidades;
    delete[] placas;
}