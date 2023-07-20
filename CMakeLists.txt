cmake_minimum_required(VERSION 3.24)
project(project_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(project_4 main.cpp Album.cpp Track.cpp Albums.cpp Albums.hpp Tracks.cpp Tracks.hpp Artists.hpp Artists.cpp Artist.cpp JSONDataObject.cpp JSONDataObject.hpp JSONArray.cpp JSONArray.hpp Pair.cpp Pair.hpp Token.cpp Token.hpp Tokenizer.cpp Tokenizer.hpp Album_images.cpp Album_images.hpp Album_image.cpp Album_image.hpp Artist_image.cpp Artist_image.hpp Artist_images.cpp Artist_images.hpp)
