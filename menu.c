#include "menu.h"

int tempPublication, tempId, studentFailToLogin=0, studentExist=0, adminFailedToLogin =0, adminLoggedIn=0;

// defining the variables for the values that will be given later in compile time.
char tempTitle[90], tempAuthor[90], tempName[50], tempUsername[25], tempPassword[25];

// a function that prompts the user to input book details.
void getBookDetails()
{
  printf("Enter Book details as below:\n\n");
  printf("Enter Book publication date:\n");
  scanf("%d", &tempPublication);

  printf("\nEnter Book title:\n");
  flush_n();
  getString(tempTitle, 90);

  printf("\nEnter Book author:(for multiple authors; separate authors with semicolon).\n");
  getString(tempAuthor, 90);

  printf("\n\n");
}

// a function that checks whether the given book details are correct or not.
void checkBookDetails()
{ int count=0;
  for (int i=0; i< totalNumberOfBooks(); i++)
  {
    if(strcmp(book[i].title , tempTitle) == 0 && strcmp(book[i].author, tempAuthor) == 0
    && book[i].publication == tempPublication)
    {
      tempId = book[i].id;
      // count the number of books for the author.
      count=1;
    }
  }

  if (count == 0)
  {
    printf("There is no book that matches your search\n");
  }
}



// a function that prompt the user to input student information and it stores them in variables.
void getAddStudentDetails()
{
  printf("Enter Student details as below:\n");
  printf("Enter Student Name:\n");
  flush_n();
  getString(tempName, 50);

  printf("Enter Student Username:\n");
  scanf("%s",tempUsername);

  printf("Enter password:\n");
  scanf("%s", tempPassword);
}

// a function that allows the student to log in to the library.
void studentLogin()
{

  char student_username[30], student_password[30];
  studentFailToLogin++;

  while (studentExist == 0)
  {

    printf("\n\n******************************* Student Sign in **************************************\n\n");
    printf("Enter username: ");
    scanf("%s", student_username);
    printf("Enter password: ");
    scanf("%s", student_password);

    for (int i=0; i<= totalNumberOfStudents(); i++)
    {
      // if the entered username and password are in the students then log in.
      if (strcmp(student[i].username, student_username) == 0 && strcmp(student[i].password, student_password) == 0)
      {
        studentExist++;
      }
    }

    // if the entered pasaword or username is wrong it breaks.
    if (studentExist == 0 )
    {
      printf("Username or password is wrong, Please try again.");
      studentFailToLogin++;

      // if password/ username is wrong for 3 times it breaks.
      if(studentFailToLogin>3)
      {
        printf("You entered wrong username/password for 3 times\n");
        break;
      }
    }
  }
}

// a function that allows the admin to log in to the library.
void adminLogin()
{
  char admin_username[25], admin_password[25];

  while(adminLoggedIn == 0)
  {
    printf("\n\n******************************* Admin Sign in **************************************\n\n");
    printf("Enter username: ");
    scanf("%s", admin_username);

    printf("\nEnter password: ");
    scanf("%s", admin_password);

    if (strcmp(admin.username , admin_username) == 0 && strcmp(admin.password, admin_password) == 0)
      {
        adminLoggedIn++;
        printf("\n\n*********************************** Login successful ****************************************\n\n");
      }
    else
    {
      printf("Username or password is wrong, Please try again.");
      adminFailedToLogin++;

      if(adminFailedToLogin > 3)
      {
        printf("You entered wrong username/password for 3 times\n");
        break;
      }
    }
  }
}

