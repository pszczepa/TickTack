#include "ai.hh"

AI::AI()
{

}

void AI::UstawPoziomTrudnosci(int poziom)
{
  _poziomTrudnosci = poziom;
}

int AI::MinMax(Gra * gra)
{
// minmax
  return -1;
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

      }


      default:
      break;
    }

  return gdzieWpisano;
}

int AI::MatrixToInt(int x, int y)
{
 int trans[3][3] = {{1,2,3},
                   {4,5,6},
                   {7,8,9}};

 return trans[x][y];

}

