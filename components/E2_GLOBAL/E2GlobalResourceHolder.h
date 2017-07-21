/*
 * E2GlobalResourceHolder.h
 *
 *  Created on: Jul 20, 2017
 *      Author: itrambovetskyi
 */

#ifndef COMPONENTS_E2_GLOBAL_E2GLOBALRESOURCEHOLDER_H_
#define COMPONENTS_E2_GLOBAL_E2GLOBALRESOURCEHOLDER_H_

#include <string>

using namespace std;

namespace e2 {

	class E2GlobalResourceHolder {

	public:
		static E2GlobalResourceHolder& Instance() {
			static E2GlobalResourceHolder myInstance;
			return myInstance;
		}

		E2GlobalResourceHolder(E2GlobalResourceHolder const&) = delete;             // Copy construct
		E2GlobalResourceHolder(E2GlobalResourceHolder&&) = delete;                  // Move construct
		E2GlobalResourceHolder& operator=(E2GlobalResourceHolder const&) = delete;  // Copy assign
		E2GlobalResourceHolder& operator=(E2GlobalResourceHolder &&) = delete;      // Move assign

		static string SSID;
		static string PASS;
		static string staIPAddress;
		static string apIPAddress;
		static string BLEServerName;


	protected:
		E2GlobalResourceHolder();
		virtual ~E2GlobalResourceHolder();

	};

} /* namespace e2 */

#endif /* COMPONENTS_E2_GLOBAL_E2GLOBALRESOURCEHOLDER_H_ */
