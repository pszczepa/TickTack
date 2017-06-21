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
  gra.DrukujPlansze();

  AiRuch ruch;
  AiRuch temp;

  int wynik_gry;
  std::vector<AiRuch> v_ruch;

  int najlepszyRuch  = 0;
  int najlepszyWynik = 0;


  gra.SprawdzCzyWygrana();
  wynik_gry = gra.ZwrocWynik();

  if(wynik_gry == -1)
    {
      temp.wynik = 10;
      std::cout<<"Zwracam1"<<std::endl;
      return temp;
    }
  else if(wynik_gry  == 1)
    {
      temp.wynik = -10;
      std::cout<<"Zwracam2"<<std::endl;
      return temp;
    }
  else if(wynik_gry  == 0)
   {
      temp.wynik = 0;
      std::cout<<"Zwracam3"<<std::endl;
      return temp;
    }


    for(int y = 0; y < 3 ; ++y)
      {
        for(int x = 0; x < 3; ++x)
          {
            if(gra.ReturnPlansza(x,y) == 0)
              {
                ruch.x = x;
                ruch.y = y;

                gra.Wypelnij(x,y,gracz);

                if(gracz == -1)
                  {
                    ruch.wynik = MinMax(gra, 1).wynik;
                  }
                else
                  {
                    ruch.wynik = MinMax(gra, -1).wynik;
                  }

                v_ruch.push_back(ruch);

                gra.Wypelnij(x,y,0);

              }
          }
      }


    if(gracz == -1)
      {
        najlepszyWynik = -1000000;
        for(unsigned int i = 0; i < v_ruch.size(); i++)
          {
            if(v_ruch[i].wynik > najlepszyWynik)
              {
                najlepszyRuch = i;
                najlepszyWynik = v_ruch.at(i).wynik;
              }
          }
      }
    else
      {
        najlepszyWynik = 1000000;
        for(unsigned int i = 0; i < v_ruch.size(); i++)
          {
            if(v_ruch[i].wynik < najlepszyWynik)
              {
                najlepszyRuch = i;
                najlepszyWynik = v_ruch.at(i).wynik;
              }
          }
      }

    std::cout<<"Najlepszy ruch: " << najlepszyRuch << std::endl;

    for(size_t it = 0; it < v_ruch.size(); ++it)
      {
        std::cout<<v_ruch.at(it).x<<" "<<v_ruch.at(it).y<<" "<< v_ruch.at(it).wynik<<std::endl;
      }



return v_ruch[najlepszyRuch];
}


void AI::MinMaxRuch(Gra & gra)
{
    AiRuch ruch = MinMax(gra, -1);

    if(ruch.x > 2 || ruch.x < 0 || ruch.y  > 2 || ruch.y < 0 )
      {
        std::cout<<"ERRROR"<<std::endl;
      }

    std::cout<<"Wpisywanie z MinMax : "<<ruch.x<<":"<<ruch.y<<std::endl;
    gra.Wypelnij(ruch.x,ruch.y, -1);
    gra.Zeruj();
}


int AI::AiRand(Gra * gra)
{
  int x,y;
  bool czyWpisano = false;

  std::srand(std::time(NULL));

  do
  {
  x = (std::rand()%3) + 0;
  y = (std::rand()%3) + 0;

  std::cout<<"AiRand: "<<x<<" : " <<y<< std::endl;

  czyWpisano = gra->Wypelnij(x,y);


  }while(!czyWpisano);

  return MatrixToInt(x,y);

}

int AI::WykonajRuch(Gra * gra)
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
        MinMaxRuch(*gra);

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

