#
# cppan
#

################################################################################
#
# header
#
################################################################################

include(/home/yong/.cppan/storage/etc/static/header.cmake)

cppan_debug_message("Entering file: ${CMAKE_CURRENT_LIST_FILE}")

################################################################################

#
# cppan
# meta config file
#

set(CPPAN_DEBUG_STACK_SPACE "" CACHE STRING "" FORCE)

################################################################################
#
# cmake setup
#
################################################################################

cppan_debug_message("Section: cmake setup")

cmake_minimum_required(VERSION 3.2.0)

################################################################################
#
# macros & functions
#
################################################################################

cppan_debug_message("Section: macros & functions")

include(/home/yong/.cppan/storage/etc/static/functions.cmake)
set(SDIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BDIR ${CMAKE_CURRENT_BINARY_DIR})

################################################################################
#
# variables
#
################################################################################

cppan_debug_message("Section: variables")

set(CPPAN_BUILD 1 CACHE STRING "CPPAN is turned on")

################################################################################
#
# storage dirs
#
################################################################################

cppan_debug_message("Section: storage dirs")

set(STORAGE_DIR "/home/yong/.cppan/storage")
set(STORAGE_DIR_ETC "/home/yong/.cppan/storage/etc")
set(STORAGE_DIR_ETC_STATIC "/home/yong/.cppan/storage/etc/static")
set(STORAGE_DIR_USR "/home/yong/.cppan/storage/usr")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(${CMAKE_CXX_COMPILER_ID} 1)

if (NOT DEFINED CPPAN_USE_CACHE)
    set(CPPAN_USE_CACHE 1)
endif()

if (NOT DEFINED CPPAN_SHOW_IDE_PROJECTS)
    set(CPPAN_SHOW_IDE_PROJECTS 0)
endif()

if (NOT DEFINED CPPAN_BUILD_EXECUTABLES_WITH_SAME_CONFIGURATION)
    set(CPPAN_BUILD_EXECUTABLES_WITH_SAME_CONFIGURATION 0)
endif()

if (NOT DEFINED CPPAN_BUILD_VERBOSE)
    set(CPPAN_BUILD_VERBOSE 1)
endif()

if (NOT DEFINED CPPAN_BUILD_WARNING_LEVEL)
    set(CPPAN_BUILD_WARNING_LEVEL 0)
endif()

get_configuration_variables()

include(helpers.cmake)

################################################################################
#
# direct dependencies
#
################################################################################

cppan_debug_message("Section: direct dependencies")

set(pvt_cppan_demo_danbloomberg_leptonica_DIR /home/yong/.cppan/storage/src/2a/b4/6dbf)
set(pvt_cppan_demo_google_tesseract_libtesseract_DIR /home/yong/.cppan/storage/src/42/e3/b04b)

################################################################################
#
# include dependencies (they should be placed at the end)
#
################################################################################

cppan_debug_message("Section: include dependencies (they should be placed at the end)")

if (CPPAN_USE_CACHE)
    # pvt.cppan.demo.danbloomberg.leptonica-1.74.4
    cppan_include("/home/yong/.cppan/storage/obj/2a/b4/6dbf/generate.cmake")
    # pvt.cppan.demo.google.tesseract.libtesseract-3.5.1
    cppan_include("/home/yong/.cppan/storage/obj/42/e3/b04b/generate.cmake")
else()
    # pvt.cppan.demo.danbloomberg.leptonica-1.74.4
    cppan_include("/home/yong/.cppan/storage/src/2a/b4/6dbf/include.cmake")
    # pvt.cppan.demo.google.tesseract.libtesseract-3.5.1
    cppan_include("/home/yong/.cppan/storage/src/42/e3/b04b/include.cmake")
endif()

################################################################################
#
# main library
#
################################################################################

cppan_debug_message("Section: main library")

add_library                   (__cppan INTERFACE)
target_link_libraries         (__cppan
    INTERFACE pvt.cppan.demo.danbloomberg.leptonica-1.74.4
    INTERFACE pvt.cppan.demo.google.tesseract.libtesseract-3.5.1
)
add_dependencies(__cppan cppan-d-c)

