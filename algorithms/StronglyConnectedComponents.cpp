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
#include <memory>
#include <stack>
#include "StronglyConnectedComponents.h"

void StronglyConnectedComponents::SCC(CGraph * g) {
    DepthFirstSearch dfs;
    dfs.DFS(g, false); // normal DFS
    g->invertEdges();
    mainloopDFS(g); // consider dfs in mainloop from descending finish time from normal DFS
}

void StronglyConnectedComponents::mainloopDFS(CGraph *g) {
    std::vector<CNode*> *nodes = g->getNodes();
    for (auto & node : *nodes) {
        node->setColor(1);
        node->setPredecessor(nullptr);
    }
    time =0;
    std::sort(nodes->begin(),nodes->end(), [](const CNode* a, const CNode* b ){
        return a->getFinishTime() > b->getFinishTime();
    });
    for (auto & node : *nodes) {
        if (node->getColor() ==1){
            dfsVisit(g, node);
        }
    }

}

void StronglyConnectedComponents::dfsVisit(CGraph * g, CNode* u) {
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
            dfsVisit(g,v);
        }
    }
    u->setColor(3);
    time++;
    u->setFinishTime(time);
}

std::map<int, std::vector<CNode *>> * StronglyConnectedComponents::createSCCs(CGraph* g, bool print) {
    SCC(g);
    using namespace std;
    vector<CNode*> nodes = *g->getNodes();
    int nils{0};
    for (auto & node : nodes) {
        if(node->getPredecessor()== nullptr) {
            sccVector.insert(std::make_pair(nils, std::vector<CNode*>()));
            ++nils;
        }
    }
    sort(nodes.begin(),nodes.end(),[](CNode* a, CNode* b){
        if (a->getPredecessor()== nullptr) return true;
        return false;
    });


    int i{0};
    while (i < nils){
        CNode* n = nodes.at(i);
        sccVector.at(i).push_back(n);
        std::stack<CNode*> stack;

        while (true) {
            unsigned int j = nils;
            while (j < nodes.size()) {
                if (nodes.at(j)->getPredecessor() == n) stack.push(nodes.at(j));
                ++j;
            }
            if (stack.empty()) break;
            while (!stack.empty()) {
                CNode *tmp = stack.top();
                stack.pop();
                sccVector.at(i).push_back(tmp);
                n = tmp;
            }
        }
        ++i;
    }

    if(print) {
        auto it = sccVector.begin();
        while (it != sccVector.end()) {
            vector<CNode *> sccs = it->second;
            cout << "SCC " << it->first << ":" << endl;
            for (auto &scc : sccs) {
                if (scc->getPredecessor() == nullptr) {
                    cout << "node:" << scc->getName() << ", pred:nil" << endl;
                } else {
                    cout << "node:" << scc->getName() << ", pred:" << scc->getPredecessor()->getName() << endl;
                }
            }
            ++it;
        }
    }
    return &sccVector;
}


