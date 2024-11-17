sdk_generate_library()

file(GLOB_RECURSE kernel_source
    "src/*.c"
)

# 添加源文件到目标
sdk_library_add_sources(
    ${kernel_source}
)
sdk_add_include_directories(
    include
)