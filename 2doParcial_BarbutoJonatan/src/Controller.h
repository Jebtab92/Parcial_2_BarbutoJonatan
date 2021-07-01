

int controller_loadFromText(char* path, LinkedList* pArrayListLibro, int* lastID);

int controller_loadFromBinary(char* path, LinkedList* pArrayListLibro);

int controller_addLibro(LinkedList* pArrayListLibro, int* contadorID);

int controller_editLibro(LinkedList* pArrayListLibro);

int controller_removeLibro(LinkedList* pArrayListLibro);

int controller_ListLibro(LinkedList* pArrayListLibro);

int controller_sortLibro(LinkedList* pArrayListLibro);

int controller_saveAsText(char* path, LinkedList* pArrayListLibro);

int controller_saveAsBinary(char* path, LinkedList* pArrayListLibro);

int controller_applyDis(LinkedList* pArrayListLibro);
