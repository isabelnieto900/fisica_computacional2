#ifndef CUERPO_H
#define CUERPO_H

class Cuerpo {
private:
    double x, y, Vx, Vy, Fx, Fy, m, R;
    static constexpr double g = 9.8;
public:
    void Inicie(double x0, double y0, double Vx0, double Vy0, double m0, double R0) {
        x = x0; y = y0; Vx = Vx0; Vy = Vy0; m = m0; R = R0;
    }
    void CalculeFuerza() {
        Fx = 0; Fy = -m * g;
    }
    void Muevase(double dt) {
        x += Vx * dt; y += Vy * dt;
        Vx += Fx / m * dt; Vy += Fy / m * dt;
    }
    double Getx() const { return x; }
    double Gety() const { return y; }
};

#endif
