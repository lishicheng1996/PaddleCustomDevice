// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "common/common.h"
#include "common/utils.h"
#include "kernels/funcs/gcu_name_list.h"
#include "paddle/phi/core/dense_tensor.h"

#pragma once
namespace custom_kernel {

#define DECLARE_BINARY_OP(op)                                      \
  void op##_compute(const phi::CustomContext& dev_ctx,             \
                    const phi::DenseTensor& x,                     \
                    const phi::DenseTensor& y,                     \
                    phi::DenseTensor* output);                     \
  phi::DenseTensor op##_compute(const phi::CustomContext& dev_ctx, \
                                const phi::DenseTensor& x,         \
                                const phi::DenseTensor& y);

#define DECLARE_COMPARE_OP(op)                                     \
  void op##_compute(const phi::CustomContext& dev_ctx,             \
                    const phi::DenseTensor& x,                     \
                    const phi::DenseTensor& y,                     \
                    phi::DenseTensor* output);                     \
  phi::DenseTensor op##_compute(const phi::CustomContext& dev_ctx, \
                                const phi::DenseTensor& x,         \
                                const phi::DenseTensor& y);

}  // namespace custom_kernel

namespace custom_kernel {

DECLARE_BINARY_OP(add)
DECLARE_BINARY_OP(mul)
DECLARE_BINARY_OP(div)
DECLARE_BINARY_OP(sub)
DECLARE_BINARY_OP(minimum)
DECLARE_BINARY_OP(maximum)
DECLARE_BINARY_OP(and)

DECLARE_COMPARE_OP(equal)
DECLARE_COMPARE_OP(not_equal)
DECLARE_COMPARE_OP(less_than)
DECLARE_COMPARE_OP(less_equal)
DECLARE_COMPARE_OP(greater_than)
DECLARE_COMPARE_OP(greater_equal)

#undef DECLARE_BINARY_OP
#undef DECLARE_COMPARE_OP

}  // namespace custom_kernel
