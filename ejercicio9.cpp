#include <iostream>
#include <cstring>
using namespace std;

int cantidadRondas;
int convierteA[1000]; 
int likes[1000];      
int memo[1001][1001][2]; 

int max(int x, int y) {
    return x > y ? x : y;
}

int calcLikes(int ronda, int ventaja, int baileAnterior) {
    if (ronda == cantidadRondas){
        return 0;
    }

    if (memo[ronda][ventaja][baileAnterior] != -1){
        return memo[ronda][ventaja][baileAnterior];
    }

    int ventajaA = ventaja + convierteA[ronda];

    int mejor = calcLikes(ronda + 1, ventajaA, 0);

    if (ventajaA >= 1) {
        int likesGanados;
        if (baileAnterior == 0) {
            likesGanados = likes[ronda];
        } else {
            likesGanados = likes[ronda] / 2;
        }
        mejor = max(mejor, likesGanados + calcLikes(ronda + 1, ventajaA - 1, 1));
    }

    memo[ronda][ventaja][baileAnterior] = mejor;
    return mejor;
}

int main() {
    cin >> cantidadRondas;
    for (int i = 0; i < cantidadRondas; i++){ 
        cin >> convierteA[i]; 
    }
    for (int i = 0; i < cantidadRondas; i++){ 
        cin >> likes[i]; 
    }

    memset(memo, -1, sizeof(memo));

    cout << calcLikes(0, 0, 0) << endl;
    return 0;
}