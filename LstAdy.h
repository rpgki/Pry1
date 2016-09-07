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
#define	LSTORDADY_H

# include <memory>
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
    
    void agr(int nady);
    bool bus(int ady);
    string aHil();
    
private:
    struct NdoLstAdy { // representa el nodo de una lista de adyacencias
        int vrtD; // representa la posición del vértice destino en Grafo
        shared_ptr<NdoLstAdy> sgt; // representa el apuntador inteligente al siguiente nodo
    };
    
    shared_ptr<NdoLstAdy> inicio; // representa el apuntador al inicio de la lista
};

#endif	/* LSTORDADY_H */