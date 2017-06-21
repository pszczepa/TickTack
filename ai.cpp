#include "ai.hh"

AI::AI()
{

}

void AI::UstawPoziomTrudnosci(int poziom)
{
  _poziomTrudnosci = poziom;
}

AiRuch AI::MinMax(Gra * gra)
{ 
  AiRuch ruch;
  AiRuch temp;
  int gracz;
  int wynik;
  std::vector<AiRuch> v_ruch;
  int najlepszyRuch  = 0;
  int najlepszyWynik = 0;

    //gra->ZamienTure();

  std::cout<<"MinMax"<<std::endl;

  if(!gra->SprawdzCzyWygrana())

{
  wynik = gra->ZwrocWynik();

  if(gra->SprawdzCzyWygrana())
  {
    if(wynik == gra->_GRACZ1)
      {
          temp.wynik = 10;
          return temp;
      }
    else if (wynik == gra->_GRACZ2_AI)
      {
          temp.wynik = -10;
          return temp;
      }
     else if(wynik != gra->_GRACZ1 && wynik != gra->_GRACZ2_AI)
      {
          temp.wynik = 0;
          return temp;
      }
   }




  if(gra->ZwrocTure())
    {
      gracz = gra->_KOLKO;
    }
  else
    {
      gracz = gra->_KRZYZYK;
    }

  gra->DrukujPlansze();

  for(int i = 0; i < 3; ++i)
    {
      for(int j = 0; j < 3; ++j)
        {
          if(gra->ReturnPlansza(i,j) == 0)
            {
              std::cout<<"petla"<<std::endl;

              ruch.x = i;
              ruch.y = j;
              gra->Wypelnij(i,j, gracz);

              if(gracz == gra->_GRACZ1)
                {
                  temp = MinMax(gra);
                  ruch.wynik = temp.wynik;
                }
              else
                {
                  temp = MinMax(gra);
                  ruch.wynik = temp.wynik;
                }
              gra->ZamienTure();


              v_ruch.push_back(ruch);

              gra->Wypelnij(i,j,gra->_PUSTE);

            }


        }
    }

  std::cout<<"Rozmiar : " << v_ruch.size() << std::endl;

}
    if(gracz == gra->_GRACZ1)
      {
        najlepszyWynik = -100000;

        for(unsigned int i = 0; i < v_ruch.size() ; ++i)
          {
            if(v_ruch[i].wynik > najlepszyWynik)
              {
                najlepszyRuch  = i;
                najlepszyWynik = v_ruch.at(i).wynik;
              }
          }
      }
    else
      {
        najlepszyWynik = 100000;

        for(unsigned int i = 0; i < v_ruch.size(); ++i)
          {
            if(v_ruch.at(i).wynik < najlepszyWynik)
              {
                najlepszyRuch = i;
                najlepszyWynik = v_ruch.at(i).wynik;
              }
          }
      }



std::cout<<"Najlpeszy ruch : " << v_ruch.at(najlepszyRuch).x << v_ruch.at(najlepszyRuch).y << std::endl;

return v_ruch.at(najlepszyRuch);

}


void AI::MinMaxRuch(Gra * gra)
{
    AiRuch ruch = MinMax(gra);

    std::cout<<"Wpisywanie z MM : "<<ruch.x<<":"<<ruch.y<<std::endl;
    gra->Wypelnij(ruch.x,ruch.y, gra->_GRACZ2_AI);
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

