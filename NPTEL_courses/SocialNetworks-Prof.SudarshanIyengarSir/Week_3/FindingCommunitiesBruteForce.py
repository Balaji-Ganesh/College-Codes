import networkx as nx
import itertools      # to pick the combinations from the list

def find_communities_via_bruteForce(G):
    """
        This function takes a graph, and returns the best possible division. ..?...
    """
    nodes = G.nodes()
    n = G.number_of_nodes()
    
    # lets get all the node combinations of the first community..
    first_community = []
    for i in range(1, n//2 + 1):  # No need of checking till """"n"""", 1st has k nodes, then 2nd will have n-k nodes, there is no need of checking for till n, as they will be the same. . `+1`, is due to range's upperbound exclusiveness.
        combination = [list(combi) for combi in itertools.combinations(nodes, i)]  # Getting all the possible combinations with "i" limit
        first_community.extend(combination)  # Used extend, so as to place the new combinations at end of list, not the list of combinations as one element(which happens when used .append(..)) -- try out to know difference..
        
        # Now its the turn for second _community ... this is going to be simple.. as we need not find the combinations again, can just use those which are not in nodes,
    second_community = []
    # Subtraction can be easily applied via `set.. -- which inturn returns a set..

    # come let's do it over all the elements of the first_community...
    for idx in  range(len(first_community)):
        second_community.append(list(set(nodes) - set(first_community[idx])))
        
    # So, let's keep track of that ratio.. (described below..)
    num_intra_edges1 = []
    num_intra_edges2 = []
    num_inter_edges = []
    # Let's keep track that every division..
    ratio = []
    
    # We need only the count of edges.. so let's do it for all the combinations of the nodes..
    # for the first_community..
    for idx in range(len(first_community)):
        num_intra_edges1.append(G.subgraph(first_community[idx]).number_of_edges()) # sotring no of intra-edges in the first_community (for each combination,,)

    # for the second-community   
    for idx in range(len(second_community)):
        num_intra_edges2.append(G.subgraph(second_community[idx]).number_of_edges())
        
    # Getting the number of inter edges...
    total_edges = G.number_of_edges()
    for idx in range(len(first_community)):
        num_inter_edges.append(total_edges - num_intra_edges1[i] - num_intra_edges2[i])
        
    # Now we have values ready for finding the ratio..
    for idx in range(len(first_community)):
        num_intra_edges = num_intra_edges1[i] + num_intra_edges2[i]
        ratio.append((num_intra_edges / num_inter_edges[i]))
        
    # Its time to get the max_ratio.. which tells the max-benefit..
    max_value = max(ratio)
    max_index = ratio.index(max_value)  # We need the index at which there is max_division, so that we can pull out that max_division..
    max_value, max_index
    
    # Let's know the divisions.. 
    return (first_community[max_index], second_community[max_index])