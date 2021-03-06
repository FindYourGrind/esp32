/*
 * BLEServiceMap.cpp
 *
 *  Created on: Jun 22, 2017
 *      Author: kolban
 */
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)
#include <sstream>
#include <iomanip>
#include "BLEServiceMap.h"
#include "BLEService.h"

/**
 * @brief Return the service by UUID.
 * @param [in] UUID The UUID to look up the service.
 * @return The characteristic.
 */
BLEService* BLEServiceMap::getByUUID(BLEUUID uuid) {
	for (auto &myPair : m_uuidMap) {
		if (myPair.second->getUUID().equals(uuid)) {
			return myPair.second;
		}
	}
	//return m_uuidMap.at(uuid.toString());
	return nullptr;
} // getByUUID


/**
 * @brief Return the service by handle.
 * @param [in] handle The handle to look up the service.
 * @return The service.
 */
BLEService* BLEServiceMap::getByHandle(uint16_t handle) {
	return m_handleMap.at(handle);
} // getByHandle


/**
 * @brief Set the service by UUID.
 * @param [in] uuid The uuid of the service.
 * @param [in] characteristic The service to cache.
 * @return N/A.
 */
void BLEServiceMap::setByUUID(BLEUUID uuid,
		BLEService *service) {
	m_uuidMap.insert(std::pair<std::string, BLEService *>(uuid.toString(), service));
} // setByUUID


/**
 * @brief Set the service by handle.
 * @param [in] handle The handle of the service.
 * @param [in] service The service to cache.
 * @return N/A.
 */
void BLEServiceMap::setByHandle(uint16_t handle,
		BLEService* service) {
	m_handleMap.insert(std::pair<uint16_t, BLEService *>(handle, service));
} // setByHandle


/**
 * @brief Return a string representation of the service map.
 * @return A string representation of the service map.
 */
std::string BLEServiceMap::toString() {
	std::stringstream stringStream;
	stringStream << std::hex << std::setfill('0');
	for (auto &myPair: m_handleMap) {
		stringStream << "handle: 0x" << std::setw(2) << myPair.first << ", uuid: " + myPair.second->getUUID().toString() << "\n";
	}
	return stringStream.str();
} // toString

void BLEServiceMap::handleGATTServerEvent(
		esp_gatts_cb_event_t      event,
		esp_gatt_if_t             gatts_if,
		esp_ble_gatts_cb_param_t *param) {
	// Invoke the handler for every Service we have.
	for (auto &myPair : m_uuidMap) {
		myPair.second->handleGATTServerEvent(event, gatts_if, param);
	}
}
#endif /* CONFIG_BT_ENABLED */
