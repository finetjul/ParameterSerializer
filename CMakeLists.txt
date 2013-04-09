cmake_minimum_required( VERSION 2.8 )

project( ParameterSerializer )

find_package( ITK REQUIRED )
include( ${ITK_USE_FILE} )

find_package( JsonCpp REQUIRED )
include_directories( ${JsonCpp_INCLUDE_DIRS} )


if( NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY )
  set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_BINARY_DIR}/bin )
endif()
if( NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY )
  set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_BINARY_DIR}/lib )
endif()
if( NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY )
  set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_BINARY_DIR}/lib )
endif()


# These will be populated by the subdirectory CMakeLists.txt.
set( ${PROJECT_NAME}_BUILD_INCLUDE_DIRS "" CACHE INTERNAL
  "Build directories with project headers.")
set( ${PROJECT_NAME}_LIBRARIES "" CACHE INTERNAL
  "Project libraries" )

add_subdirectory( include )

include_directories( ${${PROJECT_NAME}_BUILD_INCLUDE_DIRS} )
add_subdirectory( src )

include( CTest )
if( BUILD_TESTING )
  add_subdirectory( test )
endif()

add_subdirectory( cmake )