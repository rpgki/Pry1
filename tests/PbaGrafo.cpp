/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: JustinRC
 *
 * Created on 19 de septiembre de 2016, 03:59 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Grafo.h"

/*
 * Simple C++ Test Suite
 */

void testGrafo() {
    int N = 100;
    int K = 44;
    double beta = 0.2;
    Grafo grafo(N, K, beta);
    double coefGnr = grafo.coeficienteAgrupamiento();
    if (coefGnr < 0.5) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo (newsimpletest) message=error message sample" << std::endl;
    }
}

//void testGrafo2() {
//    Grafo orig;
//    Grafo grafo(orig);
//    if (true /*check result*/) {
//        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (newsimpletest) message=error message sample" << std::endl;
//    }
//}

void testGrafo3() {
    string nArch;
    nArch = "redPeq.txt";
    Grafo grafo(nArch);
    int* arrGrafo;
    bool result = false;
    if (100 == grafo.obtTotVrt()) {
        for (int i = 0; i < grafo.obtTotVrt(); i++) {
            arrGrafo = grafo.obtAdy(i);
            for (int j = 0; j < grafo.obtTotAdy(i); j++) {
                result = grafo.xstAdy(i, arrGrafo[j]);
                if (!result) {
                    std::cout << "%TEST_FAILED% time=0 testname=testGrafo3 (newsimpletest) message=fallo el constructor de grafo mediante un archivo de texto" << std::endl;
                }
            }
        }
    }else{
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo3 (newsimpletest) message=fallo el constructor de grafo mediante un archivo de texto" << std::endl;
    }
}
//
//void testCoeficienteAgrupamiento() {
//    int vrt;
//    Grafo grafo;
//    double result = grafo.coeficienteAgrupamiento(vrt);
//    if (true /*check result*/) {
//        std::cout << "%TEST_FAILED% time=0 testname=testCoeficienteAgrupamiento (newsimpletest) message=error message sample" << std::endl;
//    }
//}
//
//void testCoeficienteAgrupamiento2() {
//    Grafo grafo;
//    double result = grafo.coeficienteAgrupamiento();
//    if (true /*check result*/) {
//        std::cout << "%TEST_FAILED% time=0 testname=testCoeficienteAgrupamiento2 (newsimpletest) message=error message sample" << std::endl;
//    }
//}




void testActCntChqVrs() {
    Grafo grafo("redMuyPeq.txt");
    grafo.modTmpChqVrs(1,5);
    grafo.actCntChqVrs(1);
    int temp = grafo.obtCntChqVrs(1);
    if (temp != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testActCntChqVrs (newsimpletest) message=fallo el ActCntChqVrs con el vrt 1 valor 5" << std::endl;
    }
}


void testInfectar() {
    Grafo grafo("redMuyPeq.txt");
    grafo.infectar(3);
    int cont = 0;
    int infectado = 0;
    while (cont < grafo.obtTotVrt()) {
        if (grafo.obtEst(cont) == Grafo::I) {
            infectado++;
        }
        cont++;
    }
    if (infectado != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testInfectar (newsimpletest) message=fallo el metodo infectar con 3 nodos infectados" << std::endl;
    }
}

void testAzarizarTmpChqVrs() {
    Grafo grafo("redMuyPeq.txt");
    grafo.azarizarTmpChqVrs(5);
    int cont = 0;
    while (cont < grafo.obtTotVrt()) {
        if (grafo.obtTmpChqVrs(cont) > 5 || grafo.obtTmpChqVrs(cont) < 1) {
            std::cout << "%TEST_FAILED% time=0 testname=testAzarizarTmpChqVrs (newsimpletest) message=fallo el azarizar con 5" << std::endl;
        }
        cont++;
    }
}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo (newsimpletest)" << std::endl;
    testGrafo();
    std::cout << "%TEST_FINISHED% time=0 testGrafo (newsimpletest)" << std::endl;

   // std::cout << "%TEST_STARTED% testGrafo2 (newsimpletest)" << std::endl;
   // testGrafo2();
   // std::cout << "%TEST_FINISHED% time=0 testGrafo2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo3 (newsimpletest)" << std::endl;
    testGrafo3();
    std::cout << "%TEST_FINISHED% time=0 testGrafo3 (newsimpletest)" << std::endl;

   // std::cout << "%TEST_STARTED% testCoeficienteAgrupamiento (newsimpletest)" << std::endl;
   // testCoeficienteAgrupamiento();
   // std::cout << "%TEST_FINISHED% time=0 testCoeficienteAgrupamiento (newsimpletest)" << std::endl;

   // std::cout << "%TEST_STARTED% testCoeficienteAgrupamiento2 (newsimpletest)" << std::endl;
   // testCoeficienteAgrupamiento2();
   // std::cout << "%TEST_FINISHED% time=0 testCoeficienteAgrupamiento2 (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testActCntChqVrt (newsimpletest)" << std::endl;
    testActCntChqVrs();
    std::cout << "%TEST_FINISHED% time=0 testActCntChqVrt (newsimpletest)" << std::endl;
            
    std::cout << "%TEST_STARTED% testInfectar (newsimpletest)" << std::endl;
    testInfectar();
    std::cout << "%TEST_FINISHED% time=0 testInfectar (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testAzarizarTmpChqVrs (newsimpletest)" << std::endl;
    testAzarizarTmpChqVrs();
    std::cout << "%TEST_FINISHED% time=0 testAzarizarTmpChqVrs (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}