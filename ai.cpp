#include "ai.hh"

AI::AI()
{

}

void AI::UstawPoziomTrudnosci(int poziom)
{
  _poziomTrudnosci = poziom;
}

void AI::MinMax(Gra * gra)
{
// minmax
}

void AI::AiRand(Gra * gra)
{
  int x,y;
  bool czyWpisano = false;

  std::srand(std::time(NULL));

  do
  {
  x = (std::rand()%2) + 0;
  y = (std::rand()%2) + 0;

  czyWpisano = gra->Wypelnij(x,y);

   }while(!czyWpisano);

}

void AI::WykonajRuch(Gra * gra)
{
  switch (_poziomTrudnosci)
    {
      case 0:
      {
        std::cout<<"Izi"<<std::endl;
        AiRand(gra);

      }


      default:
      break;
    }
}
