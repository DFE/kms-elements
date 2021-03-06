# Disable error when functions are unused. This allows commenting out calls to
# `tcase_add_test()` to skip running certain tests during a debug session.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-error=unused-function")

set(KMS_TEST_UTILS_SOURCES
  kmstestutils.h kmstestutils.c
)

add_library(kmstestutils ${KMS_TEST_UTILS_SOURCES})
if(SANITIZERS_ENABLED)
  add_sanitizers(kmstestutils)
endif()

target_link_libraries(kmstestutils
  ${gstreamer-${GST_VERSION}_LIBRARIES}
  ${gstreamer-base-${GST_VERSION}_LIBRARIES}
  ${gstreamer-sdp-${GST_VERSION}_LIBRARIES}
  ${gstreamer-pbutils-${GST_VERSION}_LIBRARIES}
)
set_property(TARGET kmstestutils
  PROPERTY INCLUDE_DIRECTORIES
    ${gstreamer-${GST_VERSION}_INCLUDE_DIRS}
    ${gstreamer-video-${GST_VERSION}_INCLUDE_DIRS}
)

include(TestHelpers)
set(TEST_VARIABLES
  "GST_PLUGIN_PATH=$ENV{GST_PLUGIN_PATH}:${CMAKE_BINARY_DIR}"
  "CK_DEFAULT_TIMEOUT=50"
)
set(VALGRIND_TEST_VARIABLES
  "${TEST_VARIABLES}"
  "CK_DEFAULT_TIMEOUT=1000"
)
list(APPEND SUPPRESSIONS
  "${CMAKE_CURRENT_SOURCE_DIR}/valgrind.supp")

add_subdirectory(element)
