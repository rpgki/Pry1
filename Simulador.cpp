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
 
Simulador::Simulador(Grafo& g):grafoAct(g) {
}
 
Simulador::~Simulador() {   
}
 
void Simulador::simular() {
    Grafo grafoAnt(grafoAct); //Se crea una instancia de tipo grafo que crea una copia, la cual servira como base para los estados en el tiempo t.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Se planta la semilla.
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> prb(0.0, 1.0); //Se crea el dado.
    int* arrTemp; //Se crea un puntero al vector de adyacentes para cada vertice
    for (int i = 0; i < grafoAnt.obtTotVrt(); i++) { //Se recorre el arreglo de vertices
        arrTemp = grafoAnt.obtAdy(i); //Se guarda el vector de adyacentes.
        grafoAct.actCntChqVrs(i); //Se actualiza el contador de chequeo de virus
        //Si el vertice es susceptible, entonces se evalua cada uno de sus adyacentes.
        //Si alguno infectado se genera un numero aleatorio para evaluar la probabilidad de infeccion.
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
        } else { //Si el vertice no es susceptible, y esta infectado se evalua la probabilidad de recuperarse.
            if (grafoAnt.obtEst(i) == Grafo::I && grafoAnt.obtCntChqVrs(i)== 0) {
                double prbAlt = prb(generator);
                if(prbAlt <= rec){
                    prbAlt = prb(generator);
                    if(prbAlt <= resis){ //Si el vertice infectado se recupera, entonces se evalua la probabilidad de que se vuelva resistente al virus.
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
 
//Este metodo es solo para correr las pruebas. Ver simular().
void Simulador::simularPba() {
    Grafo grafoAnt(grafoAct);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> prb(0.0, 1.0);
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
    grafoAct.infectar(tam); //Se infecta el grafo actual
    prbInf = vsc;
    maxFrqChqVrs = mvcf;
    rec = rc;
    resis = grc;
    grafoAct.azarizarTmpChqVrs(maxFrqChqVrs); //Se inicializa el temporizador.
}
 
void Simulador::iniciarSimPba(double vsc, int mvcf, double rc, double grc) {
    prbInf = vsc;
    maxFrqChqVrs = mvcf;
    rec = rc;
    resis = grc;
    grafoAct.azarizarTmpChqVrs(maxFrqChqVrs); //Se inicializa el temporizador.
}