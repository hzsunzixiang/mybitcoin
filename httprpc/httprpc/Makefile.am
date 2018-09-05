# Defines which program executables will be produced.
bin_PROGRAMS = httprpc 

# Defines which source files are used to produce the specificed
# executable.
httprpc_SOURCES =  httprpc.cpp \
  support/lockedpool.cpp \
  support/cleanse.cpp

# Defines flags for the C preprocessor *specific to ``hw``*.
# hw_CPPLFAGS = 

# These are instead *default* flags, used by all the programs in
# ``bin_PROGRAMS``.
#AM_CPPFLAGS = -std=c++11 -fpermissive  -I$(srcdir) -I$(top_srcdir)/libmath -I$(top_srcdir)/compat --save-temps
AM_CPPFLAGS = -std=c++11 -fpermissive  -I$(srcdir)  -I$(top_srcdir)/compat --save-temps

# Extra options for the linker.
# hw_LDFLAGS = 

# Default options for the linker OR for libtool (depending on what you
# put in ``configure.ac``), used by all the programs in
# ``bin_PROGRAMS``.
#
# In this case, we want to statically link the libraries in
# ``hw_LDADD`.
AM_LDFLAGS = -static

# Libraries the ``hw`` binary will be linked to.
#hw_LDADD = $(top_srcdir)/libmath/libhwmath.la
