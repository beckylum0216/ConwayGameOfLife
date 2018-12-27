#include "pch.h"
#include <Game.h>
#include <Cellz.h>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(SampleTest, ConwayTest)
{
	Game theTest;

	EXPECT_EQ(0, theTest.GetGridX());
}