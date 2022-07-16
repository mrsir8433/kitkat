#include <platform.h>
#include <logger.h>

int main(int argc, char *argv[])
{
    // TODO: remove this!
    PlatformState state;
    platform_init(&state, "app", 100, 100, 600, 600);
    KFATAL("FLoating value %f", 3.14f);
    KERROR("FLoating value %f", 3.14f);
    KWARN("FLoating value %f", 3.14f);
    KINFO("FLoating value %f", 3.14f);
    KDEBUG("FLoating value %f", 3.14f);
    KTRACE("FLoating value %f", 3.14f);
    platform_sleep(1000 * 10);
    return 0;
}