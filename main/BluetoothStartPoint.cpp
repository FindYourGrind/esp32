#include "BLEResourceHolder.h"
#include <esp_log.h>
#include <string>
#include <sys/time.h>
#include <sstream>
#include "Task.h"

#include "sdkconfig.h"


using E2BLE = e2::BLEResourceHolder;

class E2ServerCallbacks: public BLEServerCallbacks {
	void onConnect(BLEServer *pServer) {

	};

	void onDisconnect(BLEServer *pServer) {

	}
};

class E2BLECharachteristicsCallbacks: public BLECharacteristicCallbacks {
	void onRead(BLECharacteristic *pCharacteristic) {

	}

	void onWrite(BLECharacteristic *pCharacteristic) {

	}
};

static void start() {
	E2BLE::Instance().pServer->setCallbacks(new E2ServerCallbacks());

	E2BLECharachteristicsCallbacks* characteristicsCallbacks = new E2BLECharachteristicsCallbacks();
	E2BLE::Instance().SSIDCharacteristic->setCallbacks(characteristicsCallbacks);
	E2BLE::Instance().PASSCharacteristic->setCallbacks(characteristicsCallbacks);

	E2BLE::Instance().pService->start();
	E2BLE::Instance().pAdvertising->start();
}

void Bluetooth(void)
{
	start();
}
