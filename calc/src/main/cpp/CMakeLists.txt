message("cpp level CMakeLists.txt")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

set(ACE_ROOT $ENV{ACE_ROOT})
set(TAO_ROOT $ENV{TAO_ROOT})
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.65.1 COMPONENTS date_time) 

include_directories(${ACE_ROOT} ${TAO_ROOT} ${TAO_ROOT}/orbsvcs ${Boost_INCLUDE_DIRS})
FIND_PROGRAM( CORBAIDL tao_idl )
set ( calc_GEN_STUB ${PROJECT_SOURCE_DIR}/main/cpp/CalcS.cpp  ${PROJECT_SOURCE_DIR}/main/cpp/CalcC.cpp)
add_custom_command (
	OUTPUT ${calc_GEN_STUB}
	COMMAND ${CORBAIDL}
	ARGS -Wbh=.h -Wbs=.cpp -I${PROJECT_SOURCE_DIR}/main/idl
	${PROJECT_SOURCE_DIR}/main/idl/Calc.idl -o ${PROJECT_SOURCE_DIR}/main/cpp
)

set_source_files_properties(${calc_GEN_STUB} PROPERTIES GENERATED TRUE)
SET(SRC ${calc_GEN_STUB} CalcImpl CalcLib)
ADD_LIBRARY(calc SHARED ${SRC})
