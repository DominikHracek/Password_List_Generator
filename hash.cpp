#include "hash.h"

#include <string>
#include <cryptopp/md2.h>
#include <cryptopp/md4.h>
#include <cryptopp/md5.h>
#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

std::string get_hash(const std::string& data, const std::string& hash_function) {

    if (hash_function == "md2") {
        Hash::MD MD;
        return MD.MD2(data);
    } else if (hash_function == "md4") {
        Hash::MD MD;
        return MD.MD4(data);
    } else if (hash_function == "md5") {
        Hash::MD MD;
        return MD.MD5(data);
    } else if (hash_function == "sha1-160") {
        Hash::SHA::SHA1 SHA1;
        return SHA1.SHA1_160(data);
    } else if (hash_function == "sha2-224") {
        Hash::SHA::SHA2 SHA2;
        return SHA2.SHA2_224(data);
    } else if (hash_function == "sha2-256") {
        Hash::SHA::SHA2 SHA2;
        return SHA2.SHA2_256(data);
    } else if (hash_function == "sha2-384") {
        Hash::SHA::SHA2 SHA2;
        return SHA2.SHA2_384(data);
    } else if (hash_function == "sha2-512") {
        Hash::SHA::SHA2 SHA2;
        return SHA2.SHA2_512(data);
    } else if (hash_function == "sha3-224") {
        Hash::SHA::SHA3 SHA3;
        return SHA3.SHA3_224(data);
    } else if (hash_function == "sha3-256") {
        Hash::SHA::SHA3 SHA3;
        return SHA3.SHA3_256(data);
    } else if (hash_function == "sha3-384") {
        Hash::SHA::SHA3 SHA3;
        return SHA3.SHA3_384(data);
    } else if (hash_function == "sha3-512") {
        Hash::SHA::SHA3 SHA3;
        return SHA3.SHA3_512(data);
    }

    return "";
}

std::string MD2(const std::string& data) {
    CryptoPP::Weak1::MD2 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string MD4(const std::string& data) {
    CryptoPP::Weak1::MD4 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string MD5(const std::string& data) {
    CryptoPP::Weak1::MD5 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA1_160(const std::string& data) {
    CryptoPP::SHA1 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA2_224(const std::string& data) {
    CryptoPP::SHA224 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA2_256(const std::string& data) {
    CryptoPP::SHA256 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA2_384(const std::string& data) {
    CryptoPP::SHA384 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA2_512(const std::string& data) {
    CryptoPP::SHA512 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA3_224(const std::string& data) {
    CryptoPP::SHA3_224 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA3_256(const std::string& data) {
    CryptoPP::SHA3_256 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA3_384(const std::string& data) {
    CryptoPP::SHA3_384 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}

std::string SHA3_512(const std::string& data) {
    CryptoPP::SHA3_512 hash;
    std::string digest;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}