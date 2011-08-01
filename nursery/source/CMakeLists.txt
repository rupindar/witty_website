SET(WT_PROJECT_SOURCE test.C )

SET(WT_PROJECT_TARGET hello.wt)

ADD_EXECUTABLE(hello.wt test.C)

TARGET_LINK_LIBRARIES(hello.wt wthttp wt)

INCLUDE_DIRECTORIES(/usr/include)

