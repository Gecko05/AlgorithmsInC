Graphs


## Graphs
- A *graph* is a set of nodes together with a set of edges that connect pairs of distinct nodes.
- A **connected** graph exists if there is a simple path connecting any pair of nodes.
- A **simple path** is a sequence of edges from one node to the other where no node appears twice.
- A **cycle** is a path where the first and last nodes are the same.
- A graph is a tree if it has:
	- N - 1 edges and no cycles.
	- N - 1 edges and is connected.
	- Exactly one simple path connects each pair.
	- Is connected, but does not remain connected if any edge is removed.
	- 
	
## Depth First Search
- Takes time proportional to nodes + edges, for the adjacency list representation.
- Representing the graph takes space proportional to E, while union-find solutions are proportional to V.
- 