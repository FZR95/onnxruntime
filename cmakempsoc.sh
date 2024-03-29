cd buildmpsoc
cmake ../cmake \
  -Donnxruntime_GCC_STATIC_CPP_RUNTIME=ON \
  -DCMAKE_BUILD_TYPE=RelWithReleaseDebInfo \
  -Donnxruntime_BUILD_SHARED_LIB=ON \
  -Donnxruntime_BUILD_UNIT_TESTS=OFF \
  -Donnxruntime_ENABLE_CPUINFO=OFF \
  -DCMAKE_TOOLCHAIN_FILE=linux_mpsoc_crosscompile_toolchain.cmake
# make
# 如果CMake已经运行过，并且生成了构建文件，你可以直接编辑CMakeFiles/onnxruntime_providers.dir/flags.make（或类似的文件），找到-Werror选项，并将其删除或修改。
