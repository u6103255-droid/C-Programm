// Hugo Heredia Sánchez
// u6103255
// Exercici e1

#ifndef DISTANCIA_H
#define DISTANCIA_H

#include <string>
#include <vector>
#include <iterator>
#include <list>
#include <set>
#include <algorithm>
#include "Transport.h"

/**
 @struct MesOptim
 @brief Estructura que guarda la informació del mitjà de transport més òptim per hora.

 Aquesta estructura emmagatzema les dades necessàries per determinar quin transport
 és més eficient segons l’hora del dia. Inclou el tipus de transport, l’hora
 i el temps promig que triga.
*/
struct MesOptim{
    string tipusTransport;
    int hora;
    double tempsPromig;
};

typedef list<pair<int,string>> NumPersonesTransport;

using namespace std;

/**
 @class Distancia
 @author Hugo Heredia Sánchez
 @version 1.0
 @date 04/11/2025
 @brief Guarda tota la informació respectiva a les distàncies, tal com els transports de cada distància i els trajectes nous que hi ha en aquesta.
 */

class Distancia {
    public:
        Distancia();
        /**<
        @brief No es fa res.
        */

        void netejarTrajectesNous();
        /**<
        @brief Neteja el set<string> trajectesNous
        @return void
        @pre cert
        @post
        -# Neteja el set<string> trajectesNous
        */

        void afegir(int id, int ordre, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis);
        /**<
        @brief Afegeix, a la distància seleccionada anteriorment, el transport que ve donat pels paràmetres entrats per l'usuari, sempre i quan aquest no existeixi al vector transports,
        i actualitza les diferents dades precalculades en aquest mètode.
        @return void
        @param id és un nombre que representa l'id de la persona, ordre és un nombre que representa l'ordre que pertany al trajecte segons els trajectes que ha fet la persona,
        tipusTrajecte és un string que representa el tipus del trajecte, horaIn representa l'hora
        en que s'ha començat a fer el trajecte, durada és un nombre que representa la durada del trajecte, comarcaIn i comarcaFi són strings que representen la comarca d'origen i de destí
        del trajecte, mitjaPrincipal és un string que representa el mitjà principal que s'utilitza en el trajecte, edat és un nombre que representa l'edat de la persona que ha fet el trajecte
        i estudis és un string que representa el nivell d'estudis de la persona que fa el trajecte.
        @pre
        -# durada>=0, edat>=0, ordre>=1, 0<=horaIn<=23
        @post
        -# Afegeix, a la distància seleccionada anteriorment, el transport que ve donat pels paràmetres entrats per l'usuari, sempre i quan aquest no existeixi al vector transports,
        i actualitza les diferents dades precalculades en aquest mètode.
        */

        int nombreTransports() const;
        /**<
        @brief Retorna la mida del vector transports.
        @return int
        @pre cert
        @post
        -# Retorna la mida del vector transports.
        */

        NumPersonesTransport nombrePersonesPerTransport() const;
        /**<
        @brief Retorna una llista amb el nombre de persones de cada transport, que forma del vector transports< i el seu respectiu nom.
        @return NumPersonesTransport
        @pre cert
        @post
        -# Retorna una llista amb el nombre de persones de cada transport, que forma del vector transports< i el seu respectiu nom.
        -# Si el vector transports és buit, la llista serà buida.
        */

        pair<string,double> mesRapid() const;
        /**<
        @brief Retorna el nom i el temps promig de trajecte del transport més ràpid que hi ha al vector transports.
        @return pair<string,double>
        @pre cert
        @post
        -# Retorna el nom i el temps promig de trajecte del transport més ràpid que hi ha al vector transports.
        -# Si el vector transports és buit, retornarà com a nom "--" i com a temps promig
        un valor brossa (1.79769e+308).
        */

        set<string> obtenirTrajectesNous() const;
        /**<
        @brief Retorna un set amb tots els transports de la distància.
        @return set<string>
        @pre cert
        @post
        -# Retorna un set amb tots els transports de la distància.
        */

        pair<string, double> transportMesRapid(string trajecte) const;
        /**<
        @brief Retorna un pair<string, double> que contindrà el nom del tipus de transport i el temps promig del tipus
        de transport més ràpid per realitzar un trajecte de km kilòmetres entre la comarcaIn i la comarcaFi.
        @return pair<string, double>
        @param trajecte és un string que representa la concatenació del nom de la comarcaIn i la comarcaFi ajuntats per " - "
        @pre cert
        @post
        -# Retorna un pair<string, double> que contindrà el nom del tipus de transport i el temps promig del tipus
        de transport més ràpid per realitzar un trajecte de km kilòmetres entre la comarcaIn i la comarcaFi.
        -# Altrament, retornarà com a nom "--" i 1.79769e+308 com a temps promig.
        */

