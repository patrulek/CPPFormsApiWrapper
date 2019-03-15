#include "gtest/gtest.h"
#include "FAPIWrapper.h"
#include "FAPIContext.h"

using namespace CPPFAPIWrapper;

class FAPIWrapperTest : public ::testing::Test {

};



TEST_F(FAPIWrapperTest, LoadingBuiltins) {
	ASSERT_TRUE(builtins.empty());
	
	createContext();

	ASSERT_FALSE(builtins.empty());
}
