#pragma once

#include <initializer_list>
#include <string>
#include <utility>
#include <vector>

class Krenq
{
public:
  /** Constructs Krenq. */
  Krenq(const std::initializer_list<std::string>&);
  /** Deletes assignment constructor. */
  Krenq& operator=(const Krenq&) = delete;
  /** Deletes copy constructor. */
  Krenq(const Krenq&) = delete;
  /** Destructs Krenq. */
  ~Krenq();
  /** Encrypts the entries that `Krenq` has been initialized with.
   * Saves the generated key in the specified file.*/
  void encrypt(const std::string&);
  /** Decrypts the entries in Krenq using specified key file. */
  void decrypt(const std::string&);
  /** Encrypts the entries in Krenq again using the key file
   * specified in decrypt(keyfile). */
  void encrypt_again();

private:
  const std::vector<std::string> m_roots{};
  struct Key* m_key;
  std::string m_encryptedKstr{};
  struct Key* m_providedKey;
  std::string m_decryptionKeyname{};

private:
  void p_generateKey();
  std::string p_getRandomString(size_t, const std::string& = "");
  bool p_encryptEntry(const std::string&);
  bool p_encryptEntry(const std::string&, const std::string&);
  std::tuple<bool, int, size_t> p_encryptStatus(const std::string&);
  void p_saveKey(const std::string& = "");
  void p_addPadding(const std::string&, size_t);
  std::string p_getHashOfString(const std::string&);
  void p_addHash(const std::string&, const std::string&);
  std::string p_makePrefix(size_t);
  void p_extractKey(const std::string&);
  bool p_verifyEntry(const std::string&);
  bool p_decryptEntry(const std::string&);
  void p_removePadding(const std::string&);
};


