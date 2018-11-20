////////////////////////////////////////////////////////////////////////////
//	Module 		: script_reader_script.cpp
//	Created 	: 05.10.2004
//  Modified 	: 05.10.2004
//	Author		: Dmitriy Iassenev
//	Description : Script reader
////////////////////////////////////////////////////////////////////////////

#include "pch_script.h"
#include "xrScriptEngine/ScriptExporter.hpp"

using namespace luabind;

bool r_eof(IReader* self) { return (!!self->eof()); }
LPCSTR r_stringZ(IReader* self)
{
    shared_str temp;
    self->r_stringZ(temp);
    return (*temp);
}

bool r_bool(IReader* self) { return (!!self->r_u8()); }
void r_fvector3(IReader* self, Fvector* arg0) { self->r_fvector3(*arg0); }

ICF static void IReaderScriptExport(lua_State* luaState)
{
    sol::state_view lua(luaState);

    lua.new_usertype<IReader>("reader",
        "r_seek", &IReader::seek,
        "r_tell", &IReader::tell,
        "r_vec3", &::r_fvector3,
        "r_bool", &::r_bool,
        "r_float", &IReader::r_float,
        "r_u64", &IReader::r_u64,
        "r_s64", &IReader::r_s64,
        "r_u32", &IReader::r_u32,
        "r_s32", &IReader::r_s32,
        "r_u16", &IReader::r_u16,
        "r_s16", &IReader::r_s16,
        "r_u8", &IReader::r_u8,
        "r_s8", &IReader::r_s8,
        "r_float_q16", &IReader::r_float_q16,
        "r_float_q8", &IReader::r_float_q8,
        "r_angle16", &IReader::r_angle16,
        "r_angle8", &IReader::r_angle8,
        "r_dir", &IReader::r_dir,
        "r_sdir", &IReader::r_sdir,
        "r_stringZ", &r_stringZ,
        "r_elapsed", &IReader::elapsed,
        "r_advance", &IReader::advance,
        "r_eof", &r_eof
     );
}

SCRIPT_EXPORT_FUNC(IReader, (), IReaderScriptExport);
