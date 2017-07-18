/*
 * E2DISPLAY.h
 *
 *  Created on: Jul 18, 2017
 *      Author: itrambovetskyi
 */

#ifndef MAIN_E2_E2DISPLAY_H_
#define MAIN_E2_E2DISPLAY_H_

#include <string>
#include <stdio.h>

#include <ESPU8G2.h>

using namespace std;

class E2DISPLAY {
public:
	static const string CLASS_NAME;

private:
	U8G2* u8g2;
protected:
public:
	E2DISPLAY();
	virtual ~E2DISPLAY();

	void init (void);
	void powerUp (void);
	void powerDown (void);
	void clean (void);
	void fill (void);

};

#endif /* MAIN_E2_E2DISPLAY_H_ */
