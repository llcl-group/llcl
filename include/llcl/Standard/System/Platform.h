#ifndef LLCL_STANDARD_SYSTEM_PLATFORM_H
#define LLCL_STANDARD_SYSTEM_PLATFORM_H

//@MACROS:
//  LLCL_PLATFORM_OS_*: operating system type, sub-type, and version
//  LLCL_PLATFORM_CPU_*: instruction set, instruction width, and version
//  LLCL_PLATFORM_CMP_*: compiler vendor, and version
//  LLCL_PLATFORM_COMPILER_ERROR: trigger a compiler error
//  LLCL_PLATFORM_AGGRESSIVE_INLINE: inline code for speed over text size

#ifdef __cplusplus
namespace llcl {
#endif

struct llcl_platform_assert;

#ifdef __cplusplus
}  // namespace llcl
#endif

#ifdef __cplusplus
#define LLCL_PLATFORM_COMPILER_ERROR \
  char die[sizeof(::llcl::llcl_platform_assert)]
#else
#define LLCL_PLATFORM_COMPILER_ERROR char die[sizeof(llcl_platform_assert)]
#endif

#if defined(__xlC__) || defined(__IBMC__) || defined(__IBMCPP__)
#define LLCL_PLATFORM_CMP_IBM     1
#define LLCL_PLATFORM_CMP_VERSION __xlC__

// which OS -- this compiler should only be used on AIX
#define LLCL_PLATFORM_OS_UNIX 1
#if defined(_AIX)  // must be defined
#define LLCL_PLATFORM_OS_AIX       1
#define LLCL_PLATFORM_OS_VER_MAJOR _AIX
#elif defined(__linux__)
#define LLCL_PLATFORM_OS_LINUX 1
#else
#error "AIX compiler appears to be in use on non-AIX OS."
LLCL_PLATFORM_COMPILER_ERROR;
#endif

// which CPU -- should always be POWERPC
#if defined(_ARCH_PWR2)
#define LLCL_PLATFORM_CPU_VER_MAJOR _ARCH_PWR2
#elif defined(_ARCH_PWR)
#define LLCL_PLATFORM_CPU_VER_MAJOR _ARCH_PWR
#elif defined(_ARCH_POWER)
#define LLCL_PLATFORM_CPU_VER_MAJOR _ARCH_POWER
#elif defined(_POWER)
#define LLCL_PLATFORM_CPU_VER_MAJOR _POWER
#elif defined(_ARCH_COM)
#define LLCL_PLATFORM_CPU_VER_MAJOR _ARCH_COM
#elif defined(_ARCH_601)
#define LLCL_PLATFORM_CPU_VER_MAJOR _ARCH_601
#elif defined(_ARCH_PPC)
#define LLCL_PLATFORM_CPU_VER_MAJOR _ARCH_PPC
#elif defined(_ARCH_PPC64)
#define LLCL_PLATFORM_CPU_VER_MAJOR _ARCH_PPC64
#else
#error "Unable to identify the AIX CPU."
LLCL_PLATFORM_COMPILER_ERROR;
#endif

#define LLCL_PLATFORM_CPU_POWERPC 1
#if defined(__64BIT__)
#define LLCL_PLATFORM_CPU_64_BIT 1
#else
#define LLCL_PLATFORM_CPU_32_BIT 1
#endif
// ------------------------------------------------------------------------
#elif defined(_MSC_VER)
#define LLCL_PLATFORM_CMP_MSVC    1
#define LLCL_PLATFORM_CMP_VERSION _MSC_VER

// which OS -- should be some flavor of Windows
//  there is currently no support for:
//  - 16-bit versions of Windows (3.x)
//  - Windows CE
#if defined(_WIN64) || defined(_WIN32)
#define LLCL_PLATFORM_OS_WINDOWS 1
#elif defined(_WIN16)
#error "16-bit Windows platform not supported."
LLCL_PLATFORM_COMPILER_ERROR;
#else
#error "Microsoft OS is running on an unknown platform."
LLCL_PLATFORM_COMPILER_ERROR;
#endif

