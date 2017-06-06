#include "tura.h"

Tura::Tura()
{
  _turaGry = false;
}

void Tura::ZamienTure()
{
    _turaGry = !_turaGry;
}

bool Tura::ZwrocTure()
{
    return _turaGry;
}

