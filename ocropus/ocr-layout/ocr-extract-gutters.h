// -*- C++ -*-

// Copyright 2006-2008 Deutsches Forschungszentrum fuer Kuenstliche Intelligenz
// or its licensors, as applicable.
//
// You may not use this file except under the terms of the accompanying license.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may
// obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Project: OCRopus
// File: ocr-extract-gutters.h
// Purpose: Header file declaring data structures for extracting column
//          separating whitespaces (gutters).
// Responsible: Faisal Shafait (faisal.shafait@dfki.de)
// Reviewer:
// Primary Repository:
// Web Sites: www.iupr.org, www.dfki.de

#ifndef h_ocrextractgutters__
#define h_ocrextractgutters__

#include "ocropus.h"
#include "ocr-layout.h"

namespace ocropus {
    using namespace colib;
    using namespace iulib;

    /////////////////////////////////////////////////////////////////////
    ///
    /// \struct ColSeparators
    /// Purpose: Filtering columns from the whitespace cover
    ///
    //////////////////////////////////////////////////////////////////////

    struct ColSeparators {
        float min_aspect;
        int   min_space;
        int   max_space;
        float width;
        int   max_boxes;
        int   min_boxes;

        ColSeparators();
        void findGutters(rectarray &colboxes,
                          rectarray &whitespaceboxes,
                         CharStats &charstats);
        void filterOverlaps(rectarray &colboxes, rectarray &colcandidates);
    };
    ColSeparators *make_ColSeparators();

}

#endif
