//
// Created by Razvan on 6/13/2022.
//

#include "Answear.h"

Answear::Answear(int i, int qi, std::string t, std::string u, int nrv)
{
    this->id=i;
    this->QsId=qi;
    this->text=std::move(t);
    this->userName=std::move(u);
    this->nrVotes=nrv;
}

