add_test_program (test_memory_playerendpoint playerendpoint.c)
add_dependencies(test_memory_playerendpoint kmsplugin)
target_include_directories(test_memory_playerendpoint PRIVATE
                           ${gstreamer-${GST_VERSION}_INCLUDE_DIRS}
                           ${gstreamer-check-${GST_VERSION}_INCLUDE_DIRS}
                           "${CMAKE_CURRENT_SOURCE_DIR}/../../../src")
target_link_libraries(test_memory_playerendpoint
                      ${gstreamer-${GST_VERSION}_LIBRARIES}
                      ${gstreamer-check-${GST_VERSION}_LIBRARIES})

add_test_program (test_memory_recorderendpoint recorderendpoint.c)
add_dependencies(test_memory_recorderendpoint kmsplugin)
target_include_directories(test_memory_recorderendpoint PRIVATE
                           ${gstreamer-${GST_VERSION}_INCLUDE_DIRS}
                           ${gstreamer-check-${GST_VERSION}_INCLUDE_DIRS}
                           "${CMAKE_CURRENT_SOURCE_DIR}/../../../src")
target_link_libraries(test_memory_recorderendpoint
                      ${gstreamer-${GST_VERSION}_LIBRARIES}
                      ${gstreamer-check-${GST_VERSION}_LIBRARIES})

add_test_program (test_memory_webrtcendpoint webrtcendpoint.c)
add_dependencies(test_memory_webrtcendpoint kmsplugin)
target_include_directories(test_memory_webrtcendpoint PRIVATE
                           ${gstreamer-${GST_VERSION}_INCLUDE_DIRS}
                           ${gstreamer-check-${GST_VERSION}_INCLUDE_DIRS}
                           ${gstreamer-${GST_VERSION}_SDP_SOURCE_DIRS})
target_link_libraries(test_memory_webrtcendpoint
                      ${gstreamer-${GST_VERSION}_LIBRARIES}
                      ${gstreamer-check-${GST_VERSION}_LIBRARIES}
                      ${gstreamer-${GST_VERSION}_SDP_LIBRARIES})
