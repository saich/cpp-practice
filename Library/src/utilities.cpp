#include "utilities.h"
#include <string>
namespace Utility {


template<> char* typedLiteral<char>(char* const str, wchar_t* const /*wstr*/) { return str; }
template<> wchar_t* typedLiteral<wchar_t>(char* const /*str*/, wchar_t* const wstr) { return wstr; }

} // Namespace
