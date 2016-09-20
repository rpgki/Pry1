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

//void testGrafo() {
//    int N;
//    int K;
//    double beta;
//    Grafo grafo(N, K, beta);
//    if (true /*check result*/) {
//        std::cout << "%TEST_FAILED% time=0 testname=testGrafo (newsimpletest) message=error message sample" << std::endl;
//    }
//}
//
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
    for(int i = 0; i < grafo.obtTotVrt(); i++){
        arrGrafo = grafo.obtAdy(i);
        for(int j = 0; j < grafo.obtTotAdy(i); j++){
	    result = grafo.xstAdy(i,arrGrafo[j]); 
	    if (!result) {
		  std::cout << "%TEST_FAILED% time=0 testname=testGrafo3 (newsimpletest) message=fallo el constructor de grafo mediante un archivo de texto" << std::endl;  
	    }
        }
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

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

   // std::cout << "%TEST_STARTED% testGrafo (newsimpletest)" << std::endl;
   // testGrafo();
   // std::cout << "%TEST_FINISHED% time=0 testGrafo (newsimpletest)" << std::endl;

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

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}