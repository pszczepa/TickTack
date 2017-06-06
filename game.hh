#ifndef GAME_HH
#define GAME_HH

#include <QObject>
#include <tura.h>
#include <przyciski.h>

class Game : public QObject
{
  Q_OBJECT
public:
  explicit Game(QObject *parent = nullptr);

signals:

public slots:


private:

  Tura      _tura_gry;

  Przyciski _grafika_przyciskow;


};

#endif // GAME_HH
