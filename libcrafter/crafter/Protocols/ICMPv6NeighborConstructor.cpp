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

#include "ICMPv6Neighbor.h"

using namespace Crafter;
using namespace std;

ICMPv6NeighborSolicitation::ICMPv6NeighborSolicitation() {

    allocate_bytes(24);
    SetName("ICMPv6NeighborSolicitation");
    SetprotoID(0x3A01);
    DefineProtocol();

    Fields.SetOverlap(1);

    SetType(135);
    SetCode(0);
    SetCheckSum(0);
    SetTargetIP("0000::0000");

    ResetFields();
}

void ICMPv6NeighborSolicitation::DefineProtocol() {
    Fields.push_back(new XShortField("Reserved", 1, 0));
    Fields.push_back(new IPv6Address("Target Address", 2, 0));
}

ICMPv6NeighborAdvertisement::ICMPv6NeighborAdvertisement() {

    allocate_bytes(24);
    SetName("ICMPv6NeighborAdvertisement");
    SetprotoID(0x3A01);
    DefineProtocol();

    Fields.SetOverlap(1);

    SetType(136);
    SetCode(0);
    SetCheckSum(0);
    SetRouterFlag(0);
    SetSolicitedFlag(0);
    SetOverrideFlag(0);
    SetTargetIP("0000::0000");

    ResetFields();
}

void ICMPv6NeighborAdvertisement::DefineProtocol() {
    Fields.push_back(new BitFlag<0>("Router Flag", 1, "Source is a Router", "Source is not a Router"));
    Fields.push_back(new BitFlag<1>("Solicited Flag", 1, "Was solicited", "Was not solicited"));
    Fields.push_back(new BitFlag<2>("Override Flag", 1, "Override cache", "Do not override cache"));
    Fields.push_back(new IPv6Address("Target Address", 2, 0));
}

