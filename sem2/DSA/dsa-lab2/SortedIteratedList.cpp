#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>
/*struct SortedIteratedList::SLLNode{
    TComp info;
    PNode next;
    SLLNode(TComp e, PNode n);
};
SortedIteratedList::SLLNode::SLLNode(TComp e, PNode n) {
    info=e;
    next=n;
}*/
Node::Node(TComp e, PNode urm) {
    this->info = e;
    this->next = urm;
}
TComp Node::element() const {
    return this->info;
}
PNode Node::urm() const {
    return this->next;
}
SortedIteratedList::SortedIteratedList(Relation r) {
	//TODO - Implementation
    this->relation=r;
    this->len=0;
    prim = nullptr;
}


int SortedIteratedList::size() const {
	//TODO - Implementation
    return this->len;
}//linear


bool SortedIteratedList::isEmpty() const {
	//TODO - Implementation
    if(this->len==0)
        return true;
    return false;

}//linear

ListIterator SortedIteratedList::first() const {
	//TODO - Implementation
    ListIterator it=ListIterator(*this);
    it.current=prim;
	return it;
}//linear

TComp SortedIteratedList::getElement(ListIterator pos) const {
	//TODO - Implementation
    if(pos.current== nullptr)
        throw exception();
    return pos.getCurrent();
	return NULL_TCOMP;
}//linear

TComp SortedIteratedList::remove(ListIterator& poz) {
	//TODO - Implementation
    PNode p=prim;
    if(p== nullptr)
        throw exception();
    if(poz.current== nullptr)
        throw exception();
    if(p==poz.current)
    {
        TComp x=p->info;
        prim=p->urm();
        this->len--;
        poz.next();
        return x;

    }
    else
    {
        while(p->urm()!= nullptr && p->urm()!=poz.current){
            p=p->urm();
        }
        if(p->urm()==poz.current)
        {
            PNode q=p->urm();
            TComp x=q->info;
            if(q->urm() != nullptr)
            {
                p->next=q->urm();
                poz.next();
            }
            else
            {
                p->next= nullptr;
                poz.current= nullptr;
            }

            delete q;
            this->len--;
            return x;
        }
    }
    throw exception();
}//O(this->len)

ListIterator SortedIteratedList::search(TComp e) const{
	//TODO - Implementation
    PNode p=prim;
    ListIterator it=ListIterator(*this);
    while(p != nullptr)
    {
        if(p->info==e)
        {
            it.current=p;
            return it;
        }
        p=p->urm();
    }
    it.current= nullptr;
    return it;



}//O(this->len)

ListIterator SortedIteratedList::last_pos(TComp e) const {
    PNode p=prim;
    ListIterator it=ListIterator(*this);
    bool ok=false;
    while(p != nullptr)
    {
        if(p->info==e)
        {
            ok=true;
            it.current=p;
        }
        p=p->urm();
    }
    if(!ok)
        it.current= nullptr;
    return it;
}// -O-(this->len)

void SortedIteratedList::add(TComp e)
{
	//TODO - Implementation
    PNode p;
    p=prim;
    if(p == nullptr || this->relation(e,p->info))
    {
        auto nou= new Node(e, nullptr);
        nou->next=prim;
        prim=nou;
        this->len++;
    }
    else
    {
        while(p->urm() != nullptr && this->relation(p->urm()->info,e))
        {
            p=p->urm();
        }
        if(p->urm()!= nullptr)
        {
            auto nou= new Node(e, p->urm());
            p->next=nou;
            this->len++;
        }
        else
        {
            auto nou= new Node(e, nullptr);
            p->next=nou;
            this->len++;
        }
    }

}//O(this->len)

SortedIteratedList::~SortedIteratedList() {
	//TODO - Implementation
    while(prim!= nullptr)
    {
        PNode p=prim;
        prim=prim->urm();
        delete p;
    }
}//-O-(this->len)


