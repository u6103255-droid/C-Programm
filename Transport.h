// Hugo Heredia Sánchez
// u6103255
// Exercici e1

#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include <vector>
#include <iterator>
#include <map>
#include "Persona.h"

using namespace std;

/**
 @class Transport
 @author Hugo Heredia Sánchez
 @version 1.0
 @date 04/11/2025
 @brief Guarda tota la informació respectiva als transport, tal com les persones que han agafat el transport per fer un trajecte, el nom del transport i les diferents dades que s'han
 precalculat en alguns dels mètodes d'aquesta classe.
 */

class Transport {
    public:
        Transport(string nom);
        /**<
        @brief Crea un objecte Transport amb el nom entrat per paràmetre, el vector persones buit i les diferents dades precalculades inicialitzades als valors per defecte.
        */

        void afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, int edat, string estudis);
        /**<
        @brief Afegeix a les diferents persones al vector persones i actualitza les dades precalculades en aquest mètode.
        @return void
        @param id és un nombre que representa l'id de la persona, ordre és un nombre que representa l'ordre que pertany al trajecte segons els trajectes que ha fet la persona,
        tipusTrajecte és un string que representa el tipus del trajecte, horaIn representa l'hora
        en que s'ha començat a fer el trajecte, durada és un nombre que representa la durada del trajecte, comarcaIn i comarcaFi són strings que representen la comarca d'origen i de destí
        del trajecte, edat és un nombre que representa l'edat de la persona que ha fet el trajecte
        i estudis és un string que representa el nivell d'estudis de la persona que fa el trajecte.
        @pre
        -# durada>=0, edat>=0, ordre>=1, 0<=horaIn<=23
        @post
        -# Afegeix a les diferents persones al vector persones i actualitza les dades precalculades en aquest mètode.
        */

        string obtenirNom() const;
        /**<
        @brief Retorna el nom del transport.
        @return string
        @pre cert
        @post
        -# Retorna el nom del transport.
        */

        int obtenirNombrePersones() const;
        /**<
        @brief Retorna el nombre de persones diferents que hi ha al transport.
        @return int
        @pre cert
        @post
        -# Retorna el nombre de persones diferents que hi ha al vector trajectes.
        -# Si aquest és buit, retorna 0.
        */

        double obtenirTempsPromig() const;
        /**<
        @brief Retorna el temps promig dels trajectes que hi ha al transport.
        @return double
        @pre cert
        @post
        -# Retorna el temps promig dels trajectes que hi ha al transport.
        -# Si aquest és buit, retorna 0.
        */

        bool operator==(const Transport& m) const;
        /**<
        @brief Compara el transport amb un altre passat per paràmetre i determina si són iguals o no.
        @return bool
        @pre cert
        @post
        -# retorna true si this->nom==m.nom.
        -# Altrament, retorna false.
        */

        map<string,pair<int,int>> obtenirTempsComarques() const;
        /**<
        @brief Retorna un map amb el temps total i el nombre de trajectes que hi ha per cada comarca.
        @return map<string,pair<int,int>>
        @pre cert
        @post
        -# Retorna un map amb el temps total i el nombre de trajectes que hi ha per cada comarca.
        -# Si no hi ha cap comarca, ho retornarà buit.
        */

        map<string, vector<pair<int,int>>> obtenirTempsPerHora() const;
        /**<
        @brief Retorna un map amb el temps total i el nombre de trajectes que hi ha per cada comarca i per cada hora.
        @return map<string, vector<pair<int,int>>>
        @pre cert
        @post
        -# Retorna un map amb el temps total i el nombre de trajectes que hi ha per cada comarca i per cada hora.
        -# Si no hi ha cap comarca, ho retornarà buit.
        */

        double obtenirTempsPerHora(int hora, string trajecte) const;
        /**<
        @brief Retorna la mitjana de temps dels trajectes segons l'hora passada per paràmetre.
        @return double
        @param hora és un nombre que representa l'hora d'inici del trajecte del que volem obtenir el temps promig i trajecte
        és un string que representa la concatenació de la comarcaIn i la comarcaFi separats per " - ".
        @pre
        -# 0<=hora<=23
        @post
        -# Retorna la mitjana de temps dels trajectes segons l'hora passada per paràmetre.
        -# Si no hi ha trajectes, retornarà 0.
        */

        map<string, pair<double,int>> TempsPromigperEstudis() const;
        /**<
        @brief Retorna un map amb el temps total i el nombre de trajectes que hi ha per cada nivell d'estudi.
        @return map<string, pair<double,int>>
        @pre cert
        @post
        -# Retorna un map amb el temps total i el nombre de trajectes que hi ha per cada nivell d'estudi.
        */

        int nombreTrajectes(string tipusTrajecte) const;
        /**<
        @brief Retorna el nombre de trajectes que hi ha per cada persona del tipus passat per paràmetre.
        @return int
        @pre cert
        @post
        -# Retorna el nombre de trajectes que hi ha per cada persona del tipus passat per paràmetre.
        */

    private:
        string nom;
        int tempsTotal=0;
        int nTrajectes=0;
        vector<Persona> persones;
        map<string,pair<int,int>> tempsComarques;
        map<string, vector<pair<int,int>>> tempsPerHora;

};

#endif // TRANSPORT_H

