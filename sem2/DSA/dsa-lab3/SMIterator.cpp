#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
    this->current=m.head;
}

void SMIterator::first(){
    current=map.head;
}

void SMIterator::next(){
	if(current==-1)
        throw exception();
    current=map.next[current];
}

bool SMIterator::valid() const{
	if(current!=-1)
        return true;
	return false;
}

TElem SMIterator::getCurrent() const{
    if(current==-1)
        throw exception();
    return map.elems[current];
	//return NULL_TPAIR;
}


