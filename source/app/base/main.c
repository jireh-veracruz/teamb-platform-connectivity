#include "vendors/platform-commons/modules/common/common.h"

#include "log.h"
#include "app.h"

int store_all_data_asap(void);
void emergency_shutdown(void);

int flag_running = 1;


//TODO(KGalang@hennypenny.com): find a way for main to be absract regardless of the
//      

void main(void)
{
    //hardware related init

    //dont forget to init all gpio
    // and peripherals even those 
    // not in use

    //custom firmware lib
#ifdef PROJ_CONNECT
        setup_connect_app();
#endif

    while(flag_running)
    {
        //maybe create a thread for our custom 
        //firmware lib
        //and other inits

#ifdef PROJ_CONNECT
        connect_app();
#endif

#ifdef PROJ_CONTROLBOARD
        controlboard_app()
#endif

#ifdef PROJ_OILMS
        oilms_app();
#endif

#ifdef PROJ_DUMMY
        app();
#endif

        log_service();
    }

    //must not reach this point
    //save all livedata
    store_all_data_asap();

    //force shutdown
    emergency_shutdown();
}