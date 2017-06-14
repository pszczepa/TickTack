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

int Gra::ZwrocWynik()
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
      if(ZwrocTure())
        {
          _plansza[x][y] = _KRZYZYK;
        }
      else if(!ZwrocTure() && ReturnPvC())
        {
          _plansza[x][y] = _KOLKO;
        }
      else if(!ZwrocTure() && !ReturnPvC())
        {
          std::cout<<"Komputer"<<std::endl;
        }
    }

  return true;
}


bool Gra::SprawdzCzyWygrana()
{
  int suma = 0;

  bool wygrana = false;

  //Poziome
  if(!wygrana)
    {
      for(int i = 0; i < 3; ++i)
      {
        for(int j = 0; j < 3; ++j)
          {
            suma += _plansza[i][j];
          }

        if(std::abs(suma) == 3)
          {
            wygrana =  true;
          }
        else
        {
         suma = 0;
        }
      }
    }
  //Pionowe
 if(!wygrana)
    {
     for(int i = 0; i < 3; ++i)
      {
        for(int j = 0; j < 3; ++j)
          {
            suma += _plansza[j][i];
          }

        if(std::abs(suma) == 3)
          {
            wygrana = true;
          }
        else
         {
           suma = 0;
         }
       }
   }
  //Skosne
 if(!wygrana)
   {
    for(int i = 0; i < 3; ++i)
    {
     suma += _plansza[i][i];
    }
    if(std::abs(suma) == 3)
    {

      wygrana = true;
    }
    else
      {
        suma = 0;
      }

   }

  if(!wygrana)
    {
     for(int i = 0; i < 3; ++i)
      {
        suma += _plansza[i][2-i];
      }
    }

  if(std::abs(suma) == 3)
  {
      wygrana = true;
  }

  if(suma == _KOLKO * 3 )
    {
       _ktoWygral = _KOLKO;
    }
  else if(suma == _KRZYZYK * 3)
    {
        _ktoWygral = _KRZYZYK;
    }

  if(wygrana)
    {
      std::cout<<"Wygrana"<<std::endl;
    }

  return wygrana;
}

int Gra::ReturnPoziom()
{
  return _poziomTrudnosci;
}

bool Gra::ReturnPvC()
{
  return _czyPvC;
}

void Gra::DrukujPlansze()
{
  for(int i = 0; i < 3; ++i)
    {
      for(int j = 0; j < 3; ++j)
        {
          std::cout<<"["<<ReturnPlansza(i,j)<<"]";
        }
  std::cout<<std::endl;
    }

  std::cout<<"====================="<<std::endl;

}


int Gra::ReturnPlansza(int x, int y)
{
  return _plansza[x][y];
}

void Gra::UstawPvC(bool pvc)
{
   _czyPvC = pvc;
}
