include (TestHelpers)

add_subdirectory(server)

if (${gstreamer-check-${GST_VERSION}_FOUND})
  add_subdirectory(check)
endif ()

