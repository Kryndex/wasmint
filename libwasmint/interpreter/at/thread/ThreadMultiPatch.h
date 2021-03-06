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


#ifndef WASMINT_THREADMULTIPATCH_H
#define WASMINT_THREADMULTIPATCH_H

#include <cstdint>
#include <vector>
#include <interpreter/at/thread/InstructionState.h>
#include <interpreter/at/thread/FunctionState.h>

namespace wasmint {
    class ThreadMultiPatch {

        InterpreterThread * thread_ = nullptr;
        std::size_t instructionStatesOffset_;
        std::vector<InstructionState> instructionStates_;

        std::size_t functionStatesOffset_;
        std::vector<FunctionState> functionStates_;

    public:
        ThreadMultiPatch(InterpreterThread & thread) : thread_(&thread){
        }

        void update();

        void applyPatch();
    };
}




#endif //WASMINT_THREADMULTIPATCH_H
