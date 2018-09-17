# Defines which program executables will be produced.
bin_PROGRAMS = main 

# Defines which source files are used to produce the specificed
# executable.
main_SOURCES = main.cpp \
  hash.cpp \
  crypto/aes.cpp\
  crypto/chacha20.cpp\
  crypto/hmac_sha256.cpp\
  crypto/hmac_sha512.cpp\
  crypto/ripemd160.cpp\
  crypto/sha1.cpp\
  crypto/sha256.cpp\
  crypto/sha256_sse4.cpp\
  crypto/sha512.cpp\
  support/lockedpool.cpp \
  support/cleanse.cpp

# Defines flags for the C preprocessor *specific to ``hw``*.
# main_CPPLFAGS = 

# These are instead *default* flags, used by all the programs in
# ``bin_PROGRAMS``.
AM_CPPFLAGS = -std=c++11 -O0 -fpermissive  -I$(srcdir) -I$(top_srcdir)/libmath -I$(top_srcdir)/compat --save-temps

# Extra options for the linker.
# main_LDFLAGS = 

# Default options for the linker OR for libtool (depending on what you
# put in ``configure.ac``), used by all the programs in
# ``bin_PROGRAMS``.
#
# In this case, we want to statically link the libraries in
# ``main_LDADD`.
AM_LDFLAGS = -static

# Libraries the ``hw`` binary will be linked to.
#main_LDADD = $(top_srcdir)/libmath/libhwmath.la
