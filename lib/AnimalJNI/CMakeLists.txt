add_library(AnimalJNI SHARED Animal.cpp)

target_include_directories(AnimalJNI
  PUBLIC
  ${JAVA_INCLUDE_PATH}
  ${JAVA_INCLUDE_PATH2}
  )


target_compile_options(AnimalJNI PUBLIC -fembed-bitcode=all)
target_link_options(AnimalJNI PUBLIC -fembed-bitcode=all)
generate_bitcode(AnimalJNI)
