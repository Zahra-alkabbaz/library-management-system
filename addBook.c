#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "libraryStructure.h"
#include "addBook.h"
#include "removeBook.h"

int countBooks=0;

// a function that reads the books csv file.
void readBooksFile()
{
  FILE* fp;
  // opening the file in read mode
  fp = fopen("../books.csv", "r");
  fseek ( fp , 40 , SEEK_SET );

  while(1)
  {
    // counting the number of intially added books.
    int lineInputs = fscanf(fp, "%d,%[^,],%[^,],%d,%c", &book[countBooks].id, book[countBooks].title, book[countBooks].author, &book[countBooks].publication, &book[countBooks].availability);

    if (lineInputs !=5)
    {
      break;
    }
    countBooks++;
  }
  fclose(fp);
}


// a funcion that chnages the books data borrowed/deleted/available.
void changeBooksData() {

  // opening the csv file again as writing mode to write the new book to it.
  FILE *fp = fopen("../books.csv", "w+");

  // printing the heades of the csv file.
  fprintf(fp,"Id,Title,Author,Publication,Availability\n");


  // rewriting books' data to the csv file.
  for (int i=0; i <totalNumberOfBooks(); i++)
  {
    fprintf(fp, "%d,%s,%s,%d,%c\r\n", book[i].id, book[i].title, book[i].author,
    book[i].publication, book[i].availability);
  }
  fclose(fp);
}


// a function that adds new books to the library.
void addBook(char *title, char *author, int date)
{

  // creating a variable of the size to use later in adding records.
  int newBook = totalNumberOfBooks();

  // giving the book record values to store.
  book[newBook].id = newBook+1;
  strcpy(book[newBook].title, title);
  strcpy(book[newBook].author, author);
  book[newBook].publication = date;
  book[newBook].availability = AVAILABLE_CHAR;

  // everytime this function is called the number of added books get incremented.
  countBooks++;

  /*
  // opening the csv file again as apending mode to add the book to it.
  FILE *fp = fopen("../bookss.csv", "a");

  // printing the books record into a new line in the csv file.
  fprintf(fp, "%d,%s,%s,%d,%c\r\n", book[newBook].id, book[newBook].title, book[newBook].author,
  book[newBook].publication, book[newBook].availability);

  fclose(fp);
  */
}

// a function that returns the total number of books.
int totalNumberOfBooks(){

  return countBooks;
}
