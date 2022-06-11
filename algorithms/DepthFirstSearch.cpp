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
#include <iostream>
#include "DepthFirstSearch.h"

void DepthFirstSearch::DFS(CGraph * g, bool print) {
    std::vector<CNode*> *nodes = g->getNodes();
    for (auto & node : *nodes) {
        node->setColor(1);
        node->setPredecessor(nullptr);
    }
    time =0;
    std::sort(nodes->begin(),nodes->end(), [](const CNode* a, const CNode* b ){
        return a->getId() < b->getId();
    });
    for (auto & node : *nodes) {
        if (node->getColor() ==1){
            DFS_VISITI(g, node);
        }
        if (print) {
            if (node->getPredecessor() == nullptr) {
                node->setNilPredecessor("nil");
                std::cout << "Node " << node->getId() << " , Discovery Time: " << node->getDiscoveryTime()
                          << " , Finish Time: " << node->getFinishTime()
                          << " , Predecessor: " << node->getNilPredecessor() << std::endl;
            } else {
                std::cout << "Node " << node->getId() << " , Discovery Time: " << node->getDiscoveryTime()
                          << " , Finish Time: " << node->getFinishTime()
                          << " , Predecessor: " << node->getPredecessor()->getId() << std::endl;
            }
        }
    }
    if (print) {
        std::cout << "number of node: " << std::to_string(nodes->size()) << std::endl;
    }
}

void DepthFirstSearch::DFS_VISITI(CGraph *g, CNode * u) {
    time++;
    u->setDiscoveryTime(time);
    u->setColor(2);
    std::vector<CEdge*> * adj = &g->getMap()->at(u);
    std::sort(adj->begin(), adj->end(), [](const CEdge* a, const CEdge* b ){
        return a->getEdge().second->getId() < b->getEdge().second->getId();
    });
    for (auto & i : *adj) {
        CNode * v = i->getEdge().second;
        if (v->getColor() == 1){
            v->setPredecessor(u);
            DFS_VISITI(g,v);
        }
    }
    u->setColor(3);
    time++;
    u->setFinishTime(time);
}
