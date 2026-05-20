add_executable(minishell main.c)

target_link_libraries(minishell PRIVATE cliutil)