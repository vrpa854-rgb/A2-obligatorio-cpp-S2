#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>
#include "tads/ListImp.cpp"
#include <sstream>

using namespace std;

int main()
{
    int n;
    ListImp<int> monedas;
    ListImp<string> pinturas;
    cin >> n;
    cin.ignore();
    cout << " "<< endl;
    for (int i = 0; i < n; i++)
    {
        string linea;
        getline(cin, linea);
        stringstream ss(linea);
        string comando;
        ss >> comando;
        if (comando == "ALTA")
        {
            ss >> comando;
            if (comando == "M")
            {
                int valor;
                ss >> valor;
                if (monedas.isEmpty() || valor > monedas.get(monedas.getSize() - 1)) {
                    monedas.insert(valor);
                } else {
                    int index = 0;
                    while (index < monedas.getSize() && monedas.get(index) < valor) {
                        index++;
                    }
                    if (monedas.get(index) != valor) {
                        monedas.insertAt(index, valor);
                    }
                }
            }
            else if (comando == "P")
            {
                string nombre;
                ss >> nombre;
                for (auto &c : nombre) c = tolower(c);
                if (pinturas.isEmpty() || nombre > pinturas.get(pinturas.getSize() - 1)) {
                    pinturas.insert(nombre);
                } else {
                    int index = 0;
                    while (index < pinturas.getSize() && pinturas.get(index) < nombre) {
                        index++;
                    }
                    if (pinturas.get(index) != nombre) {
                        pinturas.insertAt(index, nombre);
                    }
                }
            }
        }
        else if (comando == "BUSCAR")
        {
            ss >> comando;
            if (comando == "M")
            {
                int valor;
                ss >> valor;
                bool existe = false;
                for (int idx = 0; idx < monedas.getSize(); idx++)
                {
                    if (monedas.get(idx) == valor)
                    {
                        existe = true;
                        break;
                    }
                }
                cout << (existe ? "si" : "no") << endl;
            }
            else if (comando == "P")
            {
                string nombre;
                ss >> nombre;
                for (auto &c : nombre) c = tolower(c);
                bool existe = false;
                for (int idx = 0; idx < pinturas.getSize(); idx++)
                {
                    if (pinturas.get(idx) == nombre)
                    {
                        existe = true;
                        break;
                    }
                }
                cout << (existe ? "si" : "no") << endl;
            }
        }
        else if (comando == "RANGO")
        {
            ss >> comando;
            if (comando == "M")
            {
                int min, max;
                ss >> min >> max;
                for (int idx = 0; idx < monedas.getSize(); idx++)
                {
                    int moneda = monedas.get(idx);
                    if (moneda >= min && moneda <= max)
                    {
                        cout << moneda << endl;
                    }
                }
            }
            else if (comando == "P")
            {
                string min, max;
                ss >> min >> max;
                for (int idx = 0; idx < pinturas.getSize(); idx++)
                {
                    string pintura = pinturas.get(idx);
                    if (pintura >= min && pintura <= max)
                    {
                        cout << pintura << endl;
                    }
                }
            }
        }
    }
}