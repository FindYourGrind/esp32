/*
 * BLEResourceHolder.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: itrambovetskyi
 */

#include "BLEResourceHolder.h"
#include "E2GlobalResourceHolder.h"

namespace e2 {

using E2GLOBAL = E2GlobalResourceHolder;

BLEResourceHolder::BLEResourceHolder() {
	BLE::initServer(E2GLOBAL::BLEServerName);

	pServer = new BLEServer();

	pService = pServer->createService(BLEUUID(E2_SERVICE_UUID));

	SSIDCharacteristic = pService->createCharacteristic(
			BLEUUID(SSID_CHARACTERISTIC_UUID), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
	PASSCharacteristic = pService->createCharacteristic(
			BLEUUID(PASS_CHARACTERISTIC_UUID), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

	BLE2902 *pBLE2902 = new BLE2902();
	pBLE2902->setNotifications(true);

	SSIDCharacteristic->addDescriptor(pBLE2902);
	PASSCharacteristic->addDescriptor(pBLE2902);

	pAdvertising = pServer->getAdvertising();
}

BLEResourceHolder::~BLEResourceHolder() {
	delete pServer;
	delete pService;
	delete SSIDCharacteristic;
	delete PASSCharacteristic;
	delete pAdvertising;
}

} /* namespace e2 */
