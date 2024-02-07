# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/mihai/esp/v5.1.2/esp-idf/components/bootloader/subproject"
  "C:/Arhiva_ULBS/Proiecte/Anul_II/programare_2023-2024/familia_c/c/embedded/hello_world/build/bootloader"
  "C:/Arhiva_ULBS/Proiecte/Anul_II/programare_2023-2024/familia_c/c/embedded/hello_world/build/bootloader-prefix"
  "C:/Arhiva_ULBS/Proiecte/Anul_II/programare_2023-2024/familia_c/c/embedded/hello_world/build/bootloader-prefix/tmp"
  "C:/Arhiva_ULBS/Proiecte/Anul_II/programare_2023-2024/familia_c/c/embedded/hello_world/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Arhiva_ULBS/Proiecte/Anul_II/programare_2023-2024/familia_c/c/embedded/hello_world/build/bootloader-prefix/src"
  "C:/Arhiva_ULBS/Proiecte/Anul_II/programare_2023-2024/familia_c/c/embedded/hello_world/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Arhiva_ULBS/Proiecte/Anul_II/programare_2023-2024/familia_c/c/embedded/hello_world/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Arhiva_ULBS/Proiecte/Anul_II/programare_2023-2024/familia_c/c/embedded/hello_world/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
