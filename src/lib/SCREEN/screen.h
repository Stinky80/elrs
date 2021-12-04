
#pragma once

#include "targets.h"
#include "logos.h"
#include "TFT_eSPI_User_Setup.h"
#include <SPI.h>

class Screen
{
private:
    // Common Variables
    int current_page_index;
    int main_menu_page_index;
    int current_rate_index;
    int current_power_index;
    int current_ratio_index;

    virtual void doValueSelection(int action) = 0;
    virtual void doRateValueSelect(int action) = 0;
    virtual void doPowerValueSelect(int action) = 0; 
    virtual void doRatioValueSelect(int action) = 0;
    virtual void doPowerSavingValueSelect(int action) = 0;
    virtual void doSmartFanValueSelect(int action) = 0;

    virtual void updateMainMenuPage(int action) = 0;
    virtual void updateSubFunctionPage(int action) = 0;
    virtual void updateSubWIFIModePage() = 0;
    virtual void updateSubBindConfirmPage() = 0;
    virtual void updateSubBindingPage() = 0;

    virtual void doPageBack() = 0;
    virtual void doPageForward() = 0;
    virtual void doValueConfirm() = 0;                  

public:

    virtual void init();
    virtual void doUserAction(int action);
    virtual void doParamUpdate(uint8_t rate_index, uint8_t power_index, uint8_t ratio_index, uint8_t motion_index, uint8_t fan_index);
    virtual void doTemperatureUpdate(uint8_t temperature);
    virtual void doScreenBackLight(int state);
    virtual static void nullCallback(int updateType);
    virtual static void (*updatecallback)(int updateType);

    int getUserRateIndex();
    int getUserPowerIndex();
    int getUserRatioIndex();

};