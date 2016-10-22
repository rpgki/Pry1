/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.cpp
 * Author: Carlos
 * 
 * Created on 6 de septiembre de 2016, 11:02 PM
 */

#include "Grafo.h"

Grafo::Grafo(int N, int K, double beta) {
    cntVrt = N; //Se guarda la cantidad de vertices escogidas por el usuario
    arrNdoVrt_ptr = new NdoVrt[N]; //Se crea el arreglo

    for(int i = 0; i < N; i++){ //Se alambran los vértices con sus vecinos de acuerdo al parámetro K
        for(int j = 0; j < N; j++){
            if((abs(i-j)%(N - 1 -(K/2)) > 0) && ((abs(i-j)%(N - 1 -(K/2)) <= K/2)))
                arrNdoVrt_ptr[i].lstAdy.agr(j);
        }
    }

    // Se construye el generador de números al azar basado en una semilla tomada
    // del reloj del sistema:    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    // Se cargan los dados
    std::uniform_real_distribution<double> dados_0_1(0.0, 1.0);


    //#2: se re-alambran las conexiones usando beta
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            // Genera un número al azar entre 0 y 1
            double numAzar = dados_0_1(generator);
            if ((arrNdoVrt_ptr[i].lstAdy.bus(j)) &&(numAzar <= beta)) { // se re-alambra
                // se borra j de la lstAdy de i
                arrNdoVrt_ptr[i].lstAdy.elm(j);
                arrNdoVrt_ptr[j].lstAdy.elm(i);

                int* sonAdyDeI = new int[N];
                int cntNoAdyDeI = 0;

                // se cuentan e identifican todos los nodos no adyacentes a i
                for (int k = 0; k < N; k++) {
                    if (!arrNdoVrt_ptr[i].lstAdy.bus(k) && (k != i)) {
                        sonAdyDeI[k] = false;
                        cntNoAdyDeI++;
                    } else sonAdyDeI[k] = true;
                }

                // seleccionar entre todas las no-adyacencias una basándose en 
                // la distribución uniforme
                std::uniform_int_distribution<int> dados_0_N(0, cntNoAdyDeI - 1);
                int posNuevaAdy = dados_0_N(generator);

                // se busca nueva adyacencia en el vector de no-adyacencias
                int nuevaAdy = 0;
                int cuentaFalse = 0;
                for (int k = 0; k < N; k++) {
                    if (!sonAdyDeI[k]) {
                        if (cuentaFalse == posNuevaAdy)
                            nuevaAdy = k;
                        cuentaFalse++;
                    }
                }

                // se re-alambra o sustituye j por k
                arrNdoVrt_ptr[i].lstAdy.agr(nuevaAdy);
                arrNdoVrt_ptr[nuevaAdy].lstAdy.agr(i);
            }
        }
}

Grafo::Grafo(const Grafo& orig){
    int tam = orig.cntVrt; //Se guarda la cantidad de vértices guardadas en *this
    NdoVrt* copiaArr; //Se crea un puntero que para copiar el arreglo
    copiaArr = orig.arrNdoVrt_ptr; //El arreglo guardado en *this se copia en el objeto inicializado anteriormente
    arrNdoVrt_ptr = new NdoVrt[tam]; //Se crea un nuevo arreglo
    for(int i = 0; i < tam ; i++){ //Se copian los elementos de la copia del arreglo
        arrNdoVrt_ptr[i] = copiaArr[i];
    }
    cntVrt = tam; //Se guarda el tamaño del arreglo
    //delete[] copiaArr;
}

