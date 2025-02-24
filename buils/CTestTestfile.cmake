# CMake generated Testfile for 
# Source directory: C:/Users/tony/Dokumente/LoginApp
# Build directory: C:/Users/tony/Dokumente/LoginApp/buils
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(MainTests "C:/Users/tony/Dokumente/LoginApp/buils/Debug/tests.exe")
  set_tests_properties(MainTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/tony/Dokumente/LoginApp/CMakeLists.txt;87;add_test;C:/Users/tony/Dokumente/LoginApp/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(MainTests "C:/Users/tony/Dokumente/LoginApp/buils/Release/tests.exe")
  set_tests_properties(MainTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/tony/Dokumente/LoginApp/CMakeLists.txt;87;add_test;C:/Users/tony/Dokumente/LoginApp/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(MainTests "C:/Users/tony/Dokumente/LoginApp/buils/MinSizeRel/tests.exe")
  set_tests_properties(MainTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/tony/Dokumente/LoginApp/CMakeLists.txt;87;add_test;C:/Users/tony/Dokumente/LoginApp/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(MainTests "C:/Users/tony/Dokumente/LoginApp/buils/RelWithDebInfo/tests.exe")
  set_tests_properties(MainTests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/tony/Dokumente/LoginApp/CMakeLists.txt;87;add_test;C:/Users/tony/Dokumente/LoginApp/CMakeLists.txt;0;")
else()
  add_test(MainTests NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
