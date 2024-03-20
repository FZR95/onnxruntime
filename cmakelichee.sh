# append cmake/CMakeLists.txt row:520 :
# set(onnxruntime_LINK_LIBATOMIC true)
# mkdir buildlichee
cd buildlichee
cmake ../cmake \
  -Donnxruntime_GCC_STATIC_CPP_RUNTIME=ON \
  -DCMAKE_BUILD_TYPE=Release \
  -Donnxruntime_BUILD_UNIT_TESTS=OFF \
  -Donnxruntime_ENABLE_CPUINFO=OFF \
  -DCMAKE_TOOLCHAIN_FILE=linux_lichee_crosscompile_toolchain.cmake
# remove CMakeFiles/*provider.dir/flags.make 找到-Werror选项，并将其删除
# remove CMakeFiles/*optimizer.dir/flags.make 找到-Werror选项，并将其删除
# make
