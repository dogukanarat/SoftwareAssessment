add_library(
    LargeExponent
)
target_sources(
    LargeExponent
    PRIVATE
        LargeExponent.cpp
)

target_include_directories(
    LargeExponent 
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS LargeExponent
    EXPORT RocketLab-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/LargeExponent/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/LargeExponent
)