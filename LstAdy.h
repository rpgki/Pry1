/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/* 
 * File:   LstAdy.h
 * Author: Carlos
 *
 * Created on 6 de septiembre de 2016, 11:05 PM
 */
 
#ifndef LSTORDADY_H
#define LSTORDADY_H
 
#include <memory>
#include <iostream>
#include <sstream>
 
using namespace std;
 
class LstAdy {
    // Representa la lista ordenada de adyacencias de un nodo en Grafo.
     
public:
     
    // Construye una lista de adyacencias vacía.
    LstAdy();
     
    // Construye una lista de adyacencias idéntica a orig.
    LstAdy(const LstAdy& orig);
     
    // Destruye a *this retornando toda la memoria asignada dinámicamente.
    ~LstAdy();
     
    // MOD: *this.
    // EFE: agrega nady a *this en forma ordenada.
    //      totAdy() aumenta en uno.
    void agr(int nady);
     
    // EFE: retorna true si ady pertenece a *this y false en caso contrario.
    bool bus(int ady);
     
    // MOD: *this.
    // EFE: si ady pertenece a *this, lo elimina, en caso contrario no tiene efecto.
    //      si ady pertenece a *this, totAdy() disminuye en uno.
    void elm(int ady);
     
    // EFE: retorna una hilera como {2,5,8} que representa las adyacencias en *this.
    string aHil();
     
    // EFE: retorna la cantidad de adyacencias guardadas en *this.
    int totAdy();
     
    // EFE: retorna un arreglo de enteros que incluye todas las adyacencias en *this.
    int* obtAdy();
     
private:
    struct NdoLstAdy { // representa el nodo de una lista de adyacencias
        int vrtD; // representa la posición del vértice destino en Grafo
        shared_ptr<NdoLstAdy> sgt; // representa el apuntador inteligente al siguiente nodo
        NdoLstAdy(): vrtD(0),sgt(nullptr){}; // constructor estándar
        NdoLstAdy(int nuevo):vrtD(nuevo),sgt(0){}; //constructor no estándar
        ~NdoLstAdy(){cout << "borrando: " << vrtD << endl;}; // destructor
    };
    
    int cntAdy; // representa la cantidad de adyacencias guardadas en *this.
    shared_ptr<NdoLstAdy> inicio; // representa el apuntador al inicio de la lista
};
 
#endif  /* LSTORDADY_H */