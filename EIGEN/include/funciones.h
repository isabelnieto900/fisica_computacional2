#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <Eigen/Dense>
#include <iostream>
#include <cstdlib> // Para system()
using namespace Eigen;

 // Vectores
void sumarVectores();
void productoPunto();
void productoCruz();
 // Matrices
void sumarMatrices();
void multiplicarMatrices();
void verificarSimetria();
void diagonalizarMatriz();
void calcularAutovalores();
 // Utilidades
void mostrarMenu();
int leerOpcion();
int mostrarSubmenu();
 #endif