// which version of Windows, source sampled 2022.Dec.26 18:00EST:
// https://learn.microsoft.com/en-us/cpp/porting/ ...
//                                     ... modifying-winver-and-win32-winnt
#if _WIN32_WINNT >= 0x0A00
#define LLCL_PLATFORM_OS_WIN10 1
#elif _WIN32_WINNT >= 0x0603
#define LLCL_PLATFORM_OS_WINBLUE 1
#elif _WIN32_WINNT >= 0x0602
#define LLCL_PLATFORM_OS_WIN8 1
#elif _WIN32_WINNT >= 0x0601
#define LLCL_PLATFORM_OS_WIN7 1
#elif _WIN32_WINNT >= 0x0600
#define LLCL_PLATFORM_OS_WINVISTA 1
#elif _WIN32_WINNT >= 0x0502
#define LLCL_PLATFORM_OS_WINS03 1
#elif _WIN32_WINNT >= 0x0501
#define LLCL_PLATFORM_OS_WINXP 1
#elif _WIN32_WINNT >= 0x0500
#define LLCL_PLATFORM_OS_WIN2K 1
#elif _WIN32_WINNT >= 0x0410
#define LLCL_PLATFORM_OS_WIN9X 1
#elif _WIN32_WINNT >= 0x0400
#define LLCL_PLATFORM_OS_WINNT 1
#elif defined(WINVER) && WINVER >= 0x0400 || \
    defined(_WIN32_WINDOWS) && _WIN32_WINDOWS >= 0x401
#define LLCL_PLATFORM_OS_WIN9X 1
#else  // default when detection fails
#define LLCL_PLATFORM_OS_WINVISTA 1
#endif

// set API Version synonyms
#if defined(LLCL_PLATFORM_OS_WINVISTA) && !defined(LLCL_PLATFORM_OS_WINS08)
#define LLCL_PLATFORM_OS_WINS08 1
// Windows Server 2008 is the same API as Windows Vista
#endif
#if !defined(LLCL_PLATFORM_OS_WINVISTA) && defined(LLCL_PLATFORM_OS_WINS08)
#define LLCL_PLATFORM_OS_WINVISTA 1
// Windows Server 2008 is the same API as Windows Vista
#endif

// set Version flags
#if defined(_WIN32_WINNT)
#define LLCL_PLATFORM_OS_VER_MAJOR _WIN32_WINNT / 0x100
#define LLCL_PLATFORM_OS_VER_MINOR _WIN32_WINNT % 0x100
#elif defined(WINVER)
#define LLCL_PLATFORM_OS_VER_MAJOR WINVER / 0x100
#define LLCL_PLATFORM_OS_VER_MINOR WINVER % 0x100
#elif defined(_WIN32_WINDOWS)
#define LLCL_PLATFORM_OS_VER_MAJOR _WIN32_WINDOWS / 0x100
#define LLCL_PLATFORM_OS_VER_MINOR _WIN32_WINDOWS % 0x100
#else  // default
#define LLCL_PLATFORM_OS_VER_MAJOR 4
#define LLCL_PLATFORM_OS_VER_MINOR 0
#endif

