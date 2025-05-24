#include <escher.h>
#include <cmath>
#include <string.h>

class MiniMathsController : public ViewController, public ListViewDataSource {
public:
  MiniMathsController(Responder * parentResponder) : ViewController(parentResponder), m_selectableListView(this, this, this) {
    m_selectableListView.setMargins(Metric::CommonTopMargin, Metric::CommonTopMargin);
  }

  View * view() override { return &m_selectableListView; }
  const char * title() override { return "MiniMaths"; }

  void didBecomeFirstResponder() override {
    Container::activeApp()->setFirstResponder(&m_selectableListView);
  }

  int numberOfRows() override { return kNumberOfMenuItems; }
  KDCoordinate rowHeight(int j) override { return Metric::ParameterCellHeight; }
  HighlightCell * reusableCell(int index, int type) override { return &m_cells[index]; }
  int reusableCellCount(int type) override { return kNumberOfMenuItems; }

  void willDisplayCellForIndex(HighlightCell * cell, int index) override {
    static constexpr const char * labels[kNumberOfMenuItems] = {
      "1. Nombres complexes",
      "2. Dérivation",
      "3. Pourcentages",
      "4. Suites",
      "5. Trigo (cours)"
    };
    MessageTableCell * myCell = static_cast<MessageTableCell *>(cell);
    myCell->setMessage(I18n::Message::Default);
    myCell->setAccessoryText(labels[index]);
  }

  void tableViewDidSelectRow(SelectableTableView * t, int selectedRow) override {
    const char * messages[] = {
      "z = a + bi\n|z| = sqrt(a^2 + b^2)\nz̄ = a - bi",
      "f(x) = x^2 + 3x + 1\nf'(x) ≈ (f(x+h)-f(x))/h",
      "Valeur x (taux %) : x * (t/100)",
      "Arithmétique : u0 + n*r\nGéométrique : u0*q^n",
      "Trigonométrie :\nAngles rem. : 30°, 45°, ..."
    };
    const char * msg = messages[selectedRow];
    App::app()->displayModalText(msg);
  }

private:
  constexpr static int kNumberOfMenuItems = 5;
  MessageTableCell m_cells[kNumberOfMenuItems];
  SelectableTableView m_selectableListView;
};

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
