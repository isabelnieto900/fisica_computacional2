#include "../include/funciones.h"
using namespace std; 
void sumarVectores() {
    cout << "-- SUMAR VECTORES 3D --" << endl;
    // Solicitar dos vectores 3D al usuario y mostrar su suma
    Eigen::Vector3d v1, v2, suma;
    cout << "Ingrese el primer vector 3D (x y z): ";
    cin >> v1[0] >> v1[1] >> v1[2];
    cout << "Ingrese el segundo vector 3D (x y z): ";
    cin >> v2[0] >> v2[1] >> v2[2];

    for (int i = 0; i < 3; ++i) {
        suma[i] = v1[i] + v2[i];
    }

    cout << "La suma de los vectores es: ("
         << suma[0] << ", "
         << suma[1] << ", "
         << suma[2] << ")\n";
}
 
void productoPunto() {
    cout << "-- PRODUCTO PUNTO DE VECTORES 3D --" << endl;
    Eigen::Vector3d v1, v2;
    std::cout << "Ingrese el primer vector 3D (x y z): ";
    std::cin >> v1[0] >> v1[1] >> v1[2];
    std::cout << "Ingrese el segundo vector 3D (x y z): ";
    std::cin >> v2[0] >> v2[1] >> v2[2];

    double dot = v1.dot(v2);
    std::cout << "El producto punto es: " << dot << std::endl;
}
 
void productoCruz() {
    cout << "-- PRODUCTO CRUZ DE VECTORES 3D --" << endl;
    Eigen::Vector3d v1, v2;
    std::cout << "Ingrese el primer vector 3D (x y z): ";
    std::cin >> v1[0] >> v1[1] >> v1[2];
    std::cout << "Ingrese el segundo vector 3D (x y z): ";
    std::cin >> v2[0] >> v2[1] >> v2[2];
    Eigen::Vector3d cross = v1.cross(v2);
    std::cout << "El producto cruz es: ("
              << cross[0] << ", "
              << cross[1] << ", "
              << cross[2] << ")\n";
}
 
void sumarMatrices() {
    cout << "-- SUMAR MATRICES 2x2 --" << endl;
    Eigen::Matrix2d m1, m2;
    std::cout << "Ingrese los elementos de la primera matriz 2x2 (fila por fila):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            std::cin >> m1(i, j);

    std::cout << "Ingrese los elementos de la segunda matriz 2x2 (fila por fila):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            std::cin >> m2(i, j);

    Eigen::Matrix2d suma = m1 * m2;

    std::cout << "La suma de las matrices es:\n" << suma << std::endl;
}
 
void multiplicarMatrices() {
    cout << "-- MULTIPLICAR MATRICES 2x2 --" << endl;
    Eigen::Matrix2d m1, m2;
    std::cout << "Ingrese los elementos de la primera matriz 2x2 (fila por fila):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            std::cin >> m1(i, j);

    std::cout << "Ingrese los elementos de la segunda matriz 2x2 (fila por fila):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            std::cin >> m2(i, j);

    Eigen::Matrix2d multiplicación = m1 * m2;

    std::cout << "La multiplicación de las matrices es:\n" << multiplicación << std::endl;

}
 
void verificarSimetria() {
    cout << "-- VERIFICAR SIMETRÍA DE MATRIZ 2x2 --" << endl;
    Eigen::Matrix2d m;
    std::cout << "Ingrese los elementos de la matriz 2x2 (fila por fila):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            std::cin >> m(i, j);

    if (m.isApprox(m.transpose())) {
        std::cout << "La matriz es simétrica.\n";
    } else {
        std::cout << "La matriz NO es simétrica.\n";
    }
}
 
void diagonalizarMatriz() {
    cout << "-- DIAGONALIZAR MATRIZ 3x3 SIMÉTRICA --" << endl;
    Eigen::Matrix3d m;
    std::cout << "Ingrese los elementos de la matriz 3x3 simétrica (fila por fila):\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            std::cin >> m(i, j);

    // Verifica simetría
    if (!m.isApprox(m.transpose())) {
        std::cout << "La matriz no es simétrica. No se puede diagonalizar con este método.\n";
        return;
    }

    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> solver(m);
    if (solver.info() != Eigen::Success) {
        std::cout << "No se pudo diagonalizar la matriz.\n";
        return;
    }
    Eigen::Matrix3d D = solver.eigenvectors().transpose() * m * solver.eigenvectors();
    double epsilon = 1e-10;
    D = D.unaryExpr([epsilon](double x) { return std::abs(x) < epsilon ? 0.0 : x; });
    std::cout << "Calculando eigenvalores y autovectores...\n";
    std::cout << "Matriz diagonal (D):\n" << D << std::endl;
}


 
void calcularAutovalores() {
    cout << "-- CALCULAR AUTOVALORES DE MATRIZ 2x2 --" << endl;
    Eigen::Matrix2d m;
    std::cout << "Ingrese los elementos de la matriz 2x2 (fila por fila):\n";
    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
        std::cin >> m(i, j);
    Eigen::EigenSolver<Eigen::Matrix2d> solver(m);
    if (solver.info() != Eigen::Success) {
        std::cout << "No se pudo calcular los autovalores.\n";
        return;
    }
    std::cout << "Autovalores:\n" << solver.eigenvalues() << std::endl;

}
 
void mostrarMenu() {
    cout << "\n--- MENÚ DE OPERACIONES ---\n";
    cout << "1. Sumar vectores 3D\n";
    cout << "2. Producto punto de vectores 3D\n";
    cout << "3. Producto cruz de vectores 3D\n";
    cout << "4. Sumar matrices 2x2\n";
    cout << "5. Multiplicar matrices 2x2\n";
    cout << "6. Verificar si una matriz 2x2 es simétrica\n";
    cout << "7. Diagonalizar matriz 3x3 simétrica\n";
    cout << "8. Calcular autovalores de una matriz 2x2\n";
    cout << "0. Salir\n";
}
 
int leerOpcion() {
    int op;
    cout << "Seleccione una opción: ";
    cin >> op;
    return op;
}

int mostrarSubmenu() {
    int op;
    std::cout << "\n--- ¿Qué desea hacer ahora? ---\n";
    std::cout << "1. Repetir esta opción\n";
    std::cout << "2. Elegir otra opción\n";
    std::cout << "3. Salir del programa\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> op;
    return op;
}
