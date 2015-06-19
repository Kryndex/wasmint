//
// Created by teemperor on 19.06.15.
//

#ifndef INTERPRETER_BYTESTREAM_H
#define INTERPRETER_BYTESTREAM_H


#include <cstdint>
#include <deque>

class LEB128PayloadBiggerThan32Bit : public std::exception {};
class EndOfStreamReached : public std::exception {};

class ByteStream {

    std::deque<unsigned char> bytes_;
    uint32_t position_ = 0;

public:
    ByteStream(std::deque<uint8_t> bytes) : bytes_(bytes) {
    }
    ByteStream(const ByteStream& copy); // Don't implement

    virtual uint8_t popChar() {
        position_++;
        uint8_t result = peekChar();
        bytes_.pop_front();
        return result;
    }

    virtual uint32_t popUint32() {
        uint32_t result = 0;
        result += popChar();
        result <<= 8;
        result += popChar();
        result <<= 8;
        result += popChar();
        result <<= 8;
        result += popChar();
        return result;
    }

    virtual uint8_t peekChar() {
        if (bytes_.empty())
            throw EndOfStreamReached();
        return bytes_.front();
    }


    virtual uint32_t popLEB128() {
        uint32_t result = 0;
        uint8_t shift = 0;
        for(int i = 0; i < 4; i++) {
            uint8_t byte = popChar();

            // check if first bit is set
            if (byte >= 128u) {
                // if we currently check the 4th byte, the number has to be smaller than 128
                // or the payload would be bigger thatn 32 bit (which is restricted by the specification)
                if (i == 3) {
                    throw LEB128PayloadBiggerThan32Bit();
                }
            }

            // OR the new byte without the MSB into the result integer
            result |= (byte & 0x7F) << shift;

            // if the MSB is not set, we are done here
            if (byte < 128u) {
                break;
            }
            shift += 7;
        }
        return result;
    }

    virtual uint32_t position() {
        return position_;
    }


};


#endif //INTERPRETER_BYTESTREAM_H