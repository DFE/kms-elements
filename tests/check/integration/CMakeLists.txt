add_test_program (test_integration_playerendpoint playerendpoint.c)
add_dependencies(test_integration_playerendpoint kmstestutils kmsplugin)
target_include_directories(test_integration_playerendpoint PRIVATE
                           ${gstreamer-${GST_VERSION}_INCLUDE_DIRS}
                           ${gstreamer-check-${GST_VERSION}_INCLUDE_DIRS}
                           "${CMAKE_CURRENT_SOURCE_DIR}/../../../src")
target_link_libraries(test_integration_playerendpoint
                      ${gstreamer-${GST_VERSION}_LIBRARIES}
                      ${gstreamer-check-${GST_VERSION}_LIBRARIES}
                      kmstestutils)
