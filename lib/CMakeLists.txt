function(generate_bitcode target)
  set(output_bc ${CMAKE_BINARY_DIR}/${target}.bc)
  if (CMAKE_SYSTEM MATCHES Linux)
    add_custom_command(
      OUTPUT
      ${output_bc}
      VERBATIM COMMAND
      llvm-objcopy --dump-section=.llvmbc=${output_bc} $<TARGET_FILE:${target}>
      DEPENDS
      ${target}
    )
    add_custom_target(
      ${target}BC ALL
      DEPENDS
      ${output_bc}
    )
  else()
  add_custom_command(
    OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/${target}.xar
    VERBATIM COMMAND
    llvm-objcopy --dump-section=__LLVM,__bundle=${CMAKE_CURRENT_BINARY_DIR}/${target}.xar $<TARGET_FILE:${target}>
    DEPENDS
    ${target}
  )

  add_custom_target(
    ${target}XAR ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${target}.xar
  )

  add_custom_command(
    OUTPUT
    ${output_bc}
    COMMAND
    xar -x -f ${CMAKE_CURRENT_BINARY_DIR}/${target}.xar
    COMMAND
    mv 1 ${output_bc}
    DEPENDS
    ${CMAKE_CURRENT_BINARY_DIR}/${target}.xar
  )
  add_custom_target(
    ${target}BC ALL
    DEPENDS
    ${output_bc}
  )
  endif()

endfunction()

add_subdirectory(PersonJNI)
add_subdirectory(HiJNINative)


function(generate_linked_bitcode)
  set(links)
  set(depends)

  foreach(target IN LISTS ARGN)
    set(links ${CMAKE_BINARY_DIR}/${target}.bc ${links})
    set(depends ${CMAKE_BINARY_DIR}/${target}.bc ${depends})
  endforeach()

  add_custom_command(
    OUTPUT
    ${CMAKE_BINARY_DIR}/linked.bc
    ${CMAKE_BINARY_DIR}/linked.ll
    VERBATIM COMMAND
    ${LLVM_BIN}/llvm-link ${links} -o ${CMAKE_BINARY_DIR}/linked.bc
    COMMAND
    ${LLVM_BIN}/llvm-dis ${CMAKE_BINARY_DIR}/linked.bc -o ${CMAKE_BINARY_DIR}/linked.ll
    VERBATIM DEPENDS
    ${depends}
  )
  add_custom_target(bitcode ALL DEPENDS ${CMAKE_BINARY_DIR}/linked.bc ${CMAKE_BINARY_DIR}/linked.ll)
endfunction()

generate_linked_bitcode(PersonJNI HiJNINative)
