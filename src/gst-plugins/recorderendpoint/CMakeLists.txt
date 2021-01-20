cmake_minimum_required(VERSION 2.8)

set(KMS_RECORDERENDPOINT_SOURCES
  kmsbasemediamuxer.c
  kmsavmuxer.c
  kmsksrmuxer.c
  kmsrecorderendpoint.c
)

set(KMS_RECORDERENDPOINT_HEADERS
  kmsbasemediamuxer.h
  kmsavmuxer.h
  kmsksrmuxer.h
  kmsrecorderendpoint.h
)

add_library(recorderendpoint MODULE ${KMS_RECORDERENDPOINT_SOURCES} ${KMS_RECORDERENDPOINT_HEADERS})
if(SANITIZERS_ENABLED)
  add_sanitizers(recorderendpoint)
endif()

set_property (TARGET recorderendpoint
  PROPERTY INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_BINARY_DIR}/../../..
    ${gstreamer-${GST_VERSION}_INCLUDE_DIRS}
    ${KmsGstCommons_INCLUDE_DIRS}
)

target_link_libraries(recorderendpoint
  ${KmsGstCommons_LIBRARIES}
  ${gstreamer-${GST_VERSION}_LIBRARIES}
  ${gstreamer-base-${GST_VERSION}_LIBRARIES}
  ${gstreamer-app-${GST_VERSION}_LIBRARIES}
  ${gstreamer-pbutils-${GST_VERSION}_LIBRARIES}
)

install(
  TARGETS recorderendpoint
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_GST_PLUGINS_DIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
