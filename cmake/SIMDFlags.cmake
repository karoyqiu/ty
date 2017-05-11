function(CHECK_SIMD_FLAGS SIMD_FLAGS)
    include(TargetArch)
    target_architecture(TARGET_ARCH)

    if(TARGET_ARCH STREQUAL "i386" OR TARGET_ARCH STREQUAL "x86_64")
        if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
            set(CANDIDATE_FLAGS "-msse4.2" "-msse4.1" "-msse4a" "-msse4" "-mssse3" "-msse3" "-msse2" "-msse")
        endif()
    endif()

    include(CheckCCompilerFlags)
    select_c_compiler_flags(SIMD_FLAGS ${CANDIDATE_FLAGS})

    if(SIMD_FLAGS)
        set(SIMD_FLAGS ${SIMD_FLAGS} PARENT_SCOPE)
    else()
        unset(SIMD_FLAGS PARENT_SCOPE)
    endif()
endfunction()
