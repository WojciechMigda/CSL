/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: test_option_type.c
 *
 * Description:
 *      OPTION_TYPE macro test suite
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2016-05-23   wm              Initial version
 *
 ******************************************************************************/

#include "option_type.h"

#include <stdio.h>
#include <assert.h>


DEFINE_OPTION_TYPE(int);

OPTION_TYPE(int) none_option_type = OPTION_TYPE_NONE(int);
const OPTION_TYPE(int) const_some_option_type = OPTION_TYPE_SOME(int, 4);


int main()
{
    assert(OPTION_TYPE_GET(const_some_option_type) == 4);
    assert(OPTION_TYPE_VALUE(const_some_option_type) == 4);

    assert(OPTION_TYPE_IS_SOME(const_some_option_type));
    assert(!OPTION_TYPE_IS_SOME(none_option_type));

    puts("OK");

    return 0;
}
