add_library(
    Conversion
)
target_sources(
    Conversion
    PRIVATE
    Conversion.c
    LookUpTable.c
)

target_include_directories(
    Conversion 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS Conversion
    EXPORT RocketLab-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/Conversion/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Convertion
)