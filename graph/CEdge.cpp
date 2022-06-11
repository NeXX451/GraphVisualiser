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

#include "CEdge.h"

#include <utility>

CEdge::CEdge() = default;

CEdge::CEdge(CNode * left, CNode * right, int weight) {
    edge_ = std::make_pair(left, right);
    weight_ = weight;
}
CEdge::CEdge(CNode* left, CNode* right) {
    edge_ = std::make_pair(left, right);

}

int CEdge::getWeight() const {
    return weight_;
}

void CEdge::setWeight(int weight) {
    CEdge::weight_ = weight;
}

const std::pair<CNode*, CNode*> &CEdge::getEdge() const {
    return edge_;
}


void CEdge::setEdge(const std::pair<CNode*, CNode*> &edge) {
    edge_ = edge;
}

bool CEdge::visitedKruskal() {
    return visitedEdgeKruskal;
}
