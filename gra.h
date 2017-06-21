#ifndef GRA_H
#define GRA_H

#include <iostream>

#include "tura.h"
#include "przyciski.h"


class Gra : public Tura, public Przyciski
{
public:

  const int _KOLKO    = 1;
  const int _KRZYZYK  = -1;
  const int _PUSTE    = 0;

  const int _GRACZ1    = _KRZYZYK;
  const int _GRACZ2_AI = _KOLKO;

private:

    bool _czyStart;

    bool _czyKoniec;

    int  _ktoWygral;

    bool _czyPvC;

    int  _plansza[3][3];

    int _iloscRuchow;

public:

    Gra();

    void UstawPoziomTrudnosci(int const);

    void RozpocznijGre();

    void ZakonczGre();

    bool ZwrocKoniec();

    int  ZwrocWynik();

    bool Wypelnij(int const , int const);

    void Wypelnij(int const, int const , int);

    bool SprawdzCzyWygrana();

    bool ZwrocPvC();

    void DrukujPlansze();

    int  ReturnPlansza(int, int);

    void UstawPvC(bool);

    void PlusIloscRuchow();

    int ZwrocIloscRuchow();

    void Zeruj();


};

#endif // GRA_H
