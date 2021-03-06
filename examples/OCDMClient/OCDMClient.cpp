/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include <core/core.h>
#include <ocdm/open_cdm.h>

using namespace WPEFramework;

void TestMethod() {
    OpenCDMAccessor* ocdmSystem = opencdm_create_system();

	if (ocdmSystem != nullptr) {
        if (opencdm_is_type_supported(ocdmSystem, "HelloWorld", "MimeType") == ERROR_NONE) {
            printf("Succeeded\n");
        } else {
            printf("Failed\n");
        }
    }
}

int main()
{
	Core::SystemInfo::SetEnvironment(_T("OPEN_CDM_SERVER"), "127.0.0.1:7912", true);

	printf("Calling test method\n");
	int character;
	do {
		printf(">>");
		character = ::toupper(::getc(stdin));

		switch (character)
		{
		case'T':
		{
			// Time to create a littlebit of NV space for us...

			TestMethod();
			break;
		}
		default: break;
		}
	} while (character != 'Q');

	Core::Singleton::Dispose();

	printf("Done\n");

	return (0);
}

