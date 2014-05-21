set(SOURCE_FILES QXrdFile.cpp)
set(HEADER_FILES QXrdFile.h
                 QXrdFile_p.h)

add_library(QXrdFileTools SHARED ${SOURCE_FILES} ${HEADER_FILES})
set_target_properties(QXrdFileTools PROPERTIES VERSION ${VERSION})
target_link_libraries(QXrdFileTools ${XROOTD_LIBRARIES} ${QT_LIBRARIES})
                 
