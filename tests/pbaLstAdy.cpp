/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/* 
 * File:   newsimpletest.cpp
 * Author: JustinRC
 *
 * Created on 8 de septiembre de 2016, 04:18 PM
 */
 
#include <stdlib.h>
#include <iostream>
#include "LstAdy.h"
 
/*
 * Simple C++ Test Suite
 */
 
void testLstAdy() {
    LstAdy lstAdy;
    string h = lstAdy.aHil();
    if (h != "{}") {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy (newsimpletest) message=fallo el constructor estandar" << std::endl;
    }
    lstAdy.agr(4);
    string h2 = lstAdy.aHil();
    if (h2 != "{4}") {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy (newsimpletest) message=fallo el constructor estandar al ingresar 4" << std::endl;
    }
    lstAdy.agr(2);
    string h3 = lstAdy.aHil();
    if (h3 != "{4,2}") {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy (newsimpletest) message=fallo el constructor estandar al ingresar 2" << std::endl;
    }
    lstAdy.agr(7);
    string h4 = lstAdy.aHil();
    if (h4 != "{7,4,2}") {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy (newsimpletest) message=fallo el constructor estandar al ingresar 7" << std::endl;
    }
}
 
void testLstAdy2() {
    LstAdy orig;
    LstAdy lstAdy(orig);
    string h = lstAdy.aHil();
    if (h != "{}") {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy2 (newsimpletest) message=fallo el constructor de copias con la lista vacia" << std::endl;
    }
    orig.agr(5);
    LstAdy lstAdy2(orig);
    h = lstAdy2.aHil();
    if (h != "{5}") {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy2 (newsimpletest) message=fallo el constructor de copias con la lista 5" << std::endl;
    }
    orig.agr(8);
    LstAdy lstAdy3(orig);
    h = lstAdy3.aHil();
    if (h != "{8,5}") {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy2 (newsimpletest) message=fallo el constructor de copias con la lista 5,8" << std::endl;
    }
    orig.agr(1);
    LstAdy lstAdy4(orig);
    h = lstAdy4.aHil();
    if (h != "{8,5,1}") {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy2 (newsimpletest) message=fallo el constructor de copias con la lista 5,8,1" << std::endl;
    }
}
 
void testAgr() {
    int nady;
    LstAdy lstAdy;
    lstAdy.agr(nady);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAgr (newsimpletest) message=error message sample" << std::endl;
    }
}
 
void testBus() {
    LstAdy lstAdy;
    lstAdy.agr(15);
    bool result = lstAdy.bus(15);
    string h = lstAdy.aHil();
    if (h != "{15}" || !result) {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy2 (newsimpletest) message=fallo el buscar 7" << std::endl;
    }
    lstAdy.agr(9);
    result = lstAdy.bus(9);
    h = lstAdy.aHil();
    if (h != "{15,9}" || !result) {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy2 (newsimpletest) message=fallo el buscar 9" << std::endl;
    }
    lstAdy.agr(7);
    result = lstAdy.bus(7);
    h = lstAdy.aHil();
    if (h != "{15,9,7}" || !result) {
        std::cout << "%TEST_FAILED% time=0 testname=testLstAdy2 (newsimpletest) message=fallo el buscar 15" << std::endl;
    }
}
 
int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
 
    std::cout << "%TEST_STARTED% testLstAdy (newsimpletest)" << std::endl;
    testLstAdy();
    std::cout << "%TEST_FINISHED% time=0 testLstAdy (newsimpletest)" << std::endl;
     
    std::cout << "%TEST_STARTED% testBus (newsimpletest)" << std::endl;
    testBus();
    std::cout << "%TEST_FINISHED% time=0 testBus (newsimpletest)" << std::endl;
 
    std::cout << "%TEST_STARTED% testLstAdy2 (newsimpletest)" << std::endl;
    testLstAdy2();
    std::cout << "%TEST_FINISHED% time=0 testLstAdy2 (newsimpletest)" << std::endl;
 
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
 
    return (EXIT_SUCCESS);
}