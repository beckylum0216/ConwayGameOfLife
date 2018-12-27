cmake_minimum_required(VERSION 3.6.2)
project(Tutorial3b_Conways_Game_Of_Life)

set(CMAKE_CXX_STANDARD 14)
set(GLUT_LIBRARIES	${CMAKE_CURRENT_LIST_DIR}/freeglut-3.0.0/lib/Release/freeglut.lib 
					${CMAKE_CURRENT_LIST_DIR}/freeglut-3.0.0/lib/Debug/freeglutd.lib)
set(GLUT_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/freeglut-3.0.0/include)
set(GLUT_glut_LIBRARY	${CMAKE_CURRENT_LIST_DIR}/freeglut-3.0.0/lib/Release/freeglut.lib
						${CMAKE_CURRENT_LIST_DIR}/freeglut-3.0.0/lib/Debug/freeglutd.lib)

set(GTEST_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/Test_Conways_Game_Of_Life/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.0/build/native/include)
add_subdirectory(Test_Conways_Game_Of_Life)

include_directories(.)
include_directories(${GLUT_INCLUDE_DIR})


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)


add_executable(	Tutorial3b_Conways_Game_Of_Life
				main.cpp 
				Cellz.h 
				Cellz.cpp 
				Game.h 
				Game.cpp 
				GameManager.h 
				GameManager.cpp)

include_directories(	${OPENGL_INCLUDE_DIRS}  
						${GLUT_INCLUDE_DIRS} 
						${CMAKE_CURRENT_LIST_DIR}/Test_Conways_Game_Of_Life 
						${GTEST_INCLUDE_DIR})

target_link_libraries(Tutorial3b_Conways_Game_Of_Life ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

install(TARGETS Tutorial3b_Conways_Game_Of_Life DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin )
