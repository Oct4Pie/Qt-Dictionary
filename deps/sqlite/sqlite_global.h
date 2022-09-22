#ifndef SQLITE_GLOBAL_H
#define SQLITE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SQLITE_LIBRARY)
#  define SQLITE_EXPORT Q_DECL_EXPORT
#else
#  define SQLITE_EXPORT Q_DECL_IMPORT
#endif

#endif // SQLITE_GLOBAL_H
