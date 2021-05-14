#include "matrix.h"

Matrix::Matrix(unsigned int l,unsigned int c)
{
    lines = l;
    columns = c;
    data.resize(lines);
    for (size_t i = 0; i < lines; i++)
    {
        data[i].resize(columns);
    }
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < data.size(); i++)
    {
        data[i].clear();
    }
    data.clear();
}

unsigned int Matrix::get_lines()
{
    return lines;
}
unsigned int Matrix::get_columns()
{
    return columns;
}

QVector < QVector<qint16> > Matrix::get_data()
{
    return data;
}

void Matrix::set_data(unsigned int l, unsigned int c, qint16 a)
{
    data[l][c]=a;
}
