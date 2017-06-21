#ifndef AI_HH
#define AI_HH

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>

#include "gra.h"
#include "airuch.hh"

class AI
{
  int _poziomTrudnosci;

public:
  AI();

  void UstawPoziomTrudnosci(int);

  AiRuch MinMax(Gra &, int);
  int AiRand(Gra & );

  void MinMaxRuch(Gra &);

  int WykonajRuch(Gra &);

  int MatrixToInt(int, int);



};

#endif // AI_HH
