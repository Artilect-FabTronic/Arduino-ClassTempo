#ifndef _TEMPO_H  // si _TEMPO_H n'est pas défini
#define _TEMPO_H  // on le défini

// Cela permet d'éviter les multiples inclusion,
// en effet si le programme a déjà effectué cette partie du code,
// pas besoin de l'exécuter à nouveau !

/// Déclaration de la classe Tempo

class Tempo
{
  public:
    // Méthodes
    void begin(unsigned long interval);
    void setDuration(unsigned long interval);
    bool isTimeEnding();  // is time out ending

  private:
    // always prefix member variables with '_'
    unsigned long _previousMillis;  // store the last time (ms)
    unsigned long _interval;  // store the last time (ms)
};

#endif  // Fin si _TEMPO_H n'est pas défini
