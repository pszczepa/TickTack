#ifndef AI_HH
#define AI_HH

#include <iostream>
#include <ctime>
#include <cmath>

#include "gra.h"

class AI
{
  int _poziomTrudnosci;

public:
  AI();

  void UstawPoziomTrudnosci(int);

  int MinMax(Gra * );
  int AiRand(Gra * );

  int WykonajRuch(Gra *);

  int MatrixToInt(int, int);


};

#endif // AI_HH
