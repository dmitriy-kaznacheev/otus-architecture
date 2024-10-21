add_library(
  abstraction
  coord.cpp
  movement.cpp
  rotation.cpp
)

target_include_directories(
  abstraction
  PUBLIC 
  include
)

