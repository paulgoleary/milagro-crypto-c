/**
 * @file rsa_test.go
 * @author Alessandro Budroni
 * @brief RSA Wrappers tests
 *
 * LICENSE
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package amcl

import (
	"encoding/hex"
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestRSA(t *testing.T) {

	// Seed value for Random Number Generator (RNG)
	seedHex := "9e8b4178790cd57a5761c4a6f164ba72"
	seed, err := hex.DecodeString(seedHex)
	if err != nil {
		fmt.Println("Error decoding seed value")
		return
	}

	rng := CreateCSPRNG(seed)

	// Message to encrypt
	MESSAGEstr := "Hello World\n"
	MESSAGE := []byte(MESSAGEstr)

	// Generating public/private key pair
	RSA_PrivKey, RSA_PubKey := RSAKeyPair(&rng, 65537, nil, nil)

	// OAEP encode MESSAGE to e
	_, F := OAEPencode(HASH_TYPE_RSA, MESSAGE, &rng, nil)

	// encrypt encoded MESSAGE
	G := RSA_ENCRYPT(&RSA_PubKey, F[:])

	// decrypt encrypted MESSAGE
	ML := RSA_DECRYPT(&RSA_PrivKey, G[:])

	// OAEP decode MESSAGE
	_, Fgot := OAEPdecode(HASH_TYPE_RSA, nil, ML[:])

	// destroy private key
	RSA_PRIVATE_KEY_KILL(&RSA_PrivKey)

	assert.Equal(t, Fgot, MESSAGE, "Should be equal")
}

func TestRsaSign(t *testing.T) {

	// Seed value for Random Number Generator (RNG)
	seedHex := "9e8b4178790cd57a5761c4a6f164ba72"
	seed, err := hex.DecodeString(seedHex)
	if err != nil {
		fmt.Println("Error decoding seed value")
		return
	}

	rng := CreateCSPRNG(seed)

	// Generating public/private key pair
	RSA_PrivKey, RSA_PubKey := RSAKeyPair(&rng, 65537, nil, nil)

	// Message to encrypt
	MESSAGEstr := "Hello World\n"
	MESSAGE := []byte(MESSAGEstr)

	// Signing message
	_, C := PKCS15(HASH_TYPE_RSA, MESSAGE)

	// create signature in S
	S := RSA_DECRYPT(&RSA_PrivKey, C[:])

	Cgot := RSA_ENCRYPT(&RSA_PubKey, S[:])

	// destroy private key
	RSA_PRIVATE_KEY_KILL(&RSA_PrivKey)

	assert.Equal(t, C, Cgot, "Should be equal")
}
