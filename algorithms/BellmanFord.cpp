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

#include <algorithm>
#include "BellmanFord.h"


bool BellmanFord::bellmanFord(CGraph *g, CNode * s) {
    init(g,s);
    std::vector<CEdge*> edges = g->allEdges();
    std::sort(edges.begin(),edges.end(), [&](const CEdge * a, const CEdge * b){
            if (a->getEdge().first->getName() == b->getEdge().first->getName()){
                return a->getEdge().second->getName() < b->getEdge().second->getName();
            } else{
                return a->getEdge().first->getName() < b->getEdge().first->getName();
            }
    });

    for (unsigned int i = 0; i < g->getNodes()->size(); ++i) {
        for (auto & edge : edges) {
            relax(edge->getEdge().first, edge->getEdge().second, *edge);
        }
    }

    for (auto & edge : edges) {
        int uDistance = edge->getEdge().first->getDistance();
        int vDistance = edge->getEdge().second->getDistance();
        int edgeWeight = edge->getWeight();
        if (uDistance > vDistance + edgeWeight) return false;
    }
    return true;
}

void BellmanFord::relax(CNode * u, CNode * v, CEdge  edge) {
    int edged = edge.getWeight();
    if (v->getDistance() > u->getDistance() + edged){
        v->setDistance(u->getDistance()+edged);
        //std::cout<<"set node "<<v->getName()<<" distance to "<<u->getDistance()+edged<<std::endl;
        v->setPredecessor(u);
        //std::cout<<"set node "<<v->getName()<<" pred to "<<u->getName()<<std::endl;

    }
}

void BellmanFord::init(CGraph * ss,  CNode * s) {
    for (auto & i : *ss->getNodes()) {
        i->setDistance(INT32_MAX);
        if (i->getId() == s->getId()) i->setDistance(0);
    }
}

void BellmanFord::print(CGraph *g) {
    std::vector<CNode*> *nodes = g->getNodes();
    for (auto & node : *nodes) {
        std::cout <<"Node:"<<node->getName()
                  <<", distance:"<<node->getDistance();
        if (node->getPredecessor() == nullptr) {
            std::cout <<", pred:nill"<<std::endl;
        } else{
            std::cout <<", pred:"<<node->getPredecessor()->getName()<< std::endl;
        }
    }
}
