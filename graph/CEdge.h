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

#ifndef TEST_CEDGE_H
#define TEST_CEDGE_H


#include <utility>
#include "CNode.h"


class CEdge {
public:
    CEdge(CNode*, CNode*, int);
    CEdge(CNode*, CNode*);
    CEdge();

    int getWeight() const;

    void setWeight(int weight);

    const std::pair<CNode*, CNode*> &getEdge() const;

    void setEdge(const std::pair<CNode*, CNode*> &edge);

    bool visitedKruskal();
    void setVisitedKruskalTrue() {
        visitedEdgeKruskal = true;
    }

private:
    int weight_{};

    bool visitedEdgeKruskal = false;

    std::pair<CNode*, CNode*> edge_;
};


#endif //TEST_CEDGE_H
