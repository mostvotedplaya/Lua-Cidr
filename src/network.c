#include <lua.h>
#include <lauxlib.h>

#include "helper.c"

int cidrMatch( lua_State *L )
{
    int result = 0;
    if ( lua_isstring( L, 1 ) && lua_isstring( L, 2 ) )
    {
         result = inCidr( lua_tostring( L,1 ),
                          lua_tostring( L,2 ) );
    }
    lua_pushboolean( L, result );
    return 1;
}

static const luaL_Reg R[] =
{
  {"inCidr", cidrMatch},
  {NULL,NULL}
};

int luaopen_network( lua_State *L )
{
    luaL_openlib( L, "network", R, 0 );
    return 1;
}
