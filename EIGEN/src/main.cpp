#include "../include/funciones.h"
using namespace std;
 
int main() {
    int opcion;
    do {
        system("clear"); 
        mostrarMenu();
        opcion = leerOpcion();
 
        if (opcion == 0) {
            cout << "Saliendo del programa...\n";
            break;
        }
 
        int subopcion;
        do {
            switch (opcion) {
                case 1: sumarVectores(); break;
                case 2: productoPunto(); break;
                case 3: productoCruz(); break;
                case 4: sumarMatrices(); break;
                case 5: multiplicarMatrices(); break;
                case 6: verificarSimetria(); break;
                case 7: diagonalizarMatriz(); break;
                case 8: calcularAutovalores(); break;
                default: cout << "Opción inválida\n"; break;
            }
            subopcion = mostrarSubmenu();
            if (subopcion == 2) break;      // Elegir otra opción
            if (subopcion == 3) return 0;   // Salir del programa
            if (subopcion == 1) system("clear"); // Limpia antes de repetir la opción
        } while (subopcion == 1);           // Repetir esta opción
 
    } while (opcion != 0);
 
    return 0;
}
