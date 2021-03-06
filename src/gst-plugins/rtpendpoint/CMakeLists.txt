cmake_minimum_required(VERSION 2.8)

set(KMS_RTPENDPOINT_SOURCES
  kmsrtpbaseconnection.c
  kmsrtpconnection.c
  kmssrtpconnection.c
  kmsrtpsession.c
  kmssrtpsession.c
  kmsrtpendpoint.c
  kmssocketutils.c
  kmsrandom.c
)

set(KMS_RTPENDPOINT_HEADERS
  kmsrtpendpoint.h
  kmssocketutils.h
)

set(ENUM_HEADERS
  kmsrtpsdescryptosuite.h
)

list(APPEND KMS_RTPENDPOINT_HEADERS ${ENUM_HEADERS})
add_glib_enumtypes(KMS_RTPENDPOINT_SOURCES KMS_RTPENDPOINT_HEADERS kms-rtp-enumtypes KMS ${ENUM_HEADERS})

add_library(rtpendpoint MODULE ${KMS_RTPENDPOINT_SOURCES} ${KMS_RTPENDPOINT_HEADERS})
if(SANITIZERS_ENABLED)
  add_sanitizers(rtpendpoint)
endif()

add_dependencies(rtpendpoint rtcpdemux)

set_property(TARGET rtpendpoint
  PROPERTY INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/../../..
    ${KmsGstCommons_INCLUDE_DIRS}
    ${gstreamer-${GST_VERSION}_INCLUDE_DIRS}
)

if(MSYS)
  set(KMSRTPENDPOINT_LINK_OS_LIBRARIES gstsdp-1.0 kmssdpagent bcrypt)
endif()

target_link_libraries(rtpendpoint
  ${KmsGstCommons_LIBRARIES}
  ${gstreamer-${GST_VERSION}_LIBRARIES}
  ${gstreamer-base-${GST_VERSION}_LIBRARIES}
  ${gstreamer-sdp-${GST_VERSION}_LIBRARIES}
  ${gstreamer-pbutils-${GST_VERSION}_LIBRARIES}
  ${nice_LIBRARIES}
  ${KMSRTPENDPOINT_LINK_OS_LIBRARIES}
)

install(
  TARGETS rtpendpoint
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_GST_PLUGINS_DIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
