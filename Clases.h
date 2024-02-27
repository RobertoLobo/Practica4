#ifndef CLASES_H
#define CLASES_H
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>

typedef int posicion;


class Neurona{
private:
    int id;
    float voltaje;
    posicion x;
    posicion y;
    int red;
    int green;
    int blue;
public:
    Neurona(){
        id = 0;
        voltaje = 0;
        x = 0;
        y = 0;
        red = 0;
        green = 0;
        blue = 0;
    }
    Neurona(int id, float voltaje, posicion x, posicion y, int r, int g, int b){
        this->id = id;
        this->voltaje = voltaje;
        this->x = x;
        this->y = y;
        this->red = r;
        this->green = g;
        this->blue = b;
    }
    void putId(int id){this->id = id;}
    void putVoltaje(float voltaje){this->voltaje = voltaje;}
    void putX(posicion x){this->x = x;}
    void putY(posicion y){this->y = y;}
    void putRed(int red){this->red = red;}
    void putGreen(int green){this->green = green;}
    void putBlue(int blue){this->blue = blue;}

    int getId(){return id;}
    float getVoltaje(){return voltaje;}
    posicion getX(){return x;}
    posicion getY(){return y;}
    int getRed(){return red;}
    int getGreen(){return green;}
    int getBlue(){return blue;}
};

class AdminNeuronas{
private:
    std::list<Neurona*> neuronas;
    std::fstream archivo;
    int cuentaNeuronas;
public:
    AdminNeuronas(){
        cuentaNeuronas = 0;
    }
    bool agregarPila(Neurona * n){
        neuronas.push_front(n);
        cuentaNeuronas++;
        return true;
    }
    bool agregarCola(Neurona * n){
        neuronas.push_back(n);
        cuentaNeuronas++;
        return true;
    }
    bool guardarNeurona(Neurona * n){

        std::cout << "Neuronas #" << dameCuenta() << std::endl
                  << "ID: " << n->getId() << std::endl
                  << "Voltaje: " << n->getVoltaje() << std::endl
                  << "Cord X: " << n->getX() << std::endl
                  << "Cord Y: " << n->getY() << std::endl
                  << "Red: " << n->getRed() << std::endl
                  << "Green: " << n->getGreen() << std::endl
                  << "Blue: " << n->getBlue() << std::endl
                  << "\n";
    }
    bool guardarNeuronas(std::string fileName){
        std::cout << "Guardando archivo " << fileName << "...";
        archivo.open(fileName,std::ios_base::out);
        if (archivo.is_open()){
            archivo << std::to_string(cuentaNeuronas) << "|" << "Total" << std::endl;
            for(auto & n : neuronas){
                archivo << n->getId() << "|"
                        << n->getVoltaje() << "|"
                        << n->getX() << "|"
                        << n->getY() << "|"
                        << n->getRed() << "|"
                        << n->getGreen() << "|"
                        << n->getBlue() << "," << std::endl;
                std::cout << "Neurona guardada.\n";
            }
            archivo.close();
            std::cout << "Hecho." << std::endl;
            return true;
        }
        else{
            std::cout << "No se pudo abrir el archivo." << std::endl;
            return false;
        }
    }
    bool cargarNeuronas(std::string nombreArchivo){
        std::string cadena,subcadena;
        int pos, pos2;

        std::cout << "Cargando archivo " << nombreArchivo << "..." << std::endl;
        archivo.open(nombreArchivo,std::ios_base::in);
        if (archivo.is_open()){
            archivo >> cuentaNeuronas;
            getline(archivo,cadena);
            for(int i=0;i<cuentaNeuronas;i++){//while(!archivo.eof()){
                Neurona * n = new Neurona();
                getline(archivo,cadena,'|');
                pos=cadena.find_first_of('|',0);
                n->putId(std::stoi(cadena.substr(0,pos)));
                pos2=cadena.find_first_of('|',pos+1);
                subcadena=cadena.substr(pos,pos2);
                n->putVoltaje(std::stof(subcadena));
                pos=cadena.find_first_of('|',pos2+1);
                subcadena=cadena.substr(pos2,pos);
                n->putX(stoi(subcadena));

                pos2=cadena.find_first_of('|',pos+1);
                subcadena=cadena.substr(pos,pos2);
                n->putRed(std::stof(subcadena));
                pos=cadena.find_first_of('|',pos2+1);
                subcadena=cadena.substr(pos2,pos);
                n->putGreen(stoi(subcadena));

                pos2=cadena.find_first_of('|',pos+1);
                subcadena=cadena.substr(pos,pos2);
                n->putBlue(std::stof(subcadena));
                imprimir(n);
                agregarCola(n);
            }
            std::cout << "Hecho" << std::endl;
            archivo.close();
            return true;
        }
        else{
            std::cout << "No se pudo abrir el archivo." << std::endl;
            return false;
        }
    }
    Neurona * dameNeurona(){
        cuentaNeuronas--;
        return neuronas.back();
    }
    void imprimir(Neurona * n){
        std::cout << "Neuronas #" << dameCuenta() << std::endl
                  << "ID: " << n->getId() << std::endl
                  << "Voltaje: " << n->getVoltaje() << std::endl
                  << "Cord X: " << n->getX() << std::endl
                  << "Cord Y: " << n->getY() << std::endl
                  << "Red: " << n->getRed() << std::endl
                  << "Green: " << n->getGreen() << std::endl
                  << "Blue: " << n->getBlue() << std::endl
                  << "\n";
    }
    void listar(){
        for (Neurona * n : neuronas)
            imprimir(n);
    }
    int dameCuenta(){
        return (int)neuronas.size();
    }
    std::list<Neurona*> dameNeuronas(){
        return neuronas;
    }
};

#endif // CLASES_H
