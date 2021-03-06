// This file is part of Gram Wallet Desktop,
// a desktop application for the TON Blockchain project.
//
// For license and copyright information please follow this link:
// https://github.com/ton-blockchain/wallet-desktop/blob/master/LEGAL
//
#include "wallet/ton_default_settings.h"

#include "ton/ton_settings.h"

#include <QtCore/QFile>

namespace Wallet {

Ton::Settings GetDefaultSettings() {
	auto result = Ton::Settings();

	auto main = QFile(":/config/mainnet.config.json");
	main.open(QIODevice::ReadOnly);
	result.main.config = main.readAll();
	result.main.blockchainName = "mainnet";
	result.main.configUrl = "https://freeton.broxus.com/mainnet.config.json";
	result.main.tokenContractAddress = "0:08b697bafe589f5b14c6ce4f9cf4ff0a865a6f0c5a8371ea29ffe43643eb9fe4";

	auto test = QFile(":/config/testnet.config.json");
	test.open(QIODevice::ReadOnly);
	result.test.config= test.readAll();
	result.test.blockchainName = "net.ton.dev";
	result.test.configUrl = "https://freeton.broxus.com/testnet.config.json";
	result.test.tokenContractAddress = "0:08b697bafe589f5b14c6ce4f9cf4ff0a865a6f0c5a8371ea29ffe43643eb9fe4";

	result.useNetworkCallbacks = false;
	result.useTestNetwork = false;
	result.version = 0;
	return result;
}

} // namespace Wallet
