Next release
------------

:Date: July X, 2024

* `@marek-serafin <https://github.com/stoprocent>`__ : Fixed typo in setting peer_cid while processing message 1.
* `@marek-serafin <https://github.com/stoprocent>`__ : Fixed zcbor. Added a method to avoid generation of duplicated types.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Added EDHOC error message compose & process with unit tests.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Added EDHOC PRK exporter with unit test.

Version 0.3.0
-------------

:Date: May 20, 2024

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Full support of RFC 9528 (EDHOC).

  * add missing static diffie hellman keys authentication method.

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Implementation is verified with RFC 9529 (EDHOC traces) for chapter 3.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Create documentation for sphinx including:

  * move README to sphinx.
  * move ChangeLog to sphinx.
  * create API documentation and fix header files.

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Add documentation deployment step for github actions.

Version 0.2.0
-------------

:Date: April 28, 2024

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Update implementation for RFC 9528 (EDHOC) including:

  * external authorization data aligned with RFC.
  * add message 4 compose & process.
  * keyUpdate method.

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Separate interface for EAD.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Implementation is verified with RFC 9529 (EDHOC traces) for chapter 2.

  * extended unit tests with EAD single/multiple tokens.
  * used RFC 9529 certificates to verify authentication identified by 'x5chain'.

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Example implementation of cipher suite 2.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : EDHOC context structure with private members.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Fix connection identifiers encoding option.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Fix authentication credentials encoding option.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Fix CBOR memory requirements for integer, byte string and text string.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Add build, run unit tests and verification by cppcheck and valgrind for github actions.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Update README.

Version 0.1.0
-------------

:Date: April 01, 2024

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : EDHOC implementation for version 16:

  * limited support for authentication methods only via signatures.
  * support EAD encoded as byte string.
  * support authentication identified by: 'kid', 'x5chain', 'x5t'.

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : CoAP friendly EDHOC API.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Separate interfaces for:

  * cryptographics keys.
  * cryptographics operations.
  * authentication credentials.

* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Authentication credentials fetch callback accept only private key identifier.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Example implementation of cipher suite 0 with PSA.
* `@kamil-kielbasa <https://github.com/kamil-kielbasa>`__ : Unit test with test vectors for authentication with signatures, X.509 identified by 'kid', 'x5chain' and 'x5t'.
