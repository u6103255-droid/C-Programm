// Hugo Heredia Sánchez
// u6103255
// Pràctica 1



#ifndef MOBILITAT_H
#define MOBILITAT_H

#include <string>
#include <vector>
#include <fstream>
#include "Distancia.h"
#include "eines.h"

using namespace std;

typedef vector<pair<string,double>> MesRapids;

typedef vector<set<string>> NousTrajectes;

typedef map<string, double> TempsPerNivellEstudis;

/**
 @class Mobilitat
 @author Hugo Heredia Sánchez
 @version 1.0
 @date 04/11/2025
 @brief Guarda tota la informació respectiva a les dades proporcionades per les enquestes i segons les diferents opcions de consulta.
 */

class Mobilitat {
    public:
        Mobilitat();
        /**<
        @brief Crea un objecte Mobilitat amb el vector de distancies inicialitzat amb un espai de 7, l'objecte nous_trajectes inicialitzat amb 7 posicions i el nombre de trajectes xinoxano inicialitzat a 0.
        */

        int llegirDades(const string& path);
        /**<
        @brief Emplena l'objecte Mobilitat amb les dades que s'han passat a través de l'arxiu que es troba al path i retorna el nombre de línies llegides.
        @return int
        @param path és el directori on es troba l'arxiu del qual s'han d'extreure les dades.
        @pre cert
        @post
        -# Retorna l'objecte Mobilitat ple amb les dades que s'han passat a través d'un arxiu i el nombre de línies llegides.
        -# Si aquest no s'ha pogut obrir, o és buit, retorna 0 i l'objecte Mobilitat sense actualitzar.
        */

        int nombreTransports(int distancia) const;
        /**<
        @brief Retorna la mida del vector transport de la distància entrada com a paràmetre.
        @return int
        @param distancia és un nombre que representa la distància que volem mirar.
        @pre
        -# 0<=distancia<this->size()
        @post
        -# Retorna la mida del vector transport de la distància entrada com a paràmetre.
        */

        NumPersonesTransport nombrePersonesPerTransport(int distancia) const;
        /**<
        @brief Retorna un objecte NumPersonesTransport amb una llista amb el nombre de persones de cada transport del vector transports
        i el seu respectiu nom, segons la distancia entrada per paràmetre.
        @return NumPersonesTransport
        @param distancia és un nombre que representa la distància que volem mirar.
        @pre
        -# 0<=distancia<this->size()
        @post
        -# retorna un objecte NumPersonesTransport amb una llista amb el nombre de persones de cada transport del vector transports
        i el seu respectiu nom, segons la distancia entrada per paràmetre.
        */

        MesRapids mesRapid() const;
        /**<
        @brief Retorna un objecte MesRapids amb un vector amb el nom i el temps promig de trajecte del transport més ràpid de cada distància.
        @return MesRapids
        @pre cert
        @post
        -# Retorna un objecte MesRapids amb un vector amb el nom i el temps promig de trajecte del transport més ràpid de cada distància.
        -# Si el vector transports d'alguna distància és buit, retornarà com a nom "--" i com a temps promig un valor brossa (1.79769e+308).
        */

        pair<string,double> trajecteMesLlarg() const;
        /**<
        @brief Retorna un pair<string, double> amb el nom i el temps del trajecte de més durada. Expressem el trajecte com la concatenació del nom de la comarca d’origen,
        un guionet, i el nom de la comarca destí.
        @return pair<string, double>
        @pre cert
        @post
        -# Retorna un pair<string, double> amb el nom i el temps del trajecte de més durada. Expressem el trajecte com la concatenació del nom de la comarca d’origen,
        un guionet, i el nom de la comarca destí.
        -# Si no s'han registrat trajectes, retornara com a nom "--" i 0.0 com a durada.
        */

        NousTrajectes trajectesNous();
        /**<
        @brief Retorna un objecte NousTrajectes amb els trajectes nous de la distància x (1-7) que no es troben en la distància [1,...,x-1].
        @return NousTrajectes
        @pre cert
        @post
        -# Retorna un objecte NousTrajectes amb els trajectes nous de la distància x (1-7) que no es troben en la distància [1,...,x-1].
        -# Si no s'han enregistrar trajectes, retornarà l'objecte buit.
        */

        pair<string, double> transportMesRapid(int km, string comarcaIn, string comarcaFi) const;
        /**<
        @brief Retorna un pair<string, double> que contindrà el nom del tipus de transport i el temps promig del tipus
        de transport més ràpid per realitzar un trajecte de km kilòmetres entre la comarcaIn i la comarcaFi.
        @return pair<string, double>
        @param km és un nombre que representa els kilòmetres del trajecte, comarcaIn i comarcaFi són strings que representen la comarca d'origen i la de destí del trajecte, respectivament.
        @pre
        -# km>=0
        @post
        -# retorna un pair<string, double> que contindrà el nom del tipus de transport i el temps promig del tipus
        de transport més ràpid per realitzar un trajecte de km kilòmetres entre la comarcaIn i la comarcaFi.
        -# Altrament, retornarà com a nom "--" i 1.79769e+308 com a temps promig
        */

        vector<double> tempsHores(int km, string comarcaIn, string comarcaFi, string transport) const;
        /**<
        @brief Retorna un vector<double> amb el temps promig a les diferents hores del dia (0..23) necessari per fer un
        trajecte entre comarcaIn i comarcaFi, d’una distància km i amb un tipus transport determinats.
        @return vector<double>
        @param km és un nombre que representa els kilòmetres del trajecte, comarcaIn i comarcaFi són strings que representen la comarca d'origen i la de destí del trajecte, respectivament.
        transport és un string que representa el transport del qual es vol mirar els trajectes.
        @pre
        -# km>=0
        @post
        -# Retorna un vector<double> amb el temps promig a les diferents hores del dia (0..23) necessari per fer un
        trajecte entre comarcaIn i comarcaFi, d’una distància km i amb un tipus transport determinats.
        */

