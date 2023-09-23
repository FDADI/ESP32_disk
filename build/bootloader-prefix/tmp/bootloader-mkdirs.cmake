# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/ESP32_IDF4.4.4/Espressif/frameworks/esp-idf-v4.4.4/components/bootloader/subproject"
  "E:/ESP32_vscode_test/ESP32_noopsyche_disk/build/bootloader"
  "E:/ESP32_vscode_test/ESP32_noopsyche_disk/build/bootloader-prefix"
  "E:/ESP32_vscode_test/ESP32_noopsyche_disk/build/bootloader-prefix/tmp"
  "E:/ESP32_vscode_test/ESP32_noopsyche_disk/build/bootloader-prefix/src/bootloader-stamp"
  "E:/ESP32_vscode_test/ESP32_noopsyche_disk/build/bootloader-prefix/src"
  "E:/ESP32_vscode_test/ESP32_noopsyche_disk/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/ESP32_vscode_test/ESP32_noopsyche_disk/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
