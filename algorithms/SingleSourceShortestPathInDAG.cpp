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
#include "SingleSourceShortestPathInDAG.h"

static int i = 1;
void SingleSourceShortestPathInDAG::SSSPDAG(CGraph *g, CNode *s) {
    TopologicalSort sort;
    std::vector<CNode*> topoOrder = sort.topoSort(g);
    init(g,s);
    for (auto topoNode : topoOrder) {
        std::cout<<"iteration "<<i<<std::endl; ++i;
        std::vector<CEdge*> edges = g->getMap()->at(topoNode);
        for (auto & edge : edges) {
            relax(topoNode, edge->getEdge().second,*edge);
        }
    }
}
void SingleSourceShortestPathInDAG::relax(CNode * u, CNode * v, CEdge  edge) {
    int edged = edge.getWeight();
    if (v->getDistance() > u->getDistance() + edged){

        v->setDistance(u->getDistance()+edged);
        std::cout<<"set node "<<v->getName()<<" distance to "<<u->getDistance()+edged<<std::endl;
        v->setPredecessor(u);
        std::cout<<"set node "<<v->getName()<<" pred to "<<u->getName()<<std::endl;

    }
}

void SingleSourceShortestPathInDAG::init(CGraph * ss,  CNode * s) {
    for (auto & i : *ss->getNodes()) {
        i->setDistance(INT32_MAX);
        if (i->getId() == s->getId()) i->setDistance(0);
    }
}
