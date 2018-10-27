message("cpp level CMakeLists.txt")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

set(ACE_ROOT $ENV{ACE_ROOT})
set(TAO_ROOT $ENV{TAO_ROOT})

include_directories(${ACE_ROOT} ${TAO_ROOT} ${TAO_ROOT}/orbsvcs)
link_directories(${ACE_ROOT}/lib)

#set_source_files_properties(${calc_GEN_STUB} PROPERTIES GENERATED TRUE)
# SET(SRC ${calc_GEN_STUB})
SET(SRC calcclient.cpp)
ADD_EXECUTABLE(calcclient ${SRC})
target_link_libraries(calcclient boost_date_time TAO_AnyTypeCode TAO_PortableServer TAO ACE_FOR_TAO calc)