// a function that displays the admin menu with the functionalities they can proceed.
void adminMenu() {
  int choice;
  do
  {
    printf("\n\n\n------------------------Adminstration Menu-------------------------- \n\n");
    printf("1- add new book to the library. \n");
    printf("2- add a new student. \n");
    printf("3- Remove a book from the library. \n");
    printf("4- List all Books. \n");
    printf("5- List all available Books. \n");
    printf("6- List all borrowed Books. \n");
    printf("7- List all the deleted Books. \n");
    printf("8- List all Students. \n");
    printf("9- Log off the adminstration account. \n\n");

    // prompting the admin to choose from the menu.
    printf("please enter your choice: ");
    scanf("%d", &choice );

    switch(choice)
    {
      case 1:
      printf("******************************************** Adding new Book to the library ***********************************************\n\n");
      getBookDetails();
      addBook(tempTitle, tempAuthor, tempPublication);
      printf("The added book's record is as shown below.");
      printBook(totalNumberOfBooks()-1);
      ReadableAvailability(totalNumberOfBooks());
      break;

      case 2:
      printf("******************************************** Adding new Student to the library ***********************************************\n\n");
      getAddStudentDetails();
      addStudent(tempName, tempUsername, tempPassword);
      addStudentToTheFile();
      printf("\n\nThe added student has the details below:\n");
      studentDetails(totalNumberOfStudents()-1);
      break;

      case 3:
      printf("******************************************** Deleting a Book to the library ***********************************************\n\n");
      getBookDetails();
      checkBookDetails();
      removeBook(tempId);
      printf("The deleted book's record is as shown below.");
      printBook(tempId-1);
      ReadableAvailability(tempId);
      break;

      case 4:
      printf("********************************************* Listing All Books information **************************************************\n\n");
      listAllBooks();
      break;

      case 5:
      printf("******************************************* Listing All the available Books information ************************************************\n\n");
      listBooks(AVAILABLE_CHAR);
      break;

      case 6:
      printf("******************************************* Listing the borrowed Books information **********************************************\n\n");
      listBooks(BORROWED_CHAR);
      break;

      case 7:
      printf("******************************************* Listing Deleted Books information **********************************************\n\n");
      listBooks(DELETED_CHAR);
      break;

      case 8:
      printf("******************************************* List All Students information *************************************************\n\n");
      listAllStudents();
      break;

      case 9:
      printf("******************************************** Logging off the Admin account *******************************************\n\n");
      break;

      default:
      printf("\nInvalid choice.\n");
      flush_n();
      break;

    }
  }while(choice !=9);
}



// a function to display a menu of different options to the student to use.
void studentMenu() {
  int option;
  do
  {
    printf("\n\n------------------------Student Library Menu------------------------- \n\n");
    printf("1- search for books.\n");
    printf("2- borrow a book.\n");
    printf("3- return a book.\n");
    printf("4- Log off.\n\n");

    // prompting the user to choose an option and storing the chosen number.
    printf("Enter your chosen action number to proceed : \n");
    scanf("%d", &option);

    // using the switch statement.
    switch(option)
    {
      case 1:
      searchMenu();
      break;

      case 2:
      printf("******************************************** Borrowing Book from the library ***********************************************\n\n");
      getBookDetails();
      checkBookDetails();
      borrowBook(tempId, tempAuthor, tempPublication);
      printf("The borrowed book's record is as shown below.");
      printBook(tempId-1);
      ReadableAvailability(tempId);
      break;

      case 3:
      printf("******************************************** Returning a Book to the library ***********************************************\n\n");
      getBookDetails();
      checkBookDetails();
      returnBook(tempId, tempAuthor, tempPublication);
      printf("The returned book's record is as shown below.");
      printBook(tempId-1);
      ReadableAvailability(tempId);
      break;

      case 4:
      printf("******************************************** Logging off the Student account *******************************************\n\n");
      break;

      default:
      printf("\nWrong choice, enter an option from the menu.\n");
      flush_n();
      break;
    }

  }while(option !=4);
}

// the main menu where the system starts.
void mainMenu()
{
  int option;
  adminInfo();
  readStudentsFile();
  readBooksFile();


  do {
    printf("\n\n\n**************************************************************************************************************************************\n");
    printf("**************************************************************************************************************************************\n");
    printf("*************************************************************Library System***********************************************************\n");
    printf("**************************************************************************************************************************************\n");
    printf("**************************************************************************************************************************************\n\n");

    printf("\nChoose From below: \n");
    printf("1- Student Log in. \n");
    printf("2- Admin Log in. \n");
    printf("3- Register as a new user. \n");
    printf("4- Exit the Library system. \n\n");

    printf("Enter your choice:\n");
    scanf("%d", &option );


    switch (option) {
      case 1:
      studentLogin();
      if (studentExist == 1 && studentFailToLogin <3)
      {
        studentMenu();
      }
      break;

      case 2:
      adminLogin();
      adminMenu();
      break;

      case 3:
      printf("********************************************* Register a new student **************************************************\n\n");
      getAddStudentDetails();
      addStudent(tempName, tempUsername,tempPassword);
      addStudentToTheFile();
      studentMenu();
      break;

      case 4:
      printf("**********************************************Exiting the Library System**********************************************\n\n\n");
      changeBooksData();
      exit(0);
      break;

      default:
      printf("\nInvalid choice.\n");
      flush_n();
      break;
    }
  }while(option !=4);
}
