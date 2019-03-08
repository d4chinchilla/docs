#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include "sample.h"
#include "xcorr.h"
#include "errno.h"
#include "string.h"
#include "conf.h"

/* Make and return a stream pointed to the backend control file */
FILE *ctl_file(void)
{
    FILE *f;

    if (mkfifo(CONF_CTL, 0666) == -1)
    {
        if (errno != EEXIST)
            printf("Error, cannot make backend-ctl fifo: %s\n", strerror(errno));
    }

    f = fopen(CONF_CTL, "r");

    return f;
}

/* Cleanup temporary files and fifos once I close */
void clean_files(void)
{
    FILE *f;

    /* Delete the control file */
    unlink(CONF_CTL);

    /* Just empty the CONF_SOUND file */
    f = fopen(CONF_SOUND, "w");
    fwrite("", 1, 0, f);
}

void main(void)
{
    int running;
    FILE *ctlf;
    xcorr_manager_s manager;
    /* Make child threads */
    xcorr_manager_init(&manager);

    running = 1;
    /* Open a control file input */
    ctlf    = ctl_file();

    while (running)
    {
        char line[16];
        char *chr, *end;
        chr = &line[0];
        end = &line[sizeof(line) - 1];
        memset(line, 0, sizeof(line));

        /* Read a line from the control file */
        while (chr < end)
        {
            int cint;
            cint = fgetc(ctlf);

            if (cint == -1)
            {
                /* Clear any errors so we don't get stuck re-reading */
                clearerr(ctlf);
                usleep(100000);
                break;
            }

            *(chr++) = (unsigned char)cint;
        }

        /* If there is a stop command, stop running */
        if (memcmp("stop", line, 4) == 0)
            running = 0;

        /* Run a calibration routine if needed */
        if (memcmp("calibrate", line, 4) == 0)
        {
            manager.calibrating = 1;
            printf("CALIBRATING\n");
            sleep(5);
            printf("DONE\n");
            manager.calibrating = 0;
        }

    }
    fclose(ctlf);

    /* Kill our child thread(s) */
    xcorr_manager_kill(&manager);
    
    /* Cleanup */
    clean_files();
}
