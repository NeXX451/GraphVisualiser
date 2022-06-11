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

#include "BreadthFirstSearch.h"


#include "iostream"
//#include <string>

void BreadthFirstSearch::BFS(CGraph * g, CNode * s,  bool suppressPrint) {
    std::vector<CNode*> *nodes = g->getNodes();

    for(auto & i : *nodes){
        i->setColor(1);
        i->setDistance(INT32_MAX);
    }
    s->setColor(1);
    s->setDistance(0);
    Queue q;
    q.engueue(s);
    int counter = 1;
    int counter2 = 0;
    while (!q.isEmpty()){

        CNode * u = q.dequeueForBFS();
        std::vector<CEdge*> * adj = &g->getMap()->at(u);
        std::string foundNodes = "";

        std::sort(adj->begin(),adj->end(), [](const CEdge* a, const CEdge*  b ){
            return a->getEdge().second->getId() < b->getEdge().second->getId();
        });

        for(auto & i : *adj){
            CNode * v = i->getEdge().second;
            if (v->getColor() ==1){
                v->setColor(2);
                v->setDistance(u->getDistance()+1);
                v->setPredecessor(u);
                q.engueue(v);
                foundNodes.append(" ");
                foundNodes += std::to_string(v->getId());
            }
        }

        if (!suppressPrint) {
            if (!q.isEmpty()) {
                std::string ar = q.toStringArray();
                if (foundNodes.size() > 0) {
                    std::cout << "Iteration " << counter << " | Node u = " << u->getId() << " | Node v =" << foundNodes
                              << " | Q = [" + ar + "]" << std::endl;
                    counter++;
                } else {
                    std::cout << "Iteration " << counter << " | Node u = " << u->getId() << " | Node v = X"
                              << " | Q = [" + ar + "]" << std::endl;
                    counter++;
                }
            } else {
                if (foundNodes.length() > 0) {
                    std::cout << "Iteration " << counter << " | Node u = " << u->getId() << " | Node v =" << foundNodes
                              << " | Q = nil" << std::endl;
                    counter++;
                } else {
                    std::cout << "Iteration " << counter << " | Node u = " << u->getId() << " | Node v = X"
                              << " | Q = nil";
                    counter++;
                }
            }
        }
        u->setColor(3);
        counter2++;
    }
}

void BreadthFirstSearch::printBFS(CGraph * g, CNode * s, bool print, bool suppressAdditionalInfo) {
    BFS(g,s, suppressAdditionalInfo);
    if (print) {
        std::cout << std::endl;
        std::cout << "From starting node: " << s->getId() << std::endl;
        for(auto & i : *g->getNodes()){
            if (i->getId() != s->getId()) {
                std::cout << "node: " << i->getId()
                          << " has predecessor: " << i->getPredecessor()->getId()
                          << " and has distance to start: "
                          << i->getDistance()
                          << std::endl;
            }
        }

    }
}
