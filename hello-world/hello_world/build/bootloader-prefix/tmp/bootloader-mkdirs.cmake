# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/trngzng/esp/esp-idf/components/bootloader/subproject"
  "/home/trngzng/esp32-training/hello-world/hello_world/build/bootloader"
  "/home/trngzng/esp32-training/hello-world/hello_world/build/bootloader-prefix"
  "/home/trngzng/esp32-training/hello-world/hello_world/build/bootloader-prefix/tmp"
  "/home/trngzng/esp32-training/hello-world/hello_world/build/bootloader-prefix/src/bootloader-stamp"
  "/home/trngzng/esp32-training/hello-world/hello_world/build/bootloader-prefix/src"
  "/home/trngzng/esp32-training/hello-world/hello_world/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/trngzng/esp32-training/hello-world/hello_world/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/trngzng/esp32-training/hello-world/hello_world/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
