/**
*    GraphVis is a console-based graph visualiser.
*    Copyright (C) 2022  Tomas Duchac
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
*/
#include <iostream>
#include "Dijkstra.h"

void Dijkstra::SSSPDijkstr(CGraph * g, CNode * s) {

    init(g, s);
    Queue q;
    q.addAll(g->getNodes());
    while (!q.isEmpty()){

        CNode * u = q.extractMin();
        std::vector<CEdge*> * adj =  &g->getMap()->at(u);

        for (auto & i : *adj) {
            CNode * v = i->getEdge().second;
            relax(u,v,*i);
        }
    }


}



void Dijkstra::relax(CNode * u, CNode * v, CEdge  edge) {
    int edged = edge.getWeight();
    if (v->getDistance() > u->getDistance() + edged){
        v->setDistance(u->getDistance()+edged);
        v->setPredecessor(u);
    }
}

void Dijkstra::init(CGraph * ss,  CNode * s) {
    for (auto & i : *ss->getNodes()) {
        i->setDistance(INT32_MAX);
        if (i->getId() == s->getId()) i->setDistance(0);
    }
}

void Dijkstra::printResult(CGraph * g, CNode * s) {
    SSSPDijkstr(g,s);
    for (auto & i : *g->getNodes()) {
        if (i->getId() != s->getId()) {
            std::cout << "Pred for " << i->getId() << " : "
                      << i->getPredecessor()->getId()
                      << " , " << " Cost: " << i->getDistance()<< " | ";
        }
    }
}
