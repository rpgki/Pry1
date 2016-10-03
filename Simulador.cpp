/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulador.cpp
 * Author: Carlos
 * 
 * Created on 6 de septiembre de 2016, 11:08 PM
 */

#include "Simulador.h"

Simulador::Simulador(Grafo& g):grafo(g) {
}

Simulador::~Simulador() {   
}

void Simulador::simular() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> prb(0.0, 1.0);
    double prbAlt = prb(generator);
    grafo.infectar(tam); // se infectaron
    int* arrTemp;
    for (int i = 0; i < grafo.obtTotVrt(); i++) {
        arrTemp = grafo.obtAdy(i);
        if (grafo.obtEst(i) == Grafo::S) {
            for (int j = 0; j < grafo.obtTotAdy(i); j++) {
                if (grafo.obtEst(arrTemp[j]) == Grafo::I) {
                    double prbAlt = prb(generator);
                    if (prbAlt <= prbInf) {
                        grafo.modEst(i, Grafo::I);
                    }
                }
            }
        } else {
            if (grafo.obtEst(i) == Grafo::I && grafo.obtTmpChqVrs(i)== 0) {
                double prbAlt = prb(generator);
                if(prbAlt <= rec){
                    grafo.modEst(i, Grafo::S);
                }
            }
            if (grafo.obtEst(i) == Grafo::S && grafo.obtTmpChqVrs(i)!= 0) {
                double prbAlt = prb(generator);
                if(prbAlt <= resis){
                    grafo.modEst(i, Grafo::R);
                }
            }
        }
    }
}

void Simulador::iniciarSim(int ios, double vsc, int mvcf, double rc, double grc){
    tam = ios;
    prbInf = vsc;
    maxFrqChqVrs = mvcf;
    rec = rc;
    resis = grc;
}