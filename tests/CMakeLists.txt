set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

ADD_SUBDIRECTORY(googletest EXCLUDE_FROM_ALL)
AUX_SOURCE_DIRECTORY(. SOURCE)
ADD_EXECUTABLE(training_main ${SOURCE}
        ExecutorTest.cpp
        ../include/Executor.hpp
        ../src/ExecutorImpl.hpp
        ../src/ExecutorImpl.cpp)
TARGET_LINK_LIBRARIES(training_main training gtest_main)

ADD_TEST(NAME training_main COMMAND training_main)
