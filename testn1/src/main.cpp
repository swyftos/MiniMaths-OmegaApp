#include "controller.h"

class MiniMathsApp : public ::App {
public:
  MiniMathsApp(Container * container) : ::App(container, &m_controller) {}
  ViewController * rootViewController() override { return &m_controller; }
private:
  MiniMathsController m_controller;
};

App * miniMathsAppCreator(Container * container) {
  return new MiniMathsApp(container);
}
