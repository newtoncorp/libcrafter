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
#ifndef ICMPV6NEIGHBOR_H_
#define ICMPV6NEIGHBOR_H_

#include "ICMPv6.h"

namespace Crafter {

    class ICMPv6NeighborSolicitation: public ICMPv6 {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return ICMPv6NeighborSolicitation::ICMPv6NeighborSolicitationConstFunc;
        };

        static Layer* ICMPv6NeighborSolicitationConstFunc() {
            return new ICMPv6NeighborSolicitation;
        };

        static const byte FieldReserved = 9;
        static const byte FieldTargetIP = 10;

    public:

        enum { PROTO = 0x3A01 };

		/* ------- Messages types --------- */

		/* +++ Type +++ */
		static const byte NeighborSolicitation;

        ICMPv6NeighborSolicitation();

        void SetTargetIP(const std::string& value) {
            SetFieldValue(FieldTargetIP,value);
        };

        std::string  GetTargetIP() const {
            return GetFieldValue<std::string>(FieldTargetIP);
        };

        ~ICMPv6NeighborSolicitation() { /* Destructor */ };

    };

    class ICMPv6NeighborAdvertisement: public ICMPv6 {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return ICMPv6NeighborAdvertisement::ICMPv6NeighborAdvertisementConstFunc;
        };

        static Layer* ICMPv6NeighborAdvertisementConstFunc() {
            return new ICMPv6NeighborAdvertisement;
        };

        static const byte FieldRouterFlag = 9;
        static const byte FieldSolicitedFlag = 10;
        static const byte FieldOverrideFlag = 11;
        static const byte FieldTargetIP = 12;

    public:

        enum { PROTO = 0x3A01 };

		/* ------- Messages types --------- */

		/* +++ Type +++ */
		static const byte NeighborAdvertisement;

        ICMPv6NeighborAdvertisement();

        void SetRouterFlag(const word& value) {
            SetFieldValue(FieldRouterFlag,value);
        };

        void SetSolicitedFlag(const word& value) {
            SetFieldValue(FieldSolicitedFlag,value);
        };

        void SetOverrideFlag(const word& value) {
            SetFieldValue(FieldOverrideFlag,value);
        };

        void SetTargetIP(const std::string& value) {
            SetFieldValue(FieldTargetIP,value);
        };

        word  GetRouterFlag() const {
            return GetFieldValue<word>(FieldRouterFlag);
        };

        word  GetSolicitedFlag() const {
            return GetFieldValue<word>(FieldSolicitedFlag);
        };

        word  GetOverrideFlag() const {
            return GetFieldValue<word>(FieldOverrideFlag);
        };

        std::string  GetTargetIP() const {
            return GetFieldValue<std::string>(FieldTargetIP);
        };

        ~ICMPv6NeighborAdvertisement() { /* Destructor */ };

    };

}

#endif /* ICMPV6NEIGHBOR_H_ */
