#pragma once


#ifdef CPPFORMSAPI_EXPORTS
#define CPPFAPIWRAPPER __declspec(dllexport)
#else
#define CPPFAPIWRAPPER __declspec(dllimport)
#endif