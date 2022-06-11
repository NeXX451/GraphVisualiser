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

#include "Set.h"

std::vector<CNode*> &Set::getNodeSet(){
    return nodeSet_;
}

std::vector<CEdge*> &Set::getEdgeSet()  {
    return edgeSet_;
}

void Set::setNodeSet( std::vector<CNode*> *nodeSet) {
    nodeSet_ = *nodeSet;
}

void Set::setEdgeSet( std::vector<CEdge*> *edgeSet) {
    edgeSet_ = *edgeSet;
}





void Set::addToSet(CNode* node) {
    nodeSet_.push_back(node);
}

void Set::addToSet(CEdge* edge) {
    edgeSet_.push_back(edge);
}
