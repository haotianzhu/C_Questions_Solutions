
import networkx as nx
from networkx import *
import pygraphviz as pgv





def find_hami_cycles(G,G_prime,root,current,num_vV):

	hamiltonian_cycles = []
	num_vV += 1
	# base case
	if not G_prime[current]:
		if num_vV == len(G.nodes()): # retrieved all vertices in G
			if root in G[current]: # found cycle
				return [[[min(current,root),max(current,root)]]]
		return []

	else:
		for v in G_prime[current]:
			e = [min(current,v),max(current,v)]

			hamiltonian_cycles += [ c+[e]  for c in find_hami_cycles(G, G_prime.subgraph(set(G_prime) - {current}),root,v ,num_vV)]

		return hamiltonian_cycles










if __name__ == '__main__':
	dotFile_or_edgeFile = raw_input("d or e: ")


	if dotFile_or_edgeFile in ['d','e']:	
		fp_name  = raw_input("input file: ")

		if dotFile_or_edgeFile == 'e':
			fp = open(fp_name,'r')
			G=nx.MultiGraph()
			for line in fp:
				line = line.split()
				if len(line) == 3:
					G.add_edge(line[0],line[1],label=line[2])
			fp.close()
			nx.drawing.nx_pydot.write_dot(G,'tempfile.dot')
			A = pgv.AGraph('tempfile.dot',strict = False)
		else:
			A = pgv.AGraph(fp_name,strict = False)

		A.layout(prog='dot')
		A.draw('file.png') 
		print("done...")


		G = nx.Graph(nx.drawing.nx_pydot.read_dot('tempfile.dot'))

		# here find min distance from given position node n
		start = str(raw_input("start vertex: "))

		min_wt = 0
		weights = get_edge_attributes(G,'label')

		# print(weights)
		min_cycle = None
		E =G.edges()
		for c in find_hami_cycles(G,G,start,start,0):
			sum_wt = 0
			for i in c:
				i = tuple(i)
				try:
					sum_wt += int(weights[i])
				except KeyError as e:
					sum_wt += int(weights[(i[-1],i[0])])
			if sum_wt < min_wt or min_wt <= 0:
				min_cycle = c
				min_wt = sum_wt

		if min_wt > 0:
			print(min_cycle)
			print(min_wt)
		else:
			print("no hamiltonian cycle in this graph")






