
#ifndef GAME_API_H
#define GAME_API_H

#ifdef GAME_RUNTIME_STATIC_DEFINE
#  define GAME_API
#  define GAME_RUNTIME_NO_EXPORT
#else
#  ifndef GAME_API
#    ifdef TestGame_EXPORTS
        /* We are building this library */
#      define GAME_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define GAME_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef GAME_RUNTIME_NO_EXPORT
#    define GAME_RUNTIME_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef GAME_RUNTIME_DEPRECATED
#  define GAME_RUNTIME_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef GAME_RUNTIME_DEPRECATED_EXPORT
#  define GAME_RUNTIME_DEPRECATED_EXPORT GAME_API GAME_RUNTIME_DEPRECATED
#endif

#ifndef GAME_RUNTIME_DEPRECATED_NO_EXPORT
#  define GAME_RUNTIME_DEPRECATED_NO_EXPORT GAME_RUNTIME_NO_EXPORT GAME_RUNTIME_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef GAME_RUNTIME_NO_DEPRECATED
#    define GAME_RUNTIME_NO_DEPRECATED
#  endif
#endif

#endif /* GAME_API_H */
