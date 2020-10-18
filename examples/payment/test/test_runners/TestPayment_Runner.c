#include "unity_fixture.h"

TEST_GROUP_RUNNER(payment)
{
	RUN_TEST_CASE(payment, valueExceeded);
	RUN_TEST_CASE(payment, lowerValue);
	RUN_TEST_CASE(payment, invalidStatus);
	RUN_TEST_CASE(payment, invalidValueAndStatus);
	RUN_TEST_CASE(payment, ValidParamsWithAposentadoStatus);
	RUN_TEST_CASE(payment, ValidParamsWithVipStatus);
	RUN_TEST_CASE(payment, ValidParamsWithRegularStatus);
	RUN_TEST_CASE(payment, ValidParamsWithEstudanteStatus);
	RUN_TEST_CASE(payment, statusEmpty);
}

static void RunAllTests()
{
	RUN_TEST_GROUP(payment);
}

int main(int argc,char * argv[])
{
	return UnityMain(argc, argv, RunAllTests);
}