        pair<string, double> transportMesRapidHora(int km, int hora, string comarcaIn, string comarcaFi) const;
        /**<
        @brief Retorna un pair<string, double> que contindrà el tipus de transport més ràpid i el temps promig per fer
        un trajecte entre comarcaIn i comarcaFi, d’una distància km i hora (0..23) determinats.
        @return pair<string, double>
        @param km és un nombre que representa els kilòmetres del trajecte, hora és un nombre que representa l'hora del trajecte,
        comarcaIn i comarcaFi són strings que representen la comarca d'origen i la de destí del trajecte, respectivament.
        @pre
        -# km>=0 i 0<=hora<=23
        @post
        -# Retorna un pair<string, double> que contindrà el tipus de transport més ràpid i el temps promig per fer
        un trajecte entre comarcaIn i comarcaFi, d’una distància km i hora (0..23) determinats.
        */

        MesOptim transportOptim(int km, string comarcaIn, string comarcaFi) const;
        /**<
        @brief Retorna un objecte MesOptim que contindrà el tipus de transport, l’hora i el temps promig per fer un trajecte
        entre comarcaIn i comarcaFi, d’una distància donada (km), el més ràpid possible.
        @return MesOptim
        @param km és un nombre que representa els kilòmetres del trajecte, comarcaIn i comarcaFi són strings que representen la comarca d'origen i la de destí del trajecte, respectivament.
        @pre
        -# km>=0
        @post
        -# Retorna un objecte MesOptim que contindrà el tipus de transport, l’hora i el temps promig per fer un trajecte
        entre comarcaIn i comarcaFi, d’una distància donada (km), el més ràpid possible.
        */

        TempsPerNivellEstudis tempsPerEstudi() const;
        /**<
        @brief Retorna un objecte TempsPerNivellEstudis que contindrà el temps mitjà de desplaçament per nivell d’estudis.
        @return TempsPerNivellEstudis
        @pre cert
        @post
        -# Retorna un objecte TempsPerNivellEstudis que contindrà el temps mitjà de desplaçament per nivell d’estudis.
        */

        int nombreTrajectes(string tipusTrajecte) const;
        /**<
        @brief Retorna un int amb el nombre de persones que fan trajectes d’un tipus donat (per anar a treballar, al domicili, al cinema,...).
        @return int
        @param tipusTrajecte és un string que representa el tipus de trajecte dels trajectes que volem comptar
        @pre cert
        @post
        -# Retorna un int amb el nombre de persones que fan trajectes d’un tipus donat (per anar a treballar, al domicili, al cinema,...).
        */

        int xinoXano() const;
        /**<
        @brief Retorna un int amb els minuts que triga la persona que camina més estona per anar a treballar (transport Peu >5 minuts).
        @return int
        @pre cert
        @post
        -# Retorna un int amb els minuts que tarda la persona que camina més estona per anar a treballar (transport Peu >5 minuts).
        -# Si no hi ha trajectes, retorna 0.
        */

    private:
        void guardarDades(int id, int ordre, int distancia, string tipusTrajecte, int horaIn, int durada, string comarcaIn, string comarcaFi, string mitjaPrincipal, int edat, string estudis);
        /**<
        @brief Guarda al vector distancies tots els transports, amb els seus respectius trajectes, a la posició que pertoqui segons el paràmetre distàncies i actualitza les diferents
        dades precalculades en aquest mètode.
        @return void
        @param id és un nombre que representa l'id de la persona, ordre és un nombre que representa l'ordre que pertany al trajecte segons els trajectes que ha fet la persona,
        distancia és un nombre que representa la distància a la qual pertany el trajecte, tipusTrajecte és un string que representa el tipus del trajecte, horaIn representa l'hora
        en que s'ha començat a fer el trajecte, durada és un nombre que representa la durada del trajecte, comarcaIn i comarcaFi són strings que representen la comarca d'origen i de destí
        del trajecte, mitjaPrincipal és un string que representa el mitjà principal que s'utilitza en el trajecte, edat és un nombre que representa l'edat de la persona que ha fet el trajecte
        i estudis és un string que representa el nivell d'estudis de la persona que fa el trajecte.
        @pre
        -# 0<=distancia<this->size(), durada>=0, edat>=0, ordre>=1, 0<=horaIn<=23
        @post
        -# Guarda al vector distancies tots els transports, amb els seus respectius trajectes, a la posició que pertoqui segons el paràmetre distàncies.
        */

        int obtenirDistancia(int km) const;
        /**<
        @brief Retorna la distància que correspon als kilometres passats per paràmetre.
        @return int
        @pre
        -# km>=0
        @post
        -# Retorna la distància que correspon als kilometres passats per paràmetre.
        */

        vector<Distancia> distancies;
        pair<string, double> trajecteLlarg{"--",0.0};
        NousTrajectes nous_trajectes;
        int xinoxano; /*Precalculo això perquè sinó hauria de recòrrer totes les persones i tots els trajectes cada cop que es cridés el mètode NousTrajectes i això faria que fos lineal sobre el temps.
        D'aquesta manera, m'estalvio un temps significatiu*/
};


#endif //MOBILITAT_H
