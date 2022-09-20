cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++17 -flto -fno-rtti -Wno-inline-new-delete -fno-exceptions -nostartfiles ") #-nostdlib ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--no-entry,--allow-undefined,--export=Ctor,--export=Dtor,--export=Method_0,--export=Method_1,--export=Method_2") #,--strip-all")

add_executable(get_pub_key_app app.cpp)
target_link_libraries(get_pub_key_app PRIVATE Beam::shader-lib)
copy_shader(get_pub_key_app)
