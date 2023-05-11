#pragma once
#include "SortedIteratedList.h"

//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIteratedList;
private:
	const SortedIteratedList& list;
	explicit ListIterator(const SortedIteratedList& list);

	//TODO - Representation
    PNode current;
public:
	void first();
	void next();
	bool valid() const;
    TComp getCurrent() const;
};


