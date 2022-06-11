cmake_minimum_required(VERSION 3.17)
project(GraphVis)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic -Wno-long-long -O2 -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(GraphVis main.cpp graph/CEdge.h graph/CEdge.cpp graph/CNode.cpp graph/CNode.h graph/CGraph.h graph/CGraph.cpp algorithms/BellmanFord.cpp algorithms/BellmanFord.h algorithms/BreadthFirstSearch.cpp algorithms/BreadthFirstSearch.h algorithms/DepthFirstSearch.cpp algorithms/DepthFirstSearch.h algorithms/Dijkstra.cpp algorithms/Dijkstra.h algorithms/Kruskal.cpp algorithms/Kruskal.h algorithms/Prim.cpp algorithms/Prim.h algorithms/SingleSourceShortestPathInDAG.cpp algorithms/SingleSourceShortestPathInDAG.h algorithms/StronglyConnectedComponents.cpp algorithms/StronglyConnectedComponents.h algorithms/TopologicalSort.cpp algorithms/TopologicalSort.h accessories/Queue.cpp accessories/Queue.h accessories/Set.cpp accessories/Set.h)