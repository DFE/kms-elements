set(RTCPDEMUX_SOURCES
  rtcpdemux.c
  kmsrtcpdemux.c
)

set(RTCPDEMUX_HEADERS
  kmsrtcpdemux.h
)

include(GLibHelpers)

add_glib_marshal(RTCPDEMUX_SOURCES RTCPDEMUX_HEADERS kms-marshal __kms_marshal)

add_library(rtcpdemux MODULE ${RTCPDEMUX_SOURCES} ${RTCPDEMUX_HEADERS})
if(SANITIZERS_ENABLED)
  add_sanitizers(rtcpdemux)
endif()

target_link_libraries(rtcpdemux
  ${gstreamer-${GST_VERSION}_LIBRARIES}
  ${gstreamer-base-${GST_VERSION}_LIBRARIES}
  ${gstreamer-rtp-${GST_VERSION}_LIBRARIES}
)

set_property (TARGET rtcpdemux
  PROPERTY INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_BINARY_DIR}/../../..
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${gstreamer-${GST_VERSION}_INCLUDE_DIRS}
    ${gstreamer-base-${GST_VERSION}_INCLUDE_DIRS}
    ${gstreamer-rtp-${GST_VERSION}_INCLUDE_DIRS}
)

install(
  TARGETS rtcpdemux
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_GST_PLUGINS_DIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
