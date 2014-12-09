## An Extremely Simple C Unit Test Framework
Each test should look like `int test_case(void)`. Return value of 0 means pass.

In the main function of the test code, do something like this:

    int main()
    {
        TEST_BEGIN();

        RUN_TEST(test_1);
        RUN_TEST(test_2);

        TEST_END();

        return 0;
    }

The output will be how many test has been run and failed.
