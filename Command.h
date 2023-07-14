#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "main.h"

void Command1(char *sortName, char *inputFile, char *parameters);
void Command2(char *sortName, char *sizeInput, char *inputOrder,
              char *parameters);
void Command3(char *sortName, char *inputSize, char *parameters);
void Command4(char *sortName1, char *sortName2, char *inputFile);
void Command5(char *sortName1, char *sortName2, char *inputSize,
              char *inputOrder);

#endif  // _COMMAND_H_