#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>

class Matrix
{
private:
    QVector < QVector<qint16> > data;
    unsigned int lines;
    unsigned int columns;
public:
    Matrix(unsigned int,unsigned int);
    ~Matrix();
    unsigned int get_lines();
    unsigned int get_columns();
    QVector < QVector<qint16> >  get_data();
    void set_data(unsigned int,unsigned int,qint16);
};

#endif // MATRIX_H
