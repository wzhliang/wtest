#include <stdio.h>

typedef int TestCase();
static int _test_run = 0;
static int _test_pass = 0;

#define TEST_BEGIN() _test_run = _test_pass = 0
#define TEST_END() \
    do { printf("\n\n\nSummary: %d test run. %d pass. %d fail\n", _test_run, _test_pass, \
	_test_run - _test_pass); } while (0)

inline void RunTest(TestCase tc, char *name)
{
    int ret;

    printf("\n==== %s BEGIN ====\n", name);
    ret = tc();
    _test_run++;
    if (!ret)
	_test_pass++;
    printf("==== %s END [%s] ==== \n", name, ret ? "FAIL" : "PASS");
}

#define RUN_TEST(test) RunTest(test, #test)

#define TEST_ASSERT(cond, msg) \
    if (!(cond)) { printf("[%s, %d] FAIL: %s\n", \
	    __FILE__, __LINE__, (msg)); return -1; }
#define TEST_CHECK(cond, msg) \
    if (!(cond)) { printf("[%s, %d] fail: %s\n", __FILE__, __LINE__, (msg)) }

#define LINE() printf("_____________\n");
