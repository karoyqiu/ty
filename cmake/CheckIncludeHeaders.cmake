#.rst
# CheckIncludeHeaders
# -------------------
#
# 检查指定的头文件是否存在。
#
# CHECK_INCLUDE_HEADERS(<headers>...)
#
include(CheckIncludeFile)
include(VariableNameForSymbol)

function(CHECK_INCLUDE_HEADERS)
    foreach(_hdr ${ARGV})
        VARNAME_FOR_SYMBOL(${_hdr} _var)
        CHECK_INCLUDE_FILE(${_hdr} ${_var})
    endforeach()
endfunction()
