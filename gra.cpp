#include "gra.h"

Gra::Gra()
{
    for(auto i = 0; i < 3; ++i)
    {
        for(auto j = 0; j < 3; ++j)
        {
            _plansza[i][j] = _PUSTE;
        }
    }

}

void Gra::UstawPoziomTrudnosci(int poziom)
{
   _poziomTrudnosci = poziom;
}

void Gra::RozpocznijGre(bool tryb)
{
    _czyStart  = true;

    _czyKoniec = false;

    _czyPvC    = tryb;
}

void Gra::ZakonczGre()
{
    _czyKoniec = true;
    _czyStart  = true;
}

bool Gra::ZwrocWynik()
{
    return _ktoWygral;
}

bool Gra::Wypelnij(int const x, int const y)
{
  if(_plansza[x][y] != _PUSTE)
    {
      return false;
    }
  else
    {
      if(_tura.ZwrocTure())
        {
          _plansza[x][y] = _KRZYZYK;
        }
    }

  return true;
}

int Gra::ReturnPoziom()
{
  return _poziomTrudnosci;
}
