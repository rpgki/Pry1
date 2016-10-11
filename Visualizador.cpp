/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visualizador.cpp
 * Author: Carlos
 * 
 * Created on 6 de septiembre de 2016, 11:09 PM
 */

#include "Visualizador.h"

Visualizador::Visualizador(Grafo& g, Simulador& s): grafo(g), simulador(s) {
}

Visualizador::~Visualizador() {
}

void Visualizador::visualizar() const {
    //Se inicializan los parametros para la simulacion con los parametros recibidos en visualizar.
    simulador.iniciarSim(vrtInf, probInf, frecMax, probRec, probRes);
    
    //Se crea un ciclo cntItr cantidad de veces para llamar esa misma cantidad de veces el metodo simular().
    for(int i = 1; i <= cntItr; i++){
        simulador.simular();
        for(int j = 0; j < grafo.obtTotVrt(); j++){
            grafo.actCntChqVrs(j); //Se actualiza el contador de chequeo de virus
        }
    }
}

void Visualizador::visualizar(int cItr, int ios, double vsc, int mvcf, double rc, double grc) {
    cntItr = cItr; //Se guarda la cantidad de iteraciones.
    vrtInf = ios; //Se guarda la cantidad de vertices infectados.
    probInf = vsc; //Se guarda la probabilidad de infeccion.
    frecMax = mvcf; //Se guarda la frecuencia maxima de chequeo de virus.
    probRec = rc; //Se guarda la probabilidad de recuperacion.
    probRes = grc; //Se guarda la probabilidad de ganar resistencia.
}