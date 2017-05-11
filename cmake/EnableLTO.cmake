# - EnableLTO:

function(ENABLE_LTO _target)
    set(_mva CONFIGURATIONS)
    cmake_parse_arguments(LTO "" "" "${_mva}" ${ARGN})

    if(NOT LTO_CONFIGURATIONS OR CMAKE_BUILD_TYPE IN_LIST LTO_CONFIGURATIONS)
        message(STATUS "Enable LTO for ${_target}")
        target_compile_options(${_target} PRIVATE "-flto")
        target_link_libraries(${_target} PRIVATE "-flto")
    endif()
endfunction()
