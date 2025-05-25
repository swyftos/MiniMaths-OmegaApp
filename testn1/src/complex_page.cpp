#include "complex_page.h"
extern "C" {
  #include "maths_lib.c"
}

ComplexPage::ComplexPage(Responder * parent)
  : ViewController(parent) {}

ComplexPage * ComplexPage::sharedPage() {
  static ComplexPage page(Responder::sharedResponder());
  return &page;
}

View * ComplexPage::view() { return this; }

void ComplexPage::drawRect(KDContext * ctx, KDRect) const {
  float a = 3.0f, b = -2.0f;
  float mod = sqrt_complex(a, b);
  char buffer[64];
  ctx->drawString("z = 3 - 2i", KDPoint(10, 10));
  snprintf(buffer, sizeof(buffer), "|z| = %.2f", mod);
  ctx->drawString(buffer, KDPoint(10, 30));
}
