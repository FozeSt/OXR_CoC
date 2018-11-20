////////////////////////////////////////////////////////////////////////////
//	Module 		: script_sound_type_script.cpp
//	Created 	: 28.06.2004
//  Modified 	: 28.06.2004
//	Author		: Dmitriy Iassenev
//	Description : Script sound type script export
////////////////////////////////////////////////////////////////////////////

#include "pch_script.h"
#include "ai_sounds.h"
#include "xrScriptEngine/ScriptExporter.hpp"

// clang-format off
ICF static void CScriptSoundTypeScriptExport(lua_State* luaState)
{
    sol::state_view lua(luaState);

    lua.new_enum("snd_type",
        "no_sound", int(SOUND_TYPE_NO_SOUND),
        "weapon", int(SOUND_TYPE_WEAPON),
        "item", int(SOUND_TYPE_ITEM),
        "monster", int(SOUND_TYPE_MONSTER),
        "anomaly", int(SOUND_TYPE_ANOMALY),
        "world", int(SOUND_TYPE_WORLD),
        "pick_up", int(SOUND_TYPE_PICKING_UP),
        "drop", int(SOUND_TYPE_DROPPING),
        "hide", int(SOUND_TYPE_HIDING),
        "take", int(SOUND_TYPE_TAKING),
        "use", int(SOUND_TYPE_USING),
        "shoot", int(SOUND_TYPE_SHOOTING),
        "empty", int(SOUND_TYPE_EMPTY_CLICKING),
        "bullet_hit", int(SOUND_TYPE_BULLET_HIT),
        "reload", int(SOUND_TYPE_RECHARGING),
        "die", int(SOUND_TYPE_DYING),
        "injure", int(SOUND_TYPE_INJURING),
        "step", int(SOUND_TYPE_STEP),
        "talk", int(SOUND_TYPE_TALKING),
        "attack", int(SOUND_TYPE_ATTACKING),
        "eat", int(SOUND_TYPE_EATING),
        "idle", int(SOUND_TYPE_IDLE),
        "object_break", int(SOUND_TYPE_OBJECT_BREAKING),
        "object_collide", int(SOUND_TYPE_OBJECT_COLLIDING),
        "object_explode", int(SOUND_TYPE_OBJECT_EXPLODING),
        "ambient", int(SOUND_TYPE_AMBIENT),
        "item_pick_up", int(SOUND_TYPE_ITEM_PICKING_UP),
        "item_drop", int(SOUND_TYPE_ITEM_DROPPING),
        "item_hide", int(SOUND_TYPE_ITEM_HIDING),
        "item_take", int(SOUND_TYPE_ITEM_TAKING),
        "item_use", int(SOUND_TYPE_ITEM_USING),
        "weapon_shoot", int(SOUND_TYPE_WEAPON_SHOOTING),
        "weapon_empty", int(SOUND_TYPE_WEAPON_EMPTY_CLICKING),
        "weapon_bullet_hit", int(SOUND_TYPE_WEAPON_BULLET_HIT),
        "weapon_reload", int(SOUND_TYPE_WEAPON_RECHARGING),
        "monster_die", int(SOUND_TYPE_MONSTER_DYING),
        "monster_injure", int(SOUND_TYPE_MONSTER_INJURING),
        "monster_step", int(SOUND_TYPE_MONSTER_STEP),
        "monster_talk", int(SOUND_TYPE_MONSTER_TALKING),
        "monster_attack", int(SOUND_TYPE_MONSTER_ATTACKING),
        "monster_eat", int(SOUND_TYPE_MONSTER_EATING),
        "anomaly_idle", int(SOUND_TYPE_ANOMALY_IDLE),
        "world_object_break", int(SOUND_TYPE_WORLD_OBJECT_BREAKING),
        "world_object_collide", int(SOUND_TYPE_WORLD_OBJECT_COLLIDING),
        "world_object_explode", int(SOUND_TYPE_WORLD_OBJECT_EXPLODING),
        "world_ambient", int(SOUND_TYPE_WORLD_AMBIENT)
    );
}

SCRIPT_EXPORT_FUNC(CScriptSoundType, (), CScriptSoundTypeScriptExport);
// clang-format on
