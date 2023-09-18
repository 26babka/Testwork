set(target_name curves)
set(VECTOR_HEADER "${CMAKE_SOURCE_DIR}/include/curves/curves/vector3d.h")
set(CURVE_BASE_HEADER "${CMAKE_SOURCE_DIR}/include/curves/curves/curves_base.h")
set(CIRCLE_HEADER "${CMAKE_SOURCE_DIR}/include/curves/curves/circle.h")
set(ELLIPSE_HEADER "${CMAKE_SOURCE_DIR}/include/curves/curves/ellipse.h")
set(HELIX_HEADER "${CMAKE_SOURCE_DIR}/include/curves/curves/helix.h")
set(CURVES_HEADER "${CMAKE_SOURCE_DIR}/include/curves/curves/curves.h")


add_library(vector3d STATIC
  curves/vector3d.cpp
  ${VECTOR_HEADER})

add_library(curves_base STATIC
  ${CURVE_BASE_HEADER})

add_library(circle STATIC
  curves/circle.cpp
  ${CIRCLE_HEADER})

add_library(ellipse STATIC
  curves/ellipse.cpp
  ${ELLIPSE_HEADER})

add_library(helix STATIC
  curves/helix.cpp
  ${HELIX_HEADER})

add_library(${target_name} SHARED
  ${CURVES_HEADER})

target_link_libraries(curves_base PRIVATE vector3d)
target_link_libraries(circle PRIVATE curves_base)
target_link_libraries(ellipse PRIVATE curves_base)
target_link_libraries(helix PRIVATE curves_base m)

target_link_libraries(${target_name} PUBLIC circle ellipse helix vector3d curves_base)

include(CompileOptions)
set_compile_options(vector3d)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)


target_include_directories(
  ${target_name}
  INTERFACE
    ${CMAKE_SOURCE_DIR}/include/curves
)