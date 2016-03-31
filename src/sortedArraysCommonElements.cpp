/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};



int isEqual(char *dob1, char *dob2) {

	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0, i = 0;

	while (*(dob1 + i) != '-' && i < 2) {

		d1 = (d1 * 10) + (*(dob1 + i) - '0');
		d2 = (d2 * 10) + (*(dob2 + i) - '0');
		i++;
	}
	i++;
	while (*(dob1 + i) != '-' && i < 5) {

		m1 = (m1 * 10) + (*(dob1 + i) - '0');
		m2 = (m2 * 10) + (*(dob2 + i) - '0');
		i++;
	}
	i++;
	while (*(dob1 + i) != '\0' && i <= 9) {

		y1 = (y1 * 10) + (*(dob1 + i) - '0');
		y2 = (y2 * 10) + (*(dob2 + i) - '0');
		i++;
	}

	if (y1 == y2 && m1 == m2 && d1 == d2)
		return 1;
	else
		return 0;
}





struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	struct transaction *res = NULL;
	int k = 0,i = 0,j = 0,x;
	
	if (A == NULL)
		return NULL;
	if (B == NULL)
		return NULL;
	if (A == B)
		return A;

	for (i = 0; i < ALen; i++) {
		for ( j = 0; j < BLen; j++) {
			x = isEqual(A[i].date, B[j].date);
			if (x == 1) {
				res = (struct transaction*)calloc(1, sizeof(struct transaction));
				res[k] = A[i];
				k++;
			}
		}
	}
	return res;
}