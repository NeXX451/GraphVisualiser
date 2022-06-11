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

#ifndef GRAPHVIS_QUEUE_H
#define GRAPHVIS_QUEUE_H
#include <algorithm>

#include <queue>
#include "../graph/CNode.h"
#include "../graph/CEdge.h"

class Queue {
public:
    void addAll(std::vector<CNode*> *nodes);
    void addAll(std::vector<CEdge*> *edges);
    void engueue(CNode * node); // 1 dijkstra, 2 bfs
    CNode * dequeue();
    CEdge * dequeueEdge();
    CNode * dequeueMSTNode();

    bool isEmpty(); // 1 dijkstra, 2 bfs
    bool isEmptyEdgeQ();

    CNode * extractMin();
    bool contains(CNode * v);

    void sortKeys();
    void sortEdgesForPRIM();
    /**
     * for QUEUE with edges
     * @param a
     * @param b
     * @return
     */



    std::vector<CNode*> *getQueue() ;

    std::string toStringArray();

    CNode * dequeueForBFS();

    void sortMST();



    int size();
private:
    std::vector<CNode*> queue_;
    std::vector<CEdge*> edges_queue_;


};


#endif //GRAPHVIS_QUEUE_H
