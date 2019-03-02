cmake_minimum_required(VERSION 2.8)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)


configure_file(kport/version.h.in ${PROJECT_BINARY_DIR}/kport/version.h)

FILE(GLOB KPT_HEADER kport/*)

set( KPT_HEADER
        ${KPT_HEADER}
        ${PROJECT_BINARY_DIR}/kport/version.h
)

install(KPT_HEADER include/kport)
