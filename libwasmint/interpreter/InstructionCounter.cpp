/*
 * Copyright 2015 WebAssembly Community Group
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "InstructionCounter.h"

wasmint::InstructionCounter wasmint::InstructionCounter::operator-(uint64_t value) const {
    if (value > counter_)
        throw std::domain_error("Can't call operator- on Instruction counter with counter "
                                + std::to_string(counter_) + " and arg " + std::to_string(value) + " (underflow)");
    return InstructionCounter(counter_ - value);
}