// which CPU
//  since WinCE is not supported, neither is the HITACHI CPU
#if defined(_M_ALPHA)
#define LLCL_PLATFORM_CPU_ALPHA 1
#elif defined(_M_IX86)
#define LLCL_PLATFORM_CPU_X86       1
#define LLCL_PLATFORM_CPU_32_BIT    1
#define LLCL_PLATFORM_CPU_VER_MAJOR _M_IX86
#elif defined(_M_IA64)
#if defined(_WIN64)  // native mode
#define LLCL_PLATFORM_CPU_IA64   1
#define LLCL_PLATFORM_CPU_64_BIT 1
#else  // emulated
#define LLCL_PLATFORM_CPU_X86    1
#define LLCL_PLATFORM_CPU_32_BIT 1
#endif
#define LLCL_PLATFORM_CPU_VER_MAJOR _M_IA64
#elif defined(_M_AMD64)
#if defined(_WIN64)  // native mode
#define LLCL_PLATFORM_CPU_X86_64 1
#define LLCL_PLATFORM_CPU_64_BIT 1
#else  // emulated
#define LLCL_PLATFORM_CPU_X86    1
#define LLCL_PLATFORM_CPU_32_BIT 1
#endif
#define LLCL_PLATFORM_CPU_VER_MAJOR _M_AMD64
#elif defined(_M_PPC)
#define LLCL_PLATFORM_CPU_POWERPC   1
#define LLCL_PLATFORM_CPU_VER_MAJOR _M_PPC
#elif defined(_M_MRX000)
#define LLCL_PLATFORM_CPU_MIPS      1
#define LLCL_PLATFORM_CPU_VER_MAJOR _M_MRX000
#else
#error "Unable to identify CPU on which the MSVC compiler is running."
LLCL_PLATFORM_COMPILER_ERROR;
#endif

// ---------------------------------------------------------------------------
#elif defined(__clang__) || defined(__GNUC__) || defined(__EDG__)

#if defined(__clang__)
// Clang presents itself as GCC compatible, but sets the pre-defined
// GCC version macros ('__GNUC__', '__GNUC_MINOR__', and
// '__GNUC_PATCHLEVEL__') to version 4.2.1 no matter the version of
// Clang being used.  In order to differentiate between Clang and GCC,
// the compilers are identified by independent 'LLCL_PLATFORM' macros.
// Apple Xcode is based upon LLVM (Clang), but Apple changes the
// reported Clang versioning ('__clang_major__', '__clang_minor__',
// '__clang_patchlevel__') to report the Xcode version rather than the
// actual version of Clang the Xcode release includes.  A table of
// Xcode/Clang version information is maintained here:
// https://trac.macports.org/wiki/XcodeVersionInfo To avoid this extra
// dimension, the Clang intrinsics '__has_builtin', '__has_feature',
// and '__has_extension' should be used in preference to
// 'LLCL_PLATFORM_CMP_VERSION' when checking for compiler features.  If
// 'LLCL_PLATFORM_CMP_VERSION' must be used, then '__APPLE_CC__' can be
// tested to determine if 'LLCL_PLATFORM_CMP_VERSION' represents Clang
// LLVM or Apple Xcode version.

