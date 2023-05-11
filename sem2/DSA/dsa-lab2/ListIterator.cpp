#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	//TODO - Implementation
    current=list.prim;
}

void ListIterator::first(){
	//TODO - Implementation
    current=list.prim;
}

void ListIterator::next(){
	//TODO - Implementation
    if(valid())
        current=current->urm();
    else
        throw exception();
}

bool ListIterator::valid() const{
	//TODO - Implementation
    if(current != nullptr)
        return true;
	return false;
}

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
    if(valid())
        return current->element();
	return NULL_TCOMP;
}


