// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/framework/execution_provider.h"
#include "core/graph/constants.h"

namespace onnxruntime {


// Information needed to construct FPGA execution providers.
struct FPGAExecutionProviderInfo {
  bool create_arena{true};

  explicit FPGAExecutionProviderInfo(bool use_arena)
      : create_arena(use_arena) {}

  FPGAExecutionProviderInfo() = default;
};

// using FuseRuleFn = std::function<void(const onnxruntime::GraphViewer&,
//                                       std::vector<std::unique_ptr<ComputeCapability>>&)>;

// Logical device representation.
class FPGAExecutionProvider : public IExecutionProvider {
 public:
  explicit FPGAExecutionProvider(const FPGAExecutionProviderInfo& info);
  virtual ~FPGAExecutionProvider();

  const void* GetExecutionHandle() const noexcept override {
    // The FPGA interface does not return anything interesting.
    return nullptr;
  }

  std::shared_ptr<KernelRegistry> GetKernelRegistry() const override;
};
}  // namespace onnxruntime
