/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* Copyright by The HDF Group (THG).*
* All rights reserved. *
**
* This file is part of HDF5. The full HDF5 copyright notice, including*
* terms governing use, modification, and redistribution, is contained in*
* the files COPYING and Copyright.html. COPYING can be found at the root*
* of the source code distribution tree; Copyright.html can be found at the*
* root level of an installed copy of the electronic HDF5 document set and*
* is linked from the top-level documents page. It can also be found at*
* http://www.hdfgroup.org/HDF5/doc/Copyright.html. If you do not have*
* access to either file, you may request a copy from help@hdfgroup.org.*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#include "H5Id.h"
#include "H5S.h"
#include "H5ObjectWithAttributes.h"

#include "H5Ipublic.h"

// The HDF5DotNet namespace contains all the .NET wrappers for HDF5 library
// calls.
namespace HDF5DotNet
{
    /// <summary> H5DataSetId uniquely identifies a data set. </summary>
    public ref class H5DataSetId : public H5Id,
        H5ObjectWithAttributes
    {
    public:
        H5DataSetId(H5S::H5SType h5DatasetType);

    internal:
        /// <remarks>
        /// This is the only constructor used to create an H5DataSetId.
        /// It can only be invoked by HDF5DotNet library functions.
        /// </remarks>
        /// <param name="id"> is an HDF5 library-generated identification
        /// number that serves as a unique indentifier. </param>
        H5DataSetId(hid_t id);

    public:
        /// <summary>
        /// Allow read-only access to the internal HDF5 id to HDF5 library
        /// members. (members of this assembly).
        /// </summary>
        virtual property hid_t Id
        {
            hid_t get() { return id_; }
        }

    private:
        /// <summary>
        /// The default constructor is disallowed.  Only HDF5 library
        /// routines are capable of creating an instance of H5DataSetId
        /// and they must supply an id when doing so.
        /// </summary>
        H5DataSetId();

        /// <summary>
        // The hdf5 internal id used to identify objects.
        /// </summary>
        hid_t id_;
    };
}