#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "info.h"

eSystemInfo *eSystemInfo::instance = 0;

eSystemInfo::eSystemInfo()
{
	instance = this;

	char *model = NULL; 

	char buf[20] = {0,};

	int fd;

	if ( 0 < (fd = open("/proc/stb/info/hwmodel", O_RDONLY)))
	{
		read(fd, buf, 20);
		close(fd);
	}
	else
	{
		printf("File Open Error");
		close(fd);
	}

	if(strstr(buf, "TM-TWIN-OE") != NULL)
	{
		hwtype = TMTWIN;
		modelstr = "TM-TWIN-OE";
		hasrfmod = 1;
		hasvcr = 1;
		hasmicom = 1;
		haslnbchk = 0;
		hasyuv = 1;
	}
	else if(strstr(buf, "IOS-100HD") != NULL)
	{
		hwtype = TMTWIN;
		modelstr = "IOS-100HD";
		hasrfmod = 1;
		hasvcr = 1;
		hasmicom = 1;
		haslnbchk = 0;
		hasyuv = 1;
	}
	else if(strstr(buf, "TM-2T-OE") != NULL)
	{
		hwtype = TMTWIN;
		modelstr = "TM-2T-OE";
		hasrfmod = 1;
		hasvcr = 1;
		hasmicom = 1;
		hasyuv = 0;
	}
	else if(strstr(buf, "TM-2T") != NULL)
	{
		hwtype = TMTWIN;
		modelstr = "TM-2T";
		hasrfmod = 1;
		hasvcr = 1;
		hasmicom = 1;
		hasyuv = 0;
	}
	else if(strstr(buf, "TM-SINGLE-OE") != NULL)
	{
		hwtype = TMTWIN;
		modelstr = "TM-SINGLE-OE";
		hasrfmod = 0;
		hasvcr = 0;
		hasmicom = 0;
		hasyuv = 0;
	}
	else if(strstr(buf, "TM-SINGLE") != NULL)
	{
		hwtype = TMTWIN;
		modelstr = "TM-SINGLE";
		hasrfmod = 0;
		hasvcr = 0;
		hasmicom = 0;
		hasyuv = 0;
	}
	else
	{
		hwtype = TMTWIN;
		modelstr = "TM-TWIN";
		hasrfmod = 1;
		hasvcr = 1;
		hasmicom = 1;
		haslnbchk = 0;
		hasyuv = 1;
	}
}
