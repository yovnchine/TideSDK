/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
***
* Copyright (c) 2008-2012 Appcelerator Inc.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#include "gst_media_binding.h"
#include <gdk/gdk.h>

namespace ti
{
    GstMediaBinding::GstMediaBinding(TiObjectRef global) : MediaBinding(global)
    {
        char **argv;
        int argc = 0;
        gst_init(&argc, &argv);
    }

    GstMediaBinding::~GstMediaBinding()
    {
    }

    void GstMediaBinding::Beep()
    {
        gdk_beep();
    }

    TiObjectRef GstMediaBinding::CreateSound(std::string& url)
    {
        //This is a path so, turn it into a file:// URL
        std::string myurl = url;
        std::string path = URLUtils::URLToPath(url);
        if (path.find("://") == std::string::npos)
        {
            myurl = URLUtils::PathToFileURL(path);
        }
        return new GstSound(myurl);
    }
}
