import networkx as nx
import matplotlib.pyplot as plt
G = nx.Graph()
G.add_nodes_from([1,2,3])
G.add_edges_from([(1,2),(1,3),(2,3)])
print(G)

G.add_nodes_from([4,5,6,7])

G.add_edge(1,4)
G.add_edge(1,5)
G.add_edge(2,4)
G.add_edge(3,5)
G.add_edge(5,6)
G.add_edge(7,3)
G.add_edge(7,6)

color_list = ["silver", "red", "lightblue", "violet", "limegreen", "green", "darkorange"]
nx.draw(G,node_color=color_list, with_labels=True)
plt.show()
G.remove_node(2)
G.remove_edge(1,3)
nx.draw(G, with_labels=True)
plt.show()