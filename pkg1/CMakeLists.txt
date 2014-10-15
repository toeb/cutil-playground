cmake_minimum_required(VERSION 2.8.7)
#include cutil
include("$ENV{CUTIL_PATH}/cmake/cutil_new.cmake")

# create two library target - an interface library and an implementation also create a test application
project(CalculatorInterface)
include(CTest)
include(GenerateExportHeader)


path_component("${CMAKE_CURRENT_LIST_DIR}" --parent-dir)
ans(pd)
message("pd: ${pd}")
set(CMAKE_INSTALL_PREFIX ${pd}/installed)

# include project's own helper files
include(cmake/helpers.cmake)

add_compiler_export_flags()
#GENERATE_EXPORT_HEADER( LIBRARY_TARGET
#             [BASE_NAME <base_name>]
#             [EXPORT_MACRO_NAME <export_macro_name>]
#             [EXPORT_FILE_NAME <export_file_name>]
#             [DEPRECATED_MACRO_NAME <deprecated_macro_name>]
#             [NO_EXPORT_MACRO_NAME <no_export_macro_name>]
#             [STATIC_DEFINE <static_define>]
#             [NO_DEPRECATED_MACRO_NAME <no_deprecated_macro_name>]
#             [DEFINE_NO_DEPRECATED]
#             [PREFIX_NAME <prefix_name>]
#)

message("include install dir is ${LIBRARY_INSTALL_DIR}")

# create interface library
add_library(interface
 interface/include/calculator_interface.h 
 interface/src/calculator_interface.cpp
)
# set include directoreis for interface library
target_include_dirs_append(interface interface/include ${PROJECT_BINARY_DIR})
generate_export_header(interface)
set(exportName calcInterface)
install(TARGETS interface EXPORT ${exportName}
  RUNTIME DESTINATION ${exportName}/bin
  LIBRARY DESTINATION ${exportName}/lib
  ARCHIVE DESTINATION ${exportName}/lib/static
  )
install(FILES 
  interface/include/calculator_interface.h 
  ${PROJECT_BINARY_DIR}/interface_export.h 
  DESTINATION ${exportName}
)
install(EXPORT
  ${exportName}
  DESTINATION ${exportName}
  FILE calcInterfaceConfig.cmake
  )

# create defaultImplementation library
add_library(defaultImplementation
  default_implementation/src/imp.cpp
  default_implementation/include/simple_calc.h
)
target_link_libraries(defaultImplementation interface)
target_include_dirs_append(defaultImplementation default_implementation/include)
target_include_dirs_inherit(defaultImplementation interface)
generate_export_header(defaultImplementation
  BASE_NAME SIMPLE_CALC_LIB
)
#install(TARGETS defaultImplementation DESTINATION ${LIBRARY_INSTALL_DIR})
#install(FILES 
#  default_implementation/include/simple_calc.h 
# ${PROJECT_BINARY_DIR}/defaultImplementation_export.h
#  DESTINATION ${INCLUDE_INSTALL_DIR}
#)

# create test app
add_executable(test.defaultImplementation test.cpp)
target_include_dirs_inherit(test.defaultImplementation defaultImplementation)
target_link_libraries(test.defaultImplementation defaultImplementation)
add_test(NAME test.defaultImplementation COMMAND test.defaultImplementation)
