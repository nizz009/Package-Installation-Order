# Package-Installation-Order
## A program to decide the order of the installation of packages on the basis of dependencies on one another.

### Problem Explanation:
Softwares need the installation of other packages before they can be installed ("dependent" on the existence of other packages). Though there are many package managers available in different OSes to make this task simpler, this program aims to sort those packages and find a suitable order to install them.

### How to solve it:
The problem have been/ is aimed to be solved in two different methods. Though both use graphs, the sorting method is different and hence, it's divided into two different methods: one using trees, and one using graphs.

#### Method 1: (Using trees)
The packages are set in a tree which is then sorted into an array according to some rules (given below). Each node is set with an initial Boolean value of 0 which changes to 1 when added in the sorted array and hence, no node undergoes the check more than once.

*The properties of the tree will be:*

 Node: packages
 
 Child nodes: packages on which the parent nodes are dependent on.

*Sorting method:*

1. The tree is traversed until a node with no child is encountered. That node is then added to the array (new boolean value = 1).
2. The parent node's next child is checked using similar process. 
3. This is repeated until all the nodes are added.

##### Note: 
 If a node's boolean value is set to 1, we simply move on to the next child of the parent node as that node is added already.

#### Method 2: (Using graph)
The packages are represented in the form of a graph where:

Node: package information 

Arc <A, B>: the dependency of package B on package A. 

Any node not containing any "dependency arcs" (i.e. 0 dependency arcs) are added into the sorted list and the number of "dependency arcs" of all the other successor nodes that were dependent on that package is decreased by one. 
