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

  void MinMax(Gra * );
  void AiRand(Gra * );

  void WykonajRuch(Gra *);

};

#endif // AI_HH
