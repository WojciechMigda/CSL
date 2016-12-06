/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: move_ptr.h
 *
 * Description:
 *      Moving raw pointer
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2016-12-06   wm              Initial version
 *
 ******************************************************************************/


#ifndef MOVE_PTR_H_
#define MOVE_PTR_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif


/*
 *  MOVE_PTR null-ifies pointer passed as its argument.
 *  The moved pointer has to be an lvalue and cannot be const.
 */
#define MOVE_PTR(p) ({__typeof(*(p)) * _p = (p); (p) = NULL; _p;})


#ifdef __cplusplus
}
#endif

#endif /* MOVE_PTR_H_ */
