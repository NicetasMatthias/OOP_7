#include "stategraph.h"

StateGraph::StateGraph()
{
    m = nullptr;
    ready = false;
}

StateGraph::~StateGraph()
{
    delete_m();
}

int StateGraph::create_m(unsigned int l,unsigned int c)
{
    if ((l<=0)||(c<=0)||(c>10))
    {
        return -1;
    }
    else
    {
        m = new Matrix(l,c);
        curr_str = 0;
        ready = false;
        return 0;
    }
}

void StateGraph::reset_active_node()
{
    active_node = 0;
}

qint16 StateGraph::get_active_node()
{
    return active_node;
}

int StateGraph::emit_event(qint16 ev)
{
    ev--;
    if ((ev<0)||(ev>=m->get_columns()))
    {
        return EMIT_INVALID_EVENT;
    }
    else if (active_node==m->get_data()[active_node][ev])
    {
        return EMIT_IDLE;
    }
    else
    {
        active_node=m->get_data()[active_node][ev];
        return EMIT_SUCCESS;
    }
}
