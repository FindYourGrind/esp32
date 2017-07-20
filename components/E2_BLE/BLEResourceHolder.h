/*
 * BLEResourceHolder.h
 *
 *  Created on: Jul 20, 2017
 *      Author: itrambovetskyi
 */

#ifndef COMPONENTS_E2_BLE_BLERESOURCEHOLDER_H_
#define COMPONENTS_E2_BLE_BLERESOURCEHOLDER_H_

#include "BLE.h"
#include "BLEUtils.h"
#include "BLEServer.h"
#include "BLE2902.h"

#define E2_SERVICE_UUID        		"4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define SSID_CHARACTERISTIC_UUID 	"beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define PASS_CHARACTERISTIC_UUID 	"beb5483e-36e1-4688-b7f5-ea07361b26a9"


namespace e2 {

	class BLEResourceHolder {

	public:
		static BLEResourceHolder& Instance() {
			static BLEResourceHolder myInstance;
			return myInstance;
		}

		BLEResourceHolder(BLEResourceHolder const&) = delete;             // Copy construct
		BLEResourceHolder(BLEResourceHolder&&) = delete;                  // Move construct
		BLEResourceHolder& operator=(BLEResourceHolder const&) = delete;  // Copy assign
		BLEResourceHolder& operator=(BLEResourceHolder &&) = delete;      // Move assign

		BLEServer* pServer;

		BLEService* pService;

		BLECharacteristic* SSIDCharacteristic;
		BLECharacteristic* PASSCharacteristic;

		BLEAdvertising *pAdvertising;

	protected:
		BLEResourceHolder();
		virtual ~BLEResourceHolder();

	};

} /* namespace e2 */

#endif /* COMPONENTS_E2_BLE_BLERESOURCEHOLDER_H_ */

