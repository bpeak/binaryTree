#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNode {
	char data;
	struct BinTreeNode *pLeftChild;
	struct BinTreeNode *pRightChild;
} BinTreeNode ;

typedef struct BinTree {
	struct BinTreeNode *pRootNode;
} BinTree;

BinTreeNode* makeNewNodeBT(char data) {
	BinTreeNode *pReturn = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	pReturn->data = data;
	pReturn->pLeftChild = NULL;
	pReturn->pRightChild = NULL;
	return pReturn;
}

BinTree* makeBinTree(char rootNodeData) {
	BinTree *pReturn = NULL;
	pReturn = (BinTree *)malloc(sizeof(BinTree));
	pReturn->pRootNode = makeNewNodeBT(rootNodeData);
	return pReturn;
}


BinTreeNode* addLeftChildNodeBT(BinTreeNode* pParentNode, char data) {
	BinTreeNode* pReturn = NULL;
	if (pParentNode->pLeftChild == NULL) {
		pParentNode->pLeftChild = makeNewNodeBT(data);
		pReturn = pParentNode->pLeftChild;
	}
	else {
		printf("already exist leftChild node");
	}
	return pReturn;
}

BinTreeNode* addRightChildNodeBT(BinTreeNode* pParentNode, char data) {
	BinTreeNode* pReturn = NULL;
	if (pParentNode->pRightChild == NULL) {
		pParentNode->pRightChild = makeNewNodeBT(data);
		pReturn = pParentNode->pRightChild;
	}
	else {
		printf("already exist rightChild node");
	}
	return pReturn;
}

BinTreeNode *getRootNodeBT(BinTree* pBinTree) {
	BinTreeNode *pReturn = NULL;
	if (pBinTree != NULL) {
		pReturn = pBinTree->pRootNode;
	}
	return pReturn;
}

void deleteBinTreeNode(BinTreeNode *pNode) {
	if (pNode != NULL) {
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}

void deleteBinTree(BinTree *pBinTree) {
	if (pBinTree != NULL) {
		deleteBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
	}
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode) {
	if (pNode != NULL) {
		inorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		printf("%c", pNode->data);
		inorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
	}
}

void inorderTraversalRecursiveBinTree(BinTree *pBinTree) {
	if (pBinTree != NULL) {
		printf("\n");
		inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
	}
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode) {
	if (pNode != NULL) {
		printf("%c", pNode->data);
		preorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		preorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
	}
}

void preorderTraversalRecursiveBinTree(BinTree *pBinTree) {
	if (pBinTree != NULL) {
		preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
		printf("\n");
	}
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode) {
	if (pNode != NULL) {
		postorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		postorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
		printf("%c", pNode->data);
	}
}

void postorderTraversalRecursiveBinTree(BinTree *pBinTree) {
	if (pBinTree != NULL) {
		printf("\n");
		postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
	}
}

int main() {
	BinTree *pBinTree = NULL;
	BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
	BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;

	pBinTree = makeBinTree('A');
	if (pBinTree != NULL) {
		pNodeA = getRootNodeBT(pBinTree);
		pNodeB = addLeftChildNodeBT(pNodeA, 'B');
		pNodeC = addRightChildNodeBT(pNodeA, 'C');
		if (pNodeB != NULL) {
			pNodeD = addLeftChildNodeBT(pNodeB, 'D');
		}
		if (pNodeC != NULL) {
			pNodeE = addLeftChildNodeBT(pNodeC, 'E');
			pNodeF = addRightChildNodeBT(pNodeC, 'F');
		}
		preorderTraversalRecursiveBinTree(pBinTree);
		inorderTraversalRecursiveBinTree(pBinTree);
		postorderTraversalRecursiveBinTree(pBinTree);
		deleteBinTree(pBinTree);
	}

	return 0;
}