/*
 *  SHA1.h
 *  ChipLife
 *
 *  Created by WenBi on 11-6-14.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SOKO_3DPARTY_SHA1_H
#define SOKO_3DPARTY_SHA1_H

typedef struct {
    unsigned long state[5];
    unsigned long count[2];
    unsigned char buffer[64];
} SHA1_CTX;

#ifdef __cplusplus
extern "C" {
#endif

void SHA1Init(SHA1_CTX *context);
void SHA1Update(SHA1_CTX *context, unsigned char *data, unsigned int len);
void SHA1Final(unsigned char digest[20], SHA1_CTX *context);
	
#ifdef __cplusplus
}
#endif

#endif // SOKO_3DPARTY_SHA1_H