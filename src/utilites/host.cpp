




typedef struct _CPUInfo
{
  union {
    char string [0x20] ;
    uint32 words [0x20 / 4] ;
  } vendor ;
  uint8_t hasAVX ;
  uint8_t hasSSE42 ;
  uint8_t hasSSE41 ;
  uint8_t hasSSE3 ;
  uint8_t hasSSE2 ;
  uint8_t hasSSE ;
  uint8_t hasMMX ;
} CpuInfo ;