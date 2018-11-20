#include "pch_script.h"
#include "xrEngine/XR_IOConsole.h"
#include "xrScriptEngine/ScriptExporter.hpp"

CConsole* console() { return Console; }
int get_console_integer(CConsole* c, LPCSTR cmd)
{
    int min = 0, max = 0;
    int val = c->GetInteger(cmd, min, max);
    return val;
}

float get_console_float(CConsole* c, LPCSTR cmd)
{
    float min = 0.0f, max = 0.0f;
    float val = c->GetFloat(cmd, min, max);
    return val;
}

bool get_console_bool(CConsole* c, LPCSTR cmd) { return c->GetBool(cmd); }
void execute_console_command_deferred(CConsole* c, LPCSTR string_to_execute)
{
    Engine.Event.Defer("KERNEL:console", size_t(xr_strdup(string_to_execute)));
}

// clang-format off
ICF static void CConsoleScriptExport(lua_State* luaState)
{
    sol::state_view lua(luaState);

    lua.set_function("get_console", &console);

    lua.new_usertype<CConsole>("CConsole",
        "execute", &CConsole::Execute,
        "execute_script", &CConsole::ExecuteScript,
        "show", &CConsole::Show,
        "hide", &CConsole::Hide,

        "get_string", &CConsole::GetString,
        "get_integer", &get_console_integer,
        "get_bool", &get_console_bool,
        "get_float", &get_console_float,
        "get_token", &CConsole::GetToken,
        "execute_deferred", &execute_console_command_deferred
     );
}

SCRIPT_EXPORT_FUNC(CConsole, (), CConsoleScriptExport);
// clang-format on
