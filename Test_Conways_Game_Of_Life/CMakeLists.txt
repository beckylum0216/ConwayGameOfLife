set(GTEST_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.0/build/native/include)
set(PARENT_DIR ${CMAKE_CURRENT_LIST_DIR}/../Tutorial3b_Conways_Game_Of_Life)

add_library (TEST_CONWAYS_GOL pch.h pch.cpp)

include_directories(${PARENT_DIR} ${GTEST_INCLUDE_DIR})