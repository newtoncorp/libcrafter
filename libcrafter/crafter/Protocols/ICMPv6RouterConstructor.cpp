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

#include "ICMPv6Router.h"

using namespace Crafter;
using namespace std;

ICMPv6RouterAdvertisement::ICMPv6RouterAdvertisement() {

    allocate_bytes(16);
    SetName("ICMPv6RouterAdvertisement");
    SetprotoID(0x3A01);
    DefineProtocol();

    Fields.SetOverlap(1);

    SetType(134);
    SetCode(0);
    SetCheckSum(0);
    SetCurrentHopLimit(0);
    SetManagedAddressConfiguration(0);
    SetOtherStatefulConfiguration(0);
    SetReserved(0);
    SetRouterLifetime(0);
    SetReachableTime(0);
    SetRetransmissionTimer(0);

    ResetFields();
}

void ICMPv6RouterAdvertisement::DefineProtocol() {
    // router advertisement
    Fields.push_back(new ByteField("Current Hop Limit",1,0));
    Fields.push_back(new BitFlag<8>("Managed Address Config",1, "Use stateful method for configuration", "Do not use stateful method for configuration"));
    Fields.push_back(new BitFlag<9>("Other Stateful Config",1, "Use autoconfiration", "Do not use autoconfiguration"));
    Fields.push_back(new BitsField<6,10>("Reserved",1));
    Fields.push_back(new XShortField("Router Lifetime",1,2));
    Fields.push_back(new WordField("Reachable Timer",2,0));
    Fields.push_back(new WordField("Retransmission Timer",3,0));
}

ICMPv6RouterSolicitation::ICMPv6RouterSolicitation() {

    allocate_bytes(8);
    SetName("ICMPv6RouterSolicitation");
    SetprotoID(0x3A01);
    DefineProtocol();

    Fields.SetOverlap(1);

    SetType(133);
    SetCode(0);
    SetCheckSum(0);
    SetReserved(0);

    ResetFields();
}

void ICMPv6RouterSolicitation::DefineProtocol() {
    // router solicitation
    Fields.push_back(new WordField("Reserved",1,0));
}

