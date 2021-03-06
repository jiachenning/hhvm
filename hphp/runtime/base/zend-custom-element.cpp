/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2015 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include "hphp/runtime/base/zend-custom-element.h"

namespace HPHP {

ZendCustomElement::ZendCustomElement(void* data_, unsigned data_size,
                                     DtorFunc destructor)
  : m_destructor(destructor)
{
  m_data = req::malloc(data_size);
  memcpy(m_data, data_, data_size);
}

ZendCustomElement::~ZendCustomElement() {
  if (m_destructor) m_destructor(m_data);
  req::free(m_data);
}

}
