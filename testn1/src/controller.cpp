#include "controller.h"
#include "complex_page.h"
#include "derivation_page.h"

MiniMathsController::MiniMathsController(Responder * parentResponder)
  : ViewController(parentResponder),
    m_listView(this, this, this) {
  m_listView.setMargins(Metric::CommonTopMargin, Metric::CommonTopMargin);
}

View * MiniMathsController::view() { return &m_listView; }
const char * MiniMathsController::title() { return "MiniMaths"; }
void MiniMathsController::didBecomeFirstResponder() {
  Container::activeApp()->setFirstResponder(&m_listView);
}
int MiniMathsController::numberOfRows() { return kNumberOfMenuItems; }
KDCoordinate MiniMathsController::rowHeight(int) {
  return Metric::ParameterCellHeight;
}
HighlightCell * MiniMathsController::reusableCell(int index, int) {
  return &m_cells[index];
}
int MiniMathsController::reusableCellCount(int) {
  return kNumberOfMenuItems;
}
void MiniMathsController::willDisplayCellForIndex(HighlightCell * cell, int index) {
  static const char * labels[] = {
    "Nombres complexes",
    "Dérivation",
    "Pourcentages",
    "Suites",
    "Trigonométrie"
  };
  auto msgCell = static_cast<MessageTableCell *>(cell);
  msgCell->setMessage(I18n::Message::Default);
  msgCell->setAccessoryText(labels[index]);
}
void MiniMathsController::tableViewDidSelectRow(SelectableTableView *, int selectedRow) {
  switch (selectedRow) {
    case 0:
      Container::activeApp()->pushModalViewController(ComplexPage::sharedPage(), 0.0f, 0.0f);
      break;
    case 1:
      Container::activeApp()->pushModalViewController(DerivationPage::sharedPage(), 0.0f, 0.0f);
      break;
    // cases 2,3,4 à ajouter ultérieurement…
    default:
      break;
  }
}
