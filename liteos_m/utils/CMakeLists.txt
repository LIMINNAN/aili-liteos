sdk_generate_library()
sdk_library_add_sources(
    los_debug.c
    los_hook.c
    los_error.c
)

sdk_add_include_directories(
    .
    internal
)