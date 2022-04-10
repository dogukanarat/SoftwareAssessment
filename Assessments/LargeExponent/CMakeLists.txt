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

# set_target_properties(LargeExponent PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0")
# set_target_properties(LargeExponent PROPERTIES LINK_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g")

install(
    TARGETS LargeExponent
    EXPORT RocketLab-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/LargeExponent/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/LargeExponent
)