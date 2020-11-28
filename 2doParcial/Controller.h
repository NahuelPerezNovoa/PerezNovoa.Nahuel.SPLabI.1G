#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED




int controller_loadFromText(char* path, LinkedList* pArrayListPaises);
int controller_saveAsText(char* path, LinkedList* pArrayListPaises);
int controller_ListPaises(LinkedList* pArrayListPaises);
void* findMasCastigado(LinkedList* pArrayListPaises);
#endif // CONTROLLER_H_INCLUDED
