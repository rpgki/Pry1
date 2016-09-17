/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/* 
 * File:   main.cpp
 * Author: Carlos
 *
 * Created on 6 de septiembre de 2016, 11:02 PM
 */
 
/*Prueba 365
 65465464+otra prueba*/
 
#include <iostream>
#include <memory>
#include <iostream>
using namespace std;
 
#include "Grafo.h"
#include "Simulador.h"
#include "Visualizador.h"
#include "LstAdy.h"
 
/*
 * 
 */
int main(int argc, char** argv) {
    /*Grafo grf(20, 0.5);
    Simulador sml(grf);
    Visualizador vsl(grf,sml);*/
 
    LstAdy lista;
     
    lista.agr(4);
    lista.agr(2);
    lista.agr(7);
    lista.agr(5);
     
    int* b = lista.obtAdy();
    int a = lista.totAdy();
    /*for(int* i = lista.obtAdy(); i < b[3]; i++){
        //b += i;
        cout << "Prueba arreglo: " << *i << endl;
    }*/
     
    cout << "Prueba arreglo: " << b[0] << endl;
    //cout << "Prueba arreglo: " << b[1] << endl;
    //cout << "Prueba arreglo: " << b[2] << endl;
    //cout << "Prueba arreglo: " << b[3] << endl;
     
    lista.elm(2);
    lista.elm(7);
    lista.elm(4);
    lista.elm(5);
     
    string h = lista.aHil();
     
    cout << "Cantidad de adyacencias: " << a << endl;
    cout << "Adyacencias: " << h << endl;
    
    int pba[4] = {0};
    pba[0] = 1;
    pba[1] = 2;
    pba[2] = 3;
    pba[3] = 4;
         
    return 0;
}