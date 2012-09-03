#ifndef __info_h
#define __info_h

class eSystemInfo
{
	static eSystemInfo *instance;
	const char *modelstr;
	int hwtype, hasrfmod, hasvcr, hasmicom, haslnbchk, hasyuv;
public:
	eSystemInfo();
	
	enum { TMTWIN };
	static eSystemInfo *getInstance(){ return instance;}

	const char *getModel() { return modelstr; }
	int hasRFMod() { return hasrfmod; }
	int hasVCR() { return hasvcr; }
	int getHwType() { return hwtype; }
	int hasMicom() { return hasmicom; }
	int hasLnbChk() { return haslnbchk; }
	int hasYuv() { return hasyuv; }
};

#endif
