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
#include "Kruskal.h"

std::vector<CEdge *> Kruskal::MST_Kruskal(CGraph *g) {
    std::vector<CEdge *> A;
    int counter = 0;
    g->initNodeSetONLY();
    for (auto & i : *g->getNodes()){
        g->addToNodeSet(i,i);
    }
    std::map<CNode*,std::vector<CNode*>>::iterator it = g->getNodeSet().begin();
    while (it != g->getNodeSet().end()){
        std::cout << it->first->getId()<<std::endl;
        for (unsigned int i = 0; i < it->second.size(); ++i) {
            std::cout<< " id " <<it->second.at(i)->getId()<<std::endl;
        }
        ++it;
    }

    std::map<CNode*, std::vector<CEdge*>> *adj = g->getMap();
    std::vector<CEdge*> LWE;
    for (auto node : *g->getNodes()) {
        std::vector<CEdge*> e = adj->at(node);
        for (auto & j : e) {
            LWE.push_back(j);
        }
    }

    std::sort(LWE.begin(),LWE.end(), [&](const CEdge * a, const CEdge * b){
        if (a->getWeight() < b->getWeight()){
            return a->getWeight() < b->getWeight();
        } else if (a->getWeight() == b->getWeight() ){
            if (a->getEdge().first->getName() == b->getEdge().first->getName()){
                return a->getEdge().second->getName() < b->getEdge().second->getName();
            } else{
                return a->getEdge().first->getName() < b->getEdge().first->getName();
            }
        }
        return false;
    });

    std::string string = "{u,v} = \u0003 | w({u,v}) = \u0003 | Dazu? = \u0003 | set(a) = {a} | set(b) = {b} | set(c) = {c} | set(d) = {d} | set(e) = {e} | set(f) = {f} | set(g) = {g} | set(h) = {h} | set(j) = {j} | set(k) = {k}";
    std::cout << string << std::endl;
    std::vector<int> idA;
    for (auto & i : LWE) {
        if (!i->visitedKruskal()){
            i->setVisitedKruskalTrue();
            CNode *u = i->getEdge().first;
            CNode *v = i->getEdge().second;
            std::vector<CEdge *> s = g->getMap()->at(v);
            for (auto & j : s) {
                if(j->getEdge().second == u){
                    j->setVisitedKruskalTrue();
                    break;
                }
            }
            std::vector<CEdge *> edgeSet;
            edgeSet.push_back(i);

            std::vector<CNode *> uSet = g->getNodeSet().at(u);
            std::vector<CNode *> vSet = g->getNodeSet().at(v);


            if (uSet != vSet) {
                std::vector<CNode *> newSet;

                A = unionEdge(g, A, i);
                newSet = unionNode(g, u, v);
                g->changeSet(u, newSet);
                g->changeSet(v, newSet);

                std::vector<CNode*> toUp = g->getNodeSet().at(u);

                std::map<CNode*, std::vector<CNode*>>::iterator iterate = g->getNodeSet().begin();
                std::vector<CNode*> setOfU = g->getNodeSet().at(u);
                for (auto & j : toUp) {
                    while (iterate != g->getNodeSet().end()){
                        if (iterate->first->getId() == j->getId()){
                            iterate->second = setOfU;
                        }
                        ++iterate;
                    }
                    iterate = g->getNodeSet().begin();
                }

                print(g, i, u, v, g->getNodes(), true);
            } else {
                print(g, i, u, v, g->getNodes(), false);
            }
            counter++;
        }
    }

    std::cout<< "A = {"<<std::endl;
    for (auto & e : A) {
        std::cout << "{" << e->getEdge().first->getName()<<","<<e->getEdge().second->getName()<<"}"<<"-> weight "<< e->getWeight()<<std::endl;
    }
    std::cout<< "}" <<std::endl;

    return A;
}

void Kruskal::print(CGraph *g, CEdge *e, CNode *u, CNode *v, std::vector<CNode *> *nodes, bool in) {
    std::string com;
    for (auto & node : *nodes) {
        com +=" set(" + node->getName() +") = {";
        for (auto i : g->getNodeSet().at(node)) {
            com += i->getName() + ",";
        }
        com += "}";
    }
    if (in){
        std::cout<<"{u,v} = {" << u->getName()<< "," << v->getName() << "} | " << "w({u,v}) = " << e->getWeight() << "| "
                 <<"Dazu? = ja | " << com << std::endl;
    } else{
        std::cout <<"{u,v} = {"<< u->getName()<< "," << v->getName() << "} | " << "w({u,v}) = " << e->getWeight() << "| "
                  <<"Dazu? = nein | " << com << std::endl;
    }
}

std::vector<CNode*> Kruskal::unionNode(CGraph *g, CNode *u, CNode *v) {
    std::vector<CNode*> a = g->getNodeSet().at(u);
    std::vector<CNode*> b = g->getNodeSet().at(v);
    std::vector<CNode*> unionSet;
    for (auto & i : a) {
        unionSet.push_back(i);
    }
    for (auto & i : b) {
        unionSet.push_back(i);
    }
    for (unsigned int i = 0; i < unionSet.size(); ++i) {
        CNode* x = unionSet.at(i);
        for (unsigned int j = i+1; j < unionSet.size(); ++j) {
            if (i<unionSet.size()-1){
                if (unionSet.at(j)->getId() == x->getId()){
                    unionSet.erase(unionSet.begin()+j);
                }
            } else{
                for (unsigned int k = j; k < unionSet.size()-1; ++k) {
                    if (unionSet.at(k)->getId()==x->getId()){
                        unionSet.erase(unionSet.begin()+j);
                    }
                }
            }
        }
    }
    return unionSet;
}

std::vector<CEdge*> Kruskal::unionEdge(CGraph* g,std::vector<CEdge *> A, CEdge* edge) {
    std::vector<CEdge*> unionSet;
    for (auto & i : A) {
        unionSet.push_back(i);
    }
    unionSet.push_back(edge);
    for (unsigned int i = 0; i < unionSet.size(); ++i) {
        CEdge * x = unionSet.at(i);
        for (unsigned int j = i+1; j < unionSet.size(); ++j) {
            if (i<unionSet.size()-1){
                if (unionSet.at(j) == x){
                    unionSet.erase(unionSet.begin()+j);
                }
            } else{
                for (unsigned int k = j; k < unionSet.size()-1; ++k) {
                    if (unionSet.at(k) == x){
                        unionSet.erase(unionSet.begin()+k);
                    }
                }
            }
        }
    }
    return unionSet;
}
