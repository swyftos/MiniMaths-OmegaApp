#ifndef DEVICE
// Sur simulateur Linux, on stubbe l’API des ext-apps  
#include <stdint.h>              // pour uint32_t
void extapp_clear(void) { }
void extapp_drawPixel(int x, int y, int on) { }
// Prototype exact de l’API extapp_api.h
void extapp_msleep(uint32_t ms) { }
#endif

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

void extapp_main(void) {
  float module = sqrt_complex(3.0f, -2.0f);
  float derivee = derivative_of_fx(2.0f);
  (void)module;   // évite le warning « unused-variable »
  (void)derivee;  // idem

  extapp_clear();
  extapp_drawPixel(10, 10, 1);
  extapp_msleep(3000);
}
