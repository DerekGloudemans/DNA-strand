// File name: DNA_Strand.h
// Author: Derek Gloudemans	
// VUnetid: glouded
// Email: derek.gloudemans@vanderbilt.edu
// Class: CS201
// Date: 2/14/2015
// Honor statement: I have neither given nor recieved unauthorized help on this assignment.
// Assignment Number: 3
// Description: This will be an DNA_Strand implemented with a linked list.

#include "DNA_Strand.h"
#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;

// Constructor
// Create an empty DNA_Strand.
DNA_Strand::DNA_Strand() : mySize(0), myDNA(nullptr)
{
}


// Constructor
// Create an initialized DNA_Strand.
// A linked list the size of ipStr will be created and initialized
// Adds characters to the beginning of linked list
// with the characters in ipStr
DNA_Strand::DNA_Strand(const string & ipStr) : mySize(ipStr.length()), myDNA(nullptr)
{
	if (mySize != 0) 
	{
		DnaNodePtr temp;
		for (size_t n = 0; n < mySize; n++)
		{
			temp = new DnaNode;
			temp->val = ipStr.at(mySize - n - 1);
			temp->next = myDNA;
			myDNA = temp;
		}
	}
}


// The copy constructor. 
DNA_Strand::DNA_Strand(const DNA_Strand &rhs) : mySize(rhs.mySize), myDNA(nullptr)
{
	if (rhs.myDNA != nullptr)
	{
		
		DnaNodePtr nodeInRhs = rhs.myDNA;
		DnaNodePtr valAssigner = new DnaNode;
		DnaNodePtr nextAssigner;

		myDNA = valAssigner;
		valAssigner->val = nodeInRhs->val;
		nodeInRhs = nodeInRhs->next;

		while (nodeInRhs != nullptr)
		{
			nextAssigner = valAssigner;
			valAssigner = new DnaNode;
			valAssigner->val = nodeInRhs->val;
			nextAssigner->next = valAssigner;
			nodeInRhs = nodeInRhs->next;
		}
		valAssigner->next = nullptr;

	}
	
}


// Destructor
// Clean up the DNA_Strand (e.g., delete dynamically allocated memory).
DNA_Strand::~DNA_Strand ()
{
	while (myDNA != nullptr)
	{
		DnaNodePtr temp = myDNA;
		myDNA = myDNA->next;
		delete temp;
		
	}
	mySize = 0;
}


// Assignment operator performs an assignment by making a copy of
// the contents of parameter <rhs>
const DNA_Strand& DNA_Strand::operator= (const DNA_Strand& rhs)
{
	if (this != &rhs)
	{
		// Swaps tempCopy's DNA with myDNA; tempCopy and swapper are later deleted
		DNA_Strand tempCopy(rhs);
		swap(tempCopy.myDNA, myDNA);
		mySize = tempCopy.mySize;
	}
	return *this;
}



//toString
//Returns string equivalent of the DNA
string DNA_Strand::toString() const
{
	string outputString = "";
	for (DnaNodePtr current = myDNA; current != nullptr; current = current->next)
	{
		outputString = outputString + current->val;
	}
	return outputString;
}


// Set an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than the
// current size() of the DNA_Strand.
void DNA_Strand::set (char new_item, size_t index)
{
	if (!inRange(index))
	{
		throw  std::out_of_range("Index out of range");
	}

	DnaNodePtr temp = myDNA;
	for (size_t n = 0; n < index; n++)
	{
		temp = temp->next;
	}
	
	temp->val = new_item;
}

// Get an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than the
// current size() of the DNA_Strand.
char DNA_Strand::get (size_t index) const
{
	if (!inRange(index))
	{
		throw  std::out_of_range("Index out of range");
	}
	
	DnaNodePtr temp = myDNA;
	for (size_t n = 0; n < index; n++)
	{
	
		temp = temp->next;
	}
	

	return temp->val;
	
}


// Returns the size of the DNA
size_t DNA_Strand::size (void) const
{
   return mySize;
}


// isEqual
// Compare this DNA_Strand with rhs for equality. Returns true if the
// size()'s of the two DNA_Strands are equal and all the elements of the
// linked list are equal, else false.
bool DNA_Strand::isEqual (const DNA_Strand & rhs) const
{
	if (mySize != rhs.mySize)
	{
		return false;
	}

	else {
		for (DnaNodePtr temp1 = myDNA, temp2 = rhs.myDNA; temp1 != nullptr;
			temp1 = temp1->next, temp2 = temp2->next)
		{
			if (temp1->val != temp2->val)
			{
				return false;
			} // end of if

		} // end of for
	}

	return true;  
}


// search
// Look for target in current DNA strand and return index.
// Return -1 if not found.
int DNA_Strand::search(const string & target) const
{
	return search((size_t)0, target);
}

