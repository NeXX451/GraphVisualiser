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
#include "Prim.h"

void Prim::MST_Prim(CGraph *g, CNode * r) {
    Queue q;
    for (auto & i : *g->getNodes()) {
        i->setKeyMst(INT32_MAX);
        i->setPredecessor(nullptr);
    }
    CNode * root = r;
    root->setKeyMst(INT32_MIN);
    q.addAll(g->getNodes());
    int counter = 0;
    while (!q.isEmpty()){
        q.sortMST();
        CNode * u = q.dequeueMSTNode();
        std::vector<CEdge*> * edges = &g->getMap()->at(u);
        sort(edges);
        std::string nei;
        for (auto & edge : *edges) {
            nei += edge->getEdge().second->getName() + " ";
        }
        std::cout << "neighbors of "<<u->getName() <<" with key "<< edges->at(0)->getEdge().first->getKeyMst()<<" are " << nei<<std::endl;
        Queue q2FORadj;
        q2FORadj.addAll(edges);
        while (!q2FORadj.isEmptyEdgeQ()){
            CEdge * edge = q2FORadj.dequeueEdge();
            CNode * v = edge->getEdge().second;
            std::cout<< "node "<<u->getName() <<"'s neighbor is "<< v->getName()<<std::endl;
            if (q.contains(v) && edge->getWeight() < v->getKeyMst()){
                std::cout<<"setting new params for neighbor "<<v->getName()<<", with key: "<<edge->getWeight()<<", and pred: "<<edge->getEdge().first->getName()<<std::endl;
                v->setKeyMst(edge->getWeight());
                v->setPredecessor(u);
                print(g,edge,u);
                counter++;
                q2FORadj.sortEdgesForPRIM();
            }
        }

    }

    for (auto x : *g->getNodes()) {
        if (x->getPredecessor() != nullptr){
            std::cout << x->getName() << " has pred " << x->getPredecessor()->getName() << std::endl;
        }
    }
    std::cout << std::to_string(counter)<< " iterations." << std::endl;

}

bool Prim::comp1(const CEdge *a, const CEdge *b) {
    if (a->getEdge().second->getKeyMst() < b->getEdge().second->getKeyMst()){
        return a->getEdge().second->getKeyMst() < b->getEdge().second->getKeyMst();
    }else if (a->getEdge().second->getKeyMst() == b->getEdge().second->getKeyMst() && a->getEdge().second->getName() < b->getEdge().second->getName()){
        return a->getEdge().second->getName() < b->getEdge().second->getName();
    }
    return a->getEdge().second->getKeyMst() > b->getEdge().second->getKeyMst();
}


/**
 *
 * @param edges
 * @param option 1 vector, 2 queue
 */
void Prim::sort(std::vector<CEdge*> *edges) {
    std::sort(edges->begin(), edges->end(), [&](const CEdge* a, const CEdge* b){
        return comp1(a,b);
    });

}

void Prim::print(CGraph *g, CEdge *e, CNode *r) {
    std::string completeString = "";
    std::sort(g->getNodes()->begin(), g->getNodes()->end(), [](const CNode * a, const CNode * b){
        return a->getName() < b->getName();
    });
    for (auto node : *g->getNodes()) {
        if (node->getKeyMst() == INT32_MAX){
            completeString += node->getName() + ".k = ∞| ";
        } else if (node->getKeyMst() == INT32_MIN){
            completeString += node->getName() + ".k = -∞ | ";
        } else{
            completeString += node->getName() + ".k = ";
            completeString += std::to_string(node->getKeyMst()) + " | ";
        }
    }
    std::cout << completeString << " u = " << r->getName() << std::endl;
}