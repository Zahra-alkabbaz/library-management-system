#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "libraryStructure.h"
#include "addStudent.h"

int studentCount=0;

// reads the given students csv file ans stores its data into an array.
void readStudentsFile()
{
  FILE *fp;
  // opening the file in read mode
  fp = fopen("../students.csv", "r");
  //to skip the first line.
  fseek (fp , 25 , SEEK_SET);

//reading all lines of the csv files except the first line.
  while(1)
  {
    int lineInputs = fscanf(fp, "%d,%[^,],%[^,],%[^,\n\r]", &student[studentCount].id, student[studentCount].name, student[studentCount].username, student[studentCount].password);

    if (lineInputs !=4)
    {
      break;
    }
    studentCount++;
  }

  fclose(fp);
}

// a function that adds new students to the students' records.
void addStudent(char *name, char *username, char *password)
{


  // creating a variable of the size to use later in adding records.
  int newStudent = totalNumberOfStudents();

  // storing the given values of student records.
  student[newStudent].id = newStudent+1;
  strcpy(student[newStudent].name, name);
  strcpy(student[newStudent].username, username);
  strcpy(student[newStudent].password, password);
  studentCount++;
}

// a function that adds the new student at the end of the csv file.
void addStudentToTheFile()
{
  int newStudent = totalNumberOfStudents()-1;
  // opening the csv file again as writing mode to add the student to it.
  FILE *fp = fopen("../students.csv", "a");

  // printing the student record into a new line.
  fprintf(fp, "%d,%s,%s,%s\r\n", student[newStudent].id, student[newStudent].name,
  student[newStudent].username, student[newStudent].password);

  fclose(fp);
}

// returns the total number of registered students.
int totalNumberOfStudents()
{
  return studentCount;
}
