#ifndef MINI_MATHS_CONTROLLER_H
#define MINI_MATHS_CONTROLLER_H

#include <escher.h>

class MiniMathsController : public ViewController, public ListViewDataSource {
public:
  MiniMathsController(Responder * parentResponder);
  View * view() override;
  const char * title() override;
  void didBecomeFirstResponder() override;
  int numberOfRows() override;
  KDCoordinate rowHeight(int j) override;
  HighlightCell * reusableCell(int index, int type) override;
  int reusableCellCount(int type) override;
  void willDisplayCellForIndex(HighlightCell * cell, int index) override;
  void tableViewDidSelectRow(SelectableTableView * t, int selectedRow) override;
private:
  static constexpr int kNumberOfMenuItems = 5;
  MessageTableCell m_cells[kNumberOfMenuItems];
  SelectableTableView m_listView;
};

#endif
