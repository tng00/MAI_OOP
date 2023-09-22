# CMake generated Testfile for 
# Source directory: C:/OOP/LAB1
# Build directory: C:/OOP/LAB1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(BASIC "C:/OOP/LAB1/build/test1.exe")
set_tests_properties(BASIC PROPERTIES  _BACKTRACE_TRIPLES "C:/OOP/LAB1/CMakeLists.txt;12;add_test;C:/OOP/LAB1/CMakeLists.txt;0;")
subdirs("googletest")
