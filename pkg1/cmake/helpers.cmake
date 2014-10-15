
# adds the directories specified in ${ARGN} to the target
# resolving them using path function 
function(target_include_dirs_append target)
  paths(${ARGN})
  ans(include_dirs)
  target_append("${target}" INCLUDE_DIRECTORIES ${include_dirs})
  return()
endfunction()



# adds all public include directores from parent_target to target
function(target_include_dirs_inherit target parent_target)
  target_get("${parent_target}" INCLUDE_DIRECTORIES)
  ans(include_dirs)
  target_append("${target}" INCLUDE_DIRECTORIES ${include_dirs})
endfunction()