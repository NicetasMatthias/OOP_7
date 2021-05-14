#include "graph.h"
#include <QDebug>

Graph::Graph()
{
    m = nullptr;
    ready = false;
}

Graph::~Graph()
{
    if (m != nullptr) delete m;
}

bool Graph::is_ready()
{
    return ready;
}

int Graph::create_m(unsigned int l,unsigned int c)
{
    m = new Matrix(l,c);
    curr_str = 0;
    ready = false;
    return 0;
}

void Graph::delete_m()
{
    if (m != nullptr) delete m;
    ready = false;
}

int Graph::add_m_line(QString inp)
{
    int tmp;
    if (ready)
    {
        qDebug() << "Ошибка: слишком много строк в файле";
        return TOO_MANY_LINES;
    }
    QStringList list = inp.split(" ");
    if (list.size()!=m->get_columns())
    {
        qDebug() << "Ошибка: неверное количество чисел в строке: " << list.size();
        return INVALID_NUM_OF_COLUMNS;
    }
    for (size_t i = 0; i < list.size(); i++)
    {
        tmp=list[i].toInt();
        if ((tmp < 0)||(tmp>=m->get_lines()))
        {
            qDebug() << "Ошибка: неправильные числа в матрице";
            return INVALID_ARGS;
        }
        else
        {
            m->set_data(curr_str,i,tmp);
        }
    }
    curr_str++;
    if (curr_str==m->get_lines()) ready = true;
    return SUCCESS;
}



unsigned int Graph::get_m_lines()
{
    return m->get_lines();
}

unsigned int Graph::get_m_columns()
{
    return m->get_columns();
}
QVector < QVector<qint16> > Graph::get_matrix()
{
    return m->get_data();
}
