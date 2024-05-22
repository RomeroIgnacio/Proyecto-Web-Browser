#include <iostream>
#include <string>
#include <cstdlib>
#include "pila.h"

using namespace std;

void navegar(Pila<string>& history, Pila<string>& forward, string& current)
{
    if (!current.empty())
    {
        history.push(current);
    }

    cout << endl << "Ingrese la nueva dirección web: ";
    getline(cin, current);

    while (!forward.empty())
    {
        forward.pop();
    }
}

void atras(Pila<string>& history, Pila<string>& forward, string& current)
{
    if (!history.empty())
    {
        forward.push(current);
        current = history.top();
        history.pop();
    }
    else
    {
        cout << endl << "No hay páginas anteriores.";
    }
}

void adelante(Pila<string>& history, Pila<string>& forward, string& current)
{
    if (!forward.empty())
    {
        history.push(current);
        current = forward.top();
        forward.pop();
    }
    else
    {
        cout << endl << "No hay páginas adelante.";
    }
}

void mostrarMenu()
{
    cout << "\nMenú de navegación:\n";
    cout << "1. Navegar\n";
    cout << "2. Atrás\n";
    cout << "3. Adelante\n";
    cout << "4. Salir\n";
    cout << "Ingrese una opción: ";
}

void mostrarDireccionActual(const string& current)
{
    cout << endl << "Dirección actual: " << current << endl;
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    Pila<string> history;
    Pila<string> forward;
    string current = "inicio";
    int opcion;

    do
    {
        mostrarDireccionActual(current);
        mostrarMenu();

        cin >> opcion;
        cin.ignore();
        clearScreen();

        switch (opcion)
        {
            case 1:
                navegar(history, forward, current);
                break;

            case 2:
                atras(history, forward, current);
                break;

            case 3:
                adelante(history, forward, current);
                break;

            case 4:
                cout << endl << "Saliendo del programa..." << endl;
                break;

            default:
                cout << endl << "Opción inválida. Intente nuevamente.";
                break;
        }
    } while (opcion != 4);

    return 0;
}
