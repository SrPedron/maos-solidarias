#include "App.h"

int main() // programa principal
{
  setlocale(LC_ALL, "portuguese");// biblioteca para caracteres especiais
  App myApp;

  myApp.start();
  myApp.Finish();

  return 0;
}
