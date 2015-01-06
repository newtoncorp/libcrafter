/*
Copyright (c) 2012, Esteban Pellegrino
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ESTEBAN PELLEGRINO BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef ICMPV6ROUTER_H_
#define ICMPV6ROUTER_H_

#include "ICMPv6.h"

namespace Crafter {

    class ICMPv6RouterAdvertisement: public ICMPv6 {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return ICMPv6RouterAdvertisement::ICMPv6RouterAdvertisementConstFunc;
        };

        static Layer* ICMPv6RouterAdvertisementConstFunc() {
            return new ICMPv6RouterAdvertisement;
        };

        static const byte FieldCurrentHopLimit = 9;
        static const byte FieldManagedAddressConfiguration = 10;
        static const byte FieldOtherStatefulConfiguration = 11;
        static const byte FieldReserved = 12;
        static const byte FieldRouterLifetime = 13;
        static const byte FieldReachableTime = 14;
        static const byte FieldRetransmissionTimer = 15;

    public:

        enum { PROTO = 0x3A01 };

		/* ------- Messages types --------- */

		/* +++ Type +++ */
		static const byte RouterAdvertisement;

        ICMPv6RouterAdvertisement();

        void SetCurrentHopLimit(const byte& value) {
            SetFieldValue(FieldCurrentHopLimit,value);
        };

        void SetManagedAddressConfiguration(const word& value) {
            SetFieldValue(FieldManagedAddressConfiguration,value);
        };

        void SetOtherStatefulConfiguration(const word& value) {
            SetFieldValue(FieldOtherStatefulConfiguration,value);
        };

        void SetReserved(const word& value) {
            SetFieldValue(FieldReserved,value);
        };

        void SetRouterLifetime(const short_word& value) {
            SetFieldValue(FieldRouterLifetime,value);
        };

        void SetReachableTime(const word& value) {
            SetFieldValue(FieldReachableTime,value);
        };

        void SetRetransmissionTimer(const word& value) {
            SetFieldValue(FieldRetransmissionTimer,value);
        };

        word  GetCurrentHopLimit() const {
            return GetFieldValue<byte>(FieldCurrentHopLimit);
        };

        word  GetManagedAddressConfiguration() const {
            return GetFieldValue<word>(FieldManagedAddressConfiguration);
        };

        word  GetOtherStatefulConfiguration() const {
            return GetFieldValue<word>(FieldOtherStatefulConfiguration);
        };

        word  GetReserved() const {
            return GetFieldValue<word>(FieldReserved);
        };

        word  GetRouterLifetime() const {
            return GetFieldValue<short_word>(FieldRouterLifetime);
        };

        word  GetReachableTime() const {
            return GetFieldValue<word>(FieldReachableTime);
        };

        word  GetRetransmissionTimer() const {
            return GetFieldValue<word>(FieldRetransmissionTimer);
        };

        ~ICMPv6RouterAdvertisement() { /* Destructor */ };

    };

    class ICMPv6RouterSolicitation: public ICMPv6 {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return ICMPv6RouterSolicitation::ICMPv6RouterSolicitationConstFunc;
        };

        static Layer* ICMPv6RouterSolicitationConstFunc() {
            return new ICMPv6RouterSolicitation;
        };

        static const byte FieldReserved = 9;

    public:

        enum { PROTO = 0x3A01 };

		/* ------- Messages types --------- */

		/* +++ Type +++ */
		static const byte RouterSolicitation;

        ICMPv6RouterSolicitation();

        void SetReserved(const word& value) {
            SetFieldValue(FieldReserved,value);
        };

        word  GetReserved() const {
            return GetFieldValue<word>(FieldReserved);
        };

        ~ICMPv6RouterSolicitation() { /* Destructor */ };

    };

}

#endif /* ICMPV6ROUTER_H_ */
