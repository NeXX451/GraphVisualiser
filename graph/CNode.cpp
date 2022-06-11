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

//#include <iostream>
#include "CNode.h"



int CNode::lastId = 0;
CNode::CNode() {
    id_ = lastId;
    lastId++;
}

int CNode::getId() const {
    return id_;
}

void CNode::setId(int val) {
    CNode::id_ = val;
}

const std::string &CNode::getName() const {
    return name_;
}

void CNode::setName(const std::string &name) {
    CNode::name_ = name;
}

/* std::vector<CEdge> *CNode::getEdges()  {
    return &edges_;
}*/
/*void CNode::addEdge(CNode right) {
    CEdge e(this->getId(), right.getId());
    edges_.push_back(e);
}*/

/*void CNode::addEdge(CNode right,int weight) {
    CEdge e(this->getId(), right.getId(), weight);
    edges_.push_back(e);
}*/

void CNode::printNode() const {
    std::cout << "Node id: " << this->getId() << std::endl;
}

/*void CNode::printEdges() {
    printNode();
    std::cout << " has neighbors: ";
    for (CEdge e : edges_){
        std::cout << e.getEdge().second<< " ";
    }
    std::cout<<std::endl;
}*/

int CNode::getLastId() {
    return lastId;
}

void CNode::setLastId(int lastId) {
    CNode::lastId = lastId;
}

int CNode::getColor() const {
    return COLOR;
}

void CNode::setColor(int color) {
    COLOR = color;
}

int CNode::getDistance() const {
    return DISTANCE;
}

void CNode::setDistance(int distance) {
    DISTANCE = distance;
}

int CNode::getDiscoveryTime() const {
    return DISCOVERY_TIME;
}

void CNode::setDiscoveryTime(int discoveryTime) {
    DISCOVERY_TIME = discoveryTime;
}

int CNode::getFinishTime() const {
    return FINISH_TIME;
}

void CNode::setFinishTime(int finishTime) {
    FINISH_TIME = finishTime;
}

CNode *CNode::getPredecessor() const {
    return PREDECESSOR;
}

void CNode::setPredecessor(CNode *predecessor) {
    PREDECESSOR = predecessor;
}

/*void CNode::setEdges(std::vector<CEdge> edges) {
    edges_ = edges;
}*/

bool CNode::operator==(CNode *c) {
    if (this == c) return true;
    return false;
}

const std::string &CNode::getNilPredecessor() const {
    return nilPREDECESSOR;
}

void CNode::setNilPredecessor(const std::string &nilPredecessor) {
    nilPREDECESSOR = nilPredecessor;
}

int CNode::getKeyMst() const {
    return keyMST;
}

void CNode::setKeyMst(int keyMst) {
    keyMST = keyMst;
}







