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

void Gra::RozpocznijGre()
{
    _czyStart = true;

    _czyKoniec = false;
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

bool Gra::Wypelnij(int const nr_przycisku)
{
  int x = nr_przycisku / 3 ;
  int y = nr_przycisku - 6;



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
