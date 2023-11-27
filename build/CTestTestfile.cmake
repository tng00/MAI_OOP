# CMake generated Testfile for 
# Source directory: C:/OOP/LAB3
# Build directory: C:/OOP/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(BASIC "C:/OOP/build/test3.exe")
set_tests_properties(BASIC PROPERTIES  _BACKTRACE_TRIPLES "C:/OOP/LAB3/CMakeLists.txt;11;add_test;C:/OOP/LAB3/CMakeLists.txt;0;")
subdirs("googletest")