Grafo::Grafo(string nArch) {
	string hilera; //se inicializa la variable que contendra las hileras del archivo
	//int cntVrt; //se guarda en esta variable la cantidad de vertices leidos en la primer linea del archivo
	string aux; //en esta variable se guarda cada caracter de la hilera
	int pos = 0; //contador para posicion del arreglo que contendra los nodos
	ifstream grafo(nArch); //se lee el archivo que contiene el grafo
	
	if (!grafo) { // operador ! sobrecargado
		cerr << "No se pudo abrir el archivo de entrada" << endl;
		exit(1);
	}
	
	getline(grafo, hilera); //se lee la primera linea del archivo
	cntVrt = stoi(hilera); //se convierte la primera linea a entero
	arrNdoVrt_ptr = new NdoVrt[cntVrt]; //se inicializa el arreglo que contendra a los vertices
	while(getline(grafo, hilera)){ //mientras no se acaben las hileras del archivo
		for(int i = 0; i < hilera.size()-1; i++){ //este ciclo lee todos los caracteres de la hilera
			if(hilera[i] != ' '){
				aux = aux + hilera[i]; //se guarda el caracter en aux
			} else{
				arrNdoVrt_ptr[pos].lstAdy.agr(stoi(aux));//se cambia el caracter a entero y se asigna a la lista correspondiente a cada vertice
				//cout << "Elementos de las hileras: " << stoi(aux) << endl;
				//cout << "Posicion del arreglo: " << pos << endl;
				aux = "";
			}
		}
		arrNdoVrt_ptr[pos].lstAdy.agr(stoi(aux));//se cambia el caracter a entero y se asigna a la lista correspondiente a cada vertice
		//cout << "Elementos de las hileras: " << stoi(aux) << endl;
		//cout << "Posicion del arreglo: " << pos << endl;
		aux = "";
		pos = pos + 1; //se aumenta el contador de posiciones para el arreglo de vertices
	}
}

Grafo::~Grafo() {
    delete[] arrNdoVrt_ptr; //Destructor del arreglo que contiene a los nodos en los vertices
    //cout << "Borrando grafo" << endl;
}

bool Grafo::xstVrt(int vrt) const {
    bool res = false;
    if (vrt < cntVrt) { //Se verifica que el vertice ingresado por el usuario efectivamente exista.
        res = true;
    }
}

bool Grafo::xstAdy(int vrtO, int vrtD) const {
    bool res = false; //se inicializa la variable resultado en falso
    if(arrNdoVrt_ptr[vrtO].lstAdy.bus(vrtD)){ //si encuentra que existe adyacencia entre vrtO y vrtD entonces el resultado es verdadero
    res = true;
    }
    return res;
}

int* Grafo::obtAdy(int vrt) const {
    return arrNdoVrt_ptr[vrt].lstAdy.obtAdy(); //Retorna un arreglo con las adyacencias para vrt
}

int Grafo::obtTotVrt() const {
    return cntVrt; //Retorna la cantidad de vertices en *this
}

int Grafo::obtTotAdy() const {
    int totAdy; //Se inicializa una variable para almacenar el total de adyacentes en *this.
    for(int i = 0; i < cntVrt; i++){ //Se recorre el arreglo para sumar la cantidad de adyacencias total
        totAdy += arrNdoVrt_ptr[i].lstAdy.totAdy();
    }
    return totAdy;
}

int Grafo::obtTotAdy(int vrt) const {
	int totAdy; //se crea una variable para almacenar el total de adyacencias
	totAdy = arrNdoVrt_ptr[vrt].lstAdy.totAdy(); //se guarda el total de adyacencias para el vertice vrt
	return totAdy; //se retorna el total de adyacencias para vrt
}

double Grafo::obtPrmAdy() const {
    double promAdy; //Se inicializa una variable para almacenar el promedio
    for(int i = 0; i < cntVrt; i++){ //Se suman todas las adyacencias por vértice
        promAdy += arrNdoVrt_ptr[i].lstAdy.totAdy();
    }
    promAdy = promAdy / cntVrt; //Se divide el total de adyacencias por la cantidad total de vertices
    return promAdy;
}

Grafo::E Grafo::obtEst(int vrt) const {
    return arrNdoVrt_ptr[vrt].std; //Retorna el estado del vértice vrt
}

int Grafo::obtTmpChqVrs(int vrt) const {
    return arrNdoVrt_ptr[vrt].tmpChqVrs; //Retorna el temporizador del vértice vrt
}

