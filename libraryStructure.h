#ifndef LIBRARY_STRUCTURE_H

#define LIBRARY_STRUCTURE_H


#define AVAILABLE_CHAR 'a'
#define DELETED_CHAR 'd'
#define BORROWED_CHAR 'b'



// creating a data structure for books
typedef struct {
int id, publication; // a specific id for each book.
char title[100], author[100], availability;
}bookRecord;


// creating a student data structure
typedef struct {
int id; // a specific id for each student.
char name[60], username[60], password[60];
}userRecord;

bookRecord book[1000];
userRecord student[1000];

//defining one specific admin.
userRecord admin;


#endif
