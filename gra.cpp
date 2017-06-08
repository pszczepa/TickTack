#include <cmath>

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


bool Gra::SprawdzCzyWygrana()
{
  int suma = 0;
  //Poziome

  for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 3; ++j)
      {
        suma += _plansza[i][j];
      }

    if(suma == 3 || suma == -3)
      {
        _ktoWygral = true;
        return true;
      }
    else
    {
     suma = 0;
    }
  }

  //Pionowe

 for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 3; ++j)
      {
        suma += _plansza[j][i];
      }

    if(suma == 3 || suma == -3)
      {
        _ktoWygral = true;
        return true;
      }
    else
     {
       suma = 0;
     }
  }



  //Skosne
  for(int i = 0; i < 3; ++i)
  {
   suma += _plansza[i][i];
  }
  if(suma == 3 || suma == -3)
  {
    _ktoWygral = true;
    return true;
  }

  suma = 0;

   int j = 2;
  for(int i = 0; i < 3; ++i)
    {
      suma = _plansza[i][j];
      --j;
    }


  if(suma == 3 || suma == -3)
  {
    _ktoWygral = true;
    return true;
  }

  return false;
}




int Gra::ReturnPoziom()
{
  return _poziomTrudnosci;
}

