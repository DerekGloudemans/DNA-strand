// File name: DNA_Strand.h
// Author: Derek Gloudemans	
// VUnetid: glouded
// Email: derek.gloudemans@vanderbilt.edu
// Class: CS201
// Date: 2/14/2015
// Honor statement: I have neither given nor recieved unauthorized help on this assignment.
// Assignment Number: 3
// Description: This will be an DNA_Strand implemented with a linked list.

// Change the following line as appropriate -- this is the only line you should change in this file
// besides filling in the comment header above.
#define GRAD_STUDENT 0   // if you are a grad student, set this to 1, otherwise set it to 0


#ifndef DNA_STRAND_H
#define DNA_STRAND_H

#include <string>
using namespace std;

// the structure of a linked list node contains a single char and a next pointer
struct DnaNode
{
   char val;
   DnaNode *next;
};

typedef DnaNode* DnaNodePtr;


class DNA_Strand
{
	
private:
   // Returns true if index is within range of the current DNA_Strand
   // else returns false.
   bool inRange (size_t index) const;

   // Current size of the DNA_Strand; i.e., how many elements are in the linked list
   size_t mySize;

   // DNA_Strand's linked list. Ie, our "head" pointer
   DnaNodePtr myDNA;

   // deleteNextNode deletes the node following the node passed as a parameter and sets firstNode's
   // next value to that of the deleted node
   void deleteNextNode(DnaNodePtr firstNode);

   // insertAfterNode inserts a new node with the given character value after the node passed as 
   // a parameter, setting the new node's next value as the parameter's previous next value
   void insertAfterNode(DnaNodePtr firstNode, char newVal);

public:	

   // Create an empty DNA_Strand.
   DNA_Strand ();  // deafult ctor

   // Create an initialized DNA_Strand.
   // A linked list the size of ipStr will be created and initialized
   // with the characters in ipStr
   DNA_Strand (const string & ipStr);  // ctor that takes a string

   // The copy constructor. 
   DNA_Strand (const DNA_Strand &rhs);

   // Destructor
   // Clean up the DNA_Strand (e.g., delete dynamically allocated memory).
   ~DNA_Strand ();

   // Assignment operator performs an assignment by making a copy of
   // the contents of parameter <rhs>
   const DNA_Strand& operator= (const DNA_Strand& rhs);


   //toString
   //Returns string equivalent of the DNA
   string toString() const;

   // Set an item in the DNA_Strand at location index. Throws
   // <std::out_of_range> if index is out of range, i.e., larger than the
   // current size() of the DNA_Strand.
   void set (char new_item, size_t index);

   // Get an item in the DNA_Strand at location index. Throws
   // <std::out_of_range> if index is out of range, i.e., larger than the
   // current size() of the DNA_Strand.
   char get (size_t index) const;

   // Returns the current size of the DNA.
   size_t size (void) const;

   // Compare this DNA_Strand with rhs for equality. Returns true if the
   // size()'s of the two DNA_Strands are equal and all the elements of the
   // linked list are equal, else false.
   bool isEqual(const DNA_Strand & rhs) const;

   // search
   // Look for target in current DNA strand and return index.
   // Return -1 if not found.
   int search(const string & target) const;

   // search with start position specified
   // Look for target in current DNA strand and return index.
   // Return -1 if not found.
   int search(size_t pos, const string & target) const;

   // search with start position specified by a DnaNodePtr
   // Look for target in current DNA strand and return a pointer to it
   // Return nullptr if not found.
   DnaNodePtr search(DnaNodePtr startPtr, const string & target) const;

   // cleave
   // Removes from current DNA strand the sequence between the end of the 
   // first occurrence of passed target sequence (e.g. "TTG"), through the end
   // of the second occurence of the target sequence. 
   // pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
   // post: ACTTGA  (ACCTTG removed)
   void cleave(const string & target);

   // cleave with start position specified.
   // Start position is specified as an index.
   void cleave(size_t pos, const string & target);

   // cleave with start position specified.
   // Start position is specified with a DnaNodePtr.
   // If no cleave is performed, returns nullptr
   // Otherwise, return pointer to next node after the cleave, ie,
   //   returned ptr points to the node after the cleaved sequence (could be
   //   nullptr if the cleaved sequence was at the end of the strand).
   DnaNodePtr cleave(DnaNodePtr startPtr, const string & target);

   // cleaveAll
   // Removes from current DNA strand the sequence between pairs of target 
   // sequence, i.e. from the end 1 through the end of 2, from the end of 3 
   // through the end of 4, etc, but NOT from the end of 2 through the end 3,
   // or from the end of 4 through the end of 5.
   // (Make sure that you understand the specification)
   // pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
   // post: ACTTGGGTTGCC (ATTG and CTTG removed)
   void cleaveAll(const string & target);

   // countEnzyme
   // Counts the number of occurences of a single character target sequence
   // in the DNA strand.
   size_t countEnzyme(char target) const;

   // countEnzyme -- overloaded
   // string parameter version
   // Counts non-overlapping instances of the target
   // Eg, the target "AAA" appears 3 non-overlapping times in the DNA "AAAAAAAAA"
   // Precondition: the target is a nonempty string.
   size_t countEnzyme(const string & target) const;

   // append (accepting a string parameter)
   // Append the characters of the parameter to the end of the current DNA.
   // Example: if myDNA contained ACTTGA and "ACCTG" was received as a parameter, 
   // then afterward myDNA will contain ACTTGAACCTG
   void append(const string & rhs);

   // append (accepting a DNA_Strand parameter)
   // Append the characters of the parameter to the end of the current DNA.
   // Example: if myDNA contained ACTTGA and ACCTG was received as a parameter, 
   // then afterward myDNA will contain ACTTGAACCTG
   void append(const DNA_Strand & rhs);

   // splice (accepts 2 Strings representing sequences)
   // finds first pair of targets in current DNA strand and replaces
   // the sequence between the end of the first target through the end of the 
   // second with the insertSequence. 
   // If two instances of the target are not found, 
   // then no changes are made.
   void splice(const string & target, const string & insertSequence);

   // splice (also accepting a starting location specified as an index)
   void splice(size_t pos, const string & target, const string & insertSequence);

   // splice (also accepting a starting location specified with a DnaNodePtr)
   // If no splice is performed, returns nullptr
   // Otherwise, return a pointer to the next node after the inserted sequence
   DnaNodePtr splice(DnaNodePtr startPtr, const string & target, const string & insertSequence);


   ///////////////////////////////////////////////////
   // THE FOLLOWING METHODS ARE FOR GRAD STUDENTS ONLY

#if GRAD_STUDENT==1

   static const char MARKER = '#';

   // insertMarker
   // Find all non-overlapping occurrences of the target sequence and insert
   // the '#' marker AFTER each of them.
   // pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
   // post: ACTTG#ATTG#GGTTG#CTTG#CC
   void insertMarker(const string & target);

   // deleteMarker
   // Delete all the '#' markers that occur in the strand, shifting data to the
   // left as appropriate
   void deleteMarker();

   // countMarker
   // return the number of markers that exist in the strand
   size_t countMarker();


   // spliceAll (accepts 2 Strings representing sequences)
   // Similar to cleaveAll finds pairs of targets in current DNA strand and replaces
   // the sequence between the end of the first target through the end of the 
   // second with the insertSequence. If two instances of the target are not found, 
   // then no changes are made.
   void spliceAll(const string & target, const string & insertSequence);


#endif
   // END GRAD STUDENT ONLY METHODS
   ///////////////////////////////////////////////////


};
#endif /* ifndef */
