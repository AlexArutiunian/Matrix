#include <gtest/gtest.h>
#include "../lib/matrix.hpp"
#include <fstream>

using T = double;

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

TEST(TestDet, accuracy_det) {

    using T = double;

    T EPS1 = 0.1;
    T EPS2 = 0.01;
    T EPS3 = 0.001;

    T EPS4 = 0.00001;
    T EPS5 = 0.0000000000001;
    
    
    matrix::math_matrix<T> m(3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    ASSERT_TRUE(m.det_Gauss(EPS1) == 0);
    ASSERT_TRUE(m.det_Gauss(EPS2) == 0);
    ASSERT_TRUE(m.det_Gauss(EPS3) == 0);
    
    matrix::math_matrix<T> m1(3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    m1 = {1, 2, 1, 4, 1, 3, 0, 5, 9};

    // for small matrix accuracy influences low

    ASSERT_NEAR(14, m1.det_Gauss(EPS1), 0.1);
    ASSERT_TRUE(m1.det_Gauss(EPS2) == -58);
    ASSERT_TRUE(m1.det_Gauss(EPS3) == -58);
}


// for big matrix accuracy influence more

TEST(TestDet, accuracy_det_EPS1) {

    T EPS1 = 0.1;
    
    matrix::math_matrix<T> m2(100);
    std::ifstream file("../010.dat");

    file >> m2;

    ASSERT_NEAR(14, m2.det_Gauss(EPS1), 0.00001);

}


TEST(TestDet, accuracy_det_EPS2_abs_error1) {

    

    T EPS1 = 0.00000001;   

    matrix::math_matrix<T> m2(100);
    std::ifstream file("../010.dat");
    file >> m2;

     T abs_error1 = 0.001;

    ASSERT_NEAR(14, m2.det_Gauss(EPS1), abs_error1);
   
}

TEST(TestDet, accuracy_det_EPS2_abs_error2) {

    T EPS1 = 0.00000001;   

    matrix::math_matrix<T> m2(100);
    std::ifstream file("../010.dat");
    file >> m2;

    T abs_error2 = 0.0001;

    ASSERT_NEAR(14, m2.det_Gauss(EPS1), 0.0001);
   
}

TEST(TestExceptions, test1) {

    bool exception_thrown = false;
    try {
        // attempt to allocate matrix with too large dimensions
        matrix::matrix_<int> m(1000000000000000, 1000000000000000);
    }
    catch (std::bad_alloc& e) {
        exception_thrown = true;
    }
    ASSERT_TRUE(exception_thrown);
   
}


int main(int argc, char **argv){

    // in this unit test it excepts that 3 test will be failed
    // if it's so - tests ok 
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}