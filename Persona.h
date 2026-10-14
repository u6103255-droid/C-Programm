// Hugo Heredia Sánchez
// u6103255
// Exercici e1

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <vector>
#include <iterator>
#include "Trajecte.h"

using namespace std;

/**
 @class Persona
 @author Hugo Heredia Sánchez
 @version 1.0
 @date 04/11/2025
 @brief Guarda tota la informació respectiva a una persona, tal com els trajectes que ha fet la persona, el seu identificador, l'edat i el seu nivell d'estudis.
 */

class Persona
{
    public:

        Persona(int id, int edat, string estudis);
        /**<
        @brief Crea un objecte Persona amb l'identificador inicialitzat amb l'id passat per paràmetre, l'edat inicialitzat amb l'edat passada per paràmetre
        i el nivell d'estudis amb el que s'ha passat per paràmetre.
        */

        void afegir(const Trajecte&t);
        /**<
        @brief Afegeix al vector de trajectes el trajecte passat per paràmetre.
        @return void
        @pre cert
        @post
        -# Afegeix al vector de trajectes el trajecte passat per paràmetre
        */

        bool operator==(const Persona& p) const;
        /**<
        @brief Compara l'objecte Persona amb un altre passat per paràmetre i determina si són iguals o no.
        @return bool
        @pre cert
        @post
        -# Retorna cert si si tots dos id, les edats i el nivell d'estudis són iguals.
        -#Altrament, retorna fals.
        */

        pair<double, int> TempsPromigTrajectes() const;
        /**<
        @brief Retorna un pair amb el temps total dels trajectes que ha fet la persona i el nombre de trajectes que ha fet.
        @return pair<double, int>
        @pre cert
        @post
        -# Retorna un pair amb el temps total dels trajectes que ha fet la persona i el nombre de trajectes que ha fet.
        */

        string obtenirEstudis() const;
        /**<
        @brief Retorna el nivell d'estudis de la persona.
        @return string
        @pre cert
        @post
        -# Retorna el nivell d'estudis de la persona.
        */

        int nombreTrajectes(string tipusTrajecte) const;
        /**<
        @brief Retorna el nombre de trajectes que ha fet la persona del tipus passat per paràmetre.
        @return int
        @pre cert
        @post
        -# Retorna el nombre de trajectes que ha fet la persona del tipus passat per paràmetre.
        -# Si no n'ha fet cap del tipus, retorna 0.
        */
        //Pre: cert
        //Post: retorna el nombre de trajectes que ha fet la persona del tipus passat per paràmetre.

    private:
        int id, edat;
        string estudis;
        vector<Trajecte> trajectes;
};

#endif // PERSONA_H
