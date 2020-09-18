#include "unity.h"
#include "addBook.h"
#include "libraryStructure.h"
#include "addStudent.h"
#include "borrowBook.h"
#include "removeBook.h"
#include "returnBook.h"



// testing if books added correctly according to title of books
void testBookTitleAccuracy () {
  TEST_ASSERT_EQUAL_STRING("Cloud computing", book[1].title);
  TEST_ASSERT_EQUAL_STRING("Quantum computing", book[5].title);
  TEST_ASSERT_EQUAL_STRING("Quantum computing", book[10].title);
  TEST_ASSERT_EQUAL_STRING("Distributed computing", book[12].title);
  TEST_ASSERT_EQUAL_STRING("Computing: a human activity", book[16].title);
  TEST_ASSERT_EQUAL_STRING("Creative computing", book[22].title);
  TEST_ASSERT_EQUAL_STRING("Numerical computing with MATLAB", book[24].title);
}

// test if books added correctly according to authors names
void testBookAuthorAccuracy () {
  TEST_ASSERT_EQUAL_STRING("Nayan Ruparelia", book[0].author);
  TEST_ASSERT_EQUAL_STRING("Michael Bader;Hans-Joachim Bungartz;Tobias Weinzierl", book[2].author);
  TEST_ASSERT_EQUAL_STRING("Martyn Amos", book[9].author);
  TEST_ASSERT_EQUAL_STRING("Joseph November", book[11].author);
  TEST_ASSERT_EQUAL_STRING("Rosalind Picard", book[15].author);
  TEST_ASSERT_EQUAL_STRING("Frances James;Ann Kerr", book[22].author);
  TEST_ASSERT_EQUAL_STRING("William Press", book[23].author);
}

// test if books added correctly according to publication date
void testBookAPublicationAccuracy () {
  TEST_ASSERT_EQUAL_INT(2016, book[0].publication);
  TEST_ASSERT_EQUAL_INT(2001, book[10].publication);
  TEST_ASSERT_EQUAL_INT(1992, book[16].publication);
  TEST_ASSERT_EQUAL_INT(2004, book[24].publication);
}

// testing if borrowing book goes correctly.
void testBorrowBook()
{
  TEST_ASSERT_EQUAL_UINT8(AVAILABLE_CHAR, book[19].availability);
  borrowBook(20,"Wen-mei Hwu", 2011);
  TEST_ASSERT_EQUAL_STRING("GPU computing gems", book[19].title);
  TEST_ASSERT_EQUAL_INT(2011, book[19].publication);
  TEST_ASSERT_EQUAL_UINT8 (BORROWED_CHAR, book[19].availability);
}

// testing if a books is returned correctly.
void testReturnBook()
{
  // returning the book.
  TEST_ASSERT_EQUAL_UINT8 (BORROWED_CHAR, book[19].availability);
  returnBook(20,"Wen-mei Hwu", 2011);
  TEST_ASSERT_EQUAL_INT(2011, book[19].publication);
  TEST_ASSERT_EQUAL_UINT8 (AVAILABLE_CHAR, book[19].availability);
}

//test adding a new book.
void testAddBook()
{
  addBook("Intro to Java programming", "Daniel Liang", 2014);
  TEST_ASSERT_EQUAL_STRING("Daniel Liang", book[totalNumberOfBooks()-1].author);
  TEST_ASSERT_EQUAL_INT(2014 , book[totalNumberOfBooks()-1].publication);
  TEST_ASSERT_EQUAL_UINT8 (AVAILABLE_CHAR, book[totalNumberOfBooks()-1].availability);
}

// test deleting book.
void testRemoveBook()
{
  TEST_ASSERT_EQUAL_UINT8 (AVAILABLE_CHAR, book[totalNumberOfBooks()-1].availability);
  removeBook(totalNumberOfBooks());
  TEST_ASSERT_EQUAL_INT(2014, book[totalNumberOfBooks()-1].publication);
  TEST_ASSERT_EQUAL_STRING("Daniel Liang", book[totalNumberOfBooks()-1].author);
  TEST_ASSERT_EQUAL_UINT8 (DELETED_CHAR, book[totalNumberOfBooks()-1].availability);
}


// checking student id accuracy for added students
void testStudentIdAccuracy () {
  TEST_ASSERT_EQUAL_INT(1, student[0].id);
  TEST_ASSERT_EQUAL_INT(10, student[9].id);
  TEST_ASSERT_EQUAL_INT(20, student[19].id);
  TEST_ASSERT_EQUAL_INT(30, student[29].id);
  TEST_ASSERT_EQUAL_INT(40, student[39].id);
  TEST_ASSERT_EQUAL_INT(58, student[57].id);
}

// checking students names accuracy according tothe given csv file
void testStudentNameAccuracy () {
  TEST_ASSERT_EQUAL_STRING("Sara Walkers", student[1].name);
  TEST_ASSERT_EQUAL_STRING("Raisa Glaude", student[20].name);
  TEST_ASSERT_EQUAL_STRING("Trevor Salzman", student[40].name);
  TEST_ASSERT_EQUAL_STRING("Jean Blane", student[55].name);
}

// checking students usernames accuracy according tothe given csv file
void testStudentUsernameAccuracy () {
  TEST_ASSERT_EQUAL_STRING("fy16zkw", student[0].username);
  TEST_ASSERT_EQUAL_STRING("ba17ka", student[12].username);
  TEST_ASSERT_EQUAL_STRING("sc17nal", student[36].username);
  TEST_ASSERT_EQUAL_STRING("fy17fds", student[55].username);
}

// checking students password accuracy according to the given csv file
void testStudentPasswordAccuracy () {
  TEST_ASSERT_EQUAL_STRING("wt5TFVn4", student[3].password);
  TEST_ASSERT_EQUAL_STRING("b6apDGT2", student[24].password);
  TEST_ASSERT_EQUAL_STRING("vVjswmEN", student[38].password);
  TEST_ASSERT_EQUAL_STRING("zvvfTtLp", student[57].password);
}

// checking if new student record added correctly
void testRegisteringNewStudent()
{
  // adding student
  addStudent("Emma Tomson", "fy18etq", "aFkNTCkt");
  TEST_ASSERT_EQUAL_STRING("Emma Tomson", student[totalNumberOfStudents()-1].name);
  TEST_ASSERT_EQUAL_INT(59, student[58].id);
}

int main (void) {

  UNITY_BEGIN();

  //reading the given csv file to get students and books information.
  readStudentsFile();
  readBooksFile();

  // testing books accuracy in the array.
  printf("\n\n");
  RUN_TEST(testBookTitleAccuracy);
  printf("\n");
  RUN_TEST(testBookAuthorAccuracy);
  printf("\n");
  RUN_TEST(testBookAPublicationAccuracy);
  printf("\n");
  RUN_TEST(testBorrowBook);
  printf("\n");
  RUN_TEST(testReturnBook);
  printf("\n");
  RUN_TEST(testAddBook);
  printf("\n");
  RUN_TEST(testRemoveBook);
  printf("\n");

  // testing student existence accuracy.
  RUN_TEST(testStudentIdAccuracy);
  printf("\n");
  RUN_TEST(testStudentNameAccuracy);
  printf("\n");
  RUN_TEST(testStudentUsernameAccuracy);
  printf("\n");
  RUN_TEST(testStudentPasswordAccuracy);
  printf("\n");
  RUN_TEST(testRegisteringNewStudent);
  printf("\n");

  return UNITY_END();
}
