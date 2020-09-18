add_library(
    quadratic
    quadratic.c
    utils.c
)

target_link_libraries(
    quadratic
    m
)

add_executable(
    app
    main.c
)

target_link_libraries(app quadratic)

add_executable(
    tests
    tests.c
)

target_link_libraries(tests quadratic)
