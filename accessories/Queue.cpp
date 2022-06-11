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

#include "Queue.h"

void Queue::engueue(CNode * node) {
    queue_.push_back(node);
}

CNode * Queue::dequeue() {
    CNode * p = queue_.back();
    queue_.pop_back();
    return p;
}

CNode *Queue::extractMin() {
    sortKeys();
    return dequeue();
}

bool Queue::isEmpty() {
    return queue_.empty();
}

bool Queue::contains(CNode * v) {
    return std::find(queue_.begin(),queue_.end(),v) != queue_.end();
}

void Queue::sortKeys() {

    std::sort(queue_.begin(),queue_.end(), [](const CNode * a, const CNode * b ){
        //std::cout<<a.getDistance()<< " " << b.getDistance()<< std::endl;

       return a->getDistance() > b->getDistance();
    });

}

 std::vector<CNode*> *Queue::getQueue() {
    return &queue_;
}

void Queue::addAll(std::vector<CNode*> * no) {

    for (auto & i : *no) {
        queue_.push_back(i);
    }
}

std::string Queue::toStringArray() {

    std::string a = "";

    for (auto & i : queue_) {
        a += " " + std::to_string(i->getId());
    }

    return a;
}



CNode *Queue::dequeueForBFS() {

    CNode * p = queue_.front();
    queue_.erase(queue_.begin());
    return p;
}

CEdge *Queue::dequeueEdge() {
    CEdge * e = edges_queue_.front();
    edges_queue_.erase(edges_queue_.begin());
    return e;
}
CNode *Queue::dequeueMSTNode() {
    CNode * n = queue_.front();
    queue_.erase(queue_.begin());
    return n;
}


void Queue::addAll(std::vector<CEdge *> *edges) {
    for (auto & edge : *edges) {
        edges_queue_.push_back(edge);
    }
}

bool Queue::isEmptyEdgeQ() {
    return edges_queue_.empty();
}

void Queue::sortMST() {
    std::sort(queue_.begin(), queue_.end(), [&](const CNode* a, const CNode* b){
        if (a->getKeyMst() < b->getKeyMst()){
            return a->getKeyMst() < b->getKeyMst();
        } else if (a->getKeyMst() == b->getKeyMst() && a->getName() < b->getName()){
            return a->getName() < b->getName();
        }
        return false;
    });
}


void Queue::sortEdgesForPRIM() {
    std::sort(edges_queue_.begin(), edges_queue_.end(), [&](const CEdge* a, const CEdge* b){
        if (a->getEdge().second->getKeyMst() < b->getEdge().second->getKeyMst()){
            return a->getEdge().second->getKeyMst() < b->getEdge().second->getKeyMst();
        }else if (a->getEdge().second->getKeyMst() == b->getEdge().second->getKeyMst() && a->getEdge().second->getName() < b->getEdge().second->getName()){
            return a->getEdge().second->getName() < b->getEdge().second->getName();
        }
        return false;
    });

}

int Queue::size() {
    return queue_.size();
}







