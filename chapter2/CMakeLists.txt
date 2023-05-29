file(
  GLOB V_GLOB
  LIST_DIRECTORIES true
  "*")

foreach(item ${V_GLOB})
  if(IS_DIRECTORY ${item})
    add_subdirectory(${item})
    message("ADD SUBDIR ${item}")
  endif()
endforeach()
