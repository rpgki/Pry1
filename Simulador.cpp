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

Simulador::Simulador(Grafo& g):grafoAnt(g), grafoAct(g) {
}

Simulador::~Simulador() {   
}

void Simulador::simular() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> prb(0.0, 1.0);
    //grafoAnt.infectar(tam); // se infectaron
    grafoAct.azarizarTmpChqVrs(maxFrqChqVrs);
    int* arrTemp;
    for (int i = 0; i < grafoAnt.obtTotVrt(); i++) {
        arrTemp = grafoAnt.obtAdy(i);
        if (grafoAnt.obtEst(i) == Grafo::S) {
            for (int j = 0; j < grafoAnt.obtTotAdy(i); j++) {
                if (grafoAnt.obtEst(arrTemp[j]) == Grafo::I) {
                    double prbAlt = prb(generator);
                    if (prbAlt <= prbInf) {
                        grafoAct.modEst(i, Grafo::I);
                        j = grafoAnt.obtTotAdy(i);
                    }
                }
            }
        } else {
            if (grafoAnt.obtEst(i) == Grafo::I && grafoAnt.obtCntChqVrs(i)== 0) {
                double prbAlt = prb(generator);
                if(prbAlt <= rec){
                    prbAlt = prb(generator);
                    if(prbAlt <= resis){
                        grafoAct.modEst(i, Grafo::R);
                    }
                    else{
                        grafoAct.modEst(i, Grafo::S);
                    }
                }
            }
        }
    }
}

void Simulador::simularPba() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> prb(0.0, 1.0);
    grafoAct.azarizarTmpChqVrs(maxFrqChqVrs);
    int* arrTemp;
    for (int i = 0; i < grafoAnt.obtTotVrt(); i++) {
        arrTemp = grafoAnt.obtAdy(i);
        if (grafoAnt.obtEst(i) == Grafo::S) {
            for (int j = 0; j < grafoAnt.obtTotAdy(i); j++) {
                if (grafoAnt.obtEst(arrTemp[j]) == Grafo::I) {
                    double prbAlt = prb(generator);
                    if (prbAlt <= prbInf) {
                        grafoAct.modEst(i, Grafo::I);
                        j = grafoAnt.obtTotAdy(i);
                    }
                }
            }
        } else {
            if (grafoAnt.obtEst(i) == Grafo::I && grafoAnt.obtCntChqVrs(i)== 0) {
                double prbAlt = prb(generator);
                if(prbAlt <= rec){
                    prbAlt = prb(generator);
                    if(prbAlt <= resis){
                        grafoAct.modEst(i, Grafo::R);
                    }
                    else{
                        grafoAct.modEst(i, Grafo::S);
                    }
                }
            }
        }
    }
}

void Simulador::iniciarSim(int ios, double vsc, int mvcf, double rc, double grc){
    tam = ios;
    grafoAnt.infectar(tam); grafoAct.infectar(tam);
    prbInf = vsc;
    maxFrqChqVrs = mvcf;
    rec = rc;
    resis = grc;
}

void Simulador::iniciarSimPba(double vsc, int mvcf, double rc, double grc) {
    prbInf = vsc;
    maxFrqChqVrs = mvcf;
    rec = rc;
    resis = grc;
}
