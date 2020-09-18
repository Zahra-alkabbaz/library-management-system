#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "addBook.h"
#include "adminstration.h"
#include "removeBook.h"
#include "libraryStructure.h"
#include "addStudent.h"

int tempPublication;

// asigning a librarian to manage the library system.
void adminInfo(){
  admin.id = 1;
  strcpy(admin.name, "pablou James");
  strcpy(admin.username, "mainAdmin");
  strcpy(admin.password, "noStudents9321");
}

// prints book details for the admin.
void printBook(int i) {
  printf("\n\n");
  printf("Book Id           : %d \n", book[i].id);
  printf("Book Title        : %s \n", book[i].title);
  printf("Book Author       : %s \n", book[i].author);
  printf("Book publication  : %d\n", book[i].publication);
}


// printing all the avaliable or borrowed books to
void listAllBooks(){
  int n=0;
  for (int i=0; i<totalNumberOfBooks(); i++)
  {
    if (book[i].availability != DELETED_CHAR)
    {
      n++;
      printBook(i);
      printf("Book availability : %c\n", book[i].availability);
    }
  }
  if (n ==0)
  {
    printf("there is no books in the library.");
  }
}

// printing all the books in the library with the given status.
void listBooks(char bookStatus){
  int n=0;
  for (int i=0; i<totalNumberOfBooks(); i++)
  {
    if (book[i].availability == bookStatus)
    {
      n++;
      printBook(i);
    }
  }
  if (n ==0)
  {
    printf("There is no books of this type in the library.");
  }
}

void studentDetails(int i)
{
  printf("Student Id         : %d \n", student[i].id);
  printf("Student name       : %s \n", student[i].name);
  printf("Student username   : %s \n", student[i].username);
  printf("Student password   : %s \n\n\n", student[i].password);
}

// listing all the student registered in the library system.
void listAllStudents(){
  for (int i=0; i<totalNumberOfStudents(); i++)
  {
    studentDetails(i);
  }
}
