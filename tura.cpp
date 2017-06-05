#include "tura.h"

Tura::Tura()
{}

void Tura::ZamienTure()
{
    _turaGracza = !_turaGracza;
}

bool Tura::ZwrocTure()
{
    return _turaGracza;
}

