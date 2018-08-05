#include <iostream>

const int HASH_SIZE = 100;

template<class Item>
class HashTable
{
private:
	struct Node
	{
		Item currentItem;
		Node* next;
	};

	node**	m_pHead;		// Array of Linked List declaration - front of each hash table cell
	int		m_iHashSize;	// Size of the hash table
	int		m_iTotElems;	// Total number of Elements in the hash table
	int*	m_pBucketSize;	// Total number of Elements in each hash table cell

public:
	/* Function: Constructor initializes hash table
	Precondition: None
	Postcondition: Define private variables */
	HashTable(const int& hashSize);

	/* Function: Determine whether hash table is empty
	Precondition: Hash table has been created
	Postcondition: The function = true if the hash table is empty
	and the function = false if the hash table is not empty */
	bool IsEmpty();

	/* Function: Determine whether hash table is full
	Precondition: Hash table has been created
	Postcondition: The function = true if the hash table is full
	and the function = false if the hash table is not full */
	bool IsFull();

	/* Function: Computes and returns a unique hash key for a given item.
	The returned value is the given cell where the item is positioned
	Precondition: Hash table has been created and not full
	Postcondition: The hash index is returned*/
	int Hash(Item newItem);
};