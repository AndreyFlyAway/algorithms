/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val == 1, the second node with val == 2, and
so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite
graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the
copy of the given node as a reference to the cloned graph.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> observed_nodes;
        Node* new_graph = new Node(node->val);
        clone_dfs(new_graph, node, observed_nodes);
        return new_graph;
    }

    void clone_dfs(Node* target_node, Node* orig_node, 
                   std::unordered_map<Node*, Node*>& observed_nodes) {
        if(observed_nodes.count(orig_node)) {
            return;
        }
        observed_nodes[orig_node] = target_node;
        for(size_t i = 0 ; i < orig_node->neighbors.size() ; ++i) {
            if(observed_nodes.count(orig_node->neighbors[i])) {
                target_node->neighbors.push_back(observed_nodes[orig_node->neighbors[i]]);
            } else {
                Node* new_node = new Node(orig_node->neighbors[i]->val);
                target_node->neighbors.push_back(new_node);
                clone_dfs(new_node, orig_node->neighbors[i], observed_nodes);
            }
        }
    }
};

int main() {

}