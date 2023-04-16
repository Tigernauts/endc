#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
    int16_t size; //buffer size. bytes.
    uint8_t *data;

} Buffer;
int myEndian();
/*Out Values*/
uint16_t toUint16(Buffer *_buffer);
int16_t toInt16(Buffer *_buffer);
uint32_t toUint32(Buffer *_buffer);
int32_t toInt32(Buffer *_buffer);
float toFloat(Buffer *_buffer);
