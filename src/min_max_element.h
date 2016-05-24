/*******************************************************************************
 * Copyright (c) 2016 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: min_max_element.h
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


#ifndef MIN_MAX_ELEMENT_H_
#define MIN_MAX_ELEMENT_H_


#include "span.h"
#include "likely.h"
#include "min_max.h"

#include <stdint.h>
#include <immintrin.h>


DEFINE_SPAN(int8_t);
DEFINE_SPAN(uint8_t);

#ifdef __cplusplus
extern "C"
{
#endif


static inline
size_t mm_hmin_element_epi8(const __m256i ivec)
{
    __m256i vec = ivec;

    vec = _mm256_min_epi8(vec, _mm256_alignr_epi8(vec, vec, 1));
    vec = _mm256_min_epi8(vec, _mm256_alignr_epi8(vec, vec, 2));
    vec = _mm256_min_epi8(vec, _mm256_alignr_epi8(vec, vec, 4));
    vec = _mm256_min_epi8(vec, _mm256_alignr_epi8(vec, vec, 8));
    vec = _mm256_min_epi8(vec, _mm256_permute2x128_si256(vec, vec, 0x01));

    const __m256i vcmp = _mm256_cmpeq_epi8(ivec, vec);

    const uint32_t mask = _mm256_movemask_epi8(vcmp);

    return __builtin_ctz(mask);
}


static inline
size_t mm_hmin_element_epu8(const __m256i ivec)
{
    __m256i vec = ivec;

    vec = _mm256_min_epu8(vec, _mm256_alignr_epi8(vec, vec, 1));
    vec = _mm256_min_epu8(vec, _mm256_alignr_epi8(vec, vec, 2));
    vec = _mm256_min_epu8(vec, _mm256_alignr_epi8(vec, vec, 4));
    vec = _mm256_min_epu8(vec, _mm256_alignr_epi8(vec, vec, 8));
    vec = _mm256_min_epu8(vec, _mm256_permute2x128_si256(vec, vec, 0x01));

    const __m256i vcmp = _mm256_cmpeq_epi8(ivec, vec);

    const uint32_t mask = _mm256_movemask_epi8(vcmp);

    return __builtin_ctz(mask);
}


static inline
size_t mm_hmax_element_epi8(const __m256i ivec)
{
    __m256i vec = ivec;

    vec = _mm256_max_epi8(vec, _mm256_alignr_epi8(vec, vec, 1));
    vec = _mm256_max_epi8(vec, _mm256_alignr_epi8(vec, vec, 2));
    vec = _mm256_max_epi8(vec, _mm256_alignr_epi8(vec, vec, 4));
    vec = _mm256_max_epi8(vec, _mm256_alignr_epi8(vec, vec, 8));
    vec = _mm256_max_epi8(vec, _mm256_permute2x128_si256(vec, vec, 0x01));

    const __m256i vcmp = _mm256_cmpeq_epi8(ivec, vec);

    const uint32_t mask = _mm256_movemask_epi8(vcmp);

    return __builtin_ctz(mask);
}


static inline
size_t mm_hmax_element_epu8(const __m256i ivec)
{
    __m256i vec = ivec;

    vec = _mm256_max_epu8(vec, _mm256_alignr_epi8(vec, vec, 1));
    vec = _mm256_max_epu8(vec, _mm256_alignr_epi8(vec, vec, 2));
    vec = _mm256_max_epu8(vec, _mm256_alignr_epi8(vec, vec, 4));
    vec = _mm256_max_epu8(vec, _mm256_alignr_epi8(vec, vec, 8));
    vec = _mm256_max_epu8(vec, _mm256_permute2x128_si256(vec, vec, 0x01));

    const __m256i vcmp = _mm256_cmpeq_epi8(ivec, vec);

    const uint32_t mask = _mm256_movemask_epi8(vcmp);

    return __builtin_ctz(mask);
}

//static inline
//int8_t * naive_min_element_i8(SPAN(int8_t) span)
//{
//    int8_t result = INT8_MAX;
//
//    if (UNLIKELY((span.ptr == NULL) || (span.sz == 0)))
//    {
//        return NULL;
//    }
//
//    FOREACH_SPAN(val, span, result = MIN(val, result));
//    //FOREACH_SPAN(val, span, result = val < result ? val : result);
//
//    return span.ptr;
//}


#ifdef __cplusplus
}
#endif

#endif /* MIN_MAX_ELEMENT_H_ */
