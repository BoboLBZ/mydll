// mydll.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "mydll.h"
//for cpp
 int  add(int a, int b)
{
	return a + b;
}
 //for lua
 extern "C"
 {
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>
 }

EXTERN_C  int myadd(lua_State * L)
 {
	 int num = lua_gettop(L);
	 int sum = 0;
	 for (int i = 1; i <= num; i++)
	 {
		 sum += lua_tonumber(L, i);
	 }
	 lua_pushnumber(L, sum);
	 return 1;
 }
 static luaL_Reg cMethods[] = {
	 { "myadd", myadd },
	 { NULL, NULL }
 };
 extern "C" __declspec(dllexport) int luaopen_mydll(lua_State* L)
 {
	 const char* libName = "mydll";
	 luaL_register(L, libName, cMethods);
	 return 1;
 }
