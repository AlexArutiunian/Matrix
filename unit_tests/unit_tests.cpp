#include <gtest/gtest.h>
#include "../lib/matrix.hpp"

using namespace std;

TEST(TestConstructors, create_derived) {
    
    matrix::math_matrix<int> m(10); 
    EXPECT_EQ(m.det_Gauss(), 1);
    
}


TEST(TestConstructors, create_based) {
    
    matrix::matrix_<int> m1(10);
}

TEST(TestDet, det_from_based) {
    
    matrix::matrix_<int> m1(10);
    matrix::math_matrix<int> m(m1);
    EXPECT_EQ(m.det_Gauss(), 1);

    matrix::matrix_<int> m2(3, {1, 0 , 0, 0, 1, 0, 0, 0, 1});
    matrix::math_matrix<int> m3(m2);
    EXPECT_EQ(m3.det_Gauss(), 1);
  
}

TEST(TestOperators, test_eq) {
    
    matrix::matrix_<int> m(3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    m = {1, 0, 0, 0, 1, 0, 0, 0, 1}; 
    matrix::math_matrix<int> m1(3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    m1 = {1, 2, 1, 4, 1, 3, 0, 5, 9};

    matrix::math_matrix<int> m2(3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    m2 = {1, 0, 1, 3, 3, 3, 3, 1, 7};
    

    m1 = m;
    m2 = m1;

    
  
}



TEST(TestDet, assert_for_few_det) {
    
    matrix::math_matrix<int> m(3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    ASSERT_TRUE(m.det_Gauss() == 0);
    matrix::math_matrix<int> m1(3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    m1 = {1, 2, 1, 4, 1, 3, 0, 5, 9};
    ASSERT_TRUE(m1.det_Gauss() == -58);

    
  
}





int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}