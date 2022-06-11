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
#include <iostream>
#include "TopologicalSort.h"
#include "DepthFirstSearch.h"

std::vector<CNode*> TopologicalSort::topoSort(CGraph *g) {
    DepthFirstSearch dfs;
    dfs.DFS(g, false);
    std::vector<CNode*> *sortedList = g->getNodes();
    std::sort(sortedList->begin(),sortedList->end(),
              [](const CNode* a, const CNode* b )
              {
                return a->getFinishTime() < b->getFinishTime();
              });
    std::vector<CNode*> topoList;
    for(auto & i : *sortedList){
        topoList.insert(topoList.begin(),i);
    }

    return topoList;
}

void TopologicalSort::printTopologicalOrder(CGraph *g) {
    std::vector<CNode*> topoList = topoSort(g);
    for (auto & i : topoList) {
        std::cout<<i->getId()<<std::endl;
    }

}
