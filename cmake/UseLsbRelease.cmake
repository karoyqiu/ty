# - UseLsbRelease: 使用 lsb_release 获取发行版名称和版本。

macro(_run_lsb _lsb _arg _var)
    execute_process(COMMAND "${_lsb}" "${_arg}" OUTPUT_VARIABLE _value OUTPUT_STRIP_TRAILING_WHITESPACE)
    set(${_var} ${_value} PARENT_SCOPE)
endmacro()

function(lsb_release)
    find_program(_lsb lsb_release)

    if(NOT _lsb)
        message(WARNING "lsb_release was not found.")
        return()
    endif()

    set(_ova ID DESCRIPTION RELEASE CODENAME)
    cmake_parse_arguments(LSB "" "${_ova}" "" ${ARGN})

    if(LSB_ID)
        _run_lsb(${_lsb} "-is" ${LSB_ID})
    endif()

    if(LSB_RELEASE)
        _run_lsb(${_lsb} "-rs" ${LSB_RELEASE})
    endif()

    if(LSB_DESCRIPTION)
        _run_lsb(${_lsb} "-ds" ${LSB_DESCRIPTION})
    endif()

    if(LSB_CODENAME)
        _run_lsb(${_lsb} "-cs" ${LSB_CODENAME})
    endif()
endfunction()
