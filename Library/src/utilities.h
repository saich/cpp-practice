#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>
#include <sstream>
#include <algorithm>
#include <tr1/memory> // TODO: Remove tr1 and use C++11

/** A macro to disallow the copy constructor and operator= functions.
	This should be used in the private: declarations for a class
*/
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

namespace Utility 
{
	template <class F>
	inline std::wstring Transform(std::wstring const& in, F f)
	{
		std::wstring tmp(in);
		std::transform(in.begin(), in.end(), tmp.begin(), f);
		return tmp;
	}

	inline std::wstring ToUpper(const std::wstring& wsIn) {
		return Transform(wsIn, ::towupper);
	}
	inline std::wstring ToLower(const std::wstring& wsIn) {
		return Transform(wsIn, ::towlower);
	}

	/* turn literals to appropriate vanilla char or wide char forms as required */
	/* these templates are never used directly. Use the macro instead */
	template<class T> T* typedLiteral(char* const str, wchar_t* const wstr);

	/* the macro is called by templatized client code for choosing correct literal form */
	#define CHOOSE_APPROPRIATE_LITERAL(type, str) typedLiteral<type>(str, L##str)

	template <class T>
	inline std::wstring NumberToString( T Number )
	{
		std::wstringstream wss;
		wss << Number;
		return wss.str();
	}

	template <class T>
	inline T StringToNumber ( const std::wstring &data )
	{
		std::wstringstream wss(data);
		T result;
		return wss >> result ? result : 0;
	}

#if WIN_ENV
#define PATH_SEP "\\"
#else
#define PATH_SEP "/"
#endif

	template <class T>
	struct non_null_ptr 
	{
		 non_null_ptr(T *p) 
			  : p_(p) 
		 { 
			  if (!p_) throw std::exception("null ptr"); 
		 }
     
		 non_null_ptr(const non_null_ptr<T>& x) 
			  : p_(x.p_) 
		 { 
			  if (!p_) throw std::exception("null ptr"); 
		 }

		 non_null_ptr& operator=(const non_null_ptr<T>& x) 
		 {
			  if (!x.p_) throw std::exception("null ptr");
			  p_ = x.p_;
			  return *this;
		 }

		 T& operator* () const // never throws
		{
			return *p_;
		}

		T * operator-> () const // never throws
		{
			  return p_.operator->();
		}

		 std::tr1::shared_ptr<T> p_;
	};
}

#endif // UTILITIES_H_
