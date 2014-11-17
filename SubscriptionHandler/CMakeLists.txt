cmake_minimum_required( VERSION 2.8 )

project( SubscriptionHandler )

set ( CMAKE_CXX_FLAGS "-Wall -std=c++11" )

set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib )

set( HEADERS
   )

set( SOURCES
     main.cc
   )

add_executable( SubscriptionHandler
                ${HEADERS}
                ${SOURCES}
              )

