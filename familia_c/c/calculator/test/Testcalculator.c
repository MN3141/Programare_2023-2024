#include "unity.h"
#include "../calculator.h"

void setUp()
{

}

void add_test()
{
    TEST_ASSERT_EQUAL(0,add(-1,1));
}
void tearDown(){

}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(add_test);
    return UNITY_END();
    
}