#include <android_native_app_glue.h>
#include <android/log.h>

#define TAG "NativeTest"
#define ALOGD(__VA_ARGS__) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)
#define ALOGE(__VA_ARGS__) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
void cmd(android_app* app,int32_t state);
void android_main(android_app* app)
{
    app_dummy();
    ALOGD("android_main() started");
    android_poll_source* src;
    int state;
    app->onAppCmd = cmd;
    while(1)
    {
        while((state = ALooper_pollAll(0, nullptr,nullptr,(void**)&src)) >= 0)
        {
            if(src)
            {
                src->process(app,src);
            }
            if(app->destroyRequested)
            {
                ALOGD("android_main() exited");
                return;
            }
        }
    }
}
void cmd(android_app* app,int32_t state)
{
    switch(state)
    {
        case APP_CMD_TERM_WINDOW:
            ALOGD("window terminated");
            break;
        case APP_CMD_INIT_WINDOW:
            ALOGD("window initialized");
            break;
        case APP_CMD_GAINED_FOCUS:
            ALOGD("gained focus");
            break;
        case APP_CMD_LOST_FOCUS:
            ALOGD("lost focus");
            break;
        case APP_CMD_SAVE_STATE:
            ALOGD("saved state");
            break;
        default:
            break;
    }
}