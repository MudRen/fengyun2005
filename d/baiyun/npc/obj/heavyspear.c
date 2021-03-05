#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
    set_name("虎头铁枪", ({ "iron spear","spear" }) );
    set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
        set("long", "这是南王府中，京城地界第一铸铁师重机先生亲铸长枪，经久耐用，威力非凡。\n");
        set("value", 100);
		set("material", "steel");
	}
    ::init_spear(20);
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
