#if !defined(__EOSCONSOLE_H__)
#define __EOSCONSOLE_H__

#include <inttypes.h>
#include <avr/pgmspace.h>
#include <qp_port.h>

#if defined(ARDUINO) && ARDUINO >=100
#include "Arduino.h"
#else
#include <WProgram.h>
#endif

#include <canoneos.h>

using namespace QP;

enum TextMenuSignals 
{
    MENU_SELECT_SIG = Q_USER_SIG,
    TICK_SIG
};

struct TickEvt : public QEvt 
{
    uint8_t fine_time;                              // the fine 1/10 s counter
};

struct MenuSelectEvt : public QEvt 
{
    uint8_t  item_index;
};

class EOSConsole : public QHsm 
{
    static void PrintMenuTitles(uint8_t count, const char **menu);
    static void ShowParams();
  
public:
    EOSConsole()
        : QHsm((QStateHandler)&EOSConsole::Initial)
    {};
    int8_t MenuSelect();

protected:
    static QState Initial(EOSConsole *me, QEvt const *e);
    static QState Inactive(EOSConsole *me, QEvt const *e);
    static QState Active(EOSConsole *me, QEvt const *e);
    static QState MainMenu(EOSConsole *me, QEvt const *e);
    static QState ChangeSettingsMenu(EOSConsole *me, QEvt const *e);
    static QState ChangeApertureMenu(EOSConsole *me, QEvt const *e);
    static QState ChangeShutterSpeedMenu(EOSConsole *me, QEvt const *e);
    static QState ChangeWBMenu(EOSConsole *me, QEvt const *e);
    static QState ChangePStyleMenu(EOSConsole *me, QEvt const *e);
    static QState ChangeExpCompMenu(EOSConsole *me, QEvt const *e);
    static QState ChangeIsoMenu(EOSConsole *me, QEvt const *e);
};

#endif // __EOSCONSOLE_H__
