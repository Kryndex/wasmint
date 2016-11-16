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


#ifndef WASMINT_BYTEOPCODES_H
#define WASMINT_BYTEOPCODES_H

#include <cstdint>
#include <vector>
#include <string>
namespace wasmint {

    using ByteOpcode = uint8_t;

    namespace ByteOpcodes {
        enum Values {
        Unreachable = 0,
        I32Add,
        I32Sub,
        I32Mul,
        I32DivSigned,
        I32DivUnsigned,
        I32RemainderSigned,
        I32RemainderUnsigned,
        I32And,
        I32Or,
        I32Xor,
        I32ShiftLeft,
        I32ShiftRightZeroes,
        I32ShiftRightSigned,
        I32EqualZero,
        I32Equal,
        I32NotEqual,
        I32LessThanSigned,
        I32LessEqualSigned,
        I32LessThanUnsigned,
        I32LessEqualUnsigned,
        I32GreaterThanSigned,
        I32GreaterEqualSigned,
        I32GreaterThanUnsigned,
        I32GreaterEqualUnsigned,
        I32CountLeadingZeroes,
        I32CountTrailingZeroes,
        I32PopulationCount,

        I64Add,
        I64Sub,
        I64Mul,
        I64DivSigned,
        I64DivUnsigned,
        I64RemainderSigned,
        I64RemainderUnsigned,
        I64And,
        I64Or,
        I64Xor,
        I64ShiftLeft,
        I64ShiftRightZeroes,
        I64ShiftRightSigned,
        I64EqualZero,
        I64Equal,
        I64NotEqual,
        I64LessThanSigned,
        I64LessEqualSigned,
        I64LessThanUnsigned,
        I64LessEqualUnsigned,
        I64GreaterThanSigned,
        I64GreaterEqualSigned,
        I64GreaterThanUnsigned,
        I64GreaterEqualUnsigned,
        I64CountLeadingZeroes,
        I64CountTrailingZeroes,
        I64PopulationCount,

        I32Const,
        I64Const,
        F32Const,
        F64Const,
        CallIndirect,
        CallImport,
        Call,
        Return,
        Branch,
        BranchIf,
        BranchIfNot,

        GetLocal,
        SetLocal,
        TeeLocal,

        ClearStackPreserveTop,

        Drop,

        GrowMemory,
        PageSize,
        CurrentMemory,

        I32Load8Signed,
        I32Load8Unsigned,
        I32Load16Signed,
        I32Load16Unsigned,
        I32Load,
        I64Load8Signed,
        I64Load8Unsigned,
        I64Load16Signed,
        I64Load16Unsigned,
        I64Load32Signed,
        I64Load32Unsigned,
        I64Load,
        F32Load,
        F64Load,

        I32Store8,
        I32Store16,
        I32Store,
        I64Store8,
        I64Store16,
        I64Store32,
        I64Store,
        F32Store,
        F64Store,

        I32Wrap,
        I32TruncSignedF32,
        I32TruncSignedF64,
        I32TruncUnsignedF32,
        I32TruncUnsignedF64,
        I64ExtendSignedI32,
        I64ExtendUnsignedI32,
        I64TruncSignedF32,
        I64TruncSignedF64,
        I64TruncUnsignedF32,
        I64TruncUnsignedF64,
        F32DemoteF64,
        F32ConvertSignedI32,
        F32ConvertSignedI64,
        F32ConvertUnsignedI32,
        F32ConvertUnsignedI64,
        F64PromoteF32,
        F64ConvertSignedI32,
        F64ConvertSignedI64,
        F64ConvertUnsignedI32,
        F64ConvertUnsignedI64,

        I32Select,
        I64Select,
        F32Select,
        F64Select,

        TableSwitch,

        F32Add,
        F32Sub,
        F32Mul,
        F32Div,
        F32Abs,
        F32Neg,
        F32CopySign,
        F32Ceil,
        F32Floor,
        F32Trunc,
        F32Nearest,
        F32Equal,
        F32NotEqual,
        F32LesserThan,
        F32LesserEqual,
        F32GreaterThan,
        F32GreaterEqual,
        F32Sqrt,
        F32Min,
        F32Max,

        F64Add,
        F64Sub,
        F64Mul,
        F64Div,
        F64Abs,
        F64Neg,
        F64CopySign,
        F64Ceil,
        F64Floor,
        F64Trunc,
        F64Nearest,
        F64Equal,
        F64NotEqual,
        F64LesserThan,
        F64LesserEqual,
        F64GreaterThan,
        F64GreaterEqual,
        F64Sqrt,
        F64Min,
        F64Max,

        CopyReg,
        Nop,
        End
        };
        
