#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) {
	//TODO - Implementation
    this->r=r;
    this->size_used=0;
    this->head=-1;
    this->capacity=10;
    this->elems=new TElem[this->capacity];
    this->next=new int[this->capacity];
    this->FirstFree=0;
    for(int i=0; i< this->capacity; i++)
    {
        this->elems[i].first=-9999;
        this->elems[i].second=-9999;
    }
    for(int i=0; i< this->capacity-1; i++)
        this->next[i]=i+1;
    this->next[this->capacity-1]=-1;
}//-O-(n)

void SortedMap::resize() {
    this->capacity+=10;
    auto* ar=new TElem[this->capacity];
    for(int i=0; i< this->size_used; i++)
        ar[i]=this->elems[i];
    delete[] this->elems;
    this->elems=ar;
    auto* nn= new int[this->capacity];
    for(int i=0; i<this->size_used; i++)
        nn[i]=this->next[i];
    delete[] this->next;
    this->next=nn;
    for(int i= this->size_used; i< this->capacity; i++)
    {
        this->elems[i].first=-9999;
        this->elems[i].second=-9999;
    }
    for(int i= this->size_used; i< this->capacity; i++)
        this->next[i]=i+1;
    this->next[this->capacity-1]=-1;
    this->FirstFree=this->size_used;

}//-O-(n)

TValue SortedMap::add(TKey k, TValue v) {
    if(search(k)!=NULL_TVALUE)
    {
        for(int i=0; i< this->size_used; i++)
            if(this->elems[i].first==k)
            {
                TValue x=this->elems[i].second;
                this->elems[i].second=v;
                return x;
            }
    }
    if(this->size_used >= this->capacity)
        resize();
    bool ok=false;
    int i=0;
    while(!ok && i < this->size_used)
    {
        if(!r(k, this->elems[i].first))
        {
            ok=true;
            for(int j=this->size_used; j>i; j--)
                this->elems[j]=this->elems[j-1];
            this->elems[i].first=k;
            this->elems[i].second=v;
        }
        i++;
    }
    if(!ok)
    {
        this->elems[this->size_used].first=k;
        this->elems[this->size_used].second=v;
    }
    this->size_used++;
    int oldfirst = this->FirstFree;
    this->FirstFree = this->next[this->FirstFree];
    next[oldfirst] = this->head;
    this->head = oldfirst;
    return NULL_TVALUE;
}//-O-(n)

TValue SortedMap::search(TKey k) const {
	for(int i=0; i< this->size_used; i++)
        if(this->elems[i].first==k)
            return this->elems[i].second;
	return NULL_TVALUE;
}//O(n)

int SortedMap::operatie(SortedMap& sm) {
    int a=0;
    TValue x;
    for(int i=0; i<sm.size_used; i++)
    {
        if(search(sm.elems[i].first)==NULL_TVALUE)
        {
            a++;
            add(sm.elems[i].first, sm.elems[i].second);
        }
    }
    return a;
}//-O-(n)

TValue SortedMap::remove(TKey k) {
    for(int i=0; i< this->size_used; i++)
    {
        if(this->elems[i].first==k)
        {
            TValue x=this->elems[i].second;
            for(int j=i; j<this->size_used-1; j++)
                this->elems[j]= this->elems[j+1];
            this->size_used--;
            return x;
        }
    }
	return NULL_TVALUE;
}//-O-(n)

int SortedMap::size() const {
	return this->size_used;
}//linear

bool SortedMap::isEmpty() const {
    if(this->size_used==0)
        return true;
    return false;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
	delete[] this->elems;
    delete[] this->next;
}
