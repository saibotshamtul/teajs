# SSL/TLS module #

Defined in file `socket.so` or `socket.dll` or `socket.dylib`.

Classes: **TLS**

  * `var tls = new TLS(socket)` - create new TLS connection atop a socket
  * `tls.getSocket()` - returns wrapped socket instance
  * `tls.connect()` - initiate client TLS handshake
  * `tls.accept()` - accept client TLS handshake
  * `tls.send(data)` - send `data` to socket; data = string or Buffer
  * `tls.receive(num)` - retrieve max `num` bytes from socket. Returns an instance of Buffer.
  * `tls.validateCertificate()` - returns certificate validation result (see http://www.openssl.org/docs/apps/verify.html for return codes)
  * `tls.close()` - close a TLS connection