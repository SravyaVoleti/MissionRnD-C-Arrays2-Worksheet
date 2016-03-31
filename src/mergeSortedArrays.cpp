/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int isOlder(char *str1, char *str2) {
	int i = 0, j = 0, k, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	while (str1[i] != '-' || str2[i] != '-')
	{
		d1 = (d1 * 10) + (str1[i] - '0');
		d2 = (d2 * 10) + (str2[i] - '0');
		i++;
	}
	j = i + 1;
	while (str1[j] != '-' || str2[j] != '-')
	{
		m1 = (m1 * 10) + (str1[j] - '0');
		m2 = (m2 * 10) + (str2[j] - '0');
		j++;
	}
	k = j + 1;
	while (str1[k] != '\0' && str2[k] != '\0')
	{
		y1 = (y1 * 10) + (str1[k] - '0');
		y2 = (y2 * 10) + (str2[k] - '0');
		k++;
	}
	if (y1 == y2 && m1 == m2 && d1 == d2)
		return 0;
	if (y1 > y2)
	{
		return 2;
	}
	if (y1 == y2)
	{
		if (m1 > m2)
			return 2;
		if (d1 > d2)
			return 2;
	}

	if (y2 > y1)
	{
		return 1;
	}
	if (y1 == y2)
	{
		if (m2 > m1)
			return 1;
		if (d2 > d1)
			return 1;
	}



}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL)
		return NULL;
	if (B == NULL)
		return NULL;
	if (A == NULL && B == NULL)
		return NULL;

	struct transaction *C;
	int i = 0, j = 0, x, k = 0;
	C = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	if (A != NULL && B != NULL){
		while (i != ALen && j != BLen)
		{
			x = isOlder(A[i].date, B[j].date);
			if (x == 0)
			{
				C[k] = A[i];
				k++;
				i++;
				C[k] = B[j];
				k++;
				j++;
			}
			else if (x == 1)
			{
				C[k] = A[i];
				k++;
				i++;
			}
			else
			{
				C[k] = B[j];
				k++;
				j++;
			}
		}
		while (i != ALen)
		{
			C[k] = A[i];
			k++;
			i++;
		}
		while (j != BLen)
		{
			C[k] = B[j];
			k++;
			j++;
		}

		return C;
	}
}