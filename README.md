# Package-Installation-Order
## A program to decide the order of the installation of packages on the basis of dependencies on one another.

### How to solve it:

The packages can be set in a tree which is then sorted into an array according to the rules given below. Each node is set with an initial Boolean value of 0 which changes to 1 when added in the array and hence, it doesn't undergo the check more than once.

/*The properties of the tree will be:

 Nodes : packages 
 Child nodes: packages on which the parent nodes are dependent.

/*Sorting method:

1. The tree is traversed until a node with no child is encountered. That node is then added to the array (boolean value = 1).
2. The parent node's next child is checked using similar process. 
3. This is repeated until all the nodes are added.