export(TARGETS __cppan FILE ${CMAKE_BINARY_DIR}/exports/cppan.cmake)

################################################################################
#
# build dependencies
#
################################################################################

cppan_debug_message("Section: build dependencies")

if (CPPAN_USE_CACHE)
    get_configuration_with_generator(config)
    if (CPPAN_BUILD_EXECUTABLES_WITH_SAME_CONFIG)
        get_configuration_with_generator(config_exe)
    else()
        get_configuration_exe(config_exe)
    endif()
    
    string(TOUPPER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_UPPER)
    
    set(this cppan-d-b)
    
    get_target_property(implib_pvt_cppan_demo_danbloomberg_leptonica_1_74_4 pvt.cppan.demo.danbloomberg.leptonica-1.74.4 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_gif_5_1_4 pvt.cppan.demo.gif-5.1.4 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_google_tesseract_libtesseract_3_5_1 pvt.cppan.demo.google.tesseract.libtesseract-3.5.1 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_jpeg_9_2_0 pvt.cppan.demo.jpeg-9.2.0 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_madler_zlib_1_2_11 pvt.cppan.demo.madler.zlib-1.2.11 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_mgk25_jbig_ar_2_1_0 pvt.cppan.demo.mgk25.jbig.ar-2.1.0 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_mgk25_jbig_jbig_2_1_0 pvt.cppan.demo.mgk25.jbig.jbig-2.1.0 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_openjpeg_openjp2_2_1_2 pvt.cppan.demo.openjpeg.openjp2-2.1.2 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_png_1_6_28 pvt.cppan.demo.png-1.6.28 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_tiff_4_0_7 pvt.cppan.demo.tiff-4.0.7 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_webp_0_6_0 pvt.cppan.demo.webp-0.6.0 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    get_target_property(implib_pvt_cppan_demo_xz_utils_lzma_5_2_3 pvt.cppan.demo.xz_utils.lzma-5.2.3 IMPORTED_LOCATION_${CMAKE_BUILD_TYPE_UPPER})
    
    set(rest "-DCPPAN_BUILD_EXECUTABLES_WITH_SAME_CONFIGURATION=${CPPAN_BUILD_EXECUTABLES_WITH_SAME_CONFIGURATION} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCPPAN_BUILD_VERBOSE=${CPPAN_BUILD_VERBOSE} -DCPPAN_BUILD_WARNING_LEVEL=${CPPAN_BUILD_WARNING_LEVEL} -DCPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT=${CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT} -DN_CORES=${N_CORES} -DXCODE=${XCODE} -DNINJA=${NINJA} -DVISUAL_STUDIO=${VISUAL_STUDIO} ")
    
    set(ext sh)
    if (WIN32)
        set(ext bat)
    endif()
    
    set(file ${BDIR}/cppan_build_deps_$<CONFIG>.${ext})
    file(GENERATE OUTPUT ${file} CONTENT "
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.danbloomberg.leptonica-1.74.4> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/2a/b4/6dbf/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/2a/b4/6dbf/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.gif-5.1.4> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/d6/de/c13d/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/d6/de/c13d/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.google.tesseract.libtesseract-3.5.1> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/42/e3/b04b/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/42/e3/b04b/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.jpeg-9.2.0> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/97/2a/155a/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/97/2a/155a/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.madler.zlib-1.2.11> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/d4/78/06ca/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/d4/78/06ca/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.mgk25.jbig.ar-2.1.0> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/79/97/1d02/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/79/97/1d02/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.mgk25.jbig.jbig-2.1.0> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/95/15/a371/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/95/15/a371/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.openjpeg.openjp2-2.1.2> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/7a/de/8a22/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/7a/de/8a22/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.png-1.6.28> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/6a/36/d3a9/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/6a/36/d3a9/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.tiff-4.0.7> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/2f/16/8f89/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/2f/16/8f89/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.webp-0.6.0> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/cf/01/8747/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/cf/01/8747/build.cmake
        \"${CMAKE_COMMAND}\" -DTARGET_FILE=$<TARGET_FILE:pvt.cppan.demo.xz_utils.lzma-5.2.3> -DCONFIG=$<CONFIG> -DBUILD_DIR=/home/yong/.cppan/storage/obj/a7/68/fa0b/build/${config} -DEXECUTABLE=0 -DMULTICORE=1 ${rest} -P /home/yong/.cppan/storage/obj/a7/68/fa0b/build.cmake
    ")
    
    
    if (UNIX)
        set(file chmod u+x ${file} COMMAND ${file})
    endif()
    
    add_custom_target(${this}-d
        COMMAND ${file}
        BYPRODUCTS
            ${implib_pvt_cppan_demo_danbloomberg_leptonica_1_74_4}
            ${implib_pvt_cppan_demo_gif_5_1_4}
            ${implib_pvt_cppan_demo_google_tesseract_libtesseract_3_5_1}
            ${implib_pvt_cppan_demo_jpeg_9_2_0}
            ${implib_pvt_cppan_demo_madler_zlib_1_2_11}
            ${implib_pvt_cppan_demo_mgk25_jbig_ar_2_1_0}
            ${implib_pvt_cppan_demo_mgk25_jbig_jbig_2_1_0}
            ${implib_pvt_cppan_demo_openjpeg_openjp2_2_1_2}
            ${implib_pvt_cppan_demo_png_1_6_28}
            ${implib_pvt_cppan_demo_tiff_4_0_7}
            ${implib_pvt_cppan_demo_webp_0_6_0}
            ${implib_pvt_cppan_demo_xz_utils_lzma_5_2_3}
    )
    add_dependencies(${this} ${this}-d)
    set_target_properties(${this}-d PROPERTIES FOLDER "CPPAN Targets/Service")
    
    add_dependencies(pvt.cppan.demo.danbloomberg.leptonica-1.74 ${this})
    add_dependencies(pvt.cppan.demo.danbloomberg.leptonica-1 ${this})
    add_dependencies(pvt.cppan.demo.danbloomberg.leptonica ${this})
    
    add_dependencies(pvt::cppan::demo::danbloomberg::leptonica-1.74 ${this})
    add_dependencies(pvt::cppan::demo::danbloomberg::leptonica-1 ${this})
    add_dependencies(pvt::cppan::demo::danbloomberg::leptonica ${this})
    
    add_dependencies(pvt.cppan.demo.gif-5.1 ${this})
    add_dependencies(pvt.cppan.demo.gif-5 ${this})
    add_dependencies(pvt.cppan.demo.gif ${this})
    
    add_dependencies(pvt::cppan::demo::gif-5.1 ${this})
    add_dependencies(pvt::cppan::demo::gif-5 ${this})
    add_dependencies(pvt::cppan::demo::gif ${this})
    
    add_dependencies(pvt.cppan.demo.google.tesseract.libtesseract-3.5 ${this})
    add_dependencies(pvt.cppan.demo.google.tesseract.libtesseract-3 ${this})
    add_dependencies(pvt.cppan.demo.google.tesseract.libtesseract ${this})
    
    add_dependencies(pvt::cppan::demo::google::tesseract::libtesseract-3.5 ${this})
    add_dependencies(pvt::cppan::demo::google::tesseract::libtesseract-3 ${this})
    add_dependencies(pvt::cppan::demo::google::tesseract::libtesseract ${this})
    
    add_dependencies(pvt.cppan.demo.jpeg-9.2 ${this})
    add_dependencies(pvt.cppan.demo.jpeg-9 ${this})
    add_dependencies(pvt.cppan.demo.jpeg ${this})
    
    add_dependencies(pvt::cppan::demo::jpeg-9.2 ${this})
    add_dependencies(pvt::cppan::demo::jpeg-9 ${this})
    add_dependencies(pvt::cppan::demo::jpeg ${this})
    
    add_dependencies(pvt.cppan.demo.madler.zlib-1.2 ${this})
    add_dependencies(pvt.cppan.demo.madler.zlib-1 ${this})
    add_dependencies(pvt.cppan.demo.madler.zlib ${this})
    
    add_dependencies(pvt::cppan::demo::madler::zlib-1.2 ${this})
    add_dependencies(pvt::cppan::demo::madler::zlib-1 ${this})
    add_dependencies(pvt::cppan::demo::madler::zlib ${this})
    
    add_dependencies(pvt.cppan.demo.mgk25.jbig.ar-2.1 ${this})
    add_dependencies(pvt.cppan.demo.mgk25.jbig.ar-2 ${this})
    add_dependencies(pvt.cppan.demo.mgk25.jbig.ar ${this})
    
    add_dependencies(pvt::cppan::demo::mgk25::jbig::ar-2.1 ${this})
    add_dependencies(pvt::cppan::demo::mgk25::jbig::ar-2 ${this})
    add_dependencies(pvt::cppan::demo::mgk25::jbig::ar ${this})
    
    add_dependencies(pvt.cppan.demo.mgk25.jbig.jbig-2.1 ${this})
    add_dependencies(pvt.cppan.demo.mgk25.jbig.jbig-2 ${this})
    add_dependencies(pvt.cppan.demo.mgk25.jbig.jbig ${this})
    
    add_dependencies(pvt::cppan::demo::mgk25::jbig::jbig-2.1 ${this})
    add_dependencies(pvt::cppan::demo::mgk25::jbig::jbig-2 ${this})
    add_dependencies(pvt::cppan::demo::mgk25::jbig::jbig ${this})
    
    add_dependencies(pvt.cppan.demo.openjpeg.openjp2-2.1 ${this})
    add_dependencies(pvt.cppan.demo.openjpeg.openjp2-2 ${this})
    add_dependencies(pvt.cppan.demo.openjpeg.openjp2 ${this})
    
    add_dependencies(pvt::cppan::demo::openjpeg::openjp2-2.1 ${this})
    add_dependencies(pvt::cppan::demo::openjpeg::openjp2-2 ${this})
    add_dependencies(pvt::cppan::demo::openjpeg::openjp2 ${this})
    
    add_dependencies(pvt.cppan.demo.png-1.6 ${this})
    add_dependencies(pvt.cppan.demo.png-1 ${this})
    add_dependencies(pvt.cppan.demo.png ${this})
    
    add_dependencies(pvt::cppan::demo::png-1.6 ${this})
    add_dependencies(pvt::cppan::demo::png-1 ${this})
    add_dependencies(pvt::cppan::demo::png ${this})
    
    add_dependencies(pvt.cppan.demo.tiff-4.0 ${this})
    add_dependencies(pvt.cppan.demo.tiff-4 ${this})
    add_dependencies(pvt.cppan.demo.tiff ${this})
    
    add_dependencies(pvt::cppan::demo::tiff-4.0 ${this})
    add_dependencies(pvt::cppan::demo::tiff-4 ${this})
    add_dependencies(pvt::cppan::demo::tiff ${this})
    
    add_dependencies(pvt.cppan.demo.webp-0.6 ${this})
    add_dependencies(pvt.cppan.demo.webp-0 ${this})
    add_dependencies(pvt.cppan.demo.webp ${this})
    
    add_dependencies(pvt::cppan::demo::webp-0.6 ${this})
    add_dependencies(pvt::cppan::demo::webp-0 ${this})
    add_dependencies(pvt::cppan::demo::webp ${this})
    
    add_dependencies(pvt.cppan.demo.xz_utils.lzma-5.2 ${this})
    add_dependencies(pvt.cppan.demo.xz_utils.lzma-5 ${this})
    add_dependencies(pvt.cppan.demo.xz_utils.lzma ${this})
    
    add_dependencies(pvt::cppan::demo::xz_utils::lzma-5.2 ${this})
    add_dependencies(pvt::cppan::demo::xz_utils::lzma-5 ${this})
    add_dependencies(pvt::cppan::demo::xz_utils::lzma ${this})
    
endif()

################################################################################
#
# copy dependencies
#
################################################################################

cppan_debug_message("Section: copy dependencies")

if (CPPAN_USE_CACHE)
    set(output_dir ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    if (VISUAL_STUDIO OR XCODE)
        set(output_dir ${output_dir}/$<CONFIG>)
    endif()
    if (CPPAN_BUILD_OUTPUT_DIR)
        set(output_dir ${CPPAN_BUILD_OUTPUT_DIR})
    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.danbloomberg.leptonica-1.74.4
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.danbloomberg.leptonica-1.74.4")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.danbloomberg.leptonica-1.74.4 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.danbloomberg.leptonica-1.74.4> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.danbloomberg.leptonica-1.74.4>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.gif-5.1.4
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.gif-5.1.4")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.gif-5.1.4 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.gif-5.1.4> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.gif-5.1.4>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.google.tesseract.libtesseract-3.5.1
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.google.tesseract.libtesseract-3.5.1")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.google.tesseract.libtesseract-3.5.1 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.google.tesseract.libtesseract-3.5.1> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.google.tesseract.libtesseract-3.5.1>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.jpeg-9.2.0
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.jpeg-9.2.0")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.jpeg-9.2.0 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.jpeg-9.2.0> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.jpeg-9.2.0>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.madler.zlib-1.2.11
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.madler.zlib-1.2.11")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.madler.zlib-1.2.11 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.madler.zlib-1.2.11> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.madler.zlib-1.2.11>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.mgk25.jbig.ar-2.1.0
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.mgk25.jbig.ar-2.1.0")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.mgk25.jbig.ar-2.1.0 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.mgk25.jbig.ar-2.1.0> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.mgk25.jbig.ar-2.1.0>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.mgk25.jbig.jbig-2.1.0
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.mgk25.jbig.jbig-2.1.0")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.mgk25.jbig.jbig-2.1.0 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.mgk25.jbig.jbig-2.1.0> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.mgk25.jbig.jbig-2.1.0>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.openjpeg.openjp2-2.1.2
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.openjpeg.openjp2-2.1.2")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.openjpeg.openjp2-2.1.2 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.openjpeg.openjp2-2.1.2> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.openjpeg.openjp2-2.1.2>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.png-1.6.28
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.png-1.6.28")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.png-1.6.28 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.png-1.6.28> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.png-1.6.28>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.tiff-4.0.7
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.tiff-4.0.7")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.tiff-4.0.7 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.tiff-4.0.7> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.tiff-4.0.7>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.webp-0.6.0
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.webp-0.6.0")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.webp-0.6.0 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.webp-0.6.0> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.webp-0.6.0>
        )

    endif()

    ################################################################################
    #
    # Copy pvt.cppan.demo.xz_utils.lzma-5.2.3
    #
    ################################################################################

    cppan_debug_message("Section: Copy pvt.cppan.demo.xz_utils.lzma-5.2.3")

    set(copy 1)
    get_target_property(type pvt.cppan.demo.xz_utils.lzma-5.2.3 TYPE)
    if ("${type}" STREQUAL STATIC_LIBRARY)
        set(copy 0)
    endif()

    if (CPPAN_COPY_ALL_LIBRARIES_TO_OUTPUT)
        set(copy 1)
    endif()

    if (copy)
        add_custom_command(TARGET cppan-d-c POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:pvt.cppan.demo.xz_utils.lzma-5.2.3> ${output_dir}//$<TARGET_FILE_NAME:pvt.cppan.demo.xz_utils.lzma-5.2.3>
        )

    endif()

endif()

################################################################################
#
# local project groups
#
################################################################################

cppan_debug_message("Section: local project groups")

if (CPPAN_HIDE_LOCAL_DEPENDENCIES)
endif()

################################################################################
#
# footer
#
################################################################################

cppan_debug_message("Leaving file: ${CMAKE_CURRENT_LIST_FILE}")

string(LENGTH "${CPPAN_DEBUG_STACK_SPACE}" len)
math(EXPR len "${len}-4")
if (NOT ${len} LESS 0)
    string(SUBSTRING "${CPPAN_DEBUG_STACK_SPACE}" 0 ${len} CPPAN_DEBUG_STACK_SPACE)
else()
    set(CPPAN_DEBUG_STACK_SPACE "")
endif()
set(CPPAN_DEBUG_STACK_SPACE "${CPPAN_DEBUG_STACK_SPACE}" CACHE STRING "" FORCE)

################################################################################