#define LLCL_PLATFORM_CMP_CLANG 1
#define LLCL_PLATFORM_CMP_VERSION \
  (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#elif defined(__GNUC__)
#define LLCL_PLATFORM_CMP_GNU 1
#if defined(__GNUC_PATCHLEVEL__)
#define LLCL_PLATFORM_CMP_VERSION \
  (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
#define LLCL_PLATFORM_CMP_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100)
#endif
#else
#define LLCL_PLATFORM_CMP_EDG     1
#define LLCL_PLATFORM_CMP_VERSION __EDG_VERSION__
#endif

// which OS -- GNU and EDG/Como are implemented almost everywhere
#if defined(_AIX)
#define LLCL_PLATFORM_OS_AIX 1
#elif defined(__CYGWIN__) || defined(cygwin) || defined(__cygwin)
#define LLCL_PLATFORM_OS_CYGWIN 1
#elif defined(linux) || defined(__linux)
#define LLCL_PLATFORM_OS_LINUX 1
#elif defined(__FreeBSD__)
#define LLCL_PLATFORM_OS_FREEBSD 1
#elif defined(sun) || defined(__sun)
#if defined(__SVR4) || defined(__svr4__)
#define LLCL_PLATFORM_OS_SOLARIS 1
#else
#define LLCL_PLATFORM_OS_SUNOS 1
#endif
#elif defined(_WIN32) || \
    defined(__WIN32__) && !(defined(cygwin) || defined(__cygwin))
#define LLCL_PLATFORM_OS_WINDOWS 1
#elif defined(__APPLE__)
#define LLCL_PLATFORM_OS_DARWIN 1
#else
#if defined(__GNUC__)
#error "Unable to determine on which OS the compiler is running."
#else
#error "Unable to determine on which OS EDG compiler is running."
#endif
LLCL_PLATFORM_COMPILER_ERROR;
#endif

#if !defined(LLCL_PLATFORM_OS_WINDOWS)
#define LLCL_PLATFORM_OS_UNIX 1
#endif

// which CPU -- GNU and EDG/Como are implemented almost everywhere
#if defined(__alpha__)
#define LLCL_PLATFORM_CPU_ALPHA 1
#elif defined(__x86_64) || defined(__x86_64__)
#define LLCL_PLATFORM_CPU_X86_64 1
#define LLCL_PLATFORM_CPU_64_BIT 1
#elif defined(__i386) || defined(__i386__) || defined(__ix86) || \
    defined(__ix86__)
#define LLCL_PLATFORM_CPU_X86    1
#define LLCL_PLATFORM_CPU_32_BIT 1
#elif defined(__ia64) || defined(__ia64__) || defined(_IA64) || \
    defined(__IA64__)
#define LLCL_PLATFORM_CPU_IA64 1
#if defined(_LP64) || defined(__LP64__)
#define LLCL_PLATFORM_CPU_64_BIT 1
#else  // defined(_ILP32)
#define LLCL_PLATFORM_CPU_32_BIT 1
#endif
#elif defined(__mips__)
#define LLCL_PLATFORM_CPU_MIPS 1
#elif defined(__hppa__) || defined(__hppa)
#define LLCL_PLATFORM_CPU_HPPA 1
#elif defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || \
    defined(__ppc__) || defined(_POWER)
#define LLCL_PLATFORM_CPU_POWERPC 1
#if defined(__64BIT__) || defined(_LP64) || defined(__LP64__)
#define LLCL_PLATFORM_CPU_64_BIT 1
#else  // defined(_ILP32)
#define LLCL_PLATFORM_CPU_32_BIT 1
#endif
#elif defined(__sparc__) || defined(__sparc_v9__) || defined(__sparcv9)
#define LLCL_PLATFORM_CPU_SPARC 1
#if defined(__sparc_v9__) || defined(__sparcv9) || defined(__arch64__)
#define LLCL_PLATFORM_CPU_SPARC_V9 1
#define LLCL_PLATFORM_CPU_64_BIT   1
#else
#define LLCL_PLATFORM_CPU_SPARC_32 1
#endif
#elif defined(__arm__) || defined(__arm64__)
#define LLCL_PLATFORM_CPU_ARM 1
#if defined(__arm64__)
#define LLCL_PLATFORM_CPU_64_BIT 1
#endif
#if defined(__ARM_ARCH)
#if __ARM_ARCH == 6
#define LLCL_PLATFORM_CPU_ARM_V6 1
#elif __ARM_ARCH == 7
#define LLCL_PLATFORM_CPU_ARM_V7 1
#elif __ARM_ARCH == 8
#define LLCL_PLATFORM_CPU_ARM_V8 1
#endif
#elif defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__) || \
    defined(__ARM_ARCH_5TEJ__)
#define LLCL_PLATFORM_CPU_ARM_V5
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6ZK__)
#define LLCL_PLATFORM_CPU_ARM_V6
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || \
    defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7R__)
#define LLCL_PLATFORM_CPU_ARM_V7
#elif defined(__ARM64_ARCH_8__) || defined(__ARM_ARCH_8_3__) || \
    defined(__ARM_ARCH_8_4__) || defined(__ARM_ARCH_8_5__)
#define LLCL_PLATFORM_CPU_ARM_V8
#else
#error "Unsupported ARM platform."
#endif
#else
#if defined(__GNUC__)
#error "Unable to determine on which CPU the compiler is running."
#else
#error "Unable to determine on which CPU EDG compiler is running."
#endif
LLCL_PLATFORM_COMPILER_ERROR;
#endif

