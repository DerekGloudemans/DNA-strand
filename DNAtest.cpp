// File name: DNAtest.cpp
// Author: Derek Gloudemans	 
// VUnetid: glouded	
// Email: derek.gloudemans@vanderbilt.edu
// Class: CS201
// Date: 2/7/2015
// Honor statement: I have neither given nor received  unauthorized help on this assignment.
// Assignment Number: 3
// 
// Description: Testing of DNA_Strand ADT


#include <iostream>
#include <stdexcept>
#include "DNA_Strand.h"
using namespace std;

// Test the functions of the DNA strand class
int main()
{
	//-----------------------Tests on the default DNA_Strand() constructor---------------------//
	//-----------------------------and isEqual() and size() methods----------------------------//
	cout << "Tests on the DNA_Strand() constructor:" << endl;
	cout << "-------------------------------------" << endl;


	// Creates 2 empty DNA strands
	DNA_Strand dna_1, dna_2;

	// Verifies that the default constructor works properly
	DNA_Strand dna90 = DNA_Strand();
	if (dna90.size() != 0) {
		cout << " DNA_Strand() Test 1 FAIL" << endl;
	}
	else
	{
		cout << "mySize is correctly set to 0" << endl;
	}

	// Verifies that the isEqual() method works for two empty DNA strands 
	// and that two empty DNA strands are exactly the same
	if (!dna_1.isEqual(dna_2)) {
		cout << "DNA_Strand() Test 2 FAIL" << endl;
	}
	else {
		cout << "Equal test works on two blank DNA." << endl;
	}


	// Verifies that a DNA_Strand that has not had values assigned has mySize = 0
	// Also verifies that size() method works at minimum value (0)
	if (dna_1.size() != 0) {
		cout << "DNA_Strand() Test 3 FAIL" << endl;
		}
		else {
		cout << "Initial size for blank DNA is correctly assigned and returned." << endl;
		}


	// Verifies that the DNA_Strand does not contain any entries
	try {
		cout << "Expect \"out_of_range\" exception:" << endl;
		dna_1.get(0);
		cout << "EXCEPTION ERROR. You should not see this message." << endl;
		cout << "DNA_Strand() Test 4 FAIL" << endl;
	}
	catch (std::out_of_range & excpt) {
		cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
	}
	catch (...) {
		cout << "Threw the wrong exception." << endl;
	}




	//--------------Tests on the DNA_Strand(const string & ipStr) constructor------------------//
	//----------------------------- isEqual() and size() methods----------------------------//
	cout << endl << "Tests on the DNA_Strand(string) constructor:" << endl;
	cout <<			"-------------------------------------------" << endl;

	// creates 2 non-empty DNA strands
	string ipStr = "ABCCTG";
	DNA_Strand dna(ipStr);
	DNA_Strand dna2(ipStr);


	// Verifies equality of two nonempty strings
	// Also tests the isEqual() method on two nonempty strings
	if (!dna.isEqual(dna2)) {
		cout << "DNA_Strand(string) Test 1 FAIL" << endl;
	}
	else{
		cout << "Equal test works on nonempty DNA strands." << endl;
	}

	// Verifies the next value of the last node is nullptr
	

	// Verifies isEqual() is reflective
	if (!dna_2.isEqual(dna_1)) {
		cout << "DNA_Strand(string) Test 2 FAIL" << endl;
	}
	else {
		cout << "Equal test is reflective." << endl;
	}


	// Verifies length of DNA Strand is the same as the length of its input string
	// Also verifies that the size() method works correctly with a non-sero length strand
	if (dna.size() != ipStr.length()) {
		cout << "DNA_Strand(string) Test 3 FAIL" << endl;
	}
	else {
		cout << "DNA strand and source string have same length." << endl;
	}



	//Creates a new DNA strand from a string 
	string ipStr2 = "ACTGACTGACTCGATCGATCGACTCGACTCGATCGATCGATCGAACCAGCCGACRGGCACGC";
	DNA_Strand dna3(ipStr2);


	// Verifies that the isEqual() method returns false for two non-equal strands
	if (dna3.isEqual(dna)){
		cout << " DNA_Strand(string) Test 4 FAIL" << endl;
	}
	else {
		cout << "isEqual() method properly returns \"false\"." << endl;
	}


	DNA_Strand dna10("ACTGACTGACTCGATCGATCGACTCGACTCGATCGATCGATCGAACCAGCCGVCRGGCACGC");
	// Verifies that the isEqual() method returns false for two non-equal strands of same length
	if (dna3.isEqual(dna)){
		cout << " DNA_Strand(string) Test 5 FAIL" << endl;
	}
	else {
		cout << "isEqual() method properly returns \"false\"." << endl;
	}
	
	
	// Verifies that each index of the DNA strand matches each character in the source string
	bool dontMatch = 0;
	for (size_t n = 0; n < dna3.size(); n++) {
		if (ipStr2.at(n) != dna3.get(n)){
			dontMatch++;
		}
	}
	if (dontMatch) {
		cout << "DNA_Strand(string) Test 6 FAIL" << endl;
	}
	else {
		cout << "Indices of DNA strand match first characters of source string." << endl;
	}


	//------------------------Tests on the copy constructor-----------------------------//
	cout << endl << "Tests on the copy constructor:" << endl;
	cout <<	"-----------------------------" << endl;



	// Verifies that all fields in a copied dna strand are the same
	DNA_Strand dnaCopy2(dna2);
	bool pass = true;
	if (dnaCopy2.size() != dna2.size())
	{
		pass = false;
	}
	
	else
	{
		for (size_t n = 0; n < dna2.size(); n++ && pass)
		{
			if (dnaCopy2.get(n) != dna2.get(n))
			{
				pass = false;
			}
		}
	}

	if (!pass)
	{
		cout << "Copy Constructor Test 1 FAIL" << endl;
	}
	else
	{
		cout << "Properly copies all fields." << endl;
	}

	
	// Verifies that copy constructor doesn't copy reference 
	if (&dnaCopy2 == &dna2)
	{
		cout << "Copy Constructor Test 2 FAIL" << endl;
	}
	else
	{
		cout << "Reference is not copied." << endl;
	}


	cout << endl << "The constructors, isEqual, and size() have all been tested." << endl;


	////--------------------------- Tests on the = operator ------------------------------//
	cout << endl << "Tests on the = operator:" << endl;
	cout <<	"-----------------------" << endl;

	DNA_Strand dnaAssign1("ABCDEFG");
	DNA_Strand dnaAssign2;
	DNA_Strand dnaAssign3;
	dnaAssign3 = dnaAssign2 = dnaAssign1;
	
	// Verifies that strand = operator chains correctly assign fields
	pass = true;
	if (dnaAssign1.size() != dnaAssign2.size() || dnaAssign2.size() != dnaAssign3.size())
	{
		pass = false;
	}
	
	for (size_t n = 0; n < dnaAssign1.size(); n++)
	{
		if (dnaAssign2.get(n) != dnaAssign1.get(n) || dnaAssign2.get(n) != dnaAssign3.get(n))
			{
				pass = false;
			}
	}
	if (!pass)
	{
		cout << "= Operator Test 1 FAIL" << endl;
	}
	else
	{
		cout << "Correctly copies fields." << endl;
	}


	// Verifies that addresses of strands are not copied by the = operator
	if (&dnaAssign1 == &dnaAssign2 || &dnaAssign2 == &dnaAssign3)
	{
		cout << "= Operator Test 2 FAIL" << endl;
	}
	else
	{
		cout << "Does not assign addresses." << endl;
	}

	//Verifies that = operator does nothing if lhs and rhs are the same strand
	if (&dnaAssign1 != &(dnaAssign1 = dnaAssign1))
	{
		cout << "= Operator Test 3 FAIL" << endl;
	}
	else
	{
		cout << "Does nothing if lhs and rhs are the same strand." << endl;
	}


	//------------------------Tests on the toString() method----------------------------//
	cout << endl << "Tests on the toString() method:" << endl;
	cout <<			"------------------------------" << endl;

	// toString() should return the contents as a string
	if (dna.toString() != ipStr)
	{
	   cout << "toString() Test 1 FAIL" << endl;
	}
	else
	{
		 cout<<"Result is as expected."<<endl;
	}


	//------------------------Tests on the get() method----------------------------//
	cout << endl << "Tests on the get() method:" << endl;
	cout <<	"-------------------------" << endl;


	// Verifies that get() retrieves the same value for 
	// each same index of two identical DNA strands
	bool same = true;
	for (size_t p = 0; p < dna.size() && same == true; p++) {
		if (dna.get(5) != dna2.get(5)){
			same = false;
		}
	}
	if (!same) {
		cout << "get() Test 1 FAIL" << endl;
	}
	else {
		cout << "Retrieves same values at same indices of identical strands." << endl;
	}


	// Verifies that get() throws an "out_of_range exception when an invalid index is given
	try {
		cout << "Expect to end with an \"out_of_range\" exception" << endl;
		dna.get(dna.size() + 1);
		cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE" << endl;
		cout << "get() Test 2 FAIL" << endl;
	}
	catch (std::out_of_range& excpt) {
		cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
	}
	catch (...) {
		cout << "get() threw the wrong exception." << endl;
	}

	//Verifies that get() retrieves the correct value for the first index in a strand
	if (dna2.get(0) != 'A')
	{
		cout << "get() Test 3 FAIL" << endl;
	}
	else
	{
		cout << "Properly returns first index of a strand." << endl;
	}

	//------------------------Tests on the set() method----------------------------//
	cout << endl << "Tests on the set() method:" << endl;
	cout <<	"-------------------------" << endl;


	// Verifies that the set index is actually changed
	dna.set('X', 1);
	if (dna.get(1) != 'X') {
		cout << "set() Test 1 FAIL" << endl;
	}
	else {
		cout << "Entry correctly set in DNA strand." << endl;
	}
	dna.set('B', 1);


	// Verifies that set() throws an "out_of_range" exception when an invalid index is given
	try {
		cout << "Expect to end with an \"out_of_range\" exception" << endl;
		dna.set('X',dna.size() +1);  
		cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE" << endl;
		cout << "set() Test 2 FAIL" << endl;
	}
	catch (std::out_of_range& excpt) {
		cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
	}
	catch (...) {
		cout << "set() threw the wrong exception." << endl;
	}


	//----------------Tests on the search(const string & target) method--------------------//
	cout << endl << "Tests on the search(string) method:" << endl;
	cout <<	"----------------------------------" << endl;

	// Creates new DNA strand for searching 
	DNA_Strand dna4("QWERTYUIOPASDFGHJKLZXCVBNMASDFGHJKASDFZXCVB");
	

	//// Verifies that search returns -1 when the target doesn't appear in strand
	int firstIndex = dna4.search("XXX");
	if (firstIndex != -1) {
		cout << " search() Test 1 FAIL" << endl;
	}
	else {
		cout << "Properly returns -1 when target isn't found." << endl;
	}
	firstIndex = 0;


	// Verifies that search returns -1 if target is longer than strand
	firstIndex = dna2.search("ABCCTGXXX");
	if (firstIndex != -1) {
		cout << "search() Test 2 FAIL" << endl;
	}
	else {
		cout << "Properly returns -1 when target is too large." << endl;
	}
	firstIndex = 0;


	// Verifies search() properly returns first index of target
	firstIndex = dna4.search("ASDF");
	if (firstIndex != 10) {
		cout << "search() Test 3 FAIL" << endl;
	}
	else {
		cout << "Properly returns index of first target." << endl;
	}
	firstIndex = 0;


	//------------Tests on the search(size_t pos, const string & target) method-------------//
	cout << endl << "Tests on the search(size_t,string) method:" << endl;
	cout <<			"-----------------------------------------" << endl;


	// Verifies that search with start index returns -1 when the target doesn't appear in strand
	firstIndex = dna4.search((size_t)0,"XXX");
	if (firstIndex != -1) {
	cout << "search(size_t,string) Test 1 FAIL" << endl;
	}
	else {
	cout << "Properly returns -1 when target isn't found." << endl;
	}
	firstIndex = 0;


	// Verifies that search with start index returns -1 when the target appears before start index
	firstIndex = dna4.search((size_t)10, "QWERTY");
	if (firstIndex != -1) {
		cout << "search(size_t,string) Test 2 FAIL" << endl;
	}
	else {
		cout << "Properly returns -1 if target is before index." << endl;
	}
	firstIndex = 0;


	// Verifies that search with start index method returns -1 if target is longer than strand
	firstIndex = dna2.search((size_t)0,"ABCCTGXXX");
	if (firstIndex != -1) {
	cout << "search(size_t,string) Test 3 FAIL" << endl;
	}
	else {
	cout << "Properly returns -1 when target is too large." << endl;
	}
	firstIndex = 0;


	// Verifies search with start index properly returns first index of target after start index
	firstIndex = dna4.search((size_t)20,"ASDF");
	if (firstIndex != 26) {
	cout << "search(size_t,string) Test 4 FAIL" << endl;
	}
	else {
	cout << "Properly returns index of first target after start." << endl;
	}
	firstIndex = 0;

	
	// Verifies that search after start index method returns -1 if start index is out of range
	firstIndex = dna2.search((size_t)-1,"A");
	if (firstIndex != -1) {
		cout << "search(size_t,string) Test 5 FAIL" << endl;
	}
	else {
		cout << "Returns -1 for out of range start index." << endl;
	}
	firstIndex = 0;


	DNA_Strand dna13("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABAB");
	if (dna13.search((size_t)0,"BABA") != -1)
	{
		cout << "search(size_t,string) Test 6 FAIL" << endl;
	}
	else
	{
		cout << "Properly handles targets partially off end of strand." << endl;
	}


	if (dna13.search((size_t)0, "BAB") == 44 )
	{
		cout << "search(size_t,string) Test 7 FAIL" << endl;
	}
	else
	{
		cout << "Properly handles targets at end of strand." << endl;
	}


	// Note: The following block of code was used to test this method by temporarily making myDNA
	// public in order to obtain a startPtr
	
	////------ Tests on the search(DnaNodePtr startPtr, const string & target) method --------//
	//cout << endl << "Tests on the search(DnaNodePtr,string) method:" << endl;
	//cout <<	"---------------------------------------------" << endl;

	//DNA_Strand myDNASearch1("ABCDEFGHIJKL");
	//DnaNodePtr searchPtr1 = myDNASearch1.myDNA;
	//DNA_Strand myDNASearch2("ZYXWVUT");
	//
	//// Verifies that search returns nullptr if startPtr isn't found
	//if (myDNASearch2.search(searchPtr1, "FG") != nullptr)
	//{
	//	cout << "search(DnaNodePtr,string) Test 1 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr when start node isn't found." << endl;
	//}


	//// Verifies that search returns nullptr if target is larger than strand
	//if (myDNASearch2.search(searchPtr1, "ZYXWVUTWESTRE") != nullptr)
	//{
	//	cout << "search(DnaNodePtr,string) Test 2 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr when target is longer than strand." << endl;
	//}


	//// Verifies that search returns nullptr if sequence isn't found
	//if (myDNASearch1.search(searchPtr1, "XX") != nullptr)
	//{
	//	cout << "search(DnaNodePtr,string) Test 3 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr when target isn't found." << endl;
	//}


	//// Verifies that search returns nullptr if target is empty string
	//if (myDNASearch1.search(searchPtr1, "") != nullptr)
	//{
	//	cout << "search(DnaNodePtr,string) Test 4 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr when target is empty string." << endl;
	//}

	//// Verifies that search returns DnaNodePtr if target is found (when passed ptr = myDna)
	//if (myDNASearch1.search(searchPtr1, "AB") != searchPtr1)
	//{
	//	cout << "search(DnaNodePtr,string) Test 5 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns DnaNodePtr when target is found." << endl;
	//}


	//// Verifies that search returns DnaNodePtr when target is found at end of strand
	//DnaNodePtr searchPtr2 = searchPtr1;
	//searchPtr2 = searchPtr2->next;
	//searchPtr2 = searchPtr2->next;

	//if (myDNASearch1.search(searchPtr1, "CDEFGHIJKL") != searchPtr2)
	//{
	//	cout << "search(DnaNodePtr,string) Test 6 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns DnaNodePtr when target is found at end of strand." << endl;
	//}

	
	// Note: The following block of code was used to test this method by temporarily making myDNA
	// public in order to obtain a startPtr

	////-----------------------Tests on the cleave(DnaNodePtr) method----------------------------//
	//cout << endl << "Tests on the cleave(DnaNodePtr) method:" << endl;
	//cout << "---------------------------------------------" << endl;

	//DNA_Strand dnaCleave1("XXAAABBAACCAAACCAAXX");

	//// Verifies cleave returns nullptr when startPtr = nullptr
	//DnaNodePtr cleaveTesterPtr = dnaCleave1.cleave(nullptr,"XX");
	//if (cleaveTesterPtr != nullptr || dnaCleave1.size() != 20)
	//{
	//	cout << "cleave(DnaNodePtr) Test 1 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr when startPtr is nullptr." << endl;
	//}


	//// Verifies cleave returns nullptr when target = ""
	//cleaveTesterPtr = dnaCleave1.cleave(dnaCleave1.myDNA, "");
	//if (cleaveTesterPtr != nullptr || dnaCleave1.size() != 20)
	//{
	//	cout << "cleave(DnaNodePtr) Test 2 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr when target is an empty string." << endl;
	//}


	//// Verifies cleave returns nullptr when startPtr isn't found
	//cleaveTesterPtr = dnaCleave1.cleave(dna2.myDNA, "XX");
	//if (cleaveTesterPtr != nullptr || dnaCleave1.size() != 20)
	//{
	//	cout << "cleave(DnaNodePtr) Test 3 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr when startPtr isn't found." << endl;
	//}


	//// Verifies cleave returns nullptr when only one target is found after startPtr
	//cleaveTesterPtr = dnaCleave1.cleave(((((dnaCleave1.myDNA)->next)->next)->next), "XX");
	//if (cleaveTesterPtr != nullptr || dnaCleave1.size() != 20)
	//{
	//	cout << "cleave(DnaNodePtr) Test 4 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr when only 1 target is found." << endl;
	//}


	//// Verifies cleave returns nullptr when target is longer than strand
	//cleaveTesterPtr = dnaCleave1.cleave(dnaCleave1.myDNA, "XXAAABBAACCAAACCAAXXWWW");
	//if (cleaveTesterPtr != nullptr || dnaCleave1.size() != 20)
	//{
	//	cout << "cleave(DnaNodePtr) Test 5 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly returns nullptr target is longer than strand." << endl;
	//}


	//// Verifies that cleave doesn't return nullptr and correctly sets fields
	//// when targets are in the middle of the strand and cleave doesn't start at the beginning
	//cleaveTesterPtr = dnaCleave1.cleave(dnaCleave1.myDNA->next, "CC");
	//DNA_Strand dnaCleave1After("XXAAABBAACCAAXXWWW");
	//if (cleaveTesterPtr == nullptr || dnaCleave1.isEqual(dnaCleave1After))
	//{
	//	cout << "cleave(DnaNodePtr) Test 6 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly assigns fields and returns a DnaNodePtr." << endl;
	//}


	//// Verifies that cleave does return nullptr and correctly sets fields
	//// when targets are at the ends of the strand and cleave starts at the beginning
	//cleaveTesterPtr = dnaCleave1After.cleave(dnaCleave1After.myDNA, "XX");
	//DNA_Strand dnaCleave1After2("XX");
	//if (cleaveTesterPtr == nullptr || dnaCleave1After.isEqual(dnaCleave1After2))
	//{
	//	cout << "cleave(DnaNodePtr) Test 7 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "Properly assigns fields and returns a DnaNodePtr with edge targets." << endl;
	//}


	//------------------Tests on the cleave(const string & target) method-------------------//
	cout << endl << "Tests on the cleave(string) method:" << endl;
	cout <<	"----------------------------------" << endl;
	

	// Verifies no action is performed if target isn't found
	dna2.cleave("XX");
	if (!dna2.isEqual(dna)) {
		cout << "cleave(string) Test 1 FAIL" << endl;
	}
	else {
		cout << "No cleaving is performed if target isn't found." << endl;
	}


	// Creates a new DNA_Strand for testing and a strand for comparison after cleaving
	DNA_Strand dna5("ABCDEFGHIJKBCLMNOPBCQRSTUVBCWXYZBC");
	DNA_Strand dna6("ABCLMNOPBCQRSTUVBCWXYZBC");

	// Verifies cleaving action is correctly performed on first pair of targets 
	// and that size is correct
	dna5.cleave("BC");
	if (!dna5.isEqual(dna6)) {
		cout << "cleave(string) Test 2 FAIL" << endl;
		cout << dna5.toString() << endl;
	}
	else {
		cout << "Cleaving is correctly performed on first target and size is correct." << endl;
	}


	//--------------Tests on the cleave(size_t pos, const string & target) method---------------//
	cout << endl << "Tests on the cleave(size_t,string) method:" << endl;
	cout <<	"-----------------------------------------" << endl;


	// Verifies no action is performed if target isn't found after start index
	// Note: dna4 = "QWERTYUIOPASDFGHJKLZXCVBNMASDFGHJKASDFZXCVB"
	DNA_Strand dna4Copy(dna4);
	dna4Copy.cleave(27,"ASD");
	if (!dna4Copy.isEqual(dna4)) {
	cout << "cleave(size_t,string) Test 1 FAIL" << endl;
	}
	else {
	cout << "No cleaving is performed if target isn't found after start index." << endl;
	}
	firstIndex = 0;


	// Verifies no action is performed if first target is at end of strand
	dna4Copy.cleave(27, "VB");
	if (!dna4Copy.isEqual(dna4)) {
		cout << "cleave(size_t,string) Test 2 FAIL" << endl;
	}
	else {
		cout << "No cleaving is performed if target is at end of strand" << endl;
	}
	
	
	// Verifies no cleaving is performed if start index is out of range
	dna4Copy.cleave(-1, "ASD");
	if (!dna4Copy.isEqual(dna4)) {
		cout << "cleave(size_t,string) Test 3 FAIL" << endl;
	}
	else {
		cout << "No cleaving is performed if start index is out of range." << endl;
	}
	

	// Note: dna4 = "QWERTYUIOPASDFGHJKLZXCVBNMASDFGHJKASDFZXCVB"
	// Creates a new DNA_Strand for comparison to cleaved strand 
	DNA_Strand dna7("QWERTYUIOPASDFGHJKLZXCVBNMASDFZXCVB");
	dna4Copy.cleave(11, "ASDF");
	
	// Verifies that the size and new indices of cleaved strand are correct
	if (!dna4Copy.isEqual(dna7)) {
		cout << "cleave(size_t,string) Test 4 FAIL" << endl;
	}
	else {
		cout << "Size and new indices of cleaved strand are correct." << endl;
	}


	//--------------Tests on the cleaveAll(const string & target) method---------------//
	cout << endl << "Tests on the cleaveAll() method:" << endl;
	cout <<			"-------------------------------" << endl;


	// Creates a DNA_Strand for testing and a strand for comparison after cleaving
	DNA_Strand dna8("AABCAAAAAABCAABCAAAAAAAAABCAAAAAABCAA");
	DNA_Strand dna9("AABCAABCAAAAAABCAA");


	// Verifies no cleaving takes place if no target is found
	dna8.cleaveAll("XX");
	if (dna8.size() != 37) {
		cout << " cleaveAll() Test 1 FAIL" << endl;
	}
	else {
		cout << "Does not cleave when no target is present" << endl;
	}


	// Verifies strand has correct size and index values after cleaveAll() is performed
	// Verifies that no cleaving takes place after a target unless a second target follows
	// Verifies that all target pairs are removed
	dna8.cleaveAll("BC");
	if (!dna8.isEqual(dna9)) {
		cout << "cleaveAll() Test 2 FAIL" << endl;
	}
	else {
		cout << "Correctly adjusts size and indices of cleaved strand." << endl;
	}


	//-------------------Tests on the countEnzyme(char target) method----------------------//
	cout << endl << "Tests on the countEnzyme(char) method:" << endl;
	cout << "-----------------------------------------" << endl;


	if (dna9.countEnzyme('A' != 12)) {
		cout << "countEnzyme(char) Test 1 FAIL" << endl;
	}
	else {
		cout << "Returns correct nonzero count." << endl;
	}


	if (dna9.countEnzyme('D' != 0)) 
	{
		cout << "countEnzyme(char) Test 2 FAIL" << endl;
	}
	else {
		cout << "Returns correct 0 count." << endl;
	}

	//---------------------Tests on the countEnzyme(const string & target) method--------------//
	cout << endl << "Tests on the countEnzyme(string) method:" << endl;
	cout << "-----------------------------------------" << endl;

	// Verifies that countEnzyme() properly counts instances of target 
	DNA_Strand dnaCE1("AAAAABBAAAAABBAAABBAAABBAAAAAAB");
	if (dnaCE1.countEnzyme("AAA") != 6) 
	{
		cout << "countEnzyme(string) Test 1 FAIL" << endl;
	}
	else
	{
		cout << "Properly counts non-zero instances of target." << endl;
	}
	

	// Verifies that countEnzyme() properly returns  when target is not present
	if (dnaCE1.countEnzyme("BBB") != 0)
	{
		cout << "countEnzyme(string) Test 2 FAIL" << endl;
	}
	else
	{
		cout << "Properly returns 0 when target isn't present." << endl;
	}


	//------------------------Tests on the append(string) method----------------------//
	cout << endl << "Tests on the append(string) method:" << endl;
	cout <<	"----------------------------------" << endl;


	DNA_Strand dnaAp1("");

	// Verifies no action takes place if an empty string is passed to append()
	dnaAp1.append("");
	if (dnaAp1.size() != 0)
	{
		cout << "append(string) Test 1 FAIL" << endl;
	}
	else
	{
		cout << "No action is performed by append when an empty string is passed." << endl;
	}


	// Verifies that mySize is adjusted after DNA is appended
	dnaAp1.append("AAAAAAAAAAAA");
	if (dnaAp1.size() != 12)
	{
		cout << "append(string) Test 2 FAIL" << endl;
	}
	else
	{
		cout << "Correctly adjusts mySize." << endl;
	}


	// Verifies that index values of array are correctly assigned by append
	string testStringA = "AAAAAAAAAAAA";
	pass = true;
	for (size_t n = 0; n < testStringA.length(); n++ && pass)
	{
		if (dnaAp1.get(n) != testStringA.at(n))
		{
			pass = false;
		}

	}

	if (!pass)
	{
		cout << "append(string) Test 3 FAIL" << endl;
	}
	else
	{
		cout << "Indices are correctly assigned." << endl;
	}


	//------------------------Tests on the append(DNA_Strand) method----------------------//
	cout << endl << "Tests on the append(DNA_Strand) method:" << endl;
	cout <<			"--------------------------------------" << endl;


	DNA_Strand dnaAp2("XXXXX");
	DNA_Strand toPass1("");
	DNA_Strand toPass2("AAAAAAAAAAA");
	

	// Verifies no action takes place if an empty strand is passed to append()
	dnaAp2.append(toPass1);
	if (dnaAp2.size() != 5)
	{
		cout << "append(DNA_Strand) Test 1 FAIL" << endl;
	}
	else
	{
		cout << "No action is performed when an empty strand is passed." << endl;
	}
	
	// Verifies that mySize is adjusted correctly when initial strand is nonempty
	string testString = "XXXXXAAAAAAAAAAA";

	dnaAp2.append(toPass2);
	if (dnaAp2.size() != testString.length())
	{
		cout << "append(DNA_Strand) Test 2 FAIL" << endl;
		cout << dnaAp2.size() << endl;
	}
	else
	{
		cout << "Adjusts mySize correctly." << endl;
	}


	// Verifies that index values of array are correctly assigned by append(DNA_Strand)
	// when initial strand is nonempty
	pass = true;
	for (size_t n = 0; n < testString.size() && pass; n++)
	{
		if (dnaAp2.get(n) != testString.at(n))
		{
			pass = false;
		}

	}

	if (!pass)
	{
		cout << "append(DNA_Strand) Test 3 FAIL" << endl;
	}
	else
	{
		cout << "Indices correctly assigned when initial strand is nonempty." << endl;
	}


	// Verifies that mySize is correty adjusted when initial strand is empty
	toPass1.append(toPass2);
	if (toPass1.size() != toPass2.size())
	{
		cout << "append(DNA_Strand) Test 4 FAIL" << endl;
	}
	else
	{
		cout << "mySize is correctly adjusted after an empty strand is appended." << endl;
	}


	// Verifies that index values of array are correctly assigned by append(DNA_Strand)
	// when initial strand is empty
	string testString2 = "AAAAAAAAAAA";
	pass = true;
	for (size_t n = 0; n < testString2.size() && pass; n++)
	{
		if (toPass1.get(n) != testString2.at(n))
		{
			pass = false;
		}

	}

	if (!pass)
	{
		cout << "append(DNA_Strand) Test 5 FAIL" << endl;
	}
	else
	{
		cout << "Indices assigned correctly when initial strand is nonempty." << endl;
	}


	// Note: The following block of code was used to test this method by temporarily making myDNA
	// public in order to obtain a startPtr

	////---------------------------Tests on the Splice(DnaNodePtr) method--------------------------//
	//cout << endl << "Tests on the splice(DnaNodePtr) method:" << endl;
	//cout << "--------------------------------------" << endl;
	//
	//DNA_Strand dnaSplice1;
	//DnaNodePtr spliceTesterPtr;

	//// Verifies that nullptr is returned and mySize is unchanged when strand is empty
	//spliceTesterPtr = dnaSplice1.splice(dnaSplice1.myDNA,"X", "X");
	//if (dnaSplice1.size() != 0 || spliceTesterPtr != nullptr)
	//{
	//	cout << "splice(DnaNodePtr) Test 1 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) does nothing on an empty strand." << endl;
	//}

	//// Verifies that nullptr is returned and mySize is unchanged when no targets are found
	//DNA_Strand dnaSplice2("XAAAAA");
	//spliceTesterPtr = dnaSplice2.splice( dnaSplice2.myDNA, "B", "A");
	//if (dnaSplice2.size() != 6 || spliceTesterPtr != nullptr)
	//{
	//	cout << "splice(DnaNodePtr) Test 2 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) does nothing when no targets are found." << endl;
	//}


	//// Verifies that nullptr is returned and mySize is unchanged when one target is found
	//spliceTesterPtr = dnaSplice2.splice(dnaSplice2.myDNA, "X", "A");
	//if (dnaSplice2.size() != 6 || spliceTesterPtr != nullptr)
	//{
	//	cout << "splice(DnaNodePtr) Test 3 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) does nothing when one target is found." << endl;
	//}


	//// Verifies that nullptr is returned and mySize is unchanged when target is longer than strand
	//spliceTesterPtr = dnaSplice2.splice(dnaSplice2.myDNA, "XAAAAAAA", "A");
	//if (dnaSplice2.size() != 6 || spliceTesterPtr != nullptr)
	//{
	//	cout << "splice(DnaNodePtr) Test 4 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) does nothing when target is longer than strand." << endl;
	//}


	//// Verifies that nullptr is returned and mySize is unchanged when targets overlap
	//spliceTesterPtr = dnaSplice2.splice(dnaSplice2.myDNA, "AAA", "B");
	//if (dnaSplice2.size() != 6 || spliceTesterPtr != nullptr)
	//{
	//	cout << "splice(DnaNodePtr) Test 5 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) does nothing when targets overlap." << endl;
	//}


	//// Verifies that nullptr is returned and mySize is unchanged when startPtr isn't found
	//spliceTesterPtr = dnaSplice2.splice(dnaSplice1.myDNA, "A", "B");
	//if (dnaSplice2.size() != 6 || spliceTesterPtr != nullptr)
	//{
	//	cout << "splice(DnaNodePtr) Test 6 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) does nothing when startPtr isn't found." << endl;
	//}

	//// Verifies that nullptr is returned and mySize is unchanged when target is empty string
	//spliceTesterPtr = dnaSplice2.splice(dnaSplice2.myDNA, "", "B");
	//if (dnaSplice2.size() != 6 || spliceTesterPtr != nullptr)
	//{
	//	cout << "splice(DnaNodePtr) Test 7 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) does nothing when target is empty string." << endl;
	//}


	//// Verifies splice(DnaNodePtr) correctly changes fields and doesn't return a nullptr
	//// when targets are both found in middle of strand
	//	// Note: The actual DnaNodePtr returned cannot be known since the node is allocated 
	//	// during runtime and no pubic method can be defined to return its address
	//DNA_Strand dnaSplice3("AAXXBBBBBBBXXAAA");
	//DNA_Strand dnaSplice3AfterSplice("AAXXCCAAA");
	//spliceTesterPtr = dnaSplice3.splice(dnaSplice3.myDNA, "XX", "CC");
	//if (spliceTesterPtr == nullptr || !dnaSplice3.isEqual(dnaSplice3AfterSplice))
	//{
	//	cout << "splice(DnaNodePtr) Test 8 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) correctly returns a DnaNodePtr and changes fields." << endl;
	//}


	//// Verifies splice(DnaNodePtr) correctly changes fields and returns nullptr
	//// when targets are both found on the ends of the strand
	//DNA_Strand dnaSplice4("XXBBBBBBBXX");
	//DNA_Strand dnaSplice4AfterSplice("XXCC");
	//spliceTesterPtr = dnaSplice4.splice(dnaSplice4.myDNA, "XX", "CC");
	//if (spliceTesterPtr != nullptr || !dnaSplice4.isEqual(dnaSplice4AfterSplice))
	//{
	//	cout << "splice(DnaNodePtr) Test 9 FAIL" << endl;
	//	
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) returns nullptr and changes fields with edge targets"<< endl;
	//}


	//// Verifies splice(DnaNodePtr) correctly changes fields and doesn't return  nullptr
	//// when insertSequence is an empty string
	//DNA_Strand dnaSplice5("XXBBBBBBBXXAA");
	//DNA_Strand dnaSplice5AfterSplice("XXAA");
	//spliceTesterPtr = dnaSplice5.splice(dnaSplice5.myDNA, "XX", "");
	//if (spliceTesterPtr == nullptr || !dnaSplice5.isEqual(dnaSplice5AfterSplice))
	//{
	//	cout << "splice(DnaNodePtr) Test 10 FAIL" << endl;
	//}
	//else
	//{
	//	cout << "splice(DnaNodePtr) correctly handles empty insertSequence." << endl;
	//}


	//---------------------------Tests on the Splice(size_t pos) method--------------------------//
	cout << endl << "Tests on the splice(size_t) method:" << endl;
	cout <<			"----------------------------------" << endl;

	// Since this splice method is just a specific instance of the previous method,
	// we need only verify that it works correctly when pos = 0, pos is in the middle of the strand,
	// ++pos is at the end of the strand, ++pos is out of range, insertSequence is  empty, ++target is 
	// empty, and ++only 1 target is found after start index

	DNA_Strand dnaSplice6("AAAAXXAAAAXXAAANNAA");

	// Verifies splice does nothing when pos is the last index of the strand
	dnaSplice6.splice(18, "A", "X");
	if (dnaSplice6.size() != 19)
	{
		cout << "splice(size_t) Test 1 FAIL" << endl;
	}
	else
	{
		cout << "Does nothing when pos is last index in strand." << endl;
	}

	// Verifies splice does nothing when pos is out of range
	dnaSplice6.splice(19, "A", "X");
	if (dnaSplice6.size() != 19)
	{
		cout << "splice(size_t) Test 2 FAIL" << endl;
	}
	else
	{
		cout << "Does nothing when pos is out of range." << endl;
	}


	// Verifies splice does nothing when target is empty string
	dnaSplice6.splice((size_t)0, "", "X");
	if (dnaSplice6.size() != 19)
	{
		cout << "splice(size_t) Test 3 FAIL" << endl;
	}
	else
	{
		cout << "Does nothing when target is empty string." << endl;
	}

	// Verifies splice does nothing when only 1 target is found after start
	dnaSplice6.splice(5, "XX", "YY");
	if (dnaSplice6.size() != 19)
	{
		cout << "splice(size_t) Test 4 FAIL" << endl;
	}
	else
	{
		cout << "Does nothing when only 1 target is after pos." << endl;
	}

	//Verifies splice works correctly when pos = 0 and two targets are found
	dnaSplice6.splice((size_t)0, "XX", "YY");
	DNA_Strand dnaSplice6AfterSplice("AAAAXXYYAAANNAA");
	if (!dnaSplice6.isEqual(dnaSplice6AfterSplice))
	{
		cout << "splice(size_t) Test 5 FAIL" << endl;
	}
	else
	{
		cout << "Correctly splices starting from 0 index." << endl;
	}


	// Verifies splice works correctly when pos isn't 0 and two targets are found
	// Also shows that splice(DnaNodePtr) functions correctly when a pointer other than
	// myDNA is used (since that method is implemented by this sort method)
	dnaSplice6AfterSplice.splice(2, "AA", "YY");
	DNA_Strand dnaSplice6AfterSplice2("AAAAYYANNAA");
	if (!dnaSplice6AfterSplice.isEqual(dnaSplice6AfterSplice2))
	{
		cout << "splice(size_t) Test 6 FAIL" << endl;
		cout << dnaSplice6AfterSplice.toString() << endl;
	}
	else
	{
		cout << "Correctly splices starting from non-zero index." << endl;
	}


	//---------------------------Tests on the Splice() method--------------------------//
	cout << endl << "Tests on the splice() method:" << endl;
	cout <<	"----------------------------" << endl;

	// Must verify that this method works correctly when less than 2 targets are present, when 
	// insertSequence is an empty string, when target is an empty string, and when 2 targets are found

	DNA_Strand dnaSplice7("XXAACCAAAABBCCAAXX");
	DNA_Strand dnaSplice7AfterSplice("XXAACCZZAAXX");
	DNA_Strand dnaSplice7AfterSplice2("XX");

	// Verifies that splice does nothing if 2 targets aren't found
	dnaSplice7.splice("BB", "ZZ");
	if (dnaSplice7.size() != 18 )
	{
		cout << "splice() Test 1 FAIL" << endl;
	}
	else
	{
		cout << "Does nothing if 2 targets aren't found." << endl;
	}


	// Verifies that splice does nothing if target is an empty string
	dnaSplice7.splice("", "ZZ");
	if (dnaSplice7.size() != 18)
	{
		cout << "splice() Test 2 FAIL" << endl;
	}
	else
	{
		cout << "Does nothing if target is an empty string." << endl;
	}


	// Verifies that splice works correctly when  targets are found
	dnaSplice7.splice("CC", "ZZ");
	if (!dnaSplice7.isEqual(dnaSplice7AfterSplice))
	{
		cout << "splice() Test 3 FAIL" << endl;
	}
	else
	{
		cout << "Correctly splices when two targets are present." << endl;
	}

	// Verifies that splice works correctly when  targets are found
	// and insertSequence is an empty string
	dnaSplice7AfterSplice.splice("XX", "");
	if (!dnaSplice7AfterSplice.isEqual(dnaSplice7AfterSplice2))
	{
		cout << "splice() Test 4 FAIL" << endl;
	}
	else
	{
		cout << "Correctly splices when insertSequence is empty string." << endl;
	}





	cout << endl << endl << "Done testing." << endl << endl;
	cout << "Press enter to end program"<<endl;
	char tt;
	tt = cin.get();


	return 0;


}

