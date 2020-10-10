#include "unity_fixture.h"
#include "sort.h"
#include <limits.h>

TEST_GROUP(sort);
int vector[10];

TEST_SETUP(sort)
{
}

TEST_TEAR_DOWN(sort)
{
}


TEST(sort, allPositiveElements)
{
	int cont = 10;
	int expected[] ={1,2,3,4,5,6,7,8,9,10};

	for(int i=0; i < 10; i++)
	{
		vector[i] = cont--;
	}
	
	sort(vector, 10);
	
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
}

TEST(sort, halfSizeArray)
{
	int cont = 5;
	int expected[] ={1,2,3,4,5,-9,-9,-9,-9,-9};

	for(int i=0; i < 5; i++)
	{
		vector[i] = cont--;
	}

	for(int i=5; i < 10; i++)
	{
		vector[i] = -9;
	}
	
	sort(vector, 5);
	
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
}

TEST(sort, alreadOrdered)
{
	int cont = 1;
	int expected[] ={1,2,3,4,5,6,7,8,9,10};

	for(int i=0; i < 10; i++)
	{
		vector[i] = cont++;
	}

	sort(vector, 10);
	
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
}


TEST(sort, negativeAndPositive)
{
	int cont = -5;
	int expected[] ={-5,-4,-3,-2,-1,0,1,2,3,4};

	for(int i=0; i < 10; i++)
	{
		vector[i] = cont++;
	}
	
	sort(vector, 10);
	
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
}

TEST(sort, allNegativeNumbers)
{
	int cont = -1;
	int expected[] ={-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};

	for(int i=0; i < 10; i++)
	{
		vector[i] = cont--;
	}
	
	sort(vector, 10);
	
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
}

TEST(sort, repetedNumbers)
{
	int cont = 1;
	int expected[] ={1,2,2,2,2,2,3,5,7,9};

	for(int i=0; i < 10; i++)
	{
		if( cont % 2  == 0){
			vector[i] = 2;
			cont++;
		}
		else
		{	
			vector[i] = cont++;
		}
	}
	
	sort(vector, 10);
	
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
}

TEST(sort, validatedIntMaxAndIntMin)
{
	int expected[] ={INT_MIN,0,0,0,0,0,0,0,0,INT_MAX};

	for(int i=1; i < 9; i++)
	{
		vector[i] = 0;
	}
	vector[0] = INT_MAX;
	vector[9] = INT_MIN;
	sort(vector, 10);
	
	TEST_ASSERT_EQUAL_INT_ARRAY (expected, vector, 10);	
}

