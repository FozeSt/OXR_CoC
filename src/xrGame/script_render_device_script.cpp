////////////////////////////////////////////////////////////////////////////
//	Module 		: script_render_device_script.cpp
//	Created 	: 28.06.2004
//  Modified 	: 28.06.2004
//	Author		: Dmitriy Iassenev
//	Description : Script render device script export
////////////////////////////////////////////////////////////////////////////

#include "pch_script.h"
#include "xrScriptEngine/ScriptExporter.hpp"
#include "xrEngine/x_ray.h"

bool is_device_paused(CRenderDevice* d) { return !!Device.Paused(); }
void set_device_paused(CRenderDevice* d, bool b) { Device.Pause(b, TRUE, FALSE, "set_device_paused_script"); }
bool is_app_ready() { return pApp->IsLoaded(); }
u32 time_global(const CRenderDevice* self)
{
    THROW(self);
    return (self->dwTimeGlobal);
}

// clang-format off
ICF static void CRenderDeviceScriptExport(lua_State* luaState)
{
    sol::state_view lua(luaState);

    lua.new_usertype<CRenderDevice>("render_device",
        "width", sol::readonly(&CRenderDevice::dwWidth),
        "height", sol::readonly(&CRenderDevice::dwHeight),
        "time_delta", sol::readonly(&CRenderDevice::dwTimeDelta),
        "f_time_delta", sol::readonly(&CRenderDevice::fTimeDelta),
        "cam_pos", sol::readonly(&CRenderDevice::vCameraPosition),
        "cam_dir", sol::readonly(&CRenderDevice::vCameraDirection),
        "cam_top", sol::readonly(&CRenderDevice::vCameraTop),
        "cam_right", sol::readonly(&CRenderDevice::vCameraRight),
        //"view",           sol::readonly(&CRenderDevice::mView),
        //"projection",     sol::readonly(&CRenderDevice::mProject),
        //"full_transform", sol::readonly(&CRenderDevice::mFullTransform),
        "fov", sol::readonly(&CRenderDevice::fFOV),
        "aspect_ratio", sol::readonly(&CRenderDevice::fASPECT),
        "precache_frame", sol::readonly(&CRenderDevice::dwPrecacheFrame),
        "frame", sol::readonly(&CRenderDevice::dwFrame),
        "time_global", &time_global,
        "is_paused", &is_device_paused,
        "pause", &set_device_paused,
        "app_ready", &is_app_ready
     );
}

SCRIPT_EXPORT_FUNC(CRenderDevice, (), CRenderDeviceScriptExport);
// clang-format on
