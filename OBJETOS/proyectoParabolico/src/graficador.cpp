#include "../include/graficador.h"
#include <algorithm>
#include <cstdlib>

void graficarDatos() {
    std::string opcion;
    std::cout << "\n¿Con qué desea visualizar la gráfica? [gnuplot/python]: ";
    std::cin.ignore();
    std::getline(std::cin, opcion);

    opcion.erase(std::remove_if(opcion.begin(), opcion.end(), ::isspace), opcion.end());
    std::transform(opcion.begin(), opcion.end(), opcion.begin(), ::tolower);

    if (opcion == "gnuplot") {
        system("gnuplot -persist scripts/plot_parabolico.gp");
    } else if (opcion == "python") {
        system("python3 scripts/plot_parabolico.py");
    } else {
        std::cout << "❌ Opción no reconocida. Escriba 'gnuplot' o 'python'.\n";
    }
}