        vector<double> tempsHores(string transport, string trajecte) const;
        /**<
        @brief Retorna un vector<double> amb el temps promig a les diferents hores del dia (0..23) necessari per fer un
        trajecte entre comarcaIn i comarcaFi, d’una distància km i amb un tipus transport determinats.
        @return vector<double>
        @param trajecte és un string que representa la concatenació del nom de la comarcaIn i la comarcaFi ajuntats per " - "
        i transport és un string que representa el nom del transport del qual volem retornar el temps mitjà per hores.
        @pre cert
        @post
        -# Retorna un vector<double> amb el temps promig a les diferents hores del dia (0..23) necessari per fer un
        trajecte entre comarcaIn i comarcaFi, d’una distància km i amb un tipus transport determinats.
        */

        pair<string, double> transport_mesrapid_perhora(int hora, string trajecte) const;
        /**<
        @brief Retorna un pair<string, double> que contindrà el tipus de transport més ràpid i el temps promig per fer
        un trajecte entre comarcaIn i comarcaFi, d’una distància km i hora (0..23) determinats.
        @return pair<string, double>
        @param trajecte és un string que representa la concatenació del nom de la comarcaIn i la comarcaFi ajuntats per " - "
        i hora és un nombre que representa l'hora de la qual busquem el temps promig.
        @pre
        -# 0<=hora<=23
        @post
        -# Retorna un pair<string, double> que contindrà el tipus de transport més ràpid i el temps promig per fer
        un trajecte entre comarcaIn i comarcaFi, d’una distància km i hora (0..23) determinats.
        -# Si no hi ha trajectes, el temps promig serà 0.0 i el nom del transport serà "--".
        */

        MesOptim transportOptim(string trajecte) const;
        /**<
        @brief Retorna un objecte MesOptim que contindrà el tipus de transport, l’hora i el temps promig per fer un trajecte
        entre comarcaIn i comarcaFi, d’una distància donada (km), el més ràpid possible.
        @return MesOptim
        @param trajecte és un string que representa la concatenació del nom de la comarcaIn i la comarcaFi ajuntats per " - ".
        @pre cert
        @post
        -# Retorna un objecte MesOptim que contindrà el tipus de transport, l’hora i el temps promig per fer un trajecte
        entre comarcaIn i comarcaFi, d’una distància donada (km), el més ràpid possible.
        */

        map<string, pair<double,int>> TempsPromigperEstudis() const;
        /**<
        @brief Retorna un map amb els diferents noms dels estudis i un pair amb el temps total de tots els trajectes fets per les persones
        segons l'estudi i el nombre de trajectes que hi ha per cada estudi.
        @return map<string, pair<double,int>>
        @pre cert
        @post
        -# Retorna un map amb els diferents noms dels estudis i un pair amb el temps total de tots els trajectes fets per les persones
        segons l'estudi i el nombre de trajectes que hi ha per cada estudi.
        */

        int nombreTrajectes(string tipusTrajecte) const;
        /**<
        @brief Retorna el nombre de trajectes que hi ha segons el tipus de trajecte passat per paràmetre per cada transport i cada persona.
        @return int
        @param tipusTrajecte és un string que representa el tipus del trajecte que volem comptabilitzar.
        @pre cert
        @post
        -# Retorna el nombre de trajectes que hi ha segons el tipus de trajecte passat per paràmetre per cada transport i cada persona.
        -# Si aquest no existeix, retornarà 0.
        */

    private:
        vector<Transport> transports;
        set<string> trajectesNous;
        static bool compara(const pair<int,string>& a, const pair<int,string>& b);
        /**<
        @brief Compara dos contenidors de tipus pair<int,string> segons el primer element i, per desempatar, el segon element.
        @return bool
        @param a i b són dos contenidors de tipus pair<int,string>
        @pre cert
        @post
        -# Retorna true si a.first > b.first quan el nombre de persones no coincideix. Altrament, retorna false. Si coincideix el nombre de persones per transport, retorna true si
        a.second <= b.second. Altrament, retorna false.
        */

        static void calcularTempsMig(map<string, pair<double,int>> &res, const map<string, pair<double,int>> &aux);
        /**<
        @brief Afegeix al map res els diferents estudis, el seu temps promig i el nombre de trajectes per cadascun segons el map passat per paràmetre.
        @return void
        @param res i aux són dos contenidors de tipus map<string, pair<double,int>>
        @pre cert
        @post
        -# Afegeix al map res els diferents estudis, el seu temps promig i el nombre de trajectes per cadascun segons el map passat per paràmetre.
        */
};

#endif // DISTANCIA_H
