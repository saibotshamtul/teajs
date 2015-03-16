# Zlib module #

Defined in files `zlib.so`/`zlib.dll`/`zlib.dylib`.

  * `var result = compress(input, [level])`
  * `var output = decompress(result)`

Both input and output are instances of Buffer. Level (compression strength) is a number from 0 to 9 inclusive.