project(librarySystem)

add_compile_options(-Wall -Wextra -Wno-unused-parameter -std=c99)
set( CMAKE_BUILD_TYPE Release)
#set( CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 2.6)


add_executable(library
  main.c
  addBook.c
  addStudent.c
  additionalFunctions.c
  searchBook.c
  borrowBook.c
  returnBook.c
  removeBook.c
  menu.c
  adminstration.c
)

add_executable(test
  test.c
  unity.c
  addBook.c
  addStudent.c
  borrowBook.c
  returnBook.c
  removeBook.c
  adminstration.c
)
