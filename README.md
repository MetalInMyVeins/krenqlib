# Krenq
High quality file encryptor library written in C++ 20.

## Usage:
```
#include "krenq/Core.hxx"

int main()
{
  // Construct Krenq with files/paths.
  Krenq k{"examples/"};

  // Encrypt the entries that Krenq has been constructed with and
  // save the generated key in the specified key file.
  k.encrypt("key1.krenq");

  // Decrypt the encrypted entries in Krenq with the specified key.
  k.decrypt("key1.krenq");

  // Encrypt the decrypted entries in Krenq again with the key specified
  // in the last call of decrypt(keyfile).
  k.encrypt_again();

  // Decrypt the entries in Krenq again.
  k.decrypt("key1.krenq");
}
```

## How it works:
Krenq is constructed with a list of strings. The elements in the list are referred to as entries. Each entry is treated as a file or a directory. Construction of Krenq generates a unique key that would persist over the lifetime of the Krenq instance. The `encrypt(keyfile)` method takes a unique key filename as argument, saves the generated key in that file, and encrypts the entries with that key. The `decrypt(keyfile)` method takes a key filename as argument and decrypts the entries with that key. The `encrypt_again()` method encrypts the entries with the key specified in the last call of `decrypt(keyfile)` method. Krenq would safely ignore any invalid entry. Encryption and decryption are strictly referred to as krenqryption.

## Installation:
### Linux:
Clone the repo by doing `https://github.com/MetalInMyVeins/krenq.git`.
The Krenq header would be in `include/krenq/` and the shipped shared library would be in `lib/`. The default `src/main.cxx` is commented out. Choose which lines to uncomment and then execute `build.sh` by doing `bash build.sh` in terminal. It would generate a binary named `kbin`. Execute it. It would krenqrypt or do nothing to the files provided in `examples/` depending on how you modified `src/main.cxx`. Modify `src/main.cxx` as you want or write your own program to krenqrypt any files in any directories.

The default `build.sh` selects `lib/` as the compile time and runtime link path of the generating binary. You can move `lib/libkrenq-x86_64.so` anywhere in your filesystem and modify `build.sh` accordingly to compile your program. Compile your program any way you want. Krenq is built to be flexible.

## Special Notes:
- Upon construction, Krenq would generate a unique key that would be stored in the keyfile specified in the `encrypt(keyfile)` method. The key is encrypted iteslf. You would never see the actual key.

- The `encrypt(keyfile)` method would throw a runtime error if `keyfile` already exists. The provided `keyfile` has to be unique.

- The `encrypt(keyfile)` and `decrypt(keyfile)` methods are smart. They would never touch an already krenqrypted file provided that the encrypted files are not touched by you or any other programs other than Krenq.

- The `decrypt(keyfile)` method guarantees to successfully decrypt files as long as the encrypted files are not modified post-encryption. If any encrypted files are modified by any means other than Krenq, they would be permanently damaged and cannot be retrieved.

- If a generated key successfully encrypts a file and the key is lost, the encrypted file can never be decrypted and would be treated lost parmanently.

- Any modification to the data in the keyfile would render it an invalid key.

- The key filename would essentially have `{key_filename}.krenq` syntax. `{key-filename}` cannot be an empty string and it's okay if the `.krenq` extension is not provided explicitly as Krenq would automatically append the extension. Specification of an invalid key filename syntax or existence of another key (or file) with the same name would result in a runtime error.

- Modification of the extension and/or the key filename doesn't have any effect on decryption. Decryption would work regardless of the key filename as long as the key data is not modified. This is to ensure flexibility over decryption and that Krenq has no liability over destroyed key.

- Every successful call of the krenqryption methods would write to a log file named `krenq.log` in the following syntax: `{timestamp} {key-filename} {krenqryption-flag} {entry-filenames}....`. This way you can easily know which key krenqrypted which file and when.

### Notes on `encrypt(keyfile)`:
`encrypt(keyfile)` would throw a runtime error in the following cases:

- Another key with the same key filename already exists.

### Notes on `decrypt(keyfile)`:
`decrypt(keyfile)` would throw a runtime error in the following cases:

- The specified keyfile data is modified, but in this case a runtime error is not guaranteed. `decrypt(keyfile)` is harmless. It wouldn't decrypt a file if it can't.

## License:
See `LICENSE` to view licensing information.
