#ifndef ___SHARED_H__
#define ___SHARED_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define BOOL uint8_t

#ifdef DEBUG
#define LOG(fmt, ...)           \
    printf(fmt, ##__VA_ARGS__); \
    printf("\n");
#else
#define LOG(fmt, ...)
#endif
#define EVENTS_CLEAR_FLAGS(eg) (tx_event_flags_set(&eg, 0, TX_AND))
#define EVENTS_SET_FLAGS(eg, flags) (tx_event_flags_set(&eg, flags, TX_OR))
#define EVENTS_RESET_FLAGS(eg, flags) (tx_event_flags_set(&eg, ~flags, TX_AND))

#define ALIGN32 __attribute__((aligned(32)))
#define min(a, b) (((a) <= (b)) ? (a) : (b))
#define max(a, b) (((a) >= (b)) ? (a) : (b))

    //-快速log2 的算�
    uint32_t fast_log2(uint32_t _val);
    typedef uint8_t bool_t;
#define true 1
#define false 0

    typedef void (*EventHandler)(void *sender, void *host, void *event);

#ifdef __cplusplus
}
#endif

#endif // ___SHARED_H__