#include <iostream>
#include <sstream>

const int HASH_SIZE = 100;

template<typename Item>
class HashTable
{
private:
	struct Node
	{
		Item currentItem;
		Node* next;
		Node() { next = NULL; }
	};

	Node**		m_pHead;		// Array of Linked List declaration - front of each hash table cell
	int			m_iHashSize;	// Size of the hash table
	int			m_iTotElems;	// Total number of Elements in the hash table
	int*		m_pBucketSize;	// Total number of Elements in each hash table cell

private:
	/* Function: Adds new item to the end of the list at a given index in the hash table
	Precondition: Hash table has been created and not full
	Postcondition: Item is in the hash table */
	void Append(const int& idx, const Item& newItem);

public:
	/* Function: Constructor initializes hash table
	Precondition: None
	Postcondition: Define private variables */
	HashTable(const int hashSize = HASH_SIZE);

	/* Function: Determine whether hash table is empty at the given index
	Precondition: Hash table has been created
	Postcondition: The function = true if the hash table is empty
	and the function = false if the hash table is not empty */
	bool IsEmpty(const int& idx);

	/* Function: Determine whether hash table is full
	Precondition: Hash table has been created
	Postcondition: The function = true if the hash table is full
	and the function = false if the hash table is not full */
	bool IsFull();

	/* Function: Computes and returns a unique hash key for a given item.
	The returned value is the given cell where the item is positioned
	Precondition: Hash table has been created and not full
	Postcondition: The hash index is returned*/
	int Hash(const Item& newItem);

	/* Function: Adds new item to the back of the list  at a given index in the hash table
	A unique hash index is automatically generated for each new item
	Precondition: Hash table has been created and not full
	Postcondition: Item is in the hash table */
	void Insert(const Item& newItem);

	/* Function: Removes the first instance from the table whose value is "delItem"
	Optional second parameter indicates the index where delItem is located
	Precondition: Hash table has been created and not empty
	Postcondition: The function == true if delItem is found and the function = false
	if delItem is not found */
	bool Remove(Item delItem, int idx = -1);

	/* Function: Sort the items in the table at the given index 
	Precondition: The hash table has been initialized 
	Postcondition: The hash table is sorted */
	void Sort(const int& idx);

	/* Function: Print the items in the table at the given index
	Precondition: The hash table has been initialized
	Postcondition: The items in the cell at given index is printed */
	void Print(const int& idx);

	/* Function: Return the size of the hash table
	Precondition: The hash table has been initialized
	Postcondition: The size of the hash table is returned */
	int GetTableSize();

	/* Function: Return the total number of elements contained in the hash table
	Precondition: The hash table has been initialized
	Postcondition: The total number of elements contained in the hash table is returned */
	int GetTotalElements();

	/* Function: Return the number of items contained in the hash table cell at the given index
	Precondition: The hash table has been initialized
	Postcondition: The size of the given index cell is returned */
	int GetBucketSize(const int& idx);

	/* Function: Return the number of time search item appears in the hash table
	Precondition: The hash table has been initialized
	Postcondition: The number of time search item appears in the hash table */
	int Count(Item searchItem);

	/* Function: Initializes hash table to an empty state
	Precondition: Hash table has been created
	Postcondition: Hash table no longer exists */
	void MakeEmpty();

	/* Function: Remove the hash tables
	Precondition: Hash table has been declared
	Postcondition: Hash table no longer exists */
	~HashTable();

	/* Function: Class Iterator declaration
	Precondition: Hash table has been declared
	Postcondition: Iterator is declared */
	class Iterator;

	/* Function: Return the beginning of the current hash cell list
	Precondition: Hash table has been created
	Postcondition: The beginning of the current hash cell is returned */
	Iterator begin(const int& idx);

	/* Function: Return the end of the current hash cell list
	Precondition: Hash table has been created
	Postcondition: The end of the current hash cell is returned */
	Iterator end(const int& idx);
};

template<typename Item>
class HashTable<Item>::Iterator : public std::iterator<std::forward_iterator_tag, Item>
								/*, public HashTable<Item>*/
{
private:
	Node*	itHead;
	Item	junk;

public:
	// Constructor
	Iterator(Node* otherIterator)
	{
		itHead = otherIterator;
	}
	// Destructor
	~Iterator() {}

	Iterator& operator=(const Iterator& other)
	{
		itHead = other.itHead;
		return *this;
	}

	bool operator==(const Iterator& other)
	{
		return (itHead == other.itHead);
	}
	
	bool operator!=(const Iterator& other)
	{
		return (itHead != other.itHead);
	}

	Iterator& operator++()
	{
		if (itHead != NULL)
			itHead = itHead->next;
	}
};




template class HashTable<long>;
template class HashTable<double>;
template class HashTable<std::string>;