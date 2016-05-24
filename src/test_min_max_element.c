/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: test_min_max_element.c
 *
 * Description:
 *      description
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

#include "min_max_element.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>

//#include <immintrin.h>
//uint8_t _mm256_hmax_index(const __m256i v)
//{
//    __m256i vmax = v;
//
//    vmax = _mm256_max_epu32(vmax, _mm256_alignr_epi8(vmax, vmax, 4));
//    vmax = _mm256_max_epu32(vmax, _mm256_alignr_epi8(vmax, vmax, 8));
//    vmax = _mm256_max_epu32(vmax, _mm256_permute2x128_si256(vmax, vmax, 0x01));
//
//    __m256i vcmp = _mm256_cmpeq_epi32(v, vmax);
//
//    uint32_t mask = _mm256_movemask_epi8(vcmp);
//
//    return __builtin_ctz(mask) / 4;
//}


void test_mm_hmin_element_epi8__finds_offset(void)
{
    int8_t arr[32] __attribute__ ((aligned (32)));

    size_t ix = 0;

    for (ix = 0; ix < sizeof (arr); ++ix)
    {
        memset(arr, 0, sizeof (arr));
        arr[ix] = -ix - 1;

        const size_t ret = mm_hmin_element_epi8(_mm256_load_si256((__m256i const *)arr));
        assert(ret == ix);
    }
}


void test_mm_hmin_element_epu8__finds_offset(void)
{
    uint8_t arr[32] __attribute__ ((aligned (32)));

    size_t ix = 0;

    for (ix = 0; ix < sizeof (arr); ++ix)
    {
        memset(arr, 100, sizeof (arr));
        arr[ix] = ix + 1;

        const size_t ret = mm_hmin_element_epu8(_mm256_load_si256((__m256i const *)arr));
        assert(ret == ix);
    }
}


void test_mm_hmax_element_epi8__finds_offset(void)
{
    int8_t arr[32] __attribute__ ((aligned (32)));

    size_t ix = 0;

    for (ix = 0; ix < sizeof (arr); ++ix)
    {
        memset(arr, -100, sizeof (arr));
        arr[ix] = -ix - 1;

        const size_t ret = mm_hmax_element_epi8(_mm256_load_si256((__m256i const *)arr));
        assert(ret == ix);
    }
}


void test_mm_hmax_element_epu8__finds_offset(void)
{
    uint8_t arr[32] __attribute__ ((aligned (32)));

    size_t ix = 0;

    for (ix = 0; ix < sizeof (arr); ++ix)
    {
        memset(arr, 1, sizeof (arr));
        arr[ix] = ix + 2;

        const size_t ret = mm_hmax_element_epu8(_mm256_load_si256((__m256i const *)arr));
        assert(ret == ix);
    }
}


int main()
{
    test_mm_hmin_element_epi8__finds_offset();
    test_mm_hmin_element_epu8__finds_offset();
    test_mm_hmax_element_epi8__finds_offset();
    test_mm_hmax_element_epu8__finds_offset();

//    __auto_type foo = _mm256_hmax_index((__m256i)(__v8si){1, 4, 7, 13, 2, 6, 9, 17});
//    printf("%u\n", foo);
    puts("OK");

    return 0;
}
