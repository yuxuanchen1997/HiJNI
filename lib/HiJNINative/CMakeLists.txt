add_library(HiJNINative SHARED Hello.cpp)

target_include_directories(HiJNINative
  PUBLIC
  ${JAVA_INCLUDE_PATH}
  ${JAVA_INCLUDE_PATH2}
  )


target_compile_options(HiJNINative PUBLIC -fembed-bitcode=all)
target_link_options(HiJNINative PUBLIC -fembed-bitcode=all)
generate_bitcode(HiJNINative)
