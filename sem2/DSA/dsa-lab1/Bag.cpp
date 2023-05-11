#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <stdlib.h>
#include <iostream>
using namespace std;


Bag::Bag() {
	this->cpp=10;
    this->cpu=10;
    this->lp=0;
    this->lu=0;
    this->p=(int*) malloc(this->cpp*sizeof(int));
    this->u=(TElem*)malloc(this->cpu*sizeof(TElem));
}//linear

void Bag::resize()
{
    this->cpu*=2;
    auto* aux=(TElem*)realloc(this->u,this->cpu*sizeof(TElem));
    if (aux == NULL)
        return;
    this->u=aux;
    this->cpp*=2;
    int* ax=(int*)realloc(this->p,this->cpp*sizeof(int));
    if (aux == NULL)
        return;
    this->p=ax;
}//linear
void Bag::add(TElem elem) {
	//TODO - Implementation
    int j;
    if(this->lp>=this->cpp||this->lu>=this->cpu)
        resize();
    if(!search(elem))
    {
        this->u[this->lu]=elem;
        this->lu++;
        this->p[this->lp]=this->lu-1;
        this->lp++;
    }
    else
    {
        j=-1;
        for(int i=0; i<this->lu; i++)
        {
            if(this->u[i]==elem)
                j=i;
        }
        this->p[this->lp]=j;
        this->lp++;
    }



}//average case=this->lu


bool Bag::remove(TElem elem) {
	//TODO - Implementation
    bool ok=false;
    for(int i=this->lu-1; i>=0; i--)
    {
        if(this->u[i]==elem)
        {
            for(int j=0; j<this->lp; j++)
            {
                if(this->p[j]==i)
                {
                    for(int k=j+1; k<this->lp; k++)
                    {
                        if(this->p[k]==i)
                            ok=true;
                    }
                    if(ok)
                    {
                        for(int k=j+1; k<this->lp; k++)
                        {
                            this->p[k-1]=this->p[k];
                        }
                        this->lp--;
                        return true;
                    }
                    else
                    {
                        for(int k=i+1; k<this->lu; k++)
                        {
                            this->u[k-1]=this->u[k];
                        }
                        this->lu--;
                        for(int k=j+1; k<this->lp; k++)
                        {
                            this->p[k-1]=this->p[k];
                            if(this->p[k-1]>i)
                                this->p[k-1]--;
                        }
                        this->lp--;
                        return true;
                    }
                }
            }
        }
    }
	return false; 
}//average case=this->lp^3*this->lu


bool Bag::search(TElem elem) const {
	for(int i=0; i<this->lu; i++)
    {
        if(this->u[i]==elem)
            return true;
    }
	return false; 
}//average case=this->lu

int Bag::nrOccurrences(TElem elem) const {
	int j=-1, o=0;
    for(int i=0; i<this->lu; i++)
    {
        if(this->u[i]==elem)
            j=i;
    }
    if(j<0)
	    return 0;
    for(int i=0; i<this->lp; i++)
        if(this->p[i]==j)
            o++;
    return o;
}//average case=(this->lu or this->lp)


int Bag::size() const {
	//TODO - Implementation
	return this->lp;
}//linear


bool Bag::isEmpty() const {
	//TODO - Implementation
	return (this->lp==0);
}//linear

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

int Bag::removeOccurrences(int nr, TElem elem)
{
    if(nr<0)
        throw exception();
    int j=-1,k=0;
    for(int i=0; i<this->lu; i++)
    {
        if(this->u[i]==elem)
            j=i;
    }
    if(j==-1)
        return 0;
    for(int i=0; i<this->lp; i++)
    {
        if(this->p[i]==j)
            k++;
    }
    if(k>=nr)
        return 0;
    for(int i=j; i<this->lu-1; i++)
    {
        this->u[i]=this->u[i+1];
    }
    this->lu--;
    for(int i=0; i<this->lp; i++)
    {
        if(this->p[i]==j)
        {
            for(int m=i; i<this->lp-1; m++)
            {
                this->p[m]=this->p[m+1];
            }
            this->lp--;
            i--;
        }
    }
    for(int i=0; i<this->lp; i++)
    {
        if(this->p[i]>j)
            this->p[i]--;
    }
    return k;

}

Bag::~Bag() {
	//TODO - Implementation
    delete[]this->u;
    delete[]this->p;
}

