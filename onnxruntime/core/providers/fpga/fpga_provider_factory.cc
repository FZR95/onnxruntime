// Copyright (c) Microsoft Corporation. All rights reserved.
// Copyright (c) 2019, NXP Semiconductor, Inc. All rights reserved.
// Licensed under the MIT License.

#include "core/providers/fpga/fpga_provider_factory.h"
#include <atomic>
#include "fpga_execution_provider.h"
#include "fpga_provider_factory_creator.h"
#include "core/session/abi_session_options_impl.h"

namespace onnxruntime {

struct FPGAProviderFactory : IExecutionProviderFactory {
  FPGAProviderFactory(bool create_arena) : create_arena_(create_arena) {}
  ~FPGAProviderFactory() override {}
  std::unique_ptr<IExecutionProvider> CreateProvider() override;

 private:
  bool create_arena_;
};

std::unique_ptr<IExecutionProvider> FPGAProviderFactory::CreateProvider() {
  FPGAExecutionProviderInfo info;
  info.create_arena = create_arena_;
  return std::make_unique<FPGAExecutionProvider>(info);
}

std::shared_ptr<IExecutionProviderFactory> FPGAProviderFactoryCreator::Create(int use_arena) {
  return std::make_shared<onnxruntime::FPGAProviderFactory>(use_arena != 0);
}

}  // namespace onnxruntime

ORT_API_STATUS_IMPL(OrtSessionOptionsAppendExecutionProvider_FPGA, _In_ OrtSessionOptions* options, int use_arena) {
  options->provider_factories.push_back(onnxruntime::FPGAProviderFactoryCreator::Create(use_arena));
  return nullptr;
}