// search
// search with start position specified
// Look for target in current DNA strand and return index.
// Return -1 if not found.
int DNA_Strand::search(size_t pos, const string & target) const
{
	if (target == "")
	{
		return -1;
	}

	if (inRange(pos))
	{
		int n;
		DnaNodePtr temp = myDNA;
		// Advances in strand to the correct start index
		for (n = 0; n < pos; n++)
		{
			temp = temp->next;
		}
		
		// Searching process
		for (; n < mySize - target.length() + 1 && temp != nullptr; n++)
		{

			DnaNodePtr temp2 = temp;
			bool match = true;
			size_t k = 0;

			for (; k < target.length() && k+n < mySize && match == true; k++)
			{
				if (temp2->val == target.at(k))
				{
					temp2 = temp2->next;
					
				}
				else
				{
					match = false;
					
				}
			}
			
			if (match == true && k == target.length())
			{
				return n;
			}
			else
			{
				temp = temp->next;
			}
		}
	}

		return -1;
}

// search with start position specified by a DnaNodePtr
// Look for target in current DNA strand and return a pointer to it
// Return nullptr if not found.
DnaNodePtr DNA_Strand::search(DnaNodePtr startPtr, const string & target) const
{
	if (target.length() == 0 || target.length() > mySize)
	{
		return nullptr;
	}

	
	DnaNodePtr temp = myDNA;
	size_t n = 0;

	// Advances to startPtr if it exists in strand
	for (; temp != nullptr && temp != startPtr; temp = temp->next)
	{
		n++;
	}

	// Searching process
	for (; n < mySize - target.length() + 1 && temp != nullptr; n++)
	{
		DnaNodePtr temp2 = temp;
		bool match = true;
		size_t k = 0;

		for (; k < target.length() && k + n < mySize && match == true; k++)
		{
			if (temp2->val == target.at(k))
			{
				temp2 = temp2->next;
			}
			else
			{
				match = false;
			}
		}

		if (match == true && k == target.length())
		{
			return temp;
		}
		else
		{
			temp = temp->next;
		}
	}

	return nullptr; 
}


// cleave
// Removes from current DNA strand the sequence between the end of the 
// first occurrence of passed target sequence (e.g. "TTG"), through the end
// of the second occurence of the target sequence. 
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
// post: ACTTGA  (ACCTTG removed)
void DNA_Strand::cleave(const string & target)
{ 
	cleave(myDNA, target);
}


// cleave with start position specified.
// Start position is specified as an index.
void DNA_Strand::cleave(size_t pos, const string & target)
{
	if (inRange(pos))
	{
		DnaNodePtr tempPtr = myDNA;
		for (size_t n = 0; n < pos; n++)
		{
			tempPtr = tempPtr->next;
		}
		cleave(tempPtr, target);
	}
}

   
// cleave with start position specified.
// Start position is specified with a DnaNodePtr.
// If no cleave is performed, returns nullptr
// Otherwise, return pointer to next node after the cleave, ie,
//   returned ptr points to the node after the cleaved sequence (could be
//   nullptr if the cleaved sequence was at the end of the strand).
DnaNodePtr DNA_Strand::cleave(DnaNodePtr startPtr, const string & target)
{
	if (target.length() == 0 || target.length() > mySize)
	{
		return nullptr;
	}
	// Creates a DnaNodePtr that points to the last node in the target
	DnaNodePtr firstPtr = search(startPtr, target);
	if (firstPtr == nullptr)
	{
		return nullptr;
	}
	for (size_t n = 0; n < target.length()-1; n++)
	{
		firstPtr = firstPtr->next;
	}

	//Creates a node that points to the node after the end of the second target
	DnaNodePtr secondPtr = search(firstPtr->next, target);
	if (secondPtr == nullptr)
	{
		return nullptr;
	}
	for (size_t n = 0; n < target.length(); n++)
	{
		secondPtr = secondPtr->next;
	}

	size_t deletions = 0;
	while (firstPtr->next != secondPtr)
	{
		deleteNextNode(firstPtr);
		deletions += 1;
	}

	mySize -= deletions;
	return firstPtr->next;
	
}


// cleaveAll
// Removes from current DNA strand the sequence between pairs of target 
// sequence, i.e. from the end 1 through the end of 2, from the end of 3 
// through the end of 4, etc, but NOT from the end of 2 through the end 3,
// or from the end of 4 through the end of 5.
// (Make sure that you understand the specification)
// pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
// post: ACTTGGGTTGCC (ATTG and CTTG removed)
void DNA_Strand::cleaveAll(const string & target)
{
	DnaNodePtr temp = myDNA;
	while (temp != nullptr)
	{
		temp = cleave(temp, target);
	}
}


// countEnzyme
// Counts the number of occurences of a single character target sequence
// in the DNA strand.
size_t DNA_Strand::countEnzyme(char target) const
{
	size_t counter = 0;
	DnaNodePtr temp = myDNA;
	for (; temp != nullptr; temp = temp->next)
	{
		if (temp->val == target)
		{
			counter += 1; 
		}
		
	}
	return counter;
}


// countEnzyme -- overloaded
// string parameter version
// Counts non-overlapping instances of the target
// Eg, the target "AAA" appears 3 non-overlapping times in the DNA "AAAAAAAAA"
// Precondition: the target is a nonempty string.
size_t DNA_Strand::countEnzyme(const string & target) const
{
	size_t counter = 0;
	if (target.length() == 0 || target.length() > mySize)
	{
		return 0;
	}

	DnaNodePtr temp = search(myDNA, target);

	while (temp != nullptr)
	{
		counter += 1;
		for (size_t n = 0; temp != nullptr && n < target.length(); n++)          
		{
			temp = temp->next;
		}
		temp = search(temp, target);
	}
	return counter;
}


