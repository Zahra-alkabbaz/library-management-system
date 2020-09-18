#ifndef SEARCH_BOOK_H

#define SEARCH_BOOK_H

void ReadableAvailability(int i);
void searchBookBasedOnId (int id);
void searchBookBasedOnAuthor (char *author);
void searchBookBasedOnTitle (char *title);
void searchBookBasedOnPublication (int publication);
void searchBookBasedOnAvailability (char mode);
void searchMenu();


#endif
