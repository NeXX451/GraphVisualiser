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

#ifndef GRAPHVIS_TOPOLOGICALSORT_H
#define GRAPHVIS_TOPOLOGICALSORT_H


#include <vector>
#include "../graph/CGraph.h"

class TopologicalSort {
public:
    std::vector<CNode*> topoSort(CGraph * g);
    /**
     * prints sorted topological order. nodes with lower id have always higher priority
     * @param g
     */
    void printTopologicalOrder(CGraph * g);

};


#endif //GRAPHVIS_TOPOLOGICALSORT_H