// inRange : helper function
// Returns true if index is within range, i.e., 0 <= index < mySize 
// else returns false.
bool DNA_Strand::inRange (size_t index) const
{
	return (0 <= index && index < mySize);
}


// append (accepting a string parameter)
// Append the characters of the parameter to the end of the current DNA.
// Example: if myDNA contained ACTTGA and "ACCTG" was received as a parameter, 
// then afterward myDNA will contain ACTTGAACCTG
void DNA_Strand::append(const string & rhs)
{
	DNA_Strand temp(rhs);
	append(temp);
}


// append (accepting a DNA_Strand parameter)
// Append the characters of the parameter to the end of the current DNA.
// Example: if myDNA contained ACTTGA and ACCTG was received as a parameter, 
// then afterward myDNA will contain ACTTGAACCTG
void DNA_Strand::append(const DNA_Strand & rhs)
{
	DnaNodePtr strandPtr = myDNA;
	DnaNodePtr rhsPtr = rhs.myDNA;
	size_t insertions = 0;
	if (rhsPtr != nullptr)
	{
		if (strandPtr == nullptr)
		{
			strandPtr = new DnaNode;
			strandPtr->val = rhsPtr->val;
			strandPtr->next = nullptr;
			myDNA = strandPtr;
			rhsPtr = rhsPtr->next;
			insertions = 1;
		}
		else
		{
			while (strandPtr->next != nullptr)
			{
				strandPtr = strandPtr->next;
			}
		}

		// At this point, strandPtr points to the last node in a strand of at least 1 node
		// And rhsPtr points to the next value to be appended

		for (; insertions < rhs.mySize; insertions++)
		{
			insertAfterNode(strandPtr, rhsPtr->val);
			rhsPtr = rhsPtr->next;
			strandPtr = strandPtr->next;
		}

		mySize += insertions;
	} 
	
}



// splice (accepts 2 Strings representing sequences)
// finds first pair of targets in current DNA strand and replaces
// the sequence between the end of the first target through the end of the 
// second with the insertSequence. 
// If two instances of the target are not found, 
// then no changes are made.
void DNA_Strand::splice(const string & target, const string & insertSequence)
{
	splice(myDNA, target, insertSequence);
}


// splice (also accepting a starting location specified as an index)
void DNA_Strand::splice(size_t pos, const string & target, const string & insertSequence)
{
	DnaNodePtr temp = myDNA;
	size_t counter = 0;
	for (; counter < pos && temp != nullptr && temp->next != nullptr; counter++)
	{
		temp = temp->next;
	}
	
	// strand must have enough indices to advance to pos
	if (counter == pos)
	{
		splice(temp, target, insertSequence);
	}
}


// splice (also accepting a starting location specified with a DnaNodePtr)
// If no splice is performed, returns nullptr
// Otherwise, return a pointer to the next node after the inserted sequence
DnaNodePtr DNA_Strand::splice(DnaNodePtr startPtr, const string & target, const string & insertSequence)
{
	if (target.length() == 0 || target.length() > mySize)
	{
		return nullptr;
	}

	// Uses the cleave method to carry out the removal portion of the splice
	size_t initialSize = mySize;
	DnaNodePtr firstNodeAfterTarget = cleave(startPtr, target);
	size_t sizeAfterCleave = mySize;
	if (firstNodeAfterTarget == nullptr && initialSize == sizeAfterCleave)
	{
		return nullptr;
	}

	// Finds the last node of the first target by finding the node with a next value of 
	// firstNodeAfterTarget
	DnaNodePtr insertionPtr = myDNA;
	while (insertionPtr->next != firstNodeAfterTarget)
	{
		insertionPtr = insertionPtr->next;
	}

	// Creates a new node with each index of insertSequence, inserting it into the strand
	// after insertionPtr in a chain
	for (size_t n = 0; n < insertSequence.length(); n++)
	{
		insertAfterNode(insertionPtr, insertSequence.at(n));
		insertionPtr = insertionPtr->next;
	}

	mySize += insertSequence.length();

	return firstNodeAfterTarget;
}


// deleteNextNode deletes the node following the node passed as a parameter and sets firstNode's
// next value to that of the deleted node
void DNA_Strand::deleteNextNode(DnaNodePtr firstNode)
{
	DnaNodePtr secondNode = firstNode->next;
	firstNode->next = secondNode->next;
	delete secondNode;
}


// insertAfterNode inserts a new node with the given character value after the node passed as 
// a parameter, setting the new node's next value as the parameter's previous next value
void DNA_Strand::insertAfterNode(DnaNodePtr firstNode, char newVal)
{
	DnaNodePtr newPtr = new DnaNode;
	newPtr->val = newVal;
	newPtr->next = firstNode->next;
	firstNode->next = newPtr;
	newPtr = nullptr;
}




