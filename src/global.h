/**
 * @file
 * @brief Global Definitions
 *
 * This file contains the declaration of global variables and
 * their related values. The actual definition is located in andi.c
 */
#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#include "config.h"

/**
 * The *global* variable ::FLAGS is used to set different options
 * for the execution of the program. Use `FLAGS & F_NAME` to check
 * if `F_NAME` was set.
 */
extern int FLAGS;

/**
 * The *global* variable ::THREADS contains the number of threads the program
 * should use.
 */
extern int THREADS;

/**
 * The ::RANDOM_ANCHOR_PROP represents the probability with which a found
 * anchor is a random match and not homologous. Its value can be set using
 * the `-p` switch.
 */
extern double RANDOM_ANCHOR_PROP;

/** 
 * This enum contains the available flags. Please note that all
 * available options are a power of 2.
 */
enum {
	F_NONE = 0,
	F_RAW = 1,
	F_VERBOSE = 2,
	F_EXTRA_VERBOSE = 4,
	F_NON_ACGT = 8,
	F_JOIN = 16,
	F_LOW_MEMORY = 32,
	F_SHORT = 64
};

#endif

