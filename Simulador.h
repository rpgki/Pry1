/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulador.h
 * Author: Carlos
 *
 * Created on 6 de septiembre de 2016, 11:08 PM
 */

#ifndef SIMULADOR_H
#define	SIMULADOR_H

#include <memory>
using namespace std;

#include "Grafo.h"

class Simulador {
    // Representa el proceso de simulación de la infección en la red de computadoras.
    
public:
    
    // EFE: Construye un simulador que transformará al grafo g.
    Simulador(Grafo& g);

    // Destruye a *this retornando toda la memoria asignada dinámicamente.
    ~Simulador();
    
    // REQ: el grafo asociado (el pasado al constructor) esté bien construido.
    // MOD: el grafo asociado.
    //      Aplica la siguiente regla de cambio de estado para los vértices:
    //      1. un vértice sólo puede ser infectado por alguno de sus vecinos infectados
    //         con probabilidad vsc.
    //      2. sólo un vértice infectado cuyo temporizador de chequeo de virus está en cero
    //         puede recuperarse con probabilidad rc.
    //      3. sólo un vértice recuperado puede ganar resistencia con probabilidad grc.
    //      4. Sólo las transformaciones #2 y #3 pueden ser simultáneas.
    void simular();
    
    // REQ: el grafo asociado (el pasado al constructor) esté bien construido.
    // MOD: el grafo asociado.
    // EFE: aplica al grafo asociado cntItr transformaciones con base en los 
    //      siguientes parámetros:
    //      cItr > 1000: cantidad de iteraciones.
    //      ios o initial-outbreak-size [1..N], N cantidad de vértices: cantidad
    //           de vértices infectados al comienzo de la simulación.
    //      vsc o virus-spread-chance [0..0.1]: probabilidad de infección.
    //      mvcf o virus-check-frecuency [1..20]: máxima frecuencia de chequeo antivirus.
    //      rc o recovery-chance [0..0.1]: probabilidad de recuperación de infección.
    //      grc o gain-resistance-chance [0..1]: probabilidad de lograr resistencia.
    void iniciarSim(int ios, double vsc, int mvcf, double rc, double grc);
    
private:
    Grafo& grafo;
};

#endif	/* SIMULADOR_H */