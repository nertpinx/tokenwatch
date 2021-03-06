#include <string.h>

#include "pebble_app.h"

typedef struct _pebble_totp pebble_totp;
struct _pebble_totp {
    unsigned char key[20];
    char buffer[7];
    unsigned short interval;

    unsigned short next;
};

void pebble_totp_init(pebble_totp *token,
                      const unsigned char *key,
                      size_t keylen,
                      unsigned short interval);

bool pebble_totp_tick(pebble_totp *token);

char *pebble_totp_get_code(pebble_totp *token);
