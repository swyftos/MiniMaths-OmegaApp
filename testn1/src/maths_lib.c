#include <math.h>

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
