#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "libraryStructure.h"
#include "addBook.h"
#include "returnBook.h"

// a function that changes the availability status of a book to available(returns it).
void returnBook(int id, char *author, int publication)
{
  int position = id -1;

  // if the book is borrowed we return it to be available again.
  if (book[position].availability == BORROWED_CHAR)
  {
    book[position].availability = AVAILABLE_CHAR;
  }
}
