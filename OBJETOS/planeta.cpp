#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// ------------------ Constantes globales ------------------
const double GM = 1.0;

// ---------------------- Clase Cuerpo ----------------------
class Cuerpo {
private:
    double x, y, Vx, Vy, Fx, Fy, m, R;
public:
    void Inicie(double x0, double y0, double Vx0, double Vy0, double m0, double R0);
    void CalculeFuerza(void);
    void Muevase(double dt);
    double Getx(void) const { return x; };
    double Gety(void) const { return y; };
};

void Cuerpo::Inicie(double x0, double y0, double Vx0, double Vy0, double m0, double R0) {
    x = x0;   y = y0;
    Vx = Vx0; Vy = Vy0;
    m = m0;   R = R0;
}

void Cuerpo::CalculeFuerza(void) {
    double r2 = x * x + y * y;
    double r3 = pow(r2, 1.5);
    double aux = GM * m / r3;
    Fx = -aux * x;
    Fy = -aux * y;
}

void Cuerpo::Muevase(double dt) {
    x += Vx * dt;
    y += Vy * dt;
    Vx += Fx / m * dt;
    Vy += Fy / m * dt;
}

// ------------------ Prototipos ------------------
void solicitarDatos(double &x0, double &y0, double &Vx0, double &m0, double &R0);
void saveOrbita();

// ------------------ Función principal ------------------
int main() {
    saveOrbita();
    return 0;
}

// ---------- Guardar datos de la órbita -----------------
void saveOrbita() {
    Cuerpo planeta;
    double t, dt = 0.01, tmax;
    double x0, y0, Vx0, Vy0, m0, R0;

    // Pedir datos (sin Vy0)
    solicitarDatos(x0, y0, Vx0, m0, R0);

    // Cálculo automático de Vy0
    double r = sqrt(x0 * x0 + y0 * y0);
    Vy0 = 0.5*sqrt(GM / r);
    cout << "💡 Velocidad tangencial automática: Vy0 = sqrt(GM/r) = " << Vy0 << " m/s\n";

    // Cálculo del período orbital
    double omega = sqrt(GM / (r * r * r));
    double T = 2 * M_PI / omega;
    cout << "📏 Período orbital T ≈ " << T << " s\n";
    cout << "⏳ Se recomienda usar tmax ≈ " << T << " s para una vuelta completa.\n";

    // Tiempo total de simulación
    cout << "Ingrese el tiempo máximo tmax (s): "; cin >> tmax;

    // Guardar en archivo
    ofstream file("trayectoria.dat");
    file << fixed << setprecision(5);
    file << setw(10) << "t(s)"
         << setw(15) << "x(m)"
         << setw(15) << "y(m)" << endl;

    planeta.Inicie(x0, y0, Vx0, Vy0, m0, R0);

    for (t = 0; t < tmax; t += dt) {
        file << setw(10) << t
             << setw(15) << planeta.Getx()
             << setw(15) << planeta.Gety() << endl;
        planeta.CalculeFuerza();
        planeta.Muevase(dt);
    }

    file.close();
    cout << "✅ Datos guardados en 'trayectoria.dat'\n";
}

// ---------- Solicitar datos al usuario -------------------
void solicitarDatos(double &x0, double &y0, double &Vx0, double &m0, double &R0) {
    cout << "\n📌 Sugerencia para órbita circular:\n";
    cout << "  - x0 = 10, y0 = 0\n";
    cout << "  - Vx0 = 0 → se calculará Vy0 automáticamente\n";
    cout << "  - m0 = 1, R0 = 0.5\n\n";

    cout << "Ingrese la posición inicial x0 (m): "; cin >> x0;
    cout << "Ingrese la posición inicial y0 (m): "; cin >> y0;
    cout << "Ingrese la velocidad inicial Vx0 (m/s): "; cin >> Vx0;
    cout << "Ingrese la masa m (kg): "; cin >> m0;
    cout << "Ingrese el radio R (m): "; cin >> R0;
}

 