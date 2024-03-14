# bst-and-graphs
this contains the codes for binary search trees and graphs
In order to use the functions of any other file:
file2.cpp wants to use the functions defined in file1.cpp
we create a header file containing the prototypes of the functions:
#ifndef somename
#define somename
#endif
somename has to be same for the aboe two commands
then simply #include file_header.h wherever you want to it.
