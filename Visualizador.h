/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visualizador.h
 * Author: Carlos
 *
 * Created on 6 de septiembre de 2016, 11:09 PM
 */

#ifndef VISUALIZADOR_H
#define	VISUALIZADOR_H

#include "Simulador.h"
#include "Grafo.h"

class Visualizador {
    // Permite la visualización gráfica de una instancia de Grafo.
    
public:
    // EFE: construye un visualizador para g.
    Visualizador(Grafo& g, Simulador& s);
       
    ~Visualizador();
    
    // REQ: *this haya sido construido con un grafo y un simulador asociado.
    // MOD: el grafo asociado por medio del simulador miembro.
    // EFE: muestra gráficamente al grafo asociado diferenciando con distintos
    //      colores los estados de los vértices.
    void visualizar() const;

    // REQ: *this haya sido construido con un grafo y un simulador asociado.
    // MOD: el grafo asociado por medio del simulador miembro.
    // EFE: aplica al grafo asociado cntItr transformaciones con base en los 
    //      siguientes parámetros (por medio del simulador asociado):
    //      cItr > 1000: cantidad de iteraciones.
    //      ios o initial-outbreak-size [1..N], N cantidad de vértices: cantidad
    //           de vértices infectados al comienzo de la simulación.
    //      vsc o virus-spread-chance [0..0.1]: probabilidad de infección.
    //      mvcf o virus-check-frecuency [1..20]: frecuencia máxima de chequeo antivirus.
    //      rc o recovery-chance [0..0.1]: probabilidad de recuperación de infección.
    //      grc o gain-resistance-chance [0..1]: probabilidad de lograr resistencia.
    //      Aplica la siguiente regla de cambio de estado para los vértices:
    //      1. un vértice sólo puede ser infectado por alguno de sus vecinos infectados
    //         con probabilidad vsc.
    //      2. sólo un vértice infectado cuyo temporizador de chequeo de virus está en cero
    //         puede recuperarse con probabilidad rc.
    //      3. sólo un vértice recuperado puede ganar resistencia con probabilidad grc.
    //      4. Sólo las transformaciones #2 y #3 pueden ser simultáneas.
    // EFE: muestra gráficamente al grafo asociado diferenciando con distintos
    //      colores los estados de los vértices.
    void visualizar(int cItr, int ios, double vsc, int mvcf, double rc, double grc);
    
private:
    Grafo& grafo;
    Simulador& simulador;
    int cntItr; //Cantidad de interaciones.
    int vrtInf; // Cantidad de vertices infectados.
    double probInf; //Probabilidad de infeccion.
    int frecMax; //Frecuencia maxima de chequeo de virus. 
    double probRec; //Probabilidad de recuperacion de infeccion.
    double probRes; //Probabilidad de lograr resistencia.
};

#endif	/* VISUALIZADOR_H */