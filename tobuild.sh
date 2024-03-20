# cd onnxruntime/
# python3 -m pip install cmake
bash ./build.sh \
  --config RelWithDebInfo \
  --build_shared_lib \
  --parallel \
  --compile_no_warning_as_error \
  --skip_submodule_sync \
  --skip_tests \
  --use_fpga

  # --disable_ml_ops \
  # --enable_reduced_operator_type_support \
  # --skip_tests
# make install
# cmake --install .\build\Linux\RelWithDebInfo --config RelWithDebInfo
