#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_W = 1000;

int pesos[MAX_N + 1];
int satisfacciones[MAX_N + 1];
int categorias[MAX_N + 1];

int tab[MAX_N + 1][MAX_W + 1][4][4][4][4];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int cantidadObjetos, capacidadHeladera;
    cin >> cantidadObjetos >> capacidadHeladera;

    int limite[4];
    for (int c = 0; c < 4; c++) cin >> limite[c];

    for (int i = 1; i <= cantidadObjetos; i++) {
        cin >> pesos[i] >> satisfacciones[i] >> categorias[i];
    }

    for (int objetoActual = 1; objetoActual <= cantidadObjetos; objetoActual++) {
        int pesoObjetoActual = pesos[objetoActual];
        int valorObjetoActual = satisfacciones[objetoActual];
        int categoriaObjetoActual = categorias[objetoActual];

        for (int capacidadActual = 0; capacidadActual <= capacidadHeladera; capacidadActual++)
        for (int l0 = 0; l0 <= limite[0]; l0++)
        for (int l1 = 0; l1 <= limite[1]; l1++)
        for (int l2 = 0; l2 <= limite[2]; l2++)
        for (int l3 = 0; l3 <= limite[3]; l3++) {

            int mejor = tab[objetoActual - 1][capacidadActual][l0][l1][l2][l3];

            int lugares[4] = {l0, l1, l2, l3};
            bool entraEnPeso = pesoObjetoActual <= capacidadActual;
            bool quedaLugarEnCategoria = lugares[categoriaObjetoActual] >= 1;

            if (entraEnPeso && quedaLugarEnCategoria) {
                lugares[categoriaObjetoActual]--;
                int valorDeUsar = valorObjetoActual +
                    tab[objetoActual - 1][capacidadActual - pesoObjetoActual][lugares[0]][lugares[1]][lugares[2]][lugares[3]];
                mejor = max(mejor, valorDeUsar);
            }

            tab[objetoActual][capacidadActual][l0][l1][l2][l3] = mejor;
        }
    }

    cout << tab[cantidadObjetos][capacidadHeladera][limite[0]][limite[1]][limite[2]][limite[3]] << endl;
    return 0;
}