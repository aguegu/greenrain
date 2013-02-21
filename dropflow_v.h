#ifndef _DROPFLOW_V_H_
#define _DROPFLOW_V_H_

#include "dropflow.h"

class DropFlowV: public DropFlow
{
public:
	DropFlowV(WINDOW *win, int index, int span = 1, int indent = 0);
	virtual ~DropFlowV();
	void display();
};

#endif
