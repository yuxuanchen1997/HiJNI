add_library(PersonJNI SHARED Person.cpp)

target_include_directories(PersonJNI
  PUBLIC
  ${JAVA_INCLUDE_PATH}
  ${JAVA_INCLUDE_PATH2}
  )


target_compile_options(PersonJNI PUBLIC -fembed-bitcode=all)
target_link_options(PersonJNI PUBLIC -fembed-bitcode=all)
generate_bitcode(PersonJNI)
