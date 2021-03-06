/*******************************************************************************
* Copyright (C) 2010, Quest Software, Inc. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of
*       Quest Software, Inc.,
*       nor the names of its contributors or employees may be used to
*       endorse or promote products derived from this software without
*       specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/**
 * @author Kevin Harris
 */

#include "blocxx/BLOCXX_config.h"
#include "blocxx_test/CannedFileSystem.hpp"
#include "blocxx/CommonFwd.hpp"

#include "blocxx_test/CannedFileSystemImpl.hpp"
#include "blocxx_test/RerootFileSystemImpl.hpp"

namespace BLOCXX_NAMESPACE
{
	namespace Test
	{
		FSMockObjectRef createCannedFSObject(const String& name)
		{
			return CannedFSImpl::createCannedFSObject(name);
		}

		FSMockObjectRef createRerootedFSObject(const String& newRoot)
		{
			return RerootFSImpl::createRerootedFSObject(newRoot);
		}

		bool remapFileName(const FSMockObjectRef& obj, const blocxx::String& path, const blocxx::String& realpath)
		{
			return RerootFSImpl::remapFileName(obj, path, realpath);
		}

		bool addFSFile(FSMockObjectRef& object, FSEntryRef file)
		{
			return CannedFSImpl::addFSFile(object, file);
		}

		bool addNormalFile(FSMockObjectRef& object, const String& path, const String& contents, PermissionFlags mode, UserId owner)
		{
			return CannedFSImpl::addNormalFile(object, path, contents, mode, owner);
		}

		bool addNormalFile(FSMockObjectRef& object, const String& path, const String& contents, const FileInformation& info)
		{
			return CannedFSImpl::addNormalFile(object, path, contents, info);
		}

		bool addSymlink(FSMockObjectRef& object, const String& path, const String& value, UserId owner)
		{
			return CannedFSImpl::addSymlink(object, path, value, owner);
		}

		// FIXME! [KH-20070823] Fix the canned filesystem so directories can have
		// permissions...
		bool addDirectory(FSMockObjectRef& object, const String& path, UserId owner)
		{
			return CannedFSImpl::addDirectory(object, path, owner);
		}

	} // end namespace Test
} // end namespace BLOCXX_NAMESPACE
