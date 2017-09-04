# Distributed under the OSI-approved MIT License.  See accompanying
# file LICENSE or https://github.com/Crascit/DownloadProject for details.

cmake_minimum_required(VERSION 2.8.2)

project(SFML-download NONE)

include(ExternalProject)
ExternalProject_Add(SFML-download
                    GIT_REPOSITORY;https://github.com/SFML/SFML;GIT_TAG;b7be4b2
                    SOURCE_DIR          "C:/Users/40168766/Desktop/Astral_Insanity-master/Astral_Insanity-master/Advanced-Games-Engineering/SFML-src"
                    BINARY_DIR          "C:/Users/40168766/Desktop/Astral_Insanity-master/Astral_Insanity-master/Advanced-Games-Engineering/SFML-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
)
