#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "libraryStructure.h"
#include "addBook.h"
#include "removeBook.h"

// a function that delets the book in the given position.
void removeBook (int position)
{
  int bookToBeDeleted = position - 1;

  // checking if the book whitin the range of the books
  if ( bookToBeDeleted> -1 && bookToBeDeleted < totalNumberOfBooks())
  {
    book[bookToBeDeleted].availability = DELETED_CHAR;
  }
}
