#ifndef VIEW_H
#define VIEW_H

#include <stategraph.h>

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>


namespace Ui {
class View;
}

class View : public QWidget
{
    Q_OBJECT

public:
    View(StateGraph*);
    ~View();
    void paint(StateGraph*);

protected:
    void paintEvent (QPaintEvent *event);
    void keyPressEvent (QKeyEvent *event);

private:
    Ui::View *ui;
    StateGraph *g;
};

#endif // VIEW_H
