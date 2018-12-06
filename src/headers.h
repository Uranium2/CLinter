/**
* @file headers.h
* @brief This header file will contain all required
* definitions and basic header files for main function.
* @author Antoine TAVERNIER
* @date 16/11/2018
*/
#ifndef HEADERS
#define HEADERS

// Collector
#include "tools/collector.h"

// Config
//#include "config/config.h"
#include "tools/freeAll.h"
#include "file/listFiles.h"

// Rules
#include "rules/checker.h"
#include "rules/checkArrayBracketEol.h"
#include "rules/checkCommentsHeader.h"
#include "rules/checkMaxLineNumbers.h"
#include "rules/checkNoMultiDeclaration.h"
#include "rules/checkNoTrailingSpaces.h"
#include "rules/checkOperatorsSpacing.h"
#include "rules/checkUnusedFunction.h"
#include "rules/checkUnusedVariable.h"


#endif