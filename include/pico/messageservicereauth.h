/** \ingroup Message
 * @file
 * @author  David Llewellyn-Jones <David.Llewellyn-Jones@cl.cam.ac.uk>
 * @version $(VERSION)
 *
 * @section LICENSE
 *
 * (C) Copyright Cambridge Authentication Ltd, 2017
 *
 * This file is part of libpico.
 *
 * Libpico is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Libpico is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with libpico. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 *
 * @brief Message for continuously authenticating the verifier to the prover
 * @section DESCRIPTION
 *
 * The MessageServiceReAuth class allows a Status message to ge generated by
 * the server to be sent to the Pico.
 * 
 * This represents a message sent as part of the continuous authentication
 * process.
 * QR-code (KeyAuth or KeyPair); Start; ServiceAuth; PicoAuth; Status;
 * Pico ReAuth; Service ReAuth (repeatedly).
 *
 * The structure of the message is as follows
 * {"iv":"B64","encryptedData":"B64-ENC","sessionId":0}
 * Where encryptedData contains the following sections
 * char reauthState | int timeout | length | char sequenceNumber[length]
 *
 */

/** \addtogroup Message
 *  @{
 */

#ifndef __MESSAGESERVICEREAUTH_H
#define __MESSAGESERVICEREAUTH_H (1)

#include "pico/shared.h"
#include "pico/buffer.h"
#include "pico/sequencenumber.h"
#include "pico/messagepicoreauth.h"

// Defines

// Structure definitions

/**
 * The internal structure can be found in messageservicereauth.c
 */
typedef struct _MessageServiceReAuth MessageServiceReAuth;

// Function prototypes

MessageServiceReAuth * messageservicereauth_new();
void messageservicereauth_delete(MessageServiceReAuth * messageservicereauth);
void messageservicereauth_set(MessageServiceReAuth * messageservicereauth, Buffer * sharedKey, long int timeout, REAUTHSTATE reauthState, SequenceNumber const * sequenceNum);
void messageservicereauth_set_extra_data(MessageServiceReAuth * messageservicereauth, Buffer * extraData);
const Buffer * messageservicereauth_get_extra_data(MessageServiceReAuth * messageservicereauth);
void messageservicereauth_serialize(MessageServiceReAuth * messageservicereauth, Buffer * buffer);
bool messageservicereauth_deserialize(MessageServiceReAuth * messageservicereauth, Buffer const * buffer);
int messageservicereauth_get_timeout(MessageServiceReAuth * messageservicereauth);
void messageservicereauth_get_sequencenum(MessageServiceReAuth * messageservicereauth, SequenceNumber * sequenceNum);
REAUTHSTATE messageservicereauth_get_reauthstate(MessageServiceReAuth * messageservicereauth);
void messageservicereauth_set_reauthstate(MessageServiceReAuth * messageservicereauth, REAUTHSTATE reauthstate);


// Function definitions

#endif

/** @} addtogroup Message */

