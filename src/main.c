#include "endc.h"

const int ABCD = 0; // BE Big Endian ABCD
const int DCBA = 1; // LE Little Endian DCBA
const int BADC = 2; // MBE Mid-Big Endian BADC. Possible for 4 bytes data types
const int CDAB = 3; // MLE Mid-Little Endian CDAB. Possible for 4 bytes data types

void showHEX(Buffer *_buffer)
{
    for (uint i = 0; i < _buffer->size; i++)
    {
        printf("%.2X ", _buffer->data[i]);
    }
    printf("\n");
};

// reads the value of anytype and return Buffer result.
Buffer _readValue(void *_value, uint _size)
{
    Buffer b;
    b.size = _size;
    b.data = (uint8_t *)malloc(b.size);
    memcpy(b.data, _value, b.size);
    return b;
}
// read charString to Buffer
Buffer _readCharString(char *_string)
{
    return _readValue(_string, strlen(_string));
}

/*Convert Endianess*/
// default for linux is LittleEndian (DCBA)

// return endianess of system
int myEndian()
{
    uint8_t *data;
    data=(uint8_t*)malloc(4);
    uint32_t _testValue=0xAABBCCDD;
    memcpy(data,  &_testValue, 4);
    if ((data[0] == 0xAA) && (data[1] == 0xBB) && (data[2] == 0xCC) && (data[3] == 0xDD))
    {
        return ABCD;
    }
    if ((data[3] == 0xAA) && (data[2] == 0xBB) && (data[1] == 0xCC) && (data[0] == 0xDD))
    {
        return DCBA;
    }
    if ((data[1] == 0xAA) && (data[0] == 0xBB) && (data[3] == 0xCC) && (data[3] == 0xDD))
    {
        return BADC;
    }
    if ((data[2] == 0xAA) && (data[3] == 0xBB) && (data[0] == 0xCC) && (data[1] == 0xDD))
    {
        return BADC;
    }
    else
    {
        return -1;
    }
}

// swap bytes
Buffer reverse(Buffer *_buffer)
{
    Buffer _result;
    _result.size = _buffer->size;
    _result.data = (uint8_t *)malloc(_result.size);
    for (int i = 0; i < _buffer->size; i++)
    {
        memcpy(_result.data + i, _buffer->data + (_buffer->size - 1 - i), 1);
    }
    return _result;
}

/*Out Values*/
uint16_t toUint16(Buffer *_buffer)
{
    (_buffer->size != sizeof(uint16_t)) ? fprintf(stderr, "%s", "Warning. Buffer size not equal Uint16 size\n") : 0;
    uint16_t result;
    memcpy(&result, _buffer->data, sizeof(uint16_t));
    return result;
}
int16_t toInt16(Buffer *_buffer)
{
    (_buffer->size != sizeof(int16_t)) ? fprintf(stderr, "%s", "Warning. Buffer size not equal Int16 size\n") : -1;
    int16_t result;
    memcpy(&result, _buffer->data, sizeof(int16_t));
    return result;
}
uint32_t toUint32(Buffer *_buffer)
{
    (_buffer->size != sizeof(uint32_t)) ? fprintf(stderr, "%s", "Warning. Buffer size not equal Uint32 size\n") : -1;
    uint32_t result;
    memcpy(&result, _buffer->data, sizeof(uint32_t));
    return result;
}
int32_t toInt32(Buffer *_buffer)
{
    (_buffer->size != sizeof(int32_t)) ? fprintf(stderr, "%s", "Warning. Buffer size not equal Int32 size\n") : -1;
    int32_t result;
    memcpy(&result, _buffer->data, sizeof(int32_t));
    return result;
}
float toFloat(Buffer *_buffer)
{
    (_buffer->size != sizeof(float)) ? fprintf(stderr, "%s", "Warning. Buffer size not equal Float size\n") : -1;
    float result;
    memcpy(&result, _buffer->data, sizeof(float));
    return result;
}
/*******/
int main(int argc, char *argv[])
{
return -1;
}
