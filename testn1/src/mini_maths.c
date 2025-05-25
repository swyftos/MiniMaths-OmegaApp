#ifndef DEVICE
// Sur simulateur Linux, on stubbe l’API des ext-apps  
void extapp_clear(void) { }
void extapp_drawPixel(int x, int y, int on) { }
void extapp_msleep(int ms) { }
#endif

#include <extapp_api.h>
#include <math.h>

// --- Début fusion maths_lib.c ---
float sqrt_complex(float a, float b) {
  return sqrtf(a*a + b*b);
}
float derivative_of_fx(float x) {
  float h = 0.001f;
  float f1 = x*x + 3*x + 1;
  float f2 = (x+h)*(x+h) + 3*(x+h) + 1;
  return (f2 - f1) / h;
}
// --- Fin fusion ---

// Point d'entrée unique de l'ext-app
void extapp_main(void) {
  float module = sqrt_complex(3.0f, -2.0f);
  float derivee = derivative_of_fx(2.0f);

  extapp_clear();
  // Affiche un pixel pour indiquer que l'app tourne
  extapp_drawPixel(10, 10, 1);
  // Garde l'affichage 3 secondes
  extapp_msleep(3000);
}
