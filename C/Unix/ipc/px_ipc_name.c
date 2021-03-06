#include "../unpipc.h"

char* px_ipc_name(const char *name)
{
    char *dir, *dst, *slash;

    if ((dst = malloc(PATH_MAX)) == NULL)
        return(NULL);
    
    /* can override feault directory with  environment variable */
    if ( (dir = getenv("PX_IPC_NAME")) == NULL)
    {
        #ifdef POSIX_IPC_PREFIX
            dir = POSIX_IPC_PREFIX; /* from "config.h" */
        #else
            dir = "/tmp/";          /* default */
        #endif
    }

    /* dir must end in a slash */
    slash = (dir[strlen(dir) - 1] == '/') ? "" : "/";
    snprintf(dst, PATH_MAX, "%s%s%s", dir, slash, name);

    return(dst);                    /* caller can free() this pointer */
}