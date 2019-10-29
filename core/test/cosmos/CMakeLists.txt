cmake_minimum_required(VERSION 3.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${CMAKE_BINARY_DIR}/include)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(ledger-core-cosmos-tests main.cpp address_test.cpp transactions_test.cpp)

target_link_libraries(ledger-core-cosmos-tests gtest gtest_main)
target_link_libraries(ledger-core-cosmos-tests ledger-core)
target_link_libraries(ledger-core-cosmos-tests ledger-test)
target_link_libraries(ledger-core-cosmos-tests leveldb)
target_include_directories(ledger-core-cosmos-tests PUBLIC ../../../core/lib/leveldb/include)
include_directories(../lib/libledger-test/)

include(CopyAndInstallImportedTargets)
copy_install_imported_targets(ledger-core-cosmos-tests crypto ledger-core)

add_test (NAME ledger-core-cosmos-tests COMMAND ledger-core-cosmos-tests)