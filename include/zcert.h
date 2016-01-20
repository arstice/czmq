/*  =========================================================================
    zcert - work with CURVE security certificates

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of CZMQ, the high-level C binding for 0MQ:
    http://czmq.zeromq.org.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef __ZCERT_H_INCLUDED__
#define __ZCERT_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/zcert.xml" to make changes.
//  @interface
//  This is a stable class, and may not change except for emergencies. It
//  is provided in stable builds.

//  Create and initialize a new certificate in memory
CZMQ_EXPORT zcert_t *
    zcert_new (void);

//  Accepts public/secret key pair from caller
CZMQ_EXPORT zcert_t *
    zcert_new_from (const byte *public_key, const byte *secret_key);

//  Load certificate from file
CZMQ_EXPORT zcert_t *
    zcert_load (const char *filename);

//  Destroy a certificate in memory
CZMQ_EXPORT void
    zcert_destroy (zcert_t **self_p);

//  Return public part of key pair as 32-byte binary string
CZMQ_EXPORT byte *
    zcert_public_key (zcert_t *self);

//  Return secret part of key pair as 32-byte binary string
CZMQ_EXPORT byte *
    zcert_secret_key (zcert_t *self);

//  Return public part of key pair as Z85 armored string
CZMQ_EXPORT char *
    zcert_public_txt (zcert_t *self);

//  Return secret part of key pair as Z85 armored string
CZMQ_EXPORT char *
    zcert_secret_txt (zcert_t *self);

//  Set certificate metadata from formatted string.
CZMQ_EXPORT void
    zcert_set_meta (zcert_t *self, const char *name, const char *format, ...) CHECK_PRINTF (3);

//  Unset certificate metadata.
CZMQ_EXPORT void
    zcert_unset_meta (zcert_t *self, const char *name);

//  Get metadata value from certificate; if the metadata value doesn't
//  exist, returns NULL.                                              
CZMQ_EXPORT char *
    zcert_meta (zcert_t *self, const char *name);

//  Get list of metadata fields from certificate. Caller is responsible for
//  destroying list. Caller should not modify the values of list items.    
CZMQ_EXPORT zlist_t *
    zcert_meta_keys (zcert_t *self);

//  Save full certificate (public + secret) to file for persistent storage  
//  This creates one public file and one secret file (filename + "_secret").
CZMQ_EXPORT int
    zcert_save (zcert_t *self, const char *filename);

//  Save public certificate only to file for persistent storage
CZMQ_EXPORT int
    zcert_save_public (zcert_t *self, const char *filename);

//  Save secret certificate only to file for persistent storage
CZMQ_EXPORT int
    zcert_save_secret (zcert_t *self, const char *filename);

//  Apply certificate to socket, i.e. use for CURVE security on socket.
//  If certificate was loaded from public file, the secret key will be 
//  undefined, and this certificate will not work successfully.        
CZMQ_EXPORT void
    zcert_apply (zcert_t *self, void *zocket);

//  Return copy of certificate; if certificate is NULL or we exhausted
//  heap memory, returns NULL.                                        
//  The caller owns the return value and must destroy it when done with it.
CZMQ_EXPORT zcert_t *
    zcert_dup (zcert_t *self);

//  Return true if two certificates have the same keys
CZMQ_EXPORT bool
    zcert_eq (zcert_t *self, zcert_t *compare);

//  Print certificate contents to stdout
CZMQ_EXPORT void
    zcert_print (zcert_t *self);

//  DEPRECATED as incompatible with centralized logging
//  Print certificate contents to open stream          
CZMQ_EXPORT void
    zcert_fprint (zcert_t *self, FILE *file);

//  Self test of this class
CZMQ_EXPORT void
    zcert_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

//  Deprecated method aliases
#define zcert_dump(s) zcert_print(s)

#endif