int Grafo::obtCntChqVrs(int vrt) const {
    if(arrNdoVrt_ptr[vrt].cntChqVrs > arrNdoVrt_ptr[vrt].tmpChqVrs){
        arrNdoVrt_ptr[vrt].cntChqVrs = 0;
        return arrNdoVrt_ptr[vrt].cntChqVrs; //Retorna el contador del chequeo de virus del vértice vrt
    } else {
        return arrNdoVrt_ptr[vrt].cntChqVrs; //Retorna el contador del chequeo de virus del vértice vrt
    }   
}

double Grafo::promLongCmnsCrts() const { // ESTE NO HAY QUE HACERLO
}

double Grafo::coeficienteAgrupamiento(int vrt) const {
    double coefLoc; //se crea la variable que almacenara el coeficiente local
    int* adyLoc = Grafo::obtAdy(vrt); //se inicializa un arreglo que contendra las adyacencias de vrt
    double nv = 0.0; // se inicializa la variable total de arcos entre adyacencias de vrt en 0
    int kv = arrNdoVrt_ptr[vrt].lstAdy.totAdy(); //se guarda el total de adyacencias para vrt
    if (kv == 0) {
        coefLoc = 0;
    } else {
        if (kv != 1) { //se calcula el coeficiente siempre y cuando haya al menos dos adyacencias
            for (int i = 0; i < kv - 1; i++) { //se lee cada elemento de la lista
                for (int j = i + 1; j < kv; j++) { //se lee el elemento siguiente a i de la lista
                    if (Grafo::xstAdy(adyLoc[i], adyLoc[j])) { //se evalua si el elemento i tiene esta conectado con algun elemento j
                        nv++; //se aumenta el contador de conexiones   
                    }
                }
            }
            coefLoc = (2 * nv) / (kv * (kv - 1)); //se calcula el coeficiente local
        }
    }
    return coefLoc; //se retorna el valor del coeficiente para vrt
}

double Grafo::coeficienteAgrupamiento() const {
    int vertices = Grafo::obtTotVrt(); //se obtiene el total de vertices en *this
    double res = 0; //se crea la variable resultado que almacenara el coeficiente global
    for(int i = 0; i < vertices; i++){ //se recorren las posiciones del arreglo que contiene a los vertices
        res += Grafo::coeficienteAgrupamiento(i); //se suma el coeficiente local para cada vertice
    }
    res = res/vertices; //se calcula el promedio el cual es el coeficiente global
    return res; //se retorna el coeficiente global
}

void Grafo::modEst(int vrt, E ne) {
    arrNdoVrt_ptr[vrt].std = ne; //Modifica el estado de vrt por el ingresado en ne
}

void Grafo::modTmpChqVrs(int vrt, int nt) {
    arrNdoVrt_ptr[vrt].tmpChqVrs = nt; //Modifica el temporizador de vrt por el ingresado en nt
}

void Grafo::actCntChqVrs(int vrt) {
    arrNdoVrt_ptr[vrt].cntChqVrs++; //Aumenta en uno el contador del chequeo de virus.
}

void Grafo::infectar(int ios) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Se establece la semilla
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> nmAltr(0, cntVrt-1); //Se genera una distribución uniforme de enteros entre 0 y la cantidad de vertices - 1
    while(ios != 0){
        int num = nmAltr(generator); //Se guarda el número generado
        if(arrNdoVrt_ptr[num].std != I){// Se infectan aleatoriamente los nodos de acuerdo al valor ingresado en ios
           arrNdoVrt_ptr[num].std = I;
           ios--;
        }
    }
}

void Grafo::azarizarTmpChqVrs(int vcf) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Se crea la semilla
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> nmAltr(1, vcf); //Se genera una distribución uniforme desde 1 hasta el valor ingresado por en vcf
    for(int i = 0; i < cntVrt; i++){
        int num = nmAltr(generator); //Se guarda el número generado
        arrNdoVrt_ptr[i].tmpChqVrs = num; //Se asigna el número generado al temporizador del vertice i
    }
}