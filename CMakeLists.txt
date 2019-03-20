cmake_minimum_required(VERSION 3.9.3)

include(cmake/HunterGate.cmake)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.44.tar.gz"
    SHA1 "c4cfcc0cd39fdae8de08f6205b7f34cab4a7ba79"
    LOCAL
)

project(cpp_ssz)
hunter_add_package(ethash)
find_package(ethash CONFIG REQUIRED)

ADD_EXECUTABLE(test_bool  test_bool.cpp)
ADD_EXECUTABLE(test_uintN  test_uint.cpp)
ADD_EXECUTABLE(test_bytes test_bytes.cpp)
ADD_EXECUTABLE(test_bytesN test_bytesN.cpp)
ADD_EXECUTABLE(test_list   test_list.cpp)
ADD_EXECUTABLE(test_vector   test_vector.cpp)
ADD_EXECUTABLE(test_container   test_container.cpp)

ADD_EXECUTABLE(test_pack   test_pack.cpp)
ADD_EXECUTABLE(test_merkleize   test_merkleize.cpp)
ADD_EXECUTABLE(test_mix_in_length   test_mix_in_length.cpp)
include_directories(${ETHASH_ROOT}/include)
target_link_libraries (test_pack ${ETHASH_ROOT}/lib/libethash.a)
target_link_libraries (test_merkleize ${ETHASH_ROOT}/lib/libethash.a)
target_link_libraries (test_mix_in_length ${ETHASH_ROOT}/lib/libethash.a)
