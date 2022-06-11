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

#include "CGraph.h"


std::vector<CNode*> *CGraph::getNodes()  {
    return &nodes_;
}

void CGraph::addNodesIntoGraph(CNode * node) {
    nodes_.push_back(node);
}

CGraph::CGraph(bool directed_, bool weighed_, bool DAG) {

}

bool CGraph::isDirected() const {
    return directed_;
}

bool CGraph::isWeighed() const {
    return weighed_;
}

bool CGraph::isDag() const {
    return DAG;
}

std::map<CNode *, std::vector<CEdge*>> *CGraph::getMap(){
    return &map_;
}

void CGraph::addInitNodeONLY(CNode *node) {
    map_.insert(std::make_pair(node, std::vector<CEdge*>()));
}

void CGraph::addEdgeToNode(CNode *nodeKey, CEdge *edgeToAdd) {
    map_.at(nodeKey).push_back(edgeToAdd);
}

void CGraph::initNODES() {
    for (auto & node : nodes_) {
        addInitNodeONLY(node);
    }
    for (auto & node : nodes_) {
        node->setPredecessor(nullptr);
    }

}

void CGraph::addToNodeSet(CNode *key, CNode * nodeToAdd) {
    node_set_.at(key).push_back(nodeToAdd);
}

void CGraph::initNodeSetONLY() {
    for (auto & node : nodes_) {
        node_set_.insert(std::make_pair(node,std::vector<CNode*>()));
        idToCNode_.insert(std::make_pair(node->getId(),node));
    }
}

std::map<CNode *, std::vector<CNode*>> &CGraph::getNodeSet() {
    return node_set_;
}

const std::map<int, CNode *> &CGraph::getIdToCNode() const {
    return idToCNode_;
}

void CGraph::changeSet(CNode * node, std::vector<CNode*> set) {
    node_set_.at(node).erase(node_set_.at(node).begin(),node_set_.at(node).end());
    for (auto & i : set) {
        node_set_.at(node).push_back(i);
    }
}

std::vector<CEdge *> &CGraph::allEdges(bool forceRewrite ) {
    if (!allEdgesInGraphInit || forceRewrite) {
        auto mapIterator = map_.begin();
        while (mapIterator != map_.end()) {
            for (auto &i : mapIterator->second) {
                allEdgesInGraph.push_back(i);
            }
            ++mapIterator;
        }
        if (!allEdgesInGraphInit) allEdgesInGraphInit = true;
    }
    return allEdgesInGraph;
}

void CGraph::invertEdges() {
    using namespace std;
    vector<CEdge*> edges = allEdges();

    for (auto & edge : edges) {
        edge->setEdge(make_pair(edge->getEdge().second,edge->getEdge().first));
    }

   /* for (auto & edge : edges) {
        cout<<edge->getEdge().first->getName()<<"/"<<edge->getEdge().second->getName() << endl;
    }*/

    map_.clear();
    for (auto & node : nodes_) {
        map_.insert(std::make_pair(node, std::vector<CEdge*>()));
    }
    for (auto & edge : edges) {
        map_.at(edge->getEdge().first).push_back(edge);
    }
}

CGraph::CGraph() = default;

CGraph::~CGraph() = default;
