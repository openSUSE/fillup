# Process this file with autoconf to create configure.
AC_PREREQ([2.65])

# ====================
# Version informations
# ====================
m4_define([fillup_version_major],[1])
m4_define([fillup_version_minor],[43])
m4_define([fillup_version_micro],[0])
m4_define([fillup_version],[fillup_version_major.fillup_version_minor.fillup_version_micro])

# =============
# Automake init
# =============
AC_INIT([fillup],[fillup_version])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([1.11 foreign dist-xz])
AM_SILENT_RULES([yes])
AC_LANG([C])

# ===========================
# Find required base packages
# ===========================
AM_PROG_AR
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_CANONICAL_HOST
PKG_PROG_PKG_CONFIG([0.20])
AC_PROG_EGREP
AC_PROG_SED

# ================
# Check for cflags
# ================
AC_ARG_ENABLE([werror],
	[AS_HELP_STRING([--disable-werror], [Treat all warnings as errors, useful for development])],
	[enable_werror="$enableval"],
	[enable_werror=yes]
)
AS_IF([test x"$enable_werror" != "xno"], [
	CFLAGS="$CFLAGS -Werror"
	CXXFLAGS="$CXXFLAGS -Werror"
])
# Be tough with warnings and produce less careless code
CFLAGS="$CFLAGS -Wall -Wextra -pedantic"
CXXFLAGS="$CXXFLAGS -Wall -Wextra -Wshadow -pedantic"

# =====================
# Prepare all .in/.am files
# =====================
AC_CONFIG_FILES([
Makefile
])
AC_OUTPUT

# ==============================================
# Display final informations about configuration
# ==============================================
AC_MSG_NOTICE([
==============================================================================
Build configuration:
	werror:          ${enable_werror}
==============================================================================
])
