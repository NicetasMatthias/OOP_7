#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <stategraph.h>
#include <view.h>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT

public:
    StateGraph g;
    View *v;

    Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_pushButton_file_clicked();

    void on_pushButton_view_clicked();

private:
    Ui::Interface *ui;
};
#endif // INTERFACE_H
