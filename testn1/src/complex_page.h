#ifndef COMPLEX_PAGE_H
#define COMPLEX_PAGE_H

#include <escher.h>

class ComplexPage : public ViewController {
public:
  static ComplexPage * sharedPage();
  View * view() override;
  const char * title() override { return "Complexes"; }
  bool handleEvent(Ion::Events::Event e) override {
    if (e == Ion::Events::Back) { stackView()->pop(); return true; }
    return false;
  }
private:
  ComplexPage(Responder * parent);
  void drawRect(KDContext * ctx, KDRect rect) const override;
};

#endif
