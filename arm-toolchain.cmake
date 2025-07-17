# arm-toolchain.cmake
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_C_COMPILER	/home/user/WorkArea/buildroot_2025.04/9x60_eb/buildroot-mchp/output/host/bin/arm-buildroot-linux-gnueabi-gcc)
SET(CMAKE_CXX_COMPILER	/home/user/WorkArea/buildroot_2025.04/9x60_eb/buildroot-mchp/output/host/bin/arm-buildroot-linux-gnueabi-g++)

set(CMAKE_FIND_ROOT_PATH  /home/user/WorkArea/buildroot_2025.04/9x60_eb/buildroot-mchp/output/host/bin/arm-buildroot-linux-gnueabi/sysroot)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
