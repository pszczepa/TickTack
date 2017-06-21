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

    _iloscRuchow = 0;

}

void Gra::RozpocznijGre()
{
    _czyStart  = true;

    _czyKoniec = false;

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

bool Gra::ZwrocKoniec()
{
  return _czyKoniec;
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
      else if(!ZwrocTure() && ZwrocPvC())
        {
          _plansza[x][y] = _KOLKO;
        }
      else if(!ZwrocTure() && !ZwrocPvC())
        {
          _plansza[x][y] = _KOLKO;
          std::cout<<"Komputer"<<std::endl;
        }
    }

  return true;
}


void Gra::Wypelnij(const int x, const int y, int wartosc)
{
  _plansza[x][y] = wartosc;
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

     if(std::abs(suma) == 3)
     {
         wygrana = true;
     }
    }



  if(wygrana)
    {
      std::cout<<"Wygrana"<<std::endl;
      if(suma == _KOLKO * 3 )
        {
           _ktoWygral = _KOLKO;
        }
      else if(suma == _KRZYZYK * 3)
        {
            _ktoWygral = _KRZYZYK;
        }
    }


  return wygrana;
}


bool Gra::ZwrocPvC()
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

void Gra::PlusIloscRuchow()
{
  ++_iloscRuchow;
}

int Gra::ZwrocIloscRuchow()
{
  return _iloscRuchow;
}
