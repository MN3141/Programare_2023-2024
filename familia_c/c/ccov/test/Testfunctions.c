#include "unity.h"
#include "../functions.h"

void setUp()
{

}

void parity_tests()
{
    TEST_ASSERT_EQUAL(1,parity(0));
    TEST_ASSERT((parity(1)%2)==0);
}

void tearDown(){

}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(parity_tests);
    return UNITY_END();
    
}