/*=========================================================================

Library:   TubeTK

Copyright 2010 Kitware Inc. 28 Corporate Drive,
Clifton Park, NY, 12065, USA.

All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

=========================================================================*/
#ifndef __itkStringArrayValue_h
#define __itkStringArrayValue_h

#include "itkParameterValue.h"

namespace itk
{

/**
 * \class StringArrayValue
 *
 * \brief Holds the value of a STRING_ARRAY ParameterValueType.
 *
 * \sa ParameterValue
 * */
class StringArrayValue: public ParameterValue
{
public:
  typedef std::vector< std::string > StringArrayType;

  StringArrayValue()
    {
    this->m_ValueType = STRING_ARRAY;
    }

  const StringArrayType & GetValue() const
    {
    return m_StringArray;
    }

  StringArrayType & GetModifiableValue()
    {
    return m_StringArray;
    }

  void SetValue( const StringArrayType & value )
    {
    m_StringArray = value;
    }

private:
  StringArrayType m_StringArray;
};

} // end namespace itk

#endif
