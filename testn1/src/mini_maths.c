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

void extapp_main(void) {
  float module = sqrt_complex(3.0f, -2.0f);
  float derivee = derivative_of_fx(2.0f);
  (void)module;   // silence unused-variable
  (void)derivee;  // idem

  extapp_clear();
  extapp_drawPixel(10, 10, 1);
  extapp_msleep(3000);
}

