#include "list.h"
template <typename T>
void List<T>::reverse(){//前后倒置
    if (_size < 2) return;
    for (Posi(T) p = header; p; p = p->succ){
        swap(p->succ, p->pred);//交换各节点的前驱后继
    }
    swap(header, trailer);
}