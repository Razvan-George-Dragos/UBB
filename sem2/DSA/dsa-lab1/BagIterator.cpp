#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	//TODO - Implementation
    this->cur=0;
}//linear

void BagIterator::first() {
	//TODO - Implementation
    this->cur=0;
}//linear


void BagIterator::next() {
	//TODO - Implementation
    if(valid())
        this->cur++;
    else
        throw exception();
}//linear


bool BagIterator::valid() const {
	if(this->cur<bag.lp)
        return true;
	return false;
}//linear



TElem BagIterator::getCurrent() const
{
    if(!valid())
        throw exception();
    else
        return bag.u[bag.p[this->cur]];
}//linear
