////////////////////////////////////////////////////////////////////////////
//	Module 		: script_hit_script.cpp
//	Created 	: 06.02.2004
//  Modified 	: 24.06.2004
//	Author		: Dmitriy Iassenev
//	Description : XRay Script hit class script export
////////////////////////////////////////////////////////////////////////////

#include "pch_script.h"
#include "script_hit.h"
#include "script_game_object.h"
#include "xrScriptEngine/ScriptExporter.hpp"

#define VAR_INT(varName) sol::var(int(varName))

// clang-format off
ICF static void CScriptHitScriptExport(lua_State* luaState)
{
    sol::state_view lua(luaState);

    lua.new_usertype<CScriptHit>("hit",
        sol::constructors<CScriptHit(), CScriptHit(const CScriptHit*)>(),

        // EHitType
        "burn", VAR_INT(ALife::eHitTypeBurn),
        "shock", VAR_INT(ALife::eHitTypeShock),
        "strike", VAR_INT(ALife::eHitTypeStrike),
        "wound", VAR_INT(ALife::eHitTypeWound),
        "radiation", VAR_INT(ALife::eHitTypeRadiation),
        "telepatic", VAR_INT(ALife::eHitTypeTelepatic),
        "chemical_burn", VAR_INT(ALife::eHitTypeChemicalBurn),
        "explosion", VAR_INT(ALife::eHitTypeExplosion),
        "fire_wound", VAR_INT(ALife::eHitTypeFireWound),
        "light_burn", VAR_INT(ALife::eHitTypeLightBurn),
        "dummy", VAR_INT(ALife::eHitTypeMax),

        "power", &CScriptHit::m_fPower,
        "direction", &CScriptHit::m_tDirection,
        "draftsman", &CScriptHit::m_tpDraftsman,
        "impulse", &CScriptHit::m_fImpulse,
        "type", &CScriptHit::m_tHitType,
        "bone", &CScriptHit::set_bone_name
     );
}

SCRIPT_EXPORT_FUNC(CScriptHit, (), CScriptHitScriptExport);
// clang-format on
