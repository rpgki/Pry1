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

/*Prueba 3*/

#include <iostream>
#include <memory>
#include <iostream>
using namespace std;

#include "Grafo.h"
#include "Simulador.h"
#include "Visualizador.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Grafo grf(20, 0.5);
    Simulador sml(grf);
    Visualizador vsl(grf,sml);
  
    return 0;
}