        inline std::string name(ByteOpcodes::Values opcode) {
            static std::vector<std::string> names = {
                "Unreachable",
                "I32Add",
                "I32Sub",
                "I32Mul",
                "I32DivSigned",
                "I32DivUnsigned",
                "I32RemainderSigned",
                "I32RemainderUnsigned",
                "I32And",
                "I32Or",
                "I32Xor",
                "I32ShiftLeft",
                "I32ShiftRightZeroes",
                "I32ShiftRightSigned",
                "I32Equal",
                "I32NotEqual",
                "I32LessThanSigned",
                "I32LessEqualSigned",
                "I32LessThanUnsigned",
                "I32LessEqualUnsigned",
                "I32GreaterThanSigned",
                "I32GreaterEqualSigned",
                "I32GreaterThanUnsigned",
                "I32GreaterEqualUnsigned",
                "I32CountLeadingZeroes",
                "I32CountTrailingZeroes",
                "I32PopulationCount",

                "I64Add",
                "I64Sub",
                "I64Mul",
                "I64DivSigned",
                "I64DivUnsigned",
                "I64RemainderSigned",
                "I64RemainderUnsigned",
                "I64And",
                "I64Or",
                "I64Xor",
                "I64ShiftLeft",
                "I64ShiftRightZeroes",
                "I64ShiftRightSigned",
                "I64Equal",
                "I64NotEqual",
                "I64LessThanSigned",
                "I64LessEqualSigned",
                "I64LessThanUnsigned",
                "I64LessEqualUnsigned",
                "I64GreaterThanSigned",
                "I64GreaterEqualSigned",
                "I64GreaterThanUnsigned",
                "I64GreaterEqualUnsigned",
                "I64CountLeadingZeroes",
                "I64CountTrailingZeroes",
                "I64PopulationCount",

                "I32Const",
                "I64Const",
                "F32Const",
                "F64Const",
                "CallIndirect",
                "CallImport",
                "Call",
                "Return",
                "Branch",
                "BranchIf",
                "BranchIfNot",
                "BranchCopyReg",
                "BranchIfCopyReg",
                "BranchIfNotCopyReg",

                "GetLocal",
                "SetLocal",

                "GrowMemory",
                "PageSize",
                "CurrentMemory",

                "I32Load8Signed",
                "I32Load8Unsigned",
                "I32Load16Signed",
                "I32Load16Unsigned",
                "I32Load",
                "I64Load8Signed",
                "I64Load8Unsigned",
                "I64Load16Signed",
                "I64Load16Unsigned",
                "I64Load32Signed",
                "I64Load32Unsigned",
                "I64Load",
                "F32Load",
                "F64Load",

                "I32Store8",
                "I32Store16",
                "I32Store",
                "I64Store8",
                "I64Store16",
                "I64Store32",
                "I64Store",
                "F32Store",
                "F64Store",

                "I32Wrap",
                "I32TruncSignedF32",
                "I32TruncSignedF64",
                "I32TruncUnsignedF32",
                "I32TruncUnsignedF64",
                "I64ExtendSignedI32",
                "I64ExtendUnsignedI32",
                "I64TruncSignedF32",
                "I64TruncSignedF64",
                "I64TruncUnsignedF32",
                "I64TruncUnsignedF64",
                "F32DemoteF64",
                "F32ConvertSignedI32",
                "F32ConvertSignedI64",
                "F32ConvertUnsignedI32",
                "F32ConvertUnsignedI64",
                "F64PromoteF32",
                "F64ConvertSignedI32",
                "F64ConvertSignedI64",
                "F64ConvertUnsignedI32",
                "F64ConvertUnsignedI64",

                "I32Select",
                "I64Select",
                "F32Select",
                "F64Select",

                "TableSwitch",

                "F32Add",
                "F32Sub",
                "F32Mul",
                "F32Div",
                "F32Abs",
                "F32Neg",
                "F32CopySign",
                "F32Ceil",
                "F32Floor",
                "F32Trunc",
                "F32Nearest",
                "F32Equal",
                "F32NotEqual",
                "F32LesserThan",
                "F32LesserEqual",
                "F32GreaterThan",
                "F32GreaterEqual",
                "F32Sqrt",
                "F32Min",
                "F32Max",

                "F64Add",
                "F64Sub",
                "F64Mul",
                "F64Div",
                "F64Abs",
                "F64Neg",
                "F64CopySign",
                "F64Ceil",
                "F64Floor",
                "F64Trunc",
                "F64Nearest",
                "F64Equal",
                "F64NotEqual",
                "F64LesserThan",
                "F64LesserEqual",
                "F64GreaterThan",
                "F64GreaterEqual",
                "F64Sqrt",
                "F64Min",
                "F64Max",

                "CopyReg",
                "Nop",
                "End"
            };
            if (opcode >= names.size()) {
                return "Unknown opcode";
            } else {
                return names.at(opcode);
            }
        }
    }
}

#endif //WASMINT_BYTEOPCODES_H
