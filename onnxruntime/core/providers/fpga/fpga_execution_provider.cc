// Copyright (c) Microsoft Corporation. All rights reserved.
// Copyright (c) 2019-2020, NXP Semiconductor, Inc. All rights reserved.
// Licensed under the MIT License.

#include "fpga_execution_provider.h"
#include "core/framework/allocator.h"
#include "core/framework/op_kernel.h"
#include "core/framework/kernel_registry.h"
#include "core/framework/compute_capability.h"
#include "contrib_ops/cpu/cpu_contrib_kernels.h"
#include "fpga_fwd.h"

namespace onnxruntime {

constexpr const char* FPGA = "FPGA";

namespace fpga {

// Forward declarations of op kernels
class ONNX_OPERATOR_KERNEL_CLASS_NAME(kFPGAExecutionProvider, kOnnxDomain, 1, Conv);

class ONNX_OPERATOR_TYPED_KERNEL_CLASS_NAME(kFPGAExecutionProvider, kMSDomain, 1, float, FusedConv);

Status RegisterFPGAKernels(KernelRegistry& kernel_registry) {
  static const BuildKernelCreateInfoFn function_table[] = {
      // BuildKernelCreateInfo<void>,  //default entry to avoid the list become empty after ops-reducing
      BuildKernelCreateInfo<ONNX_OPERATOR_KERNEL_CLASS_NAME(kFPGAExecutionProvider, kOnnxDomain, 1, Conv)>,

      BuildKernelCreateInfo<ONNX_OPERATOR_TYPED_KERNEL_CLASS_NAME(kFPGAExecutionProvider, kMSDomain, 1, float, FusedConv)>,
  };

  for (auto& function_table_entry : function_table) {
    KernelCreateInfo info = function_table_entry();
    if (info.kernel_def != nullptr) {  // filter disabled entries where type is void
      ORT_RETURN_IF_ERROR(kernel_registry.Register(std::move(info)));
    }
  }

  return Status::OK();
}

std::shared_ptr<KernelRegistry> GetFPGAKernelRegistry() {
  std::shared_ptr<KernelRegistry> kernel_registry = std::make_shared<KernelRegistry>();
  ORT_THROW_IF_ERROR(RegisterFPGAKernels(*kernel_registry));
  return kernel_registry;
}

}  // namespace fpga

FPGAExecutionProvider::FPGAExecutionProvider(const FPGAExecutionProviderInfo&)
    : IExecutionProvider{onnxruntime::kFPGAExecutionProvider} {}

FPGAExecutionProvider::~FPGAExecutionProvider() {}

std::shared_ptr<KernelRegistry> FPGAExecutionProvider::GetKernelRegistry() const {
  static std::shared_ptr<KernelRegistry> kernel_registry = onnxruntime::fpga::GetFPGAKernelRegistry();
  return kernel_registry;
}

}  // namespace onnxruntime
