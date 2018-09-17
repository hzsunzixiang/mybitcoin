




StephenSun@debian-1:~/mybitcoin/gethash/src$ l config/
bitcoin-config.h  bitcoin-config.h.in  stamp-h1


bitcoin-config.h 中定义了各种宏
要包含这个文件


bitcoin源码中这一行在起作用
继续研究
AC_CONFIG_HEADERS([src/config/bitcoin-config.h])
