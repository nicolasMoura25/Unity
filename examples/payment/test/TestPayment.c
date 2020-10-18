#include "unity_fixture.h"
#include "payment.h"
#include <limits.h>

TEST_GROUP(payment);

TEST_SETUP(payment)
{
}

TEST_TEAR_DOWN(payment)
{
}

TEST(payment, valueExceeded)
{
	float value = 99999.99f;
	char status[20] = "estudante";

	TEST_ASSERT_EQUAL_INT(1, payment(value, status));			
}

TEST(payment, lowerValue)
{
	float value = 00.001f;
	char status[20] = "estudante";

	TEST_ASSERT_EQUAL_INT(1, payment(value, status));			
}

TEST(payment, invalidStatus)
{
	float value = 1000.00f;
	char status[20] = "empresario";

	TEST_ASSERT_EQUAL_INT(2, payment(value, status));			
}

//TO DO: verify asssert to valid 2 returns "1" if value issue and "2" to status issue
TEST(payment, invalidValueAndStatus)
{
	float value = 00.001f;
	char status[20] = "empresario";
	int result = payment(value, status);
	TEST_ASSERT_TRUE(result ==1 || result ==2);			
}

TEST(payment, ValidParamsWithAposentadoStatus)
{
	float value = 1000.00f;
	char status[20] = "aposentado";

	TEST_ASSERT_EQUAL_INT(0, payment(value, status));			
}

TEST(payment, ValidParamsWithVipStatus)
{
	float value = 99999.00f;
	char status[20] = "vip";

	TEST_ASSERT_EQUAL_INT(0, payment(value, status));			
}

TEST(payment, ValidParamsWithRegularStatus)
{
	float value = 00.01f;
	char status[20] = "regular";

	TEST_ASSERT_EQUAL_INT(0, payment(value, status));			
}

TEST(payment, ValidParamsWithEstudanteStatus)
{
	float value = 1000.00f;
	char status[20] = "estudante";

	TEST_ASSERT_EQUAL_INT(0, payment(value, status));			
}

TEST(payment, statusEmpty)
{
	float value = 1000.00f;
	char status[20] = "\0";

	TEST_ASSERT_EQUAL_INT(2, payment(value, status));			
}

