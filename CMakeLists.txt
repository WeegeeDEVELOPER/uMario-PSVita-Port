## This file is a quick tutorial on writing CMakeLists for targeting the Vita
cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(uMario)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Super Mario Bros")
set(VITA_TITLEID  "WDEV75837")
set(VITA_VERSION  "01.00")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

enable_language(C ASM)

include_directories(
  ../common # This is for debugScreenPrintf(), you shouldn't need it in your projects
)

# ${CMAKE_CURRENT_BINARY_DIR} lets you use any library currently being built
link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(${PROJECT_NAME}
  uNext/AboutMenu.cpp
  uNext/Beetle.cpp
  uNext/Block.cpp
  uNext/BlockDebris.cpp
  uNext/Bowser.cpp
  uNext/Bubble.cpp
  uNext/BulletBill.cpp
  uNext/BulletBillSpawner.cpp
  uNext/CFG.cpp
  uNext/Cheep.cpp
  uNext/CheepSpawner.cpp
  uNext/Coin.cpp
  uNext/Console.cpp
  uNext/Core.cpp
  uNext/Event.cpp
  uNext/Fire.cpp
  uNext/Fireball.cpp
  uNext/Flag.cpp
  uNext/Flower.cpp
  uNext/Goombas.cpp
  uNext/Hammer.cpp
  uNext/HammerBro.cpp
  uNext/IMG.cpp
  uNext/Koppa.cpp
  uNext/Lakito.cpp
  uNext/LevelEditor.cpp
  uNext/LevelText.cpp
  uNext/LoadingMenu.cpp
  uNext/main.cpp
  uNext/MainMenu.cpp
  uNext/Map.cpp
  uNext/MapLevel.cpp
  uNext/Menu.cpp
  uNext/MenuManager.cpp
  uNext/MenuOption.cpp
  uNext/Minion.cpp
  uNext/Mushroom.cpp
  uNext/Music.cpp
  uNext/MusicManager.cpp
  uNext/OptionsMenu.cpp
  uNext/PauseMenu.cpp
  uNext/Pipe.cpp
  uNext/Plant.cpp
  uNext/Platform.cpp
  uNext/Player.cpp
  uNext/PlayerFireBall.cpp
  uNext/Points.cpp
  uNext/Spikey.cpp
  uNext/Spring.cpp
  uNext/Sprite.cpp
  uNext/Squid.cpp
  uNext/Star.cpp
  uNext/Text.cpp
  uNext/Texture.cpp
  uNext/Toad.cpp
  uNext/UpFire.cpp
  uNext/Vector2.cpp
  uNext/Vine.cpp
  #../common/debugScreen.c
)

# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(${PROJECT_NAME}

  SDL2_mixer
  SDL2_gfx
  SDL2_image
  SDL2_net
  SDL2_ttf
  SDL2main
  SDL2
  vorbisfile
  vorbis
  FLAC
  mikmod
  mpg123
  ogg
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceAppMgr_stub
  SceTouch_stub
  SceHid_stub
  SceMotion_stub
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
  FILE uNext/files uNext/files
)
