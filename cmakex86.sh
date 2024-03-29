cd buildx86
cmake ../cmake \
  -Donnxruntime_GCC_STATIC_CPP_RUNTIME=ON \
  -DCMAKE_BUILD_TYPE=RelWithReleaseDebInfo \
  -Donnxruntime_BUILD_SHARED_LIB=ON \
  -Donnxruntime_BUILD_UNIT_TESTS=OFF \
  -Donnxruntime_ENABLE_CPUINFO=OFF
