#include "tura.h"

Tura::Tura()
{
  _turaGracza = true;
}

void Tura::ZamienTure()
{
    _turaGracza = !_turaGracza;
}

bool Tura::ZwrocTure()
{
    return _turaGracza;
}

