OBJS = main.cpp game.cpp utilities/*.cpp

OBJ_NAME = main

ASSETS = assets 
RAYLIB_DIR = ~/raylib/src

DESKTOP_BUILD_FOLDER = ../builds/desktop

WEB_BUILD_FOLDER = ../builds/web

build_desktop:
	gcc $(OBJS) -std=c++11 -lstdc++ -lraylib -lGL -lm -lpthread -ldl -lrt -o $(DESKTOP_BUILD_FOLDER)/$(OBJ_NAME)

run_desktop:
	./$(DESKTOP_BUILD_FOLDER)/$(OBJ_NAME)

run_no_music:
	./$(DESKTOP_BUILD_FOLDER)/$(OBJ_NAME) nomusic

build_web:
	emcc -o $(WEB_BUILD_FOLDER)/index.html $(OBJS) -Wall -std=c++11 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os -I. -I $(RAYLIB_DIR) -I $(RAYLIB_DIR)/external -L. -L $(RAYLIB_DIR) --preload-file $(ASSETS) -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --shell-file $(RAYLIB_DIR)/minshell.html $(RAYLIB_DIR)/libraylib.web.a -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]' -s EXPORTED_RUNTIME_METHODS=ccall
	zip ./builds/web.zip $(WEB_BUILD_FOLDER)/*