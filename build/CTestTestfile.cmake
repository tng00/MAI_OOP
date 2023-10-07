# CMake generated Testfile for 
# Source directory: C:/OOP/LAB2
# Build directory: C:/OOP/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(BASIC "C:/OOP/build/test2.exe")
set_tests_properties(BASIC PROPERTIES  _BACKTRACE_TRIPLES "C:/OOP/LAB2/CMakeLists.txt;11;add_test;C:/OOP/LAB2/CMakeLists.txt;0;")
subdirs("googletest")
