// Hugo Heredia Sánchez
// u6103255
// Exercici e1
#ifndef TRAJECTE_H
#define TRAJECTE_H

#include <string>
#include <iostream>
using namespace std;

/**
 @class Trajecte
 @author Hugo Heredia Sánchez
 @version 1.0
 @date 04/11/2025
 @brief Guarda tota la informació respectiva a un trajecte, tal com l'ordre del trajecte fet per la persona, el tipus de trajecte, l'hora d'inici i la durada d'aquest
 i la seva comarca d'origen i de destí.

 */

class Trajecte{
    public:
        Trajecte();
        /**<
        @brief Crea un objecte Trajecte amb tot inicialitza a 0 o a " ".
        */

        Trajecte(int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi);
        /**<
        @brief Crea un objecte Trajecte amb l'ordre, el tipusTrajecte, horaIn, durada, comarcaIn i comarcaFi amb els seus respectius valors passats per paràmetre.
        */

        string obtenirTrajecte() const;
        /**<
        @brief Retorna la concatenació de la comarca d'origen i la comarca destí separats per " - ".
        @return string
        @pre cert
        @post
        -# Retorna la concatenació de la comarca d'origen i la comarca destí separats per " - ".
        */

        int obtenirDurada() const;
        /**<
        @brief Retorna la durada del trajecte.
        @return int
        @pre cert
        @post
        -# Retorna la durada del trajecte.
        */

        string obtenirtipusTrajecte() const;
        /**<
        @brief Retorna el tipus del trajecte.
        @return string
        @pre cert
        @post
        -# Retorna el tipus del trajecte.
        */

    private:
        int ordre;
        string tipusTrajecte;
        int horaIn;
        int durada;
        string comarcaIn;
        string comarcaFi;
};

#endif // TRAJECTE_H
