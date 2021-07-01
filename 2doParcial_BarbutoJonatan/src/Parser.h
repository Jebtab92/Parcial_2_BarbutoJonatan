

#ifndef PARSER_H_
#define PARSER_H_

int parser_LibroFromText(FILE* pFile, LinkedList* pArrayListLibro, int* lastID);

int parser_LibroFromBinary(FILE* pFile, LinkedList* pArrayListLibro);

#endif /* PARSER_H_ */
