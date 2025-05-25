#ifndef DERIVATION_PAGE_H
#define DERIVATION_PAGE_H

#include <escher.h>

class DerivationPage : public ViewController {
public:
  static DerivationPage * sharedPage();
  View * view() override;
  const char * title() override { return "Dérivation"; }
  bool handleEvent(Ion::Events::Event e) override {
    if (e == Ion::Events::Back) { stackView()->pop(); return true; }
    return false;
  }
private:
  DerivationPage(Responder * parent);
  void drawRect(KDContext * ctx, KDRect rect) const override;
};

#endif
