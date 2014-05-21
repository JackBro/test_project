M2Crypto
=========

 * Maintainer: Martin Paljak
 * URL: https://github.com/martinpaljak/M2Crypto
 * Temporary wiki: https://github.com/martinpaljak/M2Crypto/wiki/NextSteps
 * If you have problems, file an issue. Better yet, send a pull request!
 * The official repository shall soon live at https://github.com/M2Crypto/M2Crypto. Please file "structural" issues with version 0.22.3 to the issue tracker at the above repository. Any pull requests applied here shall be force-updated to the new repository that has cleaner history.

M2Crypto = Python + OpenSSL + SWIG
------------------------------------

M2Crypto is a crypto and SSL toolkit for Python.

M2 stands for "me, too!"

M2Crypto comes with the following:

- **RSA**, **DSA**, **DH**, **HMACs**, **message digests**,
  **symmetric ciphers** including **AES**,

- **SSL** functionality to implement **clients and servers**.

- **Example SSL client and server programs**, which are variously
  **threading**, **forking** or based on **non-blocking socket IO**.

- **HTTPS** extensions to Python's **httplib, urllib and xmlrpclib**.

- Unforgeable HMAC'ing **AuthCookies** for **web session management**.

- **FTP/TLS** client and server.

- **S/MIME v2**.

- **ZServerSSL**: A **HTTPS server for Zope**.

- **ZSmime**: An S/MIME messenger for **Zope**.

- And much more.

M2Crypto is released under a very liberal BSD-style licence. See 
LICENCE for details.

To install, see the file INSTALL.

Look at the tests and demos for example use. Recommended reading before
deploying in production is "Network Security with OpenSSL" by John Viega,
Matt Messier and Pravir Chandra, ISBN 059600270X.

Note these caveats:

- Possible memory leaks, because some objects need to be freed on the
  Python side and other objects on the C side, and these may change
  between OpenSSL versions. (Multiple free's lead to crashes very
  quickly, so these should be relatively rare.)
    
- No memory locking/clearing for keys, passphrases, etc. because AFAIK
  Python does not provide the features needed. On the C (OpenSSL) side
  things are cleared when the Python objects are deleted.
    

Have fun! Your feedback is welcome.
