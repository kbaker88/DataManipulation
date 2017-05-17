#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

void DataStruct_HashTable()
{

}

struct BinarySearchTreeNode
{
	BinarySearchTreeNode* LeftChild, *Parent, *RightChild;
	int Data;
};

void DataStruct_BinarySearchTreeAdd(BinarySearchTreeNode* Tree, 
	int Value)
{
	bool Exit = false;
	if (Tree)
	{
		if (!Tree->Data)
		{
			Tree->Data = Value;
		}
		else
		{
			while (!Exit)
			{
				if (Value < Tree->Data)
				{
					if (Tree->LeftChild)
					{
						Tree = Tree->LeftChild;
					}
					else
					{
						Tree->LeftChild = new BinarySearchTreeNode{};
						Tree->LeftChild->Parent = Tree;
						Tree = Tree->LeftChild;
						Tree->Data = Value;
						Exit = true;
					}
				}
				else
				{
					if (Tree->RightChild)
					{
						Tree = Tree->RightChild;
					}
					else
					{
						Tree->RightChild = new BinarySearchTreeNode{};
						Tree->RightChild->Parent = Tree;
						Tree = Tree->RightChild;
						Tree->Data = Value;
						Exit = true;
					}
				}
			}
		}
	}
}

void DataStruct_BinarySearchTreeRemove()
{

}


struct RedBlackNode
{
	RedBlackNode* LeftChild, *Parent, *RightChild;
	int Data;
	bool Color; // 1 is red, 0 is black
};

void DataStruct_RedBlackTree()
{
	//The root is black
	//All leaves(null) are black
	//If a node is red, then both its children are black
	//Every path from a given node to any descendant null leaf contains
	//the same number of black nodes.



}

#endif
