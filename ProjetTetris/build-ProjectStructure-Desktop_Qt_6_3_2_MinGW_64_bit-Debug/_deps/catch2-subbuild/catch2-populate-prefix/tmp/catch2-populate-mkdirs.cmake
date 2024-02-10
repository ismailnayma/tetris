# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/esi_2024/Q4/DEV4/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/_deps/catch2-src"
  "C:/esi_2024/Q4/DEV4/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/_deps/catch2-build"
  "C:/esi_2024/Q4/DEV4/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix"
  "C:/esi_2024/Q4/DEV4/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/tmp"
  "C:/esi_2024/Q4/DEV4/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
  "C:/esi_2024/Q4/DEV4/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src"
  "C:/esi_2024/Q4/DEV4/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/esi_2024/Q4/DEV4/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/${subDir}")
endforeach()
