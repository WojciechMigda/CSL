/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: min_max.h
 *
 * Description:
 *      MIN and MAX macros, need type checking, though
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2016-05-10   wm              Initial version
 *
 ******************************************************************************/


#ifndef MIN_MAX_H_
#define MIN_MAX_H_

#ifdef __cplusplus
extern "C"
{
#endif


//#define MAX(x, y) (x ^ ((x ^ y) & -(x < y)))
#define MAX(a, b) (a > b ? a : b)
//#define MAX(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
//#define MIN(x, y) (y ^ ((x ^ y) & -(x < y)))
#define MIN(a, b) (a < b ? a : b)
//#define MIN(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })


#ifdef __cplusplus
}
#endif

#endif /* MIN_MAX_H_ */
