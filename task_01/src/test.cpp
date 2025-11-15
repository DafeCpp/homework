#include <gtest/gtest.h>
#include "mediana.h"

TEST(Test, Simple) {
    ASSERT_EQ(mediana(1, 2, 3), 2);
    ASSERT_EQ(mediana(4, 5, 4.4), 4.4);
    ASSERT_EQ(mediana(34, 2, 676), 34);
    ASSERT_EQ(mediana(0, 0, 0), 0);
    ASSERT_EQ(mediana(1, -6, -5), -5);

}



