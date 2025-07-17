cmake_minimum_required(VERSION 3.5)

project(cdplayer C)

add_executable(cdplayer src/main.c)

# 依需求加入 include/lib 路徑，例如使用 libcdio 或 ALSA

target_link_libraries(cdplayer cdio)

# end of file
