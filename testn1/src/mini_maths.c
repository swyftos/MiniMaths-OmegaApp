#ifndef DEVICE
// Sur simulateur Linux, on stubbe l’API des ext-apps  
void extapp_clear(void) { }
void extapp_drawPixel(int x, int y, int on) { }
// Ajustement : uint32_t pour coller au prototype officiel
#include <stdint.h>
void extapp_msleep(uint32_t ms) { }
#endif

#include <extapp_api.h>
#include <math.h>

// --- tes fonctions mathématiques ici ---

void extapp_main(void) {
  float module = sqrt_complex(3.0f, -2.0f);
  float derivee = derivative_of_fx(2.0f);
  (void)module;
  (void)derivee;

  extapp_clear();
  extapp_drawPixel(10, 10, 1);
  extapp_msleep(3000);
}
