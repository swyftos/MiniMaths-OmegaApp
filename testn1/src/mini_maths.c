#ifndef DEVICE
// sur simulateur Linux, on stubbe extapp_API  
void extapp_clear(void) { }
void extapp_drawPixel(int x, int y, int on) { }
void extapp_msleep(int ms) { }
#endif

#include <extapp_api.h>
#include <math.h>
// … le reste de mini_maths.c …


// Calcul du module d'un complexe
float sqrt_complex(float a, float b) {
  return sqrtf(a*a + b*b);
}

// Dérivée approchée de f(x)=x^2+3x+1
float derivative_of_fx(float x) {
  float h = 0.001f;
  float f1 = x*x + 3*x + 1;
  float f2 = (x+h)*(x+h) + 3*(x+h) + 1;
  return (f2 - f1) / h;
}

// Entrée de l'ext-app — c'est obligatoire !
void extapp_main(void) {
  // Exemple d'utilisation de tes fonctions
  float module = sqrt_complex(3.0f, -2.0f);
  float derivee = derivative_of_fx(2.0f);

  // On peut juste effacer l'écran et afficher un pixel pour tester
  extapp_clear();
  // pixel en (10,10) => présence de l'app
  extapp_drawPixel(10, 10, 1);
  // on garde l'affichage 10 secondes
  extapp_msleep(10000);
}
