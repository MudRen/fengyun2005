#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"玉玺"NOR, ({ "jade seal","seal" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "当今圣上的玉玺，上面小篆刻着：受命于天，棘寿永昌。\n");
		set("unit", "件");
		set("material", "cloth");
		set("value", 100);
		set("thief_obj", 1);
	}
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
