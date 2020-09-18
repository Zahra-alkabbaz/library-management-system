#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "libraryStructure.h"
#include "borrowBook.h"

// a function that changes the availability status of the book to borrowed rather than available.
void borrowBook(int id, char *author, int publication)
{
  int position = id -1;

  // if the book is borrowed we return it to available again.
  if(book[position].availability == AVAILABLE_CHAR)
  {
    book[position].availability = BORROWED_CHAR;
  }
}
