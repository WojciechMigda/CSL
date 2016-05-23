/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: test_span.c
 *
 * Description:
 *      SPAN macro test suite
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2016-05-20   wm              Initial version
 *
 ******************************************************************************/

#include "span.h"

#include <stdio.h>

DEFINE_SPAN(int);
DEFINE_SPAN_T(int);

SPAN(int) null_span = NULL_SPAN(int);
const SPAN(int) null_span_const = NULL_SPAN(int);

void receive_span(SPAN(int) span)
{
    printf("Got span at %p with %zu elements\n", (void *)span.ptr, span.sz);
}


SPAN(int) make_null_span(void)
{
    return MAKE_NULL_SPAN(int);
}


void foreach_span(SPAN(int) span)
{
    FOREACH_SPAN(item, span, printf("x: %d\n", item));
    FOREACH_SPAN(item, span,
    {
        const int foo = item * 2 + 1;
        printf("2x+1: %d\n", foo);
    });
}

SPAN(int) iota_span(SPAN(int) span)
{
    IOTA_SPAN(span, 1);

    return span;
}

int main()
{
    int array[10];
    iota_span(MAKE_SPAN(int, &array[0], 10));

    receive_span(MAKE_SPAN(int, &array[0], 10));

    make_null_span();

    int initialized[] = {1, 4, 7};
    foreach_span(MAKE_SPAN(int, &initialized[0], 3));

    puts("OK");

    return 0;
}
