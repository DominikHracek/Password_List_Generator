#include "hash.h"

#include <iostream>
#include <string>
#include <cryptopp/md2.h>
#include <cryptopp/md4.h>
#include <cryptopp/md5.h>
#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

Hash::Hash() {
    data = "";
    hash_function = "";
}

void Hash::get_parameters(const std::string& data, const std::string& hash_function) {
    this->data = data;
    this->hash_function = hash_function;
}

std::string Hash::get_hash(const std::string& data, const std::string& hash_function) {

    Hash hash;
    if (hash_function == "md2") {
        return hash.MD2(data);
    } else if (hash_function == "md4") {
        return hash.MD4(data);
    } else if (hash_function == "md5") {
        return hash.MD5(data);
    } else if (hash_function == "sha224") {
        return hash.SHA2_224(data);
    } else if (hash_function == "sha256") {
        return hash.SHA2_256(data);
    } else if (hash_function == "sha384") {
        return hash.SHA2_384(data);
    } else if (hash_function == "sha512") {
        return hash.SHA2_512(data);
    } else if (hash_function == "sha3_224") {
        return hash.SHA3_224(data);
    } else if (hash_function == "sha3_256") {
        return hash.SHA3_256(data);
    } else if (hash_function == "sha3_384") {
        return hash.SHA3_384(data);
    } else if (hash_function == "sha3_512") {
        return hash.SHA3_512(data);
    }

    return "";
}

std::string Hash::MD2(const std::string& data) {
    CryptoPP::Weak1::MD2 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::MD4(const std::string& data) {
    CryptoPP::Weak1::MD4 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::MD5(const std::string& data) {
    CryptoPP::Weak1::MD5 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA2_224(const std::string& data) {
    CryptoPP::SHA224 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA2_256(const std::string& data) {
    CryptoPP::SHA256 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA2_384(const std::string& data) {
    CryptoPP::SHA384 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA2_512(const std::string& data) {
    CryptoPP::SHA512 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA3_224(const std::string& data) {
    CryptoPP::SHA3_224 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA3_256(const std::string& data) {
    CryptoPP::SHA3_256 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA3_384(const std::string& data) {
    CryptoPP::SHA3_384 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}

std::string Hash::SHA3_512(const std::string& data) {
    CryptoPP::SHA3_512 hash;
    std::string output;

    CryptoPP::StringSource(data, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(output)
            )
        )
    );

    return output;
}