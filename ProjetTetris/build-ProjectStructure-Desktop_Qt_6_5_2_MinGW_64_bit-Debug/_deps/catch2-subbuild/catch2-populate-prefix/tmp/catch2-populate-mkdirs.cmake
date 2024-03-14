# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-src"
  "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-build"
  "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix"
  "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/tmp"
  "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
  "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src"
  "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/paras/Desktop/PROJET DEV4 TETRIS/60085_55996_tetris/ProjetTetris/build-ProjectStructure-Desktop_Qt_6_5_2_MinGW_64_bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
