#include "../include/funciones.h"
#include "../include/Cuerpo.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
namespace fs = std::filesystem;

void solicitarDatos(double &x0, double &y0, double &Vx0, double &Vy0, double &m0, double &R0) {
    std::cout << "Ingrese la posición inicial x0 (m): "; std::cin >> x0;
    std::cout << "Ingrese la posición inicial y0 (m): "; std::cin >> y0;
    std::cout << "Ingrese la velocidad inicial Vx0 (m/s): "; std::cin >> Vx0;
    std::cout << "Ingrese la velocidad inicial Vy0 (m/s): "; std::cin >> Vy0;
    std::cout << "Ingrese la masa m (kg): "; std::cin >> m0;
    std::cout << "Ingrese el radio R (m): "; std::cin >> R0;
}

void saveParabolicoDato() {
    Cuerpo Balon;
    double t, dt = 0.1, tmax;
    double x0, y0, Vx0, Vy0, m0, R0;

    solicitarDatos(x0, y0, Vx0, Vy0, m0, R0);

        std::cout << "Ingrese el tiempo máximo tmax (s): "; std::cin >> tmax;

    // Crear carpeta 'results' si no existe
    if (!fs::exists("results")) {
        fs::create_directory("results");
    }

    std::ofstream file("results/datos.dat");
    file << std::fixed << std::setprecision(4);
    file << std::setw(10) << "t(s)"
         << std::setw(15) << "x(m)"
         << std::setw(15) << "y(m)" << std::endl;

    Balon.Inicie(x0, y0, Vx0, Vy0, m0, R0);

    for (t = 0; t < tmax; t += dt) {
        file << std::setw(10) << t
             << std::setw(15) << Balon.Getx()
             << std::setw(15) << Balon.Gety() << std::endl;
        Balon.CalculeFuerza();
        Balon.Muevase(dt);
    }

    file.close();
    std::cout << "✅ Datos guardados en 'results/datos.dat'\n";
}
