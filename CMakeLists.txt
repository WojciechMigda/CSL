################################################################################
project( "CSL" C )

cmake_minimum_required( VERSION 2.8.3 )

set( CMAKE_ECLIPSE_VERSION 3.8 )
set( _ECLIPSE_VERSION 3.8 )

add_definitions( -D_GNU_SOURCE -std=c99 )

#add_definitions( -O0 -ggdb -Wall -pedantic -mmmx -msse -msse2 -msse3 -s -pipe -Wno-sign-compare -march=native )
#add_definitions( -O2 -ggdb -std=c++11 -Wall -pedantic -mmmx -msse -msse2 -msse3 -s -pipe -Wno-sign-compare -march=native )
#add_definitions( -O2 -g -unroll-loops -std=c++11 -Wall -pedantic -mmmx -msse -msse2 -msse3 -s -pipe -Wno-sign-compare -march=native )
#add_definitions( -O3 -DNDEBUG -g -unroll-loops -Wall -pedantic -mmmx -msse -msse2 -msse3 -s -pipe -Wno-sign-compare -march=native )
add_definitions( -O3 -DNDEBUG -g -unroll-loops -Wall -pedantic -mmmx -msse -msse2 -msse3 -mavx2 -s -pipe -Wno-sign-compare -march=native )
#add_definitions( -O3 -DNDEBUG )



################################################################################

include_directories(
    src
)

################################################################################

add_executable( test_min_max_element src/test_min_max_element.c )
add_executable( test_option_type src/test_option_type.c )
add_executable( test_span src/test_span.c )

################################################################################
