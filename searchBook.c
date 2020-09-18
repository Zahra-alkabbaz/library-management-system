#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "libraryStructure.h"
#include "searchBook.h"
#include "addBook.h"
#include "removeBook.h"
#include "adminstration.h"
#include "additionalFunctions.h"

// a function that prints the book availability in a way readable to the user.
void ReadableAvailability(int i)
{
  if (book[i-1].availability == AVAILABLE_CHAR )
  {
    printf("Book availability : available\n");
  }
  else if (book[i-1].availability == BORROWED_CHAR)
  {
    printf("Book availability : borrowed\n");
  }

  else
  {
    printf("Book availability : deleted\n");
  }
}


// a function that displays a menu with variety of search options.
void searchMenu()
{
  int choice, idToBeSearched, publicationTobeSearched;
  char authorToBeSearched[60], titleToBeSearched[90];

// asking the user to choose what type of search they would like.
do
{
  printf("\n\n\n***************************************Search Menu***************************************\n");
  printf("1- Serach For Books based on their id\n");
  printf("2- Serach for Books based on their title\n");
  printf("3- Serach For Books based on their author\n");
  printf("4- Serach for Books based on their publication date\n");
  printf("5- Serach For available Books\n");
  printf("6- Serach For borrowed Books\n");
  printf("7- exit to main menu.\n");

  // prompting the user to choose the action they want to procceed.
  printf("\nEnter the number of the option you want to procceed: ");
  // storing the student chosen search type in choice variable.
  choice = 0;
  scanf("%d", &choice);

  // allowing the student to serach for the books based on their chosen charchteristics.
  switch (choice)
  {
    case 1:
    printf("\n\n\n--------------------------------------------------------Search Book Based on id------------------------------------------------------\n");
    printf("Enter the book id you want to Search for: \n");
    scanf("%d", &idToBeSearched);
    searchBookBasedOnId(idToBeSearched);
    break;

    case 2:
    printf("-------------------------------------------------------Search Book Based on title-----------------------------------------------------\n");
    printf("Enter the book title you want to Search for: \n");
    flush_n();
    getString(titleToBeSearched, 90);
    printf("\n\n");
    searchBookBasedOnTitle(titleToBeSearched);
    break;

    case 3:
    printf("-------------------------------------------------------Search Book Based on author-----------------------------------------------------\n");
    printf("Enter the book author you want to Search for: \n");
    flush_n();
    getString(authorToBeSearched, 110);
    printf("\n\n");
    searchBookBasedOnAuthor(authorToBeSearched);
    break;

    case 4:
    printf("--------------------------------------------------Search Book Based on publication------------------------------------------------------\n");
    printf("Enter the book publication date you want to Search for: \n");
    scanf("%d", &publicationTobeSearched);
    printf("\n\n");
    searchBookBasedOnPublication(publicationTobeSearched);
    break;

    case 5:
    printf("----------------------------------------------------Search For available Books----------------------------------------------------------\n");
    printf("\n\n");
    searchBookBasedOnAvailability(AVAILABLE_CHAR);
    break;

    case 6:
    printf("----------------------------------------------------Search For borrowed Books----------------------------------------------------------\n");
    printf("\n\n");
    searchBookBasedOnAvailability(BORROWED_CHAR);
    break;

    case 7:
    printf("--------------------------------------------------------Exiting Serach menu--------------------------------------------------------------\n");
    break;

    default:
    printf("\nWrong choice, enter an option from the menu.\n");
    flush_n();
    break;
  }
}while(choice !=7);
}

// a function that prints the book based on its id
void searchBookBasedOnId (int id)
{
  int count =0;

  for (int i=0; i< totalNumberOfBooks(); i++)
  {
    if(book[i].id == id )
    {
      // count the number of books for the author.
      count++;
      printBook(i);
      ReadableAvailability(id);
    }
  }

  if (count == 0)
  {
    printf("There is no book with this id\n");
  }
}


// a function that prints the book based on its author.
void searchBookBasedOnAuthor (char *author)
{
  int count =0;

  for (int i=0; i< totalNumberOfBooks(); i++)
  {
    if (strcmp(book[i].author, author ) == 0)
    {
      // count the number of books for the author.
      count++;
      printBook(i);
      ReadableAvailability(book[i].id);
    }
  }

  if (count == 0)
  {
    printf("There is no book author with this name\n");
  }
}

// a function that prints the book based on its title.
void searchBookBasedOnTitle (char *title)
{
  int count =0;

  for (int i=0; i< totalNumberOfBooks(); i++)
  {
    if(strcmp( book[i].title , title) == 0)
    {
      // count the number of books for the author.
      count++;
      printBook(i);
      ReadableAvailability(book[i].id);
    }
  }

  if (count == 0)
  {
    printf("There is no book with this name\n");
  }
}

// a function that prints the book based on its publication.
void searchBookBasedOnPublication (int publication)
{
  int count =0;

  for (int i=0; i< totalNumberOfBooks(); i++)
  {
    if(book[i].publication == publication )
    {
      // count the number of books for the author.
      count++;
      printBook(i);
      ReadableAvailability(book[i].id);
    }
  }

  if (count == 0)
  {
    printf("There is no book  published in this year\n");
  }
}

// a function that prints the book based on its availability.
void searchBookBasedOnAvailability (char mode)
{
  int count =0;

  for (int i=0; i< totalNumberOfBooks(); i++)
  {
    if(book[i].availability == mode )
    {
      // count the number of books for the author.
      count++;
      printBook(i);
    }
  }

  if (count == 0)
  {
    printf("There is no books of this status in the library\n");
  }
}
