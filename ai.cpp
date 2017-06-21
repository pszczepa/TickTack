#include "ai.hh"

AI::AI()
{

}

void AI::UstawPoziomTrudnosci(int poziom)
{
  _poziomTrudnosci = poziom;
}

AiRuch AI::MinMax(Gra & gra, int gracz)
{ 
  AiRuch ruch;
  AiRuch temp;
  int wynik_gry;
  std::vector<AiRuch> v_ruch;

  int najlepszyRuch  = 0;
  int najlepszyWynik = 0;

  gra.SprawdzCzyWygrana();
  wynik_gry = gra.ZwrocWynik();


  if(wynik_gry == gra._GRACZ2_AI)
    {
      temp.wynik = 10;
      return temp;
    }
  else if(wynik_gry  == gra._GRACZ1)
    {
      temp.wynik = -10;
      return temp;
    }
  else if(wynik_gry  == gra._PUSTE)
   {
      temp.wynik = 0;
      return temp;
    }


    for(int x = 0; x < 3; ++x)
      {
        for(int y = 0; y < 3; ++y)
          {
            if(gra.ReturnPlansza(x,y) == gra._PUSTE)
              {
                ruch.x = x;
                ruch.y = y;

                gra.Wypelnij(x,y,gracz);
                if(gracz == gra._GRACZ2_AI)
                  {
                     ruch.wynik = MinMax(gra, gra._GRACZ1).wynik;

                  }
                else
                  {
                    ruch.wynik = MinMax(gra, gra._GRACZ2_AI).wynik;

                  }


                v_ruch.push_back(ruch);
                gra.Wypelnij(x,y,gra._PUSTE);
              }
          }
      }

    if(gracz == gra._GRACZ2_AI)
      {
        najlepszyWynik = -100000;
        for(int i = 0; i < v_ruch.size(); ++i)
          {
            if(v_ruch.at(i).wynik > najlepszyWynik)
              {
                najlepszyRuch = i;
                najlepszyWynik = v_ruch.at(i).wynik;
              }
          }
      }
    else
      {
        najlepszyWynik = 100000;
        for(int i = 0; i < v_ruch.size(); ++i)
          {
            if(v_ruch.at(i).wynik < najlepszyWynik)
              {
                najlepszyRuch = i;
                najlepszyWynik = v_ruch.at(i).wynik;
              }
          }
      }

return v_ruch.at(najlepszyRuch);
}


void AI::MinMaxRuch(Gra & gra)
{
    AiRuch ruch = MinMax(gra, gra._GRACZ2_AI);

    std::cout<<"Wpisywanie z MinMax : "<<ruch.x<<":"<<ruch.y<<std::endl;
    gra.Wypelnij(ruch.x,ruch.y, gra._GRACZ2_AI);
}


int AI::AiRand(Gra & gra)
{
  int x,y;
  bool czyWpisano = false;

  std::srand(std::time(NULL));

  do
  {
  x = (std::rand()%3) + 0;
  y = (std::rand()%3) + 0;

  std::cout<<"AiRand: "<<x<<" : " <<y<< std::endl;

  czyWpisano = gra.Wypelnij(x,y);


  }while(!czyWpisano);

  return MatrixToInt(x,y);

}

int AI::WykonajRuch(Gra & gra)
{
  int gdzieWpisano;

  switch (_poziomTrudnosci)
    {
      case 0:
      {
        std::cout<<"Izi"<<std::endl;
        gdzieWpisano = AiRand(gra);
        break;
      }

      case 1:
      {
        std::cout<<"Trudniej"<<std::endl;
        MinMaxRuch(gra);

        break;
      }


      default:
      break;
    }

  return gdzieWpisano;
}

int AI::MatrixToInt(int x, int y)
{
 int trans[3][3] = {{0,1,2},
                   {3,4,5},
                   {6,7,8}};

 return trans[x][y];

}

