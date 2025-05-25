#include "derivation_page.h"
extern "C" float derivative_of_fx(float x);

DerivationPage::DerivationPage(Responder * parent)
  : ViewController(parent) {}

DerivationPage * DerivationPage::sharedPage() {
  static DerivationPage page(Responder::sharedResponder());
  return &page;
}

View * DerivationPage::view() { return this; }

void DerivationPage::drawRect(KDContext * ctx, KDRect) const {
  float x = 2.0f;
  float d = derivative_of_fx(x);
  char buffer[64];
  ctx->drawString("f(x)=x^2+3x+1", KDPoint(10, 10));
  snprintf(buffer, sizeof(buffer), "f'(%.1f)≈%.3f", x, d);
  ctx->drawString(buffer, KDPoint(10, 30));
}
