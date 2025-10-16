/*
 * Copyright (c) 2025, Team B
 * All rights reserved.
 */

#include "source/app/base/main.h"
#include "source/app/projects/connectivity/app.h"
#include "vendors/platform-commons/modules/common/common.h"
#include "vendors/platform-commons/modules/log/log.h"

int store_all_data_asap(void);
void emergency_shutdown(void);

int flag_running = 1;

// TODO(KGalang@hennypenny.com): find a way for main to be absract

void main(void) {
    // hardware related init
    // dont forget to init all gpio
    // and peripherals even those
    // not in use
    // custom firmware lib
#ifdef PROJ_CONNECT
        setup_connect_app();
#endif
    while (flag_running) {
        // maybe create a thread for our custom
        // firmware lib
        // and other inits
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

    // must not reach this point
    // save all livedata
    store_all_data_asap();

    // force shutdown
    emergency_shutdown();
}