#if !defined(LLCL_PLATFORM_CPU_64_BIT)
#define LLCL_PLATFORM_CPU_32_BIT 1
#endif
// ----------------------------------------------------------------------------
#elif defined(__SUNPRO_CC) || defined(__SUNPRO_C)

#define LLCL_PLATFORM_CMP_SUN 1
#if defined(__cplusplus)
#define LLCL_PLATFORM_CMP_VERSION __SUNPRO_CC
#else
#define LLCL_PLATFORM_CMP_VERSION __SUNPRO_C
#endif

// which OS
#define LLCL_PLATFORM_OS_UNIX 1
#if defined(sun) || defined(__sun)
#define LLCL_PLATFORM_OS_SOLARIS 1
#if defined(__SVR4) || defined(__svr4__)
#if defined(__SunOS_5_7)
#define LLCL_PLATFORM_OS_VER_MAJOR 7
#define LLCL_PLATFORM_OS_VER_MINOR 0
#elif defined(__SunOS_5_8)
#define LLCL_PLATFORM_OS_VER_MAJOR 8
#define LLCL_PLATFORM_OS_VER_MINOR 0
#elif defined(__SunOS_5_9)
#define LLCL_PLATFORM_OS_VER_MAJOR 9
#define LLCL_PLATFORM_OS_VER_MINOR 0
#elif defined(__SunOS_5_10)
#define LLCL_PLATFORM_OS_VER_MAJOR 10
#define LLCL_PLATFORM_OS_VER_MINOR 0
#elif defined(__SunOS_5_11)
#define LLCL_PLATFORM_OS_VER_MAJOR 11
#define LLCL_PLATFORM_OS_VER_MINOR 0
#else
#define LLCL_PLATFORM_OS_VER_MAJOR 1
#define LLCL_PLATFORM_OS_VER_MINOR 0
#endif
#else
#error "Unable to determine SUN OS version."
LLCL_PLATFORM_COMPILER_ERROR;
#endif
#elif defined(__SVR4) || defined(__svr4__)
#define LLCL_PLATFORM_OS_SUNOS 1
#if defined(__SunOS_5_7)
#define LLCL_PLATFORM_OS_VER_MAJOR 7
#define LLCL_PLATFORM_OS_VER_MINOR 0
#elif defined(__SunOS_5_8)
#define LLCL_PLATFORM_OS_VER_MAJOR 8
#define LLCL_PLATFORM_OS_VER_MINOR 0
#elif defined(__SunOS_5_9)
#define LLCL_PLATFORM_OS_VER_MAJOR 9
#define LLCL_PLATFORM_OS_VER_MINOR 0
#else
#define LLCL_PLATFORM_OS_VER_MAJOR 1
#endif
#else
#error "Unable to determine SUN OS version."
LLCL_PLATFORM_COMPILER_ERROR;
#endif

// determine which CPU
#if defined(__x86_64) || defined(__x86_64__)
#define LLCL_PLATFORM_CPU_X86_64 1
#define LLCL_PLATFORM_CPU_64_BIT 1
#elif defined(i386) || defined(__i386)
#define LLCL_PLATFORM_CPU_X86    1
#define LLCL_PLATFORM_CPU_32_BIT 1
#elif defined(__sparc64) || defined(__sparcv9)
#define LLCL_PLATFORM_CPU_SPARC    1
#define LLCL_PLATFORM_CPU_SPARC_V9 1
#define LLCL_PLATFORM_CPU_64_BIT   1
#elif defined(sparc) || defined(__sparc)
#define LLCL_PLATFORM_CPU_SPARC    1
#define LLCL_PLATFORM_CPU_SPARC_32 1
#define LLCL_PLATFORM_CPU_32_BIT   1
#else
#error "Cannot determine CPU on which the SUN compiler is running."
LLCL_PLATFORM_COMPILER_ERROR;
#endif
// ---------------------------------------------------------------------------
#else
#error "Could not identify the compiler."
LLCL_PLATFORM_COMPILER_ERROR;
#endif

#endif  // LLCL_STANDARD_SYSTEM_PLATFORM_